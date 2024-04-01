/*
/ Name:       Josh Dunlap
/ Date:       03/29/2024
/ Class:      CYCS 1200
/ Assignment: Decimal to Different Base Converter
/ Notes:      We're using math.h for this, so we'll compile with -lm
/             to import the mathematics library.
/ Compile:    gcc -o nbc decimal-base-conv.c -lm
*/

#include <stdio.h>
#include <string.h>
#include "decimal-base-conv.h"


int main() {
    int choice, decimal;
    char another = 'y';

    while(another == 'y') {
        printf("Decimal to Different Base Conversion\n");
        printf("1. Convert to Binary\n");
        printf("2. Convert to Octal\n");
        printf("3. Convert to Hexadecimal\n");
        printf("4. Exit\n\n");
        printf("Enter your choice (1/2/3/4): ");
        scanf("%d", &choice);

        if(choice == 4) {
            printf("Exiting...\n");
            break;
        }
        
        printf("Enter a decimal number: ");
        scanf("%d", &decimal);

        if (decimal < 0) {
            printf("Invalid input. Please enter a positive decimal number.\n");
            continue;
        }

        if(choice == 1) {
            // Call the binary conversion function and print the result
            printf("Binary equivalent: %s\n", decimalToBinary(decimal));
        } else if(choice == 2) {
            // Call the octal conversion function and print the result
            printf("Octal equivalent: %s\n", decimalToOctal(decimal));
        } else if(choice == 3) {
            // Call the hexadecimal conversion function and print the result
            printf("Hexadecimal equivalent: %s\n", decimalToHexadecimal(decimal));
        } else {
            printf("Invalid choice. Please enter a number between 1 and 4.\n");
        }

        printf("\nDo you want to convert another number? (y/n): ");
        scanf(" %c", &another); // Notice the space before %c to consume any newline left in the input buffer
    }

    return 0;
}

// Helper function to reverse a string
void reverseString(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

// Conversion function for decimal to binary
char* decimalToBinary(int decimal) {
    static char binary[33];  // 32 bits for the binary digits plus 1 for the null terminator
    int index = 0;

    do {
        binary[index++] = (decimal % 2) + '0';
        decimal /= 2;
    } while (decimal > 0);
    
    binary[index] = '\0'; // Null-terminate the string
    reverseString(binary);

    return binary;
}

// Conversion function for decimal to octal
char* decimalToOctal(int decimal) {
    static char octal[12];  // 32 bits can be represented in 11 octal digits plus 1 for the null terminator
    int index = 0;

    do {
        octal[index++] = (decimal % 8) + '0';
        decimal /= 8;
    } while (decimal > 0);
    
    octal[index] = '\0'; // Null-terminate the string
    reverseString(octal);

    return octal;
}

// Conversion function for decimal to hexadecimal
char* decimalToHexadecimal(int decimal) {
    static char hexadecimal[9];  // 32 bits can be represented in 8 hexadecimal digits plus 1 for the null terminator
    int index = 0;

    do {
        int temp = decimal % 16;
        if(temp < 10) {
            hexadecimal[index++] = temp + '0';
        } else {
            hexadecimal[index++] = temp + 55; // ASCII value for 'A' is 65
        }
        decimal /= 16;
    } while (decimal > 0);

    hexadecimal[index] = '\0'; // Null-terminate the string
    reverseString(hexadecimal);

    return hexadecimal;
}