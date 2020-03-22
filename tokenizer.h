/**
 * Header file for the tokenizer project
 * @author Brett Dale
 * @author Julia Januchowski
 * @version 1.0 (3/2/2020)
 */
/* Constants */
#define LINE 100
#define TSIZE 20
#define TRUE 1
#define FALSE 0
/* Function prototype headers */
void get_token(char *);
int write_output(const char tokens[], FILE *output, int , int *, int, int);
void clear_token_array(char tokens[], int);