#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


typedef struct {
    char username[50];
    char password[50];
    double balance;
} User;


void loginUser(User* users, int userCount, User* currentUser);
void displayBalance(User user);
void transferMoney(User* users, int userCount, User currentUser);
void printCurrentTime();

int main() {
    
    User users[5] = {{"user1", "pass1", 1000.0},
                     {"user2", "pass2", 1500.0},
                     {"user3", "pass3", 2000.0},
                     {"Eren Mızrakçı", "eren123", 2500.0},
                     {"Bayram Alper KILIÇ", "bayram789", 3000.0}};

    int userCount = sizeof(users) / sizeof(users[0]);

   
    User currentUser;
    loginUser(users, userCount, &currentUser);

   
    int choice;
    do {
        printf("\nBank Application\n");
        printf("1. Display Account Balance\n");
        printf("2. Transfer Money\n");
        printf("3. Print Current Time\n");
        printf("4. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayBalance(currentUser);
                break;
            case 2:
                transferMoney(users, userCount, currentUser);
                break;
            case 3:
                printCurrentTime();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void loginUser(User* users, int userCount, User* currentUser) {
    char enteredUsername[50];
    char enteredPassword[50];

    printf("Username: ");
    scanf(" %[^\n]", enteredUsername);  
    printf("Password: ");
    scanf(" %[^\n]", enteredPassword);  

    for (int i = 0; i < userCount; ++i) {
        if (strcmp(users[i].username, enteredUsername) == 0 && strcmp(users[i].password, enteredPassword) == 0) {
            *currentUser = users[i];
            printf("Login successful. Hello, %s!\n", enteredUsername);
            return;
        }
    }

    printf("Invalid username or password. Exiting...\n");
    exit(1);
}

void displayBalance(User user) {
    printf("Your Account Balance: $%.2f\n", user.balance);
}

void transferMoney(User* users, int userCount, User currentUser) {
    char targetUsername[50];
    double amount;

    printf("Enter the username to transfer money to: ");
    scanf(" %[^\n]", targetUsername);  

    int targetIndex = -1;
    for (int i = 0; i < userCount; ++i) {
        if (strcmp(users[i].username, targetUsername) == 0) {
            targetIndex = i;
            break;
        }
    }

    if (targetIndex == -1) {
        printf("Target user not found. Transaction canceled...\n");
        return;
    }

    printf("Enter the transfer amount: ");
    scanf("%lf", &amount);

    if (amount <= 0 || amount > currentUser.balance) {
        printf("Invalid amount. Transaction canceled...\n");
        return;
    }

    currentUser.balance -= amount;
    users[targetIndex].balance += amount;

    printf("$%.2f successfully transferred. Your new balance: $%.2f\n", amount, currentUser.balance);
}

void printCurrentTime() {
    time_t currentTime;
    time(&currentTime);

    printf("Current Time: %s", ctime(&currentTime));
}
