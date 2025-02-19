#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAX_INPUT_SIZE 1000
#define MAX_LINE_SIZE 100
#define MAX_TOKENS 100

int main() {
    int sy, o, v, c, i = 0, j, k, kw, keyword_index = 0, variable_index = 0, constant_index = 0, operator_index = 0, symbol_index = 0;
    char s[MAX_INPUT_SIZE] = ""; 
    char g[MAX_LINE_SIZE];
    char keywords[MAX_TOKENS][20]; 
    char variables[MAX_TOKENS][20];
    char constants[MAX_TOKENS][20];
    char operators[MAX_TOKENS]; 
    char symbols[MAX_TOKENS]; 
    char constant[20];
    char word[20];
    int already_exists, is_keyword;

    const char *keyword_list[] = {
        "int", "float", "if", "else", "while", "return", "for", "break",
        "continue", "char", "double", "void", "do", "switch", "case", 
        "default", "goto", "main"
    };
    const int keyword_count = sizeof(keyword_list) / sizeof(keyword_list[0]);

    const char operator_list[] = "+-/=<>";  // Corrected
    const char *symbol_list = "();{}";

    printf("Enter Program (type $ on a new line to terminate input):\n");

    while (1) {
        if (fgets(g, sizeof(g), stdin) == NULL) break; 
        if (g[strlen(g) - 1] == '\n') g[strlen(g) - 1] = '\0';
        if (strcmp(g, "$") == 0) break;
        if (strlen(s) + strlen(g) >= MAX_INPUT_SIZE - 1) {
            printf("Error: Input too long!\n");
            return 1;
        }
        strcat(s, g); 
        strcat(s, " "); 
    }

    i = 0;
    while (s[i] != '\0') {
        already_exists = 0; 
        is_keyword = 0;

        // Handle constants (numbers)
        if (isdigit(s[i])) {
            j = i;
            while (isdigit(s[i + 1])) i++;
            strncpy(constant, &s[j], i - j + 1);
            constant[i - j + 1] = '\0';

            for (c = 0; c < constant_index; c++) {
                if (strcmp(constants[c], constant) == 0) {
                    already_exists = 1;
                    break;
                }
            }
            if (!already_exists) strcpy(constants[constant_index++], constant);
        }
        // Handle words (keywords or variables)
        else if (isalpha(s[i]) || s[i] == '_') {
            j = i;
            while (isalnum(s[i + 1]) || s[i + 1] == '_') i++;
            strncpy(word, &s[j], i - j + 1);
            word[i - j + 1] = '\0';

            // Check if it's a keyword
            for (k = 0; k < keyword_count; k++) {
                if (strcmp(word, keyword_list[k]) == 0) {
                    is_keyword = 1;
                    for (kw = 0; kw < keyword_index; kw++) {
                        if (strcmp(keywords[kw], word) == 0) {
                            already_exists = 1;
                            break;
                        }
                    }
                    if (!already_exists) strcpy(keywords[keyword_index++], word);
                    break;
                }
            }

            // If it's not a keyword, it's a variable
            if (!is_keyword) {
                already_exists = 0;
                for (v = 0; v < variable_index; v++) {
                    if (strcmp(variables[v], word) == 0) {
                        already_exists = 1;
                        break;
                    }
                }
                if (!already_exists) strcpy(variables[variable_index++], word);
            }
        }
        // Handle operators
        else if (strchr(operator_list, s[i])) {
            already_exists = 0;
            for (o = 0; o < operator_index; o++) {
                if (operators[o] == s[i]) {
                    already_exists = 1;
                    break;
                }
            }
            if (!already_exists) operators[operator_index++] = s[i];
        }
        // Handle symbols
        else if (strchr(symbol_list, s[i])) {
            already_exists = 0;
            for (sy = 0; sy < symbol_index; sy++) {
                if (symbols[sy] == s[i]) {
                    already_exists = 1;
                    break;
                }
            }
            if (!already_exists) symbols[symbol_index++] = s[i];
        }

        i++;
    }

    // Output results
    printf("\nKeywords:\n");
    for (kw = 0; kw < keyword_index; kw++) {
        printf("%s ", keywords[kw]);
    }

    printf("\n\nVariables:\n");
    for (v = 0; v < variable_index; v++) {
        printf("%s ", variables[v]);
    }

    printf("\n\nConstants:\n");
    for (c = 0; c < constant_index; c++) {
        printf("%s ", constants[c]);
    }

    printf("\n\nOperators:\n");
    for (o = 0; o < operator_index; o++) {
        printf("%c ", operators[o]);
    }

    printf("\n\nSymbols:\n");
    for (sy = 0; sy < symbol_index; sy++) {
        printf("%c ", symbols[sy]);
    }

    printf("\n");
    return 0;
}
