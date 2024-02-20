#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool hasLowercase(char password[]) {
    int len = strlen(password);
    int i;

    for (i = 0; i < len; i++) {
        if (password[i] >= 'a' && password[i] <= 'z') {
            return true;
        }
    }

    return false;
}

bool hasUppercase(char password[]) {
    int len = strlen(password);
    int i;

    for (i = 0; i < len; i++) {
        if (password[i] >= 'A' && password[i] <= 'Z') {
            return true;
        }
    }

    return false;
}

bool hasDigit(char password[]) {
    int len = strlen(password);
    int i;

    for (i = 0; i < len; i++) {
        if (password[i] >= '0' && password[i] <= '9') {
            return true;
        }
    }

    return false;
}

bool hasSpecialChar(char password[]) {
    int len = strlen(password);
    int i;

    for (i = 0; i < len; i++) {
        if ((password[i] >= 32 && password[i] <= 47) || (password[i] >= 58 && password[i] <= 64) || (password[i] >= 91 && password[i] <= 96) || (password[i] >= 123 && password[i] <= 126)) {
            return true;
        }
    }

    return false;
}

int evaluateStrength(char password[]) {
    int score = 0;

    if (hasLowercase(password) == true) {
        score++;
    }

    if (hasUppercase(password) == true) {
        score++;
    }

    if (hasDigit(password) == true) {
        score++;
    }

    if (hasSpecialChar(password) == true) {
        score++;
    }

    if (strlen(password) >= 12) {
        score++;
    }

    return score;
}

int main() {
    printf("\n\tPassword Resilience Analyzer\n");
    printf("---------------------------------------------\n\n");

    int selection = 0;
    char strength[100];

    while (true) {
        printf("(1) - Test a New Password\n");
        printf("(2) - View Strength of Last Tested Password\n");
        printf("(3) - Exit\n\n");

        printf("Enter Selection: ");
        scanf("%d", &selection);

        getchar();

        printf("\n");

        if (selection == 1) {
            char password[100];

            printf("Enter a Password: ");
            fgets(password, 100, stdin);
            password[strlen(password) - 1] = '\0';

            if (strlen(password) < 8) {
                printf("Error: Password should be at least 8 characters long.\n\n\n");
                continue;
            }

            int score = evaluateStrength(password);

            if (score >= 0 && score <= 2) {
                strcpy(strength, "Weak");
            }

            else if (score >= 3 && score <= 4) {
                strcpy(strength, "Moderate");
            }

            else {
                strcpy(strength, "Strong");
            }
            
            printf("Password Strength: %s\n\n\n", strength);
        }

        else if (selection == 2) {
            if (strlen(strength) == 0) {
                printf("No Password was Tested Before. Test a Password First to View.\n\n\n");
            }

            else {
                printf("Last Tested Password Strength: %s\n\n\n", strength);
            }
        }

        else if (selection == 3) {
            printf("Goodbye!\n");
            break;
        }
        
        else {
            printf("Invalid Selection. Try Again.\n\n\n");
        }
    }

    return 0;
}
