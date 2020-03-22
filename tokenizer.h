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
}lexeme;

/* Function prototype headers */
void get_token(char *);
int initialize_lexemes(lexeme lexemes[]);
int add_lexeme(lexeme lexemes[], lexeme lexeme, int);
int write_output(const char tokens[], FILE *output, int , int *, int, int);
void read_file(const char tokens[], FILE *output, int);
void clear_token_array(char tokens[], int);