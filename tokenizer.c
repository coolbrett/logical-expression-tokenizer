/**
 * tokenizer.c - A simple token recognizer.
 *
 * NOTE: The terms 'token' and 'lexeme' are used interchangeably in this
 *       program.
 *
 * @author Your Name
 * @version current date
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tokenizer.h"

// global variables
char *line;             // Global pointer to line of input

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

    while (fgets(input_line, LINE, in_file) != NULL)
    {
        line = input_line;  // Sets a global pointer to the memory location
        // where the input line resides.

        // Add code here.

    }

    fclose(in_file);
    fclose(out_file);
    return 0;
}

/**
* add javadoc-like comment
*/
void get_token(char *token_ptr)
{
    // Add code here.
}