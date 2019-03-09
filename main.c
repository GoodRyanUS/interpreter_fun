#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int INPUT_SIZE = 10;

struct Token{
  char type[10]; 
  char value[4];
}; 

void remove_spaces(char *original, char *cleaned_code);
void tokenize(char *code);
void addition();
void subtraction();
void multiplication();

struct Token code_tokens[3];

int main(int argc, char **argv){
  int result = 0;
  while(1){
    char code[INPUT_SIZE];
    char cleaned_code[INPUT_SIZE];
    printf("> "); fgets(code, 11, stdin); //supports up to 2, 3 digit operators
    remove_spaces(code, cleaned_code);
    tokenize(cleaned_code);
    if (strcmp(code_tokens[1].type, "PLUS") == 0){
      addition();
    }else if (strcmp(code_tokens[1].type, "MINUS") == 0){
      subtraction();
    }else if (strcmp(code_tokens[1].type, "MULT") == 0){
      multiplication();
    }
  }

  return 0;
}

void remove_spaces(char *original, char *cleaned_code){

  int i = 0;
  while(*original != '\0'){
    if(*original != ' ' && *original != '\n'){
      cleaned_code[i] = *original;
      i++;
    }
    original++;
  }
  cleaned_code[i] = '\0';
}


void addition(){
  int val1;
  int val2;
  char *garbage;
  val1 = strtol(code_tokens[0].value, &garbage, 10);
  val2 = strtol(code_tokens[2].value, &garbage, 10);
  printf("%d\n", val1+val2);
}

void subtraction(){
  int val1;
  int val2;
  char *garbage;
  val1 = strtol(code_tokens[0].value, &garbage, 10);
  val2 = strtol(code_tokens[2].value, &garbage, 10);
  int result = val1 - val2;
  printf("%d\n", result);
}

void multiplication(){
  int val1;
  int val2;
  char *garbage;
  val1 = strtol(code_tokens[0].value, &garbage, 10);
  val2 = strtol(code_tokens[2].value, &garbage, 10);
  int result = val1 * val2;
  printf("%d\n", result);
}

/**
Turn input into tokens
**/
void tokenize(char *code){
  int token_pos = 0; //determines which token is affected
  int value;
  char strvalue[4];
  while (*code != '\0'){
    if isdigit(*code){//if digit found, pull out entire number
      value = strtol(code, &code, 10); 
      strcpy(code_tokens[token_pos].type, "INTEGER");
      sprintf(strvalue, "%d", value);
      strcpy(code_tokens[token_pos].value, strvalue);
    }else if(*code == '+'){
      strcpy(code_tokens[token_pos].type, "PLUS");
      strcpy(code_tokens[token_pos].value, "+");
      code++;
    }else if(*code == '-'){
      strcpy(code_tokens[token_pos].type, "MINUS");
      strcpy(code_tokens[token_pos].value, "-");
      code++;
    }else if(*code == '*'){
      strcpy(code_tokens[token_pos].type, "MULT");
      strcpy(code_tokens[token_pos].value, "x");
      code++;
    }else{
      fprintf(stderr, "Incorrect input on char: '%c'\n", *code); 
      exit(EXIT_FAILURE);
    }
    
    token_pos++;
  }
}

