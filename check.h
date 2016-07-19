#ifndef INCLUDE_CHECK
#define INCLUDE_CHECK

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//入力文字列が書式に合うか判定
// 0-9 => k=0
// ^*/+- => k=1
// ( => k=2
// ) => k=3
// scetl => k=4
// %i => k=5
int check(char *str){
  int len,i=0,err=0,k=-1,a=0,l=0;
  char buf[256];
  len = strlen(str);
  while(str[i] != '\0'){
    switch(str[i]){
    case '0':
      if(k == 3 || k == 5){
	err = 2;
      }
      k = 0;
      break;
    case '1':
      if(k == 3 || k == 5){
	err = 2;
      }
      k = 0;
      break;
    case '2':
      if(k == 3 || k == 5){
	err = 2;
      }
      k = 0;
      break;
    case '3':
      if(k == 3 || k == 5){
	err = 2;
      }
      k = 0;
      break;
    case '4':
      if(k == 3 || k == 5){
	err = 2;
      }
      k = 0;
      break;
    case '5':
      if(k == 3 || k == 5){
	err = 2;
      }
      k = 0;
      break;
    case '6':
      if(k == 3 || k == 5){
	err = 2;
      }
      k = 0;
      break;
    case '7':
      if(k == 3 || k == 5){
	err = 2;
      }
      k = 0;
      break;
    case '8':
      if(k == 3 || k == 5){
	err = 2;
      }
      k = 0;
      break;
    case '9':
      if(k == 3 || k == 5){
	err = 2;
      }
      k = 0;
      break;
    case '.':
      if(l == 1 || k == 3 || k == 5){
	err = 11;
      }
      l = 1;
      k = 6;
      break;
    case '^':
      if(k == 1 || k == 2 || k == 4){
	err = 3;
      }
      k = 1;
      break;
    case '*':
      if(k == 1 || k == 2 || k == 4){
	err = 3;
      }
      k = 1;
      l = 0;
      break;
    case '/':
      if(k == 1 || k == 2 || k == 4){
	err = 3;
      }
      k = 1;
      l = 0;
      break;
    case '+':
      if(k == 1 || k == 4){
	err = 3;
      }
      k = 1;
      l = 0;
      break;
    case '-':
      if(k == 1 || k == 4){
	err = 3;
      }
      k = 1;
      l = 0;
      break;
    case '(':
      if(k == 0 || k == 5 || k == 6){
	err = 4;
      }
      k = 2;
      break;
    case ')':
      if(k == 1 || k == 4 || k == 6){
	err = 7;
      }
      k = 3;
      break;
    case 's':
      if(str[i+1] == 'q' && str[i+2] == 'r' && str[i+3] == 't'){
	k = 4;
	i = i + 3;
	break;
      }
      if(str[i+1] != 'i' || str[i+2] != 'n'){
	err = 5;
      }
      if(k == 0 || k == 3 || k == 4 || k == 5 || k == 6){
	err = 6;
      }
      k = 4;
      i = i+2;
      break;
    case 'c':
      if(str[i+1] != 'o' || str[i+2] != 's'){
	err = 5;
      }
      if(((k == 0 || k == 3 || k == 4) && i != 0) || k == 5 || k == 6){
	err = 6;
      }
      k = 4;
      i = i+2;
      break;
    case 't':
      if(str[i+1] != 'a' || str[i+2] != 'n'){
	err = 5;
      }
      if(((k == 0 || k == 3 || k == 4) && i != 0) || k == 5 || k == 6){
	err = 6;
      }
      k = 4;
      i = i+2;
      break;
    case 'e':
      if(str[i+1] != 'x' || str[i+2] != 'p'){
	err = 5;
      }
      if(k == 0 || k == 3 || k == 4 || k == 5 || k == 6){
	err = 6;
      }
      k = 4;
      i = i+2;
      break;
    case 'l':
      if(str[i+1] != 'n'){
	err = 5;
      }
      if(k == 0 || k == 3 || k == 4 || k == 5 || k == 6){
	err = 6;
      }
      k = 4;
      i = i+1;
      break;
    case '%':
      if(str[i+1] != 'i'){
	err = 12;
      }
      if(k == 0 || k == 3 || k == 5){
	err = 13;
      }
      k = 5;
      i = i+1;
      break;
    case '\n':
      if(k == 1 || k == 2 || k == 4){
	err = 9;
      }
      break;
    default:
      err = 1;
    }
    i++;
  }

  //先頭が"("の場合は"0+("に置き換え
  if(str[0] == '('){
    for(i=len-1; i>=0; i--){
      str[i+1] = str[i];
    }
    str[0] = '+';
    len++;
  }

  //先頭が"-"または"+"の場合は"0-"または"0+"に置き換え 
  if(str[0] == '-' || str[0] == '+'){
    for(i=len-1; i >=0; i--){
      str[i+1] = str[i];
    }
    str[0] = '0';
  }

  //"(+..."や"(-...)を"(0+..."または"(0-..."に置き換え
  i = 0;
  while(str[i] != '\0'){
    if(str[i] == '(' && (str[i+1] == '+' || str[i+1] == '-')){
      strcpy(buf,str+i+1);
      str[i+1] = '0';
      str[i+2] = '\0';
      strcat(str,buf);
    }
    i++;
  }

  //先頭が"."の場合"0."に置き換え
  if(str[0] == '.'){
    for(i=len-1; i>=0; i--){
      str[i+1] = str[i];
    }
    str[0] = '0';
    len++;
  }
  
  //"."の直前が数字でない場合に"0"を補完
  i = 0;
  while(str[i] != '\0'){
    if(str[i] == '.' && (str[i-1] < 48 || str[i-1] > 57)){
      strcpy(buf,str+i);
      str[i] = '0';
      str[i+1] = '\0';
      strcat(str,buf);
    }
    i++;
  }
  
  //"("と")"の数
  i = 0;
  while(str[i] != '\0'){
    if(str[i] == '('){
      a++;
    }else if(str[i] == ')'){
      a--;
    }
    if(a < 0){
      break;
    }
    i++;
  }
  if(a != 0){
    err = 10;
  }
  //  printf("str = %s\n",str);

  return err;
}

#endif
