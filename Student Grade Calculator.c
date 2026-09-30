#include <stdio.h>

int main()
{
    float hindi, english, maths, science, computer;
    float total, percentage;

    printf("Enter Hindi marks: ");
    scanf("%f", &hindi);

    printf("Enter English marks: ");
    scanf("%f", &english);

    printf("Enter Maths marks: ");
    scanf("%f", &maths);

    printf("Enter Science marks: ");
    scanf("%f", &science);

    printf("Enter Computer marks: ");
    scanf("%f", &computer);

    total = hindi + english + maths + science + computer;
    percentage = total / 5;

    printf("\n============================\n");
    printf("Total Marks = %.2f\n", total);
    printf("Percentage = %.2f%%\n", percentage);

    if (percentage >= 90)
    {
        printf("Grade = A+\n");
    }
    else if (percentage >= 80)
    {
        printf("Grade = A\n");
    }
    else if (percentage >= 70)
    {
        printf("Grade = B\n");
    }
    else if (percentage >= 60)
    {
        printf("Grade = C\n");
    }
    else if (percentage >= 50)
    {
        printf("Grade = D\n");
    }
    else
    {
        printf("Grade = F\n");
    }

    printf("============================\n");

    return 0;
}
