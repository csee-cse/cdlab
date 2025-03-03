#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define MAX_IDENTIFIERS 50 // Maximum number of identifiers
#define MAX_LENGTH 100 // Maximum length of input expression

// Structure to store symbol table entry
struct Symbol {
    char name[MAX_LENGTH]; // Identifier name
    char type[10]; // Data type (int, float, etc.)
    char scope[10]; // Scope (global, local)
    void *address; // Memory address
    char value[20]; // Value (if assigned)
};

// Symbol table array
struct Symbol symbolTable[MAX_IDENTIFIERS];
int i, symbolCount = 0; // Number of identifiers stored

// Function to add an identifier to the symbol table
void insertSymbol(char name[], char type[], char scope[], char value[]) {
    struct Symbol *s = &symbolTable[symbolCount]; // Get next free entry
    strcpy(s->name, name);
    strcpy(s->type, type);
    strcpy(s->scope, scope);
    s->address = malloc(strlen(name) + 1); // Allocate memory
    strcpy(s->value, value);
    symbolCount++; // Increase count
}

// Function to display the symbol table
void displaySymbolTable() {
    printf("\nSymbol Table:\n");
    printf("----------------------------------------------------------\n");
    printf("Name       Type     Scope    Address      Value\n");
    printf("----------------------------------------------------------\n");
    for (i = 0; i < symbolCount; i++) {
        printf("%-10s %-8s %-8s %p %s\n",
            symbolTable[i].name,
            symbolTable[i].type,
            symbolTable[i].scope,
            symbolTable[i].address,
            symbolTable[i].value);
    }
    printf("----------------------------------------------------------\n");
}

// Function to check if a word is a data type
int isDataType(char *word) {
    return (strcmp(word, "int") == 0 || strcmp(word, "float") == 0 || strcmp(word, "char") == 0);
}

int main() {
    char input[MAX_LENGTH], c;
    int i = 0, j = 0;
    char lastType[10] = ""; // Store last detected type

    printf("Enter expression terminated by $: ");
    while ((c = getchar()) != '$' && i < MAX_LENGTH - 1) { // Read input
        input[i] = c;
        i++;
    }
    input[i] = '\0'; // Null-terminate string

    printf("\nGiven Expression: %s\n", input);

    // Parse input and store identifiers
    while (j < i) {
        if (isalpha(input[j])) { // If character is alphabetic (identifier start)
            char identifier[MAX_LENGTH];
            int k = 0;
            // Collect the whole word
            while (isalnum(input[j])) {
                identifier[k++] = input[j++];
            }
            identifier[k] = '\0'; // Null-terminate

            // Check if it's a datatype
            if (isDataType(identifier)) {
                strcpy(lastType, identifier); // Store last found datatype
            } else {
                char value[20] = "0"; // Default value

                // Check if next char is '=' to capture assigned value
                if (input[j] == '=') {
                    j++; // Move past '='
                    k = 0;
                    while (isdigit(input[j]) || input[j] == '.') {
                        value[k++] = input[j++];
                    }
                    value[k] = '\0'; // Null-terminate value
                }

                // Insert into symbol table
                insertSymbol(identifier, lastType, "global", value);
            }
        } else {
            j++; // Move to next character
        }
    }

    // Display the final symbol table
    displaySymbolTable();

    // Free allocated memory
    for (i = 0; i < symbolCount; i++) {
        free(symbolTable[i].address);
    }

    getch();
    return 0;
}
                           