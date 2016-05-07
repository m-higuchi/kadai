#ifndef INCLUDE_CHECK
#define INCLUDE_CHECK

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check(char *str){
  printf("check started: %s\n",str);
  int len,i=0,err=0,k,a=0;
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
      if(k == 1 || k == 2 || k == 4){
	err = 2;
      }
      k = 1;
      break;
    case '*':
      if(k == 1 || k == 2 || k == 4){
	err = 2;
      }
      k = 1;
      break;
    case '/':
      if(k == 1 || k == 2 || k == 4){
	err = 2;
      }
      k = 1;
      break;
    case '+':
      if(k == 1 || k == 2 || k == 4){
	err = 2;
      }
      k = 1;
      break;
    case '-':
      if(k == 1 || k == 2 || k == 4){
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
      if(k == 1 || k == 4){
	printf("k = %d\n",k);
	err = 6;
      }
      k = 3;
      break;
    case 's':
      if(str[i+1] != 'i' || str[i+2] != 'n'){
	err = 4;
      }
      if((k == 0 || k == 3 || k == 4) && i != 0){
	err = 5;
      }
      k = 4;
      i = i+2;
      break;
    case 'c':
      if(str[i+1] != 'o' || str[i+2] != 's'){
	err = 4;
      }
      if((k == 0 || k == 3 || k == 4) && i != 0){
	err = 5;
      }
      k = 4;
      i = i+2;
      break;
    case 't':
      if(str[i+1] != 'a' || str[i+2] != 'n'){
	err = 4;
      }
      if((k == 0 || k == 3 || k == 4) && i != 0){
	err = 5;
      }
      k = 4;
      i = i+2;
      break;
    case 'e':
      if(str[i+1] != 'x' || str[i+2] != 'p'){
	err = 4;
      }
      if((k == 0 || k == 3 || k == 4) && i != 0){
	err = 5;
      }
      k = 4;
      i = i+2;
      break;
    case 'l':
      if(str[i+1] != 'n'){
	err = 4;
      }
      if((k == 0 || k == 3 || k == 4) && i != 0){
	err = 5;
      }
      k = 4;
      i = i+1;
      break;
    case '\n':
      if(k == 1 || k == 2 || k == 4){
	err = 8;
      }
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
  while(str[i] != '\0'){
    if(str[i] == '('){
      a++;
    }else if(str[i] == ')'){
      a--;
    }
    if(a < 0){
      break;
    }
  }
  if(a != 0){
    err = 7;
  }
  //  printf("str = %s\n",str);

  return err;
}

#endif
