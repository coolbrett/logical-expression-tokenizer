/**
 * tokenizer.c - A simple token recognizer.
 *
 * NOTE: The terms 'token' and 'lexeme' are used interchangeably in this
 *       program.
 *
 * @author Brett Dale
 * @author Julia Januchowski
 * @version 1.0 (3/2/2020)
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "tokenizer.h"

// global variables
char *line; // Global pointer to line of input


/**
 * This method eliminates all whitespace leading and/or trailing the string passed
 * @param string string to be trimmed
 */
void trim(char *string) {
    char *ptr = string;
    int length = strlen(ptr);

    while(isspace(ptr[length - 1])){
        ptr[--length] = 0;
    }
    while(*ptr && isspace(*ptr)){
        ++ptr, --length;
    }
    memmove(string, ptr, length + 1);
}

/**
 * This function adds a lexeme to the lexemes array passed in,
 * then returns the index where it was added
 * @param lexemes array to add lexeme
 * @param lexeme lexeme to be added
 * @param count index of last added lexeme
 * @return index of next available spot in array
 */
int add(Lexeme lexemes[], Lexeme lexeme, int count){
    lexemes[count] = lexeme;
    return count + 1;
}

/**
 * This function creates all lexemes along with their values and prefixes
 * and places them into the array passed in
 * @param lexemes array to hold created lexemes
 */
void initialize_lexemes(Lexeme lexemes[]){
    int count = 0;
    Lexeme ADD_OP = {"ADD_OP", "+", "an"};
    Lexeme SUB_OP = {"SUB_OP", "-", "a"};
    Lexeme MULT_OP = {"MULT_OP", "*", "a"};
    Lexeme DIV_OP = {"DIV_OP", "/", "a"};
    Lexeme LEFT_PAREN = {"LEFT_PAREN", "(", "a"};
    Lexeme RIGHT_PAREN = {"RIGHT_PAREN", ")", "a"};
    Lexeme EXPON_OP = {"EXPON_OP", "^", "an"};
    Lexeme ASSIGN_OP = {"ASSIGN_OP", "=", "an"};
    Lexeme LESS_THAN_OP = {"LESS_THAN_OP", "<", "a"};
    Lexeme LESS_THAN_OR_EQUAL_OP = {"LESS_THAN_OR_EQUAL_OP", "<=", "a"};
    Lexeme GREATER_THEN_OP = {"GREATER_THEN_OP", ">", "a"};
    Lexeme GREATER_THEN_OR_EQUAL_OP = {"GREATER_THEN_OR_EQUAL_OP", ">=", "a"};
    Lexeme EQUALS_OP = {"EQUALS_OP", "==", "a"};
    Lexeme NOT_OP = {"NOT_OP", "!", "a"};
    Lexeme NOT_EQUALS_OP = {"NOT_EQUALS_OP", "!", "a"};
    Lexeme SEMI_COLON = {"SEMI_COLON", ";", "a"};
    Lexeme INT_LITERAL = {"INT_LITERAL", "[0-9]+", "an"};

    count = add(lexemes, ADD_OP, count);
    count = add(lexemes, SUB_OP, count);
    count = add(lexemes, MULT_OP, count);
    count = add(lexemes, DIV_OP, count);
    count = add(lexemes, LEFT_PAREN, count);
    count = add(lexemes, RIGHT_PAREN, count);
    count = add(lexemes, EXPON_OP, count);
    count = add(lexemes, ASSIGN_OP, count);
    count = add(lexemes, LESS_THAN_OP, count);
    count = add(lexemes, LESS_THAN_OR_EQUAL_OP, count);
    count = add(lexemes, GREATER_THEN_OP, count);
    count = add(lexemes, GREATER_THEN_OR_EQUAL_OP, count);
    count = add(lexemes, EQUALS_OP, count);
    count = add(lexemes, NOT_OP, count);
    count = add(lexemes, NOT_EQUALS_OP, count);
    count = add(lexemes, SEMI_COLON, count);
    count = add(lexemes, INT_LITERAL, count);

}

/**
 * The function will have a character pointer as an argument.
 * This pointer will point to a character array (declared in main) that
 * should contain the last token discovered after the function returns.
 * The char* that is passed to the get_token function will contain the
 * next token in line when it, get_token returns. So if I had the line 12=17,
 * AFTER the first time I ran get_token(var), var would contain the
 * string ``12'' and the second time it would contain the string ``=''
 *
 * @param token_ptr pointer to token passed
*/
void get_token(char *token_ptr)
{
    // Add code here.
}

/**
* add comment
*/
int main(int argc, char* argv[]) {
    char  token[TSIZE];      /* Spot to hold a token, fixed size */
    char  input_line[LINE];  /* Line of input, fixed size        */
    FILE  *in_file = NULL;        /* File pointer                     */
    FILE  *out_file = NULL;
    int   line_count,        /* Number of lines read             */
    start,             /* start of new statement           */
    count;             /* count of tokens                  */

    if (argc != 3) {
        printf("Usage: tokenizer inputFile outputFile\n");
        exit(1);
    }

    in_file = fopen(argv[1], "r");
    if (in_file == NULL) {
        fprintf(stderr, "ERROR: could not open %s for reading\n", argv[1]);
        exit(1);
    }

    out_file = fopen(argv[2], "w");
    if (out_file == NULL) {
        fprintf(stderr, "ERROR: could not open %s for writing\n", argv[2]);
        exit(1);
    }

    //Brett did this
    Lexeme lexemes[TSIZE];
    initialize_lexemes(lexemes);

    while (fgets(input_line, LINE, in_file) != NULL){
        // Sets a global pointer to the memory location
        // where the input line resides.
        line = input_line;
        // Add code here.
        //printf("%s", line);

    }

    fclose(in_file);
    fclose(out_file);
    return 0;
}