#include <stdio.h>

int main() {
    char inputString[100];

    printf("Accept a string from keyboard:\n");
    printf("-----------------------------------\n");

    printf("Input the string: ");
    fgets(inputString, sizeof(inputString), stdin);

    printf("The string you entered is: %s", inputString);

    return 0;
}
