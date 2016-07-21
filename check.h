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
// sin,cos,conj,tan,exp,ln,sqrt,arg,abs,acos,asin,atan,imag,real => k=4
// %i,%pi => k=5
// . => k=6
int check(char *str){
  int len,i=0,err=0,k=-1,a=0,l=0;
  char buf[256];
  len = strlen(str);
  while(str[i] != '\0'){
    if(str[i] >= '0' && str[i] <= '9'){
      if(k == 3 || k == 5){
	err = 1;
      }
      k = 0;
    }else if(str[i] == '.'){
      if(k == 3 || k == 5 || l == 1){
	err = 2;
      }
      l = 1;
      k = 6;
    }else if(str[i] == '^'){
      if(k == 1 || k == 2 || k == 4){
	err = 3;
      }
      k = 1;
      l = 0;
    }else if(str[i] == '*'){
      if(k == 1 || k == 2 || k == 4){
	err = 4;
      }
      k = 1;
      l = 0;
    }else if(str[i] == '/'){
      if(k == 1 || k == 2 || k == 4){
	err = 5;
      }
      k = 1;
      l = 0;
    }else if(str[i] == '+'){
      if(k == 1 || k == 4){
	err = 6;
      }
      k = 1;
      l = 0;
    }else if(str[i] == '-'){
      if(k == 1 || k == 4){
	err = 7;
      }
      k = 1;
      l = 0;
    }else if(str[i] == '('){
      if(k == 0 || k == 5 || k == 6){
	err = 8;
      }
      k = 2;
    }else if(str[i] == ')'){
      if(k == 1 || k == 4 || k == 6){
	err = 9;
      }
      k = 3;
    }else if(str[i] == 's' && str[i+1] == 'q' && str[i+2] == 'r' && str[i+3] == 't'){
      if(k == 0 || k == 3 || k == 4 || k == 5 || k == 6){
	err = 10;
      }
      k = 4;
      i = i + 3;
    }else if(str[i] == 's' && str[i+1] == 'i' && str[i+2] == 'n'){
      if(k == 0 || k == 3 || k == 4 || k == 5 || k == 6){
	err = 11;
      }
      k = 4;
      i = i+2;
    }else if(str[i] == 'c' && str[i+1] == 'o' && str[i+2] == 's'){
      if(k == 0 || k == 3 || k == 4 || k == 5 || k == 6){
	err = 12;
      }
      k = 4;
      i = i+2;
    }else if(str[i] == 'c' && str[i+1] == 'o' && str[i+2] == 'n' && str[i+3] == 'j'){
      if(k == 0 || k == 3 || k == 4 || k == 5 || k == 6){
	err = 13;
      }
      k = 4;
      i = i+3;
    }else if(str[i] == 't' && str[i+1] == 'a' && str[i+2] == 'n'){
      if(k == 0 || k == 3 || k == 4 || k == 5 || k == 6){
	err = 14;
      }
      k = 4;
      i = i+2;
    }else if(str[i] == 'e' && str[i+1] == 'x' && str[i+2] == 'p'){
      if(k == 0 || k == 3 || k == 4 || k == 5 || k == 6){
	err = 15;
      }
      k = 4;
      i = i+2;
    }else if(str[i] == 'l' && str[i+1] == 'n'){
      if(k == 0 || k == 3 || k == 4 || k == 5 || k == 6){
	err = 16;
      }
      k = 4;
      i = i+1;
    }else if(str[i] == 'a' && str[i+1] == 'c' && str[i+2] == 'o' && str[i+3] == 's'){
      if(k == 0 || k == 3 || k == 4 || k == 5 || k == 6){
	err = 17;
      }
      k = 4;
      i = i+3;
    }else if(str[i] == 'a' && str[i+1] == 's' && str[i+2] == 'i' && str[i+3] == 'n'){
      if(k == 0 || k == 3 || k == 4 || k == 5 || k == 6){
	err = 18;
      }
      k = 4;
      i = i+3;
    }else if(str[i] == 'a' && str[i+1] == 't' && str[i+2] == 'a' && str[i+3] == 'n'){
      if(k == 0 || k == 3 || k == 4 || k == 5 || k == 6){
	err = 19;
      }
      k = 4;
      i = i+3;
    }else if(str[i] == 'a' && str[i+1] == 'r' && str[i+2] == 'g'){
      if(k == 0 || k == 3 || k == 4 || k == 5 || k == 6){
	err = 20;
      }
      k = 4;
      i = i+2;
    }else if(str[i] == 'a' && str[i+1] == 'b' && str[i+2] == 's'){
      if(k == 0 || k == 3 || k == 4 || k == 5 || k == 6){
	err = 21;
      }
      k = 4;
      i = i+2;
    }else if(str[i] == 'i' && str[i+1] == 'm' && str[i+2] == 'a' && str[i+3] == 'g'){
      if(k == 0 || k == 3 || k == 4 || k == 5 || k == 6){
	err = 22;
      }
      k = 4;
      i = i+3;
    }else if(str[i] == 'r' && str[i+1] == 'e' && str[i+2] == 'a' && str[i+3] == 'l'){
      if(k == 0 || k == 3 || k == 4 || k == 5 || k == 6){
	err = 23;
      }
      k = 4;
      i = i+3;
    }else if(str[i] == '%' && str[i+1] == 'i'){
      if(k == 0 || k == 3 || k == 5){
	err = 24;
      }
      k = 5;
      i = i+1;
    }else if(str[i] == '%' && str[i+1] == 'p' && str[i+2] == 'i'){
      if(k == 0 || k == 3 || k == 5){
	err = 25;
      }
      k = 5;
      i = i+2;
    }else if(str[i] == '\n'){
      if(k == 1 || k == 2 || k == 4){
	err = 26;
      }
    }else{
      err = 27;
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

  return err;
}

#endif
