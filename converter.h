#ifndef INCLUDE_CONVERTER
#define INCLUDE_CONVERTER
#include "define.h"
#include "stack.h"
//逆ポーランド記法に変換

int priority(char);

int converter(char *buf,char *s){

  stack_rpn stk = {0};
  
  int i=0,j=0,k,flag;
  char top;
  rpn_init(&stk);

  while(1){
    flag = 0;
    while(priority(buf[i]) == 0){
      if(flag == 1){
	j--;
      }
      s[j] = buf[i];
      j++;
      s[j] = ' ';
      j++;
      i++;
      flag = 1;
    }
    
    if(buf[i] == '('){
      rpn_push(&stk,buf[i]);
      i++;
    }else if(priority(buf[i]) <= 5 && priority(buf[i]) >= 1){
      while(rpn_pop(&stk,&top) != -1 && priority(buf[i]) >= priority(top)){
	if(buf[i] == ')' && top == '('){
	  break;
	}
	s[j] = top;
	j++;
	s[j] = ' ';
	j++;
      }

      if(top != '(' || buf[i] != ')'){
	rpn_push(&stk,top);
	if(buf[i] != ')'){
	  rpn_push(&stk,buf[i]);

	}
      }
      i++;
    }else{
      break;
    }
  }
  while(stk.n > 0){
    rpn_pop(&stk,&top);
    sprintf(s,"%s%c ",s,top);
  }
  return 0;
}

int priority(char c){
  if((c >= '0' && c <= '9') || c == '.' || c == 'I' || c == 'P'){
    return 0;
  }else if(c == 's' || c == 'c' || c == 't' || c == 'e' || c == 'l' || c == 'q' || c == 'o' || c == 'n' || c == 'u' || c == 'r' || c == 'i' || c == 'b' || c == 'g' || c == 'j'){
    return 1;
  }else if(c == '^'){
    return 2;
  }else if(c == '*' || c == '/'){
    return 3;
  }else if(c == '+' || c == '-'){
    return 4;
  }else if(c == '(' || c == ')'){
    return 5;
  }else{
    return 99;
  }
}
#endif
