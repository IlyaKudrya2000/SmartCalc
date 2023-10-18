#include "polka.h"

int preRead(char* input, double* ress) {
  int flag = 0;
  char* message = calloc(500, sizeof(char));
  char* tmp = calloc(500, sizeof(char));
  if (input[0] == '+' || input[0] == '-') {
    for (int i = 0; input[i] != '\0'; i++) {
      tmp[i + 1] = input[i];
    }
    tmp[0] = '0';

  } else {
    strcpy(tmp, input);
  }
  strcpy(input, tmp);
  strcpy(message, input);
  for (int i = 0, k = 0; input[i] != '\0'; i++) {
    if (input[i] == '(' && (input[i + 1] == '+' || input[i + 1] == '-')) {
      message[i + 1 + k] = '0';
      for (int j = i; j < 500 - i - 1; j++) {
        message[j + 2 + k] = input[j + 1];
      }
      k++;
    }
  }
  strcpy(input, message);
  flag = validationStr(input);
  if (flag == 0) {
    *ress = readd(message);
  }

  free(message);

  return flag;
}

double readd(char* input) {

  unsigned long size = 255;
  char* stack = calloc(size + 1, sizeof(char));
  char* queu = calloc(size + 1, sizeof(char));
  double rez = 0;
  char F = 0;
  F = valid(input);
  for (unsigned long i = 0; i < strlen(input); i++) {
    if ((input[i] <= 57 && input[i] >= 48) || input[i] == 46) {
      queu[strlen(queu)] = input[i];
      queu[strlen(queu) + 1] = '\0';
    } else {
      if (queu[strlen(queu)] != ' ') {
        queu[strlen(queu)] = ' ';
      }

      add_sing(stack, queu, input[i], F);
    }
  }
  strcat(queu, stack);
  free(stack);
  rez = calc(queu);
  free(queu);
  return rez;
}
// распределение по стеку и очереди всего кроме цифр
void add_sing(char* stack, char* queu, char input_i, char F) {

  char* tmp = calloc(256, sizeof(char));
  int flag = 0;
  int priority_input = 0;
  int priority_stack = 0;
  priority(input_i, stack[0], &priority_input, &priority_stack, &flag);

  if (F) {
    priority_input = 4;
  }
  if (flag == 2) {
    bracked(stack, queu);

  } else {
    if (stack[0] == '\0') {
      stack[strlen(stack)] = input_i;
      stack[strlen(stack) + 1] = '\0';  //  если стек пуст
    } else if (priority_input ==
               priority_stack) {  // если приоритет операций равен
      queu[strlen(queu)] = stack[0];
      queu[strlen(queu) + 1] = '\0';
      stack[0] = input_i;

    } else if (priority_stack <
               priority_input) {  // если приоитет  операции выше
      for (unsigned long k = 0; k < strlen(stack) + 1; k++) {
        tmp[k] = stack[k];
      }
      sprintf(stack, "%c", input_i);
      strcat(stack, tmp);

    } else if (priority_stack >
               priority_input) {  // если приоритет операции ниже
      queu[strlen(queu)] = stack[0];
      for (unsigned long j = 0; j < strlen(stack) + 1; j++) {
        stack[j] = stack[j + 1];
      }
      add_sing(stack, queu, input_i, F);
    }
  }
  free(tmp);
}
// вызывается после закрывшийся скобки, переносит элементы стека в очередь,
// удаляет из стека перенесённые элементы
int bracked(char* stack, char* queu) {
  int rez = 0;
  int size = strlen(stack);
  for (int j = 0; j < size;) {
    if (stack[j] == '(') {
      for (int i = 0; i < size; i++) {
        stack[i] = stack[i + 1];
      }
      rez = 1;
      break;
    } else {
      if (queu != NULL) {
        queu[strlen(queu)] = stack[0];
      }
      for (int i = 0; i < size; i++) {
        stack[i] = stack[i + 1];
      }
    }
  }
  return rez;
}
// на вход строка на выход цифровое обознацение фунции:
// l - ln
// c - cos
// s - sin
// t - tan
// g - log
// o - acos
// n - asin
// a - atan
// q - sqtr
// m - mod
// 0 - ничего из выше перечисленного
char what_is_funck(char* str2, char* str3, char* str4) {
  char rez = 0;
  if (strcmp(str2, "ln") == 0) {
    rez = 'L';
  } else if (strcmp(str3, "cos") == 0) {
    rez = 'c';
  } else if (strcmp(str3, "sin") == 0) {
    rez = 's';
  } else if (strcmp(str3, "tan") == 0) {
    rez = 't';
  } else if (strcmp(str3, "log") == 0) {
    rez = 'g';
  } else if (strcmp(str4, "acos") == 0) {
    rez = 'O';
  } else if (strcmp(str4, "asin") == 0) {
    rez = 'N';
  } else if (strcmp(str4, "atan") == 0) {
    rez = 'A';
  } else if (strcmp(str4, "sqrt") == 0) {
    rez = 'Q';
  } else if (strcmp(str3, "mod") == 0) {
    rez = 'M';
  }
  return rez;
}

void priority(char INPUT, char STACK, int* priority_input, int* priority_stack,
              int* flag) {
  *priority_input = (INPUT == '*' || INPUT == '/' || INPUT == 77) ? 2 : 1;
  *priority_stack = (STACK == '*' || STACK == '/' || INPUT == 77) ? 2 : 1;
  if (INPUT == '^') *priority_input = 3;
  if (STACK == '^') *priority_stack = 3;
  if (STACK == 76 || STACK == 99 || STACK == 115 || STACK == 116 ||
      STACK == 103 || STACK == 79 || STACK == 78 || STACK == 65 ||
      STACK == 81) {
    *priority_stack = 4;
    // *priority_input = 4;
  }
  if (INPUT == 76 || INPUT == 99 || INPUT == 115 || INPUT == 116 ||
      INPUT == 103 || INPUT == 79 || INPUT == 78 || INPUT == 65 ||
      INPUT == 81) {
    // *priority_stack = 4;
    *priority_input = 4;
  }
  if (INPUT == '(') {
    *flag = 1;
    *priority_input = 5;
    *priority_stack = 0;
  }

  if (INPUT == ')') *flag = 2;
  if (STACK == ')' || STACK == '(') *priority_stack = 0;
}
double calc(char* str) {
  double* stack = calloc(256, sizeof(double));
  double rez = 0;
  char* Queu = calloc(256, sizeof(char));
  char* tmp = calloc(256, sizeof(char));
  int j = 0;
  // int k = 0;
  for (unsigned long i = 0, k = 0; i < strlen(str); i++) {
    if ((str[i] <= 57 && str[i] >= 48) || str[i] == 46) {
      // ss
      if (str[i] == 46) {
        str[i] = ',';
      }
      tmp[k] = str[i];
      tmp[k + 1] = '\0';
      k++;
    } else if (tmp[0] != '\0') {
      stack[j] = atof(tmp);
      j++;
      sprintf(tmp, "%c", '\0');
      k = 0;
    }

    if (str[i] == '+') {
      stack[j - 2] = stack[j - 2] + stack[j - 1];
      j--;
    }
    if (str[i] == '-') {
      stack[j - 2] = stack[j - 2] - stack[j - 1];
      j--;
    }
    if (str[i] == '*') {
      stack[j - 2] = stack[j - 2] * stack[j - 1];
      j--;
    }
    if (str[i] == '/') {
      stack[j - 2] = stack[j - 2] / stack[j - 1];
      j--;
    }
    if (str[i] == '^') {
      stack[j - 2] = pow(stack[j - 2], stack[j - 1]);
      j--;
    }
    if (str[i] == 'L') {
      stack[j - 1] = log(stack[j - 1]);
    }
    if (str[i] == 'g') {
      stack[j - 1] = log10(stack[j - 1]);
    }
    if (str[i] == 'c') {
      stack[j - 1] = cos(stack[j - 1]);
    }
    if (str[i] == 's') {
      stack[j - 1] = sin(stack[j - 1]);
    }
    if (str[i] == 't') {
      stack[j - 1] = tan(stack[j - 1]);
    }
    if (str[i] == 'O') {
      stack[j - 1] = acos(stack[j - 1]);
    }
    if (str[i] == 'N') {
      stack[j - 1] = asin(stack[j - 1]);
    }
    if (str[i] == 'A') {
      stack[j - 1] = atan(stack[j - 1]);
    }
    if (str[i] == 'Q') {
      stack[j - 1] = sqrt(stack[j - 1]);
    }
    if (str[i] == 'M') {
      stack[j - 2] = fmod(stack[j - 2], stack[j - 1]);
      j--;
    }
  }
  free(Queu);
  free(tmp);
  rez = stack[0];
  free(stack);
  return rez;
}
char valid(char* input) {
  char F = 0;
  char* tmp = calloc(255, sizeof(char));
  sprintf(tmp, "%c", ' ');

  for (unsigned long i = 0, j = 0; input[i] != '\0'; i++) {
    char* funck_two = calloc(3, sizeof(char));
    char* funck_three = calloc(4, sizeof(char));
    char* funck_four = calloc(5, sizeof(char));
    if (i < strlen(input) - 1)
      sprintf(funck_two, "%c%c", input[i], input[i + 1]);  // функция из 2х букв
    if (i < strlen(input) - 2)
      sprintf(funck_three, "%c%c%c", input[i], input[i + 1],
              input[i + 2]);  // функция из 3х букв
    if (i < strlen(input) - 3)
      sprintf(funck_four, "%c%c%c%c", input[i], input[i + 1], input[i + 2],
              input[i + 3]);  // функция из 4х букв
    F = what_is_funck(funck_two, funck_three, funck_four);
    free(funck_two);
    free(funck_three);
    free(funck_four);
    if (F == 76) {
      i = i + 1;
      tmp[j] = F;
      j++;
      continue;
    } else if (F == 99 || F == 115 || F == 116 || F == 103 || F == 77) {
      i = i + 2;
      tmp[j] = F;
      j++;
      continue;
    } else if (F) {
      i = i + 3;
      tmp[j] = F;
      j++;
      continue;
    }
    tmp[j] = input[i];
    j++;
  }
  strcpy(input, tmp);
  free(tmp);
  return F;
}

int validationStr(char* str) {
  int res = 0;
  int brecket = 0;
  int control_point = 0;
  int flag = transformationsMathFunc(str);
  for (int i = 0; str[i] != '\0' && !flag; i++) {
    if (i == 0 && ((is_signMath(str[i]) && str[i] != '-' && str[i] != '+') ||
                   str[i] == '.' || str[i] == ')')) {  //если начало строки
      flag++;
    } else if (str[i] == '(') {  //если (
      brecket++;
      if (str[i + 1] == ')') flag++;
    } else if (str[i] == ')') {  //если )
      brecket--;
      if (brecket < 0) flag++;
      if (control_point) control_point = 0;
    } else if (str[i] == '.') {  //если .
      if (control_point) flag++;
      if (is_digit(str[i - 1]) == 0 || is_digit(str[i + 1] == 0)) {
        flag++;
      } else {
        control_point++;
      }
    } else if (str[i] == 'x') {  //если х
      if (is_digit(str[i - 1]) || is_digit(str[i + 1]) ||
          is_simbolMath(str[i + 1])) {
        flag++;
      } else if (str[i - 1] == '.' || str[i + 1] == '.') {
        flag++;
      }
    } else if (is_signMath(str[i])) {  //если +-*/^m
      if (str[i] != '-' && str[i] != '+') {
        if (is_digit(str[i - 1]) == 0 && str[i - 1] != 'x' &&
            str[i - 1] != ')') {
          flag++;
        } else if (is_digit(str[i + 1]) == 0 && str[i + 1] != 'x' &&
                   str[i + 1] != '(' && is_simbolMath(str[i + 1]) == 0) {
          flag++;
        }
      } else {
        if (is_digit(str[i + 1]) == 0 && str[i + 1] != 'x' &&
            str[i + 1] != '(' && is_simbolMath(str[i + 1]) == 0) {
          flag++;
        }
      }
      if (control_point) control_point = 0;
    } else if (is_digit(str[i])) {  //если число
      if (str[i + 1] == '(' || str[i + 1] == 'x' || is_simbolMath(str[i + 1])) {
        flag++;
      } else if (str[i - 1] == ')' || str[i - 1] == 'x') {
        flag++;
      }
    } else if ((unsigned long)i ==
               (strlen(str) - 1)) {  //если последний элемент
      if (str[i] == '.' || str[i] == '(' || is_signMath(str[i])) flag++;
    }
  }
  if (flag || brecket) res = 1;
  return res;
}
int is_signMath(char ch) {
  int res = 0;
  if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' ||
      ch == 'm')
    res = 1;
  return res;
}
int is_simbolMath(char ch) {
  int res = 0;
  if (ch >= 97 && ch <= 105) res = 1;
  return res;
}
int is_digit(char ch) {
  int res = 0;
  if (ch >= 48 && ch <= 57) res = 1;
  return res;
}
int transformationsMathFunc(char* str) {
  int flag = 0;
  char* tmp_str = calloc(256, sizeof(char));
  char* tmp_str_pointer = tmp_str;
  int k = 0;
  for (int i = 0; str[i] != '\0'; i++) {
    if (str[i] == 'c' && str[i + 1] == 'o' && str[i + 2] == 's') {
      tmp_str[k++] = 'a';  // cos
      i += 2;
      if (str[i + 1] != '(') flag = 1;
    } else if (str[i] == 's' && str[i + 1] == 'i' && str[i + 2] == 'n') {
      tmp_str[k++] = 'b';  // sin
      i += 2;
      if (str[i + 1] != '(') flag = 1;
    } else if (str[i] == 's' && str[i + 1] == 'q' && str[i + 2] == 'r' &&
               str[i + 3] == 't') {
      tmp_str[k++] = 'g';  // sqrt
      i += 3;
      if (str[i + 1] != '(') flag = 1;
    } else if (str[i] == 'a' && str[i + 1] == 'c' && str[i + 2] == 'o' &&
               str[i + 3] == 's') {
      tmp_str[k++] = 'd';  // acos
      i += 3;
      if (str[i + 1] != '(') flag = 1;
    } else if (str[i] == 'a' && str[i + 1] == 's' && str[i + 2] == 'i' &&
               str[i + 3] == 'n') {
      tmp_str[k++] = 'e';  // asin
      i += 3;
      if (str[i + 1] != '(') flag = 1;
    } else if (str[i] == 'a' && str[i + 1] == 't' && str[i + 2] == 'a' &&
               str[i + 3] == 'n') {
      tmp_str[k++] = 'f';  // atan
      i += 3;
      if (str[i + 1] != '(') flag = 1;
    } else if (str[i] == 'l' && str[i + 1] == 'n') {
      tmp_str[k++] = 'h';  // ln
      i++;
      if (str[i + 1] != '(') flag = 1;
    } else if (str[i] == 'l' && str[i + 1] == 'o' && str[i + 2] == 'g') {
      tmp_str[k++] = 'i';  // log
      i += 2;
      if (str[i + 1] != '(') flag = 1;
    } else if (str[i] == 't' && str[i + 1] == 'a' && str[i + 2] == 'n') {
      tmp_str[k++] = 'c';  // tan
      i += 2;
      if (str[i + 1] != '(') flag = 1;
    } else if (str[i] == 'm' && str[i + 1] == 'o' && str[i + 2] == 'd') {
      tmp_str[k++] = 'm';  // mod
      i += 2;
    } else if ((str[i] == '-' || str[i] == '+') &&
               (i == 0 || str[i - 1] == '(')) {
      tmp_str[k++] = str[i];
      tmp_str[k++] = '1';
      tmp_str[k++] = '*';
    } else if (str[i] != ' ') {
      tmp_str[k++] = str[i];
    }
  }
  tmp_str[k] = '\0';
  memset(str, 0, strlen(str));
  strcpy(str, tmp_str);
  tmp_str = tmp_str_pointer;
  free(tmp_str);
  return flag;
}
