#include <stdio.h>
#include <string.h>

struct Question {
    char subject[20];
    char question[200];
    char optionA[50];
    char optionB[50];
    char optionC[50];
    char optionD[50];
    char correctOption;
    int importance;
};

int main() {
    int score = 0;
    int subjectChoice;
    char answer;
    char name[30];
    char chosenSubject[20];

    struct Question q[] = {

        {"Computer Science",
         "What is the size of int in C (on most systems)?",
         "2 bytes", "4 bytes", "8 bytes", "Depends on compiler",
         'B', 3},

        {"Computer Science",
         "Which loop is best when iterations are known?",
         "while", "do-while", "for", "if",
         'C', 2},

        {"Physics",
         "SI unit of force is?",
         "Joule", "Pascal", "Newton", "Watt",
         'C', 3},

        {"Physics",
         "Speed of light is approximately?",
         "3 x 10^8 m/s", "3 x 10^6 m/s", "3 x 10^5 m/s", "3 x 10^3 m/s",
         'A', 2},

        {"Maths",
         "Derivative of x^2 is?",
         "2x", "x", "x^2", "1",
         'A', 3},

        {"Maths",
         "Value of pi is approximately?",
         "2.14", "3.14", "4.13", "3.41",
         'B', 2}
    };

    int totalQuestions = sizeof(q) / sizeof(q[0]);

    printf("====================================\n");
    printf(" AI BASED EXAM QUIZ SYSTEM\n");
    printf("====================================\n");

    printf("Enter your name: ");
    scanf("%s", name);

    /* SUBJECT SELECTION (FIXED) */
    do {
        printf("\nSelect Subject:\n");
        printf("1. Computer Science\n");
        printf("2. Physics\n");
        printf("3. Maths\n");
        printf("Enter choice (1-3): ");
        scanf("%d", &subjectChoice);
    } while(subjectChoice < 1 || subjectChoice > 3);

    if(subjectChoice == 1)
        strcpy(chosenSubject, "Computer Science");
    else if(subjectChoice == 2)
        strcpy(chosenSubject, "Physics");
    else
        strcpy(chosenSubject, "Maths");

    printf("\nYou selected: %s\n", chosenSubject);
    printf("Starting quiz...\n\n");

    /* QUIZ START */
    for(int i = 0; i < totalQuestions; i++) {

        if(strcmp(q[i].subject, chosenSubject) == 0 &&
           q[i].importance >= 2) {

            printf("%s\n", q[i].question);
            printf("A. %s\n", q[i].optionA);
            printf("B. %s\n", q[i].optionB);
            printf("C. %s\n", q[i].optionC);
            printf("D. %s\n", q[i].optionD);

            printf("Your answer: ");
            scanf(" %c", &answer);

            if(answer == q[i].correctOption) {
                printf("Correct!\n\n");
                score++;
            } else {
                printf("Wrong! Correct answer is %c\n\n",
                       q[i].correctOption);
            }
        }
    }

    printf("====================================\n");
    printf("Quiz Finished!\n");
    printf("Score: %d\n", score);

    if(score >= 2)
        printf("Feedback: Good exam preparation!\n");
    else
        printf("Feedback: Needs more practice.\n");

    printf("====================================\n");

    return 0;
}
