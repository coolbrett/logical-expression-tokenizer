/**
 * Header file for the tokenizer project
 * @author Brett Dale
 * @author Julia Januchowski
 * @version 1.0 (3/2/2020)
 */
/* Constants */
#define LINE 100
#define TSIZE 20
#define LEXEME_NAME 25
#define LEXEME_SYMBOL 10
#define LEXEME_PREFIX 3
#define TRUE 1
#define FALSE 0

typedef struct {
    char name[LEXEME_NAME];
    char symbol[LEXEME_SYMBOL];
    char prefix[LEXEME_PREFIX];
}Lexeme;

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
void get_token(char *);

/**
 * This function eliminates all whitespace leading and/or trailing the string passed
 * @param string string to be trimmed
 */
void trim(char *string);

/**
 * This function creates all lexemes along with their values and prefixes
 * and places them into the array passed in
 * @param lexemes array to hold created lexemes
 */
void initialize_lexemes(Lexeme lexemes[]);

/**
 * This function adds a lexeme to the lexemes array passed in,
 * then returns the index where it was added
 * @param lexemes array to add lexeme
 * @param lexeme lexeme to be added
 * @param count index of last added lexeme
 * @return index of last added lexeme
 */
int add(Lexeme lexemes[], Lexeme lexeme, int count);