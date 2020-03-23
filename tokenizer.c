/**
 * tokenizer.c - A simple token recognizer.
 *
 * NOTE: The terms 'token' and 'lexeme' are used interchangeably in this
 *       program.
 *
 * @author Brett Dale
 * @author Julia Januchowski
 * @version 1.0 (3/22/2020)
 */

#include "tokenizer.h"

// global variables
char *line; // Global pointer to line of input

/**
 * Main function of the tokenizer program file. takes user input and either gives error messages if input is incorrect
 * or if correct information supplied then it calls the remaining helper functions to read through the file and output
 * the found tokens into the output file.
 * @param argc the number of command line arguments.
 * @param argv the command line arguments
 * @return returns the number 0 if the function completes.
 */
int main(int argc, char* argv[]) {
    char  token[TSIZE];         /* Spot to hold a token, fixed size */
    char  input_line[LINE];     /* Line of input, fixed size        */
    FILE  *in_file = NULL;      /* File pointer                     */
    FILE  *out_file = NULL;     /* File pointer                     */
    int   line_count,           /* Number of lines read             */
    start,                  /* start of new statement           */
    count;                  /* count of tokens                  */
    //If missing all arguments notifies user and gracefully exits
    if (argc != 3) {
        printf("Usage: tokenizer inputFile outputFile\n");
        exit(1);
    }
    in_file = fopen(argv[1], "r");
    //if input file can't be read the user is notified and program gracefully exits
    if (in_file == NULL) {
        fprintf(stderr, "ERROR: could not open %s for reading\n", argv[1]);
        exit(1);
    }
    //if output file can't be written into the user is notified and program gracefully exits
    out_file = fopen(argv[2], "w");
    if (out_file == NULL) {
        fprintf(stderr, "ERROR: could not open %s for writing\n", argv[2]);
        exit(1);
    }
    line_count = 1;  // variable that keeps track of the statements
    start = TRUE;  // variable that keeps track of whether the current lexeme is the start of a new line
    //counters for tokens and lexemes
    count = 0;
    int curr_lexeme = 0;
    // while loop that loops through each line of the input file then writes it to the output file.
    while (fgets(input_line, LINE, in_file) != NULL){
        clear_token_array(token, TSIZE);
        // Sets a global pointer to the memory location where the input line resides.
        line = input_line;
        // while the current lexeme is not a null character get the token and then write it to the file
        while(line[0] != '\0') {
            get_token(token);
            // write to file
            curr_lexeme = write_output(token, out_file, line_count, &start, count, curr_lexeme);
            // if the current token is the start of a new statement set the current counters to true.
            if(start == TRUE){
                count = 0;
                curr_lexeme = 0;
            } // end if
        } // end while
        // if you are at the start a new line add the dashed line and increment line count
        if(token[0] != '\0' && start == TRUE) {
            fprintf(out_file, "\n---------------------------------------------------------\n");
            line_count++;
        } // end if
    } // end while
    fclose(in_file);
    fclose(out_file);
    return 0;
} // end main

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
    while (line[0] != '\0') {
        //if statement that is used to get rid of spaces in a line
        if (!(isspace(line[0]))) {
            *token_ptr = line[0];
            //if statement that ends a line after reaching a semi colan. otherwise increment the pointer
            if (line[0] == ';'){
                token_ptr++;
                *token_ptr = '\0';
            }else{
                token_ptr++;
            } // end if/else
        } // end if
        line++;
    } // end while
} // end get_token

/**
 * this function prints the output to the the output file while also identifying the tokens of each lexeme
 * @param tokens an array that holds the current input file line
 * @param output output file
 * @param line_count the current line / statement count of the file
 * @param start "boolean" value that holds whether the current token is the start of the current statement
 * @param curr_token holds the number of the current index of the token array
 * @param curr_lexeme counter that holds the number of the current lexeme of a statement
 * @return returns the current lexeme number to be used later if the current lexeme is not the end of a statement
 */
int write_output(const char tokens[], FILE *output, int line_count, int *start, int curr_token, int curr_lexeme){
    //if the current token is the start of a new statement print the correct output
    if(tokens[0] != '\0' && *start == TRUE) {
        fprintf(output, "Statement #%d", line_count);
    } // end if
    // while loop that loops through the tokens until it reaches the null character and prints out the correct output
    while(tokens[curr_token] != '\0') {
        *start = FALSE; // sets the start value to false
        char temp = tokens[curr_token];
        char digits[TSIZE];
        int curr_digit = 0;
        //switch statement for each token case
        switch (temp) {
            case '=' :
                if (tokens[curr_token + 1] == '=') {
                    fprintf(output, "\nLexeme %d is ==", curr_lexeme);
                    curr_token = curr_token + 2;
                    curr_lexeme++;
                } else {
                    fprintf(output, "\nLexeme %d is =", curr_lexeme);
                    curr_token++;
                    curr_lexeme++;
                } // end if/else
                break;
            case '<':
                if (tokens[curr_token + 1] == '=') {
                    fprintf(output, "\nLexeme %d is <=", curr_lexeme);
                    curr_token = curr_token + 2;
                    curr_lexeme++;
                } else {
                    fprintf(output, "\nLexeme %d is <", curr_lexeme);
                    curr_token++;
                    curr_lexeme++;
                } // end if/else
                break;
            case '>':
                if (tokens[curr_token + 1] == '=') {
                    fprintf(output, "\nLexeme %d is >=", curr_lexeme);
                    curr_token = curr_token + 2;
                    curr_lexeme++;
                } else {
                    fprintf(output, "\nLexeme %d is >", curr_lexeme);
                    curr_token++;
                    curr_lexeme++;
                } // end if/else
                break;
            case '!':
                if (tokens[curr_token + 1] == '=') {
                    fprintf(output, "\nLexeme %d is !=", curr_lexeme);
                    curr_token = curr_token + 2;
                    curr_lexeme++;
                } else {
                    fprintf(output, "\nLexeme %d is !", curr_lexeme);
                    curr_token++;
                    curr_lexeme++;
                } // end if/else
                break;
            case '+':
                fprintf(output, "\nLexeme %d is +", curr_lexeme);
                curr_token++;
                curr_lexeme++;
                break;
            case '-':
                fprintf(output, "\nLexeme %d is -", curr_lexeme);
                curr_token++;
                curr_lexeme++;
                break;
            case '*':
                fprintf(output, "\nLexeme %d is *", curr_lexeme);
                curr_token++;
                curr_lexeme++;
                break;
            case '/':
                fprintf(output, "\nLexeme %d is /", curr_lexeme);
                curr_token++;
                curr_lexeme++;
                break;
            case '(':
                fprintf(output, "\nLexeme %d is (", curr_lexeme);
                curr_token++;
                curr_lexeme++;
                break;
            case ')':
                fprintf(output, "\nLexeme %d is )", curr_lexeme);
                curr_token++;
                curr_lexeme++;
                break;
            case '^':
                fprintf(output, "\nLexeme %d is ^", curr_lexeme);
                curr_token++;
                curr_lexeme++;
                break;
            case ';':
                fprintf(output, "\nLexeme %d is ;", curr_lexeme);
                curr_token++;
                *start = 1;
                curr_lexeme++;
                break;
            case '0' ... '9':
                // while loop that looks for additional digits
                while (isdigit(tokens[curr_token])){
                    digits[curr_digit] = tokens[curr_token];
                    curr_digit++;
                    curr_token++;
                } // end while
                fprintf(output, "\nLexeme %d is %s", curr_lexeme, digits);
                curr_lexeme++;
                break;
            default:
                fprintf(output,"\n===> '%c'", temp);
                fprintf(output,"\nLexical error: not a lexeme");
                curr_token++;
                break;
        } // end switch case
    } // end while
    return curr_lexeme;
} // end write_output

/**
 * clears the token array
 * @param tokens array that holds the current tokens in the array
 * @param count holds the number of tokens in the array
 */
void clear_token_array(char tokens[], int count){
    int i = 0;
    //loops through the token array
    while(i < count){
        tokens[i] = '\0';
        i++;
    } // end while
} // end clear_token_array