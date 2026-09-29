#include <stdio.h>

void displayMenu(void);
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);

int main(void)
{
    int choice;
    double firstNumber;
    double secondNumber;
    double result;
    char continueChoice;

    printf("========================================\n");
    printf("          SIMPLE CALCULATOR\n");
    printf("========================================\n");

    do
    {
        displayMenu();

        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 4)
        {
            printf("Enter the first number: ");
            scanf("%lf", &firstNumber);

            printf("Enter the second number: ");
            scanf("%lf", &secondNumber);

            switch (choice)
            {
                case 1:
                    result = add(firstNumber, secondNumber);
                    printf("\nResult: %.2f + %.2f = %.2f\n",
                           firstNumber, secondNumber, result);
                    break;

                case 2:
                    result = subtract(firstNumber, secondNumber);
                    printf("\nResult: %.2f - %.2f = %.2f\n",
                           firstNumber, secondNumber, result);
                    break;

                case 3:
                    result = multiply(firstNumber, secondNumber);
                    printf("\nResult: %.2f * %.2f = %.2f\n",
                           firstNumber, secondNumber, result);
                    break;

                case 4:
                    if (secondNumber == 0)
                    {
                        printf("\nError: Division by zero is not allowed.\n");
                    }
                    else
                    {
                        result = divide(firstNumber, secondNumber);
                        printf("\nResult: %.2f / %.2f = %.2f\n",
                               firstNumber, secondNumber, result);
                    }
                    break;
            }
        }
        else if (choice == 5)
        {
            printf("\nThank you for using Simple Calculator.\n");
            break;
        }
        else
        {
            printf("\nInvalid choice. Please select an option from 1 to 5.\n");
        }

        if (choice != 5)
        {
            printf("\nWould you like to perform another calculation? (y/n): ");
            scanf(" %c", &continueChoice);

            if (continueChoice != 'y' && continueChoice != 'Y')
            {
                printf("\nThank you for using Simple Calculator.\n");
                break;
            }

            printf("\n");
        }

    } while (1);

    return 0;
}

void displayMenu(void)
{
    printf("\n----------------------------------------\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Exit\n");
    printf("----------------------------------------\n");
}

double add(double a, double b)
{
    return a + b;
}

double subtract(double a, double b)
{
    return a - b;
}

double multiply(double a, double b)
{
    return a * b;
}

double divide(double a, double b)
{
    return a / b;
}