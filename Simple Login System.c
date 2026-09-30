#include <stdio.h>

int main()
{
    int password;

    printf("========== LOGIN ==========\n");

    printf("Enter password: ");
    scanf("%d", &password);

    if (password == 1234)
    {
        printf("\nLogin Successful!\n");
        printf("Welcome to the system.\n");
    }
    else
    {
        printf("\nWrong Password!\n");
        printf("Login Failed.\n");
    }

    return 0;
}
