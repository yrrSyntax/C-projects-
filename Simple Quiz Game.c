#include <stdio.h>
#include <string.h>

/* Function Declarations */
void welcomeScreen();
void showMenu();
void showInstructions();
void startQuiz();
void showResult(int score, int total);

int main()
{
    int choice;
    char playAgain;

    welcomeScreen();

    do
    {
        showMenu();

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                do
                {
                    startQuiz();

                    printf("\nDo you want to play again? (Y/N): ");
                    scanf(" %c", &playAgain);

                } while (playAgain == 'Y' || playAgain == 'y');

                break;

            case 2:
                showInstructions();
                break;

            case 3:
                printf("\n====================================\n");
                printf("       Thank You for Playing!\n");
                printf("====================================\n");
                return 0;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }

    } while (1);

    return 0;
}


/* Welcome Screen */
void welcomeScreen()
{
    printf("\n========================================\n");
    printf("          WELCOME TO QUIZ GAME\n");
    printf("========================================\n");
    printf("       Test Your General Knowledge\n");
    printf("========================================\n");
}


/* Main Menu */
void showMenu()
{
    printf("\n\n========== MAIN MENU ==========\n");
    printf("1. Start Quiz\n");
    printf("2. Instructions\n");
    printf("3. Exit\n");
    printf("===============================\n");
}


/* Instructions */
void showInstructions()
{
    printf("\n========== INSTRUCTIONS ==========\n");
    printf("1. The quiz contains 10 questions.\n");
    printf("2. Each question has 4 options.\n");
    printf("3. Enter the option number (1-4).\n");
    printf("4. Correct answer gives 1 point.\n");
    printf("5. Wrong answer gives 0 points.\n");
    printf("6. The correct answer will be shown\n");
    printf("   if your answer is wrong.\n");
    printf("7. Your final score and percentage\n");
    printf("   will be displayed at the end.\n");
    printf("==================================\n");
}


/* Start Quiz */
void startQuiz()
{
    /* Questions */
    char questions[10][200] =
    {
        "Which language is known as the mother of many programming languages?",
        "What is the size of an int in C (commonly)?",
        "Which symbol is used to end a statement in C?",
        "Which function is used to print output in C?",
        "Which function is used to take input in C?",
        "Which loop executes at least once?",
        "Which keyword is used to define a constant?",
        "Which operator is used for logical AND?",
        "Which header file is used for printf() and scanf()?",
        "Who developed the C programming language?"
    };

    /* Options */
    char options[10][4][100] =
    {
        {
            "C",
            "Python",
            "Java",
            "HTML"
        },

        {
            "1 byte",
            "2 bytes",
            "4 bytes",
            "8 bytes"
        },

        {
            ".",
            ";",
            ":",
            ","
        },

        {
            "scanf()",
            "printf()",
            "main()",
            "print()"
        },

        {
            "input()",
            "get()",
            "scanf()",
            "read()"
        },

        {
            "for loop",
            "while loop",
            "do-while loop",
            "none"
        },

        {
            "var",
            "constant",
            "const",
            "define"
        },

        {
            "&",
            "||",
            "&&",
            "!"
        },

        {
            "string.h",
            "math.h",
            "stdio.h",
            "stdlib.h"
        },

        {
            "James Gosling",
            "Dennis Ritchie",
            "Bjarne Stroustrup",
            "Guido van Rossum"
        }
    };

    /* Correct answers */
    int correctAnswers[10] =
    {
        1, 3, 2, 2, 3,
        3, 3, 3, 3, 2
    };

    int userAnswer;
    int score = 0;
    int wrong = 0;
    int i;

    printf("\n========================================\n");
    printf("             QUIZ STARTED\n");
    printf("========================================\n");

    for (i = 0; i < 10; i++)
    {
        printf("\nQuestion %d:\n", i + 1);
        printf("%s\n", questions[i]);

        printf("\n1. %s", options[i][0]);
        printf("\n2. %s", options[i][1]);
        printf("\n3. %s", options[i][2]);
        printf("\n4. %s", options[i][3]);

        printf("\n\nEnter your answer (1-4): ");
        scanf("%d", &userAnswer);

        if (userAnswer == correctAnswers[i])
        {
            printf("\nCorrect! +1 Point\n");
            score++;
        }
        else
        {
            printf("\nWrong Answer!\n");
            printf("Correct Answer: %s\n",
                   options[i][correctAnswers[i] - 1]);

            wrong++;
        }
    }

    showResult(score, 10);
}


/* Final Result */
void showResult(int score, int total)
{
    float percentage;

    percentage = ((float)score / total) * 100;

    printf("\n\n========================================\n");
    printf("             FINAL RESULT\n");
    printf("========================================\n");

    printf("Total Questions : %d\n", total);
    printf("Correct Answers : %d\n", score);
    printf("Wrong Answers   : %d\n", total - score);
    printf("Score           : %d/%d\n", score, total);
    printf("Percentage      : %.2f%%\n", percentage);

    printf("\nMessage: ");

    if (percentage >= 80)
    {
        printf("Very Good! Excellent Work!\n");
    }
    else if (percentage >= 60)
    {
        printf("Good Job! Keep Practicing!\n");
    }
    else if (percentage >= 40)
    {
        printf("Nice Try! Keep Learning!\n");
    }
    else
    {
        printf("Keep Practicing! You Can Do Better!\n");
    }

    printf("========================================\n");
}
