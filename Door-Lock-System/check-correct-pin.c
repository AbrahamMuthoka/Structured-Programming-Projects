#include <stdio.h>
#include <string.h>

int main() {
    char correct_pin[] = "1234";
    char entered_pin[20]; // Buffer larger than 4 to safely capture wrong/long inputs
    int max_attempts = 3;
    int attempts = 0;

    printf("=== Secure Door Lock System ===\n");

    while (attempts < max_attempts) {
        printf("\nEnter your 4-digit PIN: ");
        scanf("%s", entered_pin);

        // 1. Check if the entered code is exactly 4 digits long
        if (strlen(entered_pin) != 4) {
            printf("INVALID INPUT! The PIN must be exactly 4 digits.\n");
            // This does not count as a security fail attempt, it just prompts again
            continue; 
        } 
        // 2. If it is 4 digits, check if it matches the correct PIN
        else {
            if (strcmp(entered_pin, correct_pin) == 0) {
                printf("ACCESS GRANTED! Door is unlocked.\n");
                return 0; // Exit program on success
            } else {
                attempts++;
                printf("ACCESS DENIED! Incorrect PIN.\n");
                
                if (attempts < max_attempts) {
                    printf("You have %d attempt(s) left.\n", max_attempts - attempts);
                } else {
                    printf("\nSystem locked! Too many incorrect attempts.\n");
                }
            }
        }
    }

    return 0;
}