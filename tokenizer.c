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
int add_lexeme(lexeme lexemes[], lexeme lexeme, int count){
    lexemes[count] = lexeme;
    return count + 1;
}

/**
 * This function creates all lexemes along with their values and prefixes
 * and places them into the array passed in
 * @param lexemes array to hold created lexemes
 */
int initialize_lexemes(lexeme lexemes[]){
    int count = 0;
    lexeme ADD_OP = {"ADD_OP", "+", "an"};
    lexeme SUB_OP = {"SUB_OP", "-", "a"};
    lexeme MULT_OP = {"MULT_OP", "*", "a"};
    lexeme DIV_OP = {"DIV_OP", "/", "a"};
    lexeme LEFT_PAREN = {"LEFT_PAREN", "(", "a"};
    lexeme RIGHT_PAREN = {"RIGHT_PAREN", ")", "a"};
    lexeme EXPON_OP = {"EXPON_OP", "^", "an"};
    lexeme ASSIGN_OP = {"ASSIGN_OP", "=", "an"};
    lexeme LESS_THAN_OP = {"LESS_THAN_OP", "<", "a"};
    lexeme LESS_THAN_OR_EQUAL_OP = {"LESS_THAN_OR_EQUAL_OP", "<=", "a"};
    lexeme GREATER_THEN_OP = {"GREATER_THEN_OP", ">", "a"};
    lexeme GREATER_THEN_OR_EQUAL_OP = {"GREATER_THEN_OR_EQUAL_OP", ">=", "a"};
    lexeme EQUALS_OP = {"EQUALS_OP", "==", "an"};
    lexeme NOT_OP = {"NOT_OP", "!", "a"};
    lexeme NOT_EQUALS_OP = {"NOT_EQUALS_OP", "!=", "a"};
    lexeme SEMI_COLON = {"SEMI_COLON", ";", "a"};
    //this needs attention
    lexeme INT_LITERAL = {"INT_LITERAL", "[0-9]+", "an"};

    count = add_lexeme(lexemes, ADD_OP, count);
    count = add_lexeme(lexemes, SUB_OP, count);
    count = add_lexeme(lexemes, MULT_OP, count);
    count = add_lexeme(lexemes, DIV_OP, count);
    count = add_lexeme(lexemes, LEFT_PAREN, count);
    count = add_lexeme(lexemes, RIGHT_PAREN, count);
    count = add_lexeme(lexemes, EXPON_OP, count);
    count = add_lexeme(lexemes, ASSIGN_OP, count);
    count = add_lexeme(lexemes, LESS_THAN_OP, count);
    count = add_lexeme(lexemes, LESS_THAN_OR_EQUAL_OP, count);
    count = add_lexeme(lexemes, GREATER_THEN_OP, count);
    count = add_lexeme(lexemes, GREATER_THEN_OR_EQUAL_OP, count);
    count = add_lexeme(lexemes, EQUALS_OP, count);
    count = add_lexeme(lexemes, NOT_OP, count);
    count = add_lexeme(lexemes, NOT_EQUALS_OP, count);
    count = add_lexeme(lexemes, SEMI_COLON, count);
    //count = add_lexeme(lexemes, INT_LITERAL, count);
    return count;
}

/**
 * This function puts two chars together
 * @param original char to be combined with
 * @param other string to go into original
 */
void concatenate_two_char(char *original, const char *other){
    while(*original) {
        original++;
    }
    original++;
    *original = *other;
    original++;
    *original = '\0';
}

int check_if_lexeme(char character, lexeme lexemes[], char tokens[], int count){
    //1 will be true
    //-1 will be false
    int i = 0;
    while(i < count){
        if (character == '=')
        i++;
    }
}

int check_if_INT_LITERAL(char character){
    //1 will be true
    //-1 will be false
    if (character == '0' || character == '1' || character == '2' ||
    character == '3' || character == '4' || character == '5' || character == '6' ||
    character == '7' || character == '8' || character == '9'){
        return 1;
    }
    return -1;
}

void clear_token_array(char tokens[], int count){
    int i = 0;
    while(i < count){
        tokens[i] = '\0';
        i++;
    }
}

void write_output(char tokens[]){

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
void get_token(char *token_ptr){
    // Add code here.
    //printf("%s", line);
    while (line[0] != '\0') {
        if (line[0] != ' ' && line[0] != '\n') {
            *token_ptr = line[0];
            if (line[0] == ';'){
                token_ptr++;
                *token_ptr = '\0';
            }else{
                token_ptr++;
            }
        }
        line++;
    }
}

/**
* add comment
*/
int main(int argc, char* argv[]) {
    //printf("%x", argc);
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
    //printf("%s", argv[1]);
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
    lexeme lexemes[TSIZE];
    count = initialize_lexemes(lexemes);

    while (fgets(input_line, LINE, in_file) != NULL){
        // Sets a global pointer to the memory location
        // where the input line resides.
        line = input_line;

        // Add code here.
        while(line[0] != '\0') {
            get_token(token);
            //write to file
        }
        clear_token_array(token, count);
    }

    fclose(in_file);
    fclose(out_file);
    return 0;
}