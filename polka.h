#ifndef POLKA_H
#define POLKA_H
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void add_space_back(char* str);
void add_sing(char* stack, char* queu, char input_i, char F);
double readd(char* input);
int bracked(char* stack, char* queu);
char what_is_funck(char* str2, char* str3, char* str4);
void add_funck(char rez, char* queu);
void priority(char INPUT, char STACK, int* priority_input, int* priority_stack,
              int* flag);
double calc(char* str);
char valid(char* input);
double rr(double* r);
int validationStr(char* str);
int is_signMath(char ch);
int is_simbolMath(char ch);
int transformationsMathFunc(char* str);
int preRead(char* input, double* ress);
int is_digit(char ch);
#endif  // POLKA_H
