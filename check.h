#ifndef INCLUDE_CHECK
#define INCLUDE_CHECK

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check(char *str){
  printf("\n\n check started: %s\n",str);
  int len,i=0,err=0,k;
  len = strlen(str);
  while(str[i] != '\0'){
    switch(str[i]){
    case '0':
      if(k == 3){
	err = 2;
      }
      k = 0;
      break;
    case '1':
      if(k == 3){
	err = 2;
      }
      k = 0;
      break;
    case '2':
      if(k == 3){
	err = 2;
      }
      k = 0;
      break;
    case '3':
      if(k == 3){
	err = 2;
      }
      k = 0;
      break;
    case '4':
      if(k == 3){
	err = 2;
      }
      k = 0;
      break;
    case '5':
      if(k == 3){
	err = 2;
      }
      k = 0;
      break;
    case '6':
      if(k == 3){
	err = 2;
      }
      k = 0;
      break;
    case '7':
      if(k == 3){
	err = 2;
      }
      k = 0;
      break;
    case '8':
      if(k == 3){
	err = 2;
      }
      k = 0;
      break;
    case '9':
      if(k == 3){
	err = 2;
      }
      k = 0;
      break;
    case '^':
      if(k == 1){
	err = 2;
      }
      k = 1;
      break;
    case '*':
      if(k == 1){
	err = 2;
      }
      k = 1;
      break;
    case '/':
      if(k == 1){
	err = 2;
      }
      k = 1;
      break;
    case '+':
      if(k == 1){
	err = 2;
      }
      k = 1;
      break;
    case '-':
      if(k == 1){
	err = 2;
      }
      k = 1;
      break;
    case '(':
      if(k == 0 && i != 0){
	err = 3;
      }
      k = 2;
      break;
    case ')':
      k = 3;
      break;
    case '\n':
      break;
    default:
      err = 1;
    }
    i++;
  }
  if(str[0] == '('){
    for(i=len-1; i>=0; i--){
      str[i+1] = str[i];
    }
    str[0] = '+';
    len++;
  }
  if(str[0] == '-' || str[0] == '+'){
    for(i=len-1; i >=0; i--){
      str[i+1] = str[i];
    }
    str[0] = '0';
  }
  //  printf("str = %s\n",str);

  return err;
}

#endif
