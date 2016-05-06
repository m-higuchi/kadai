#ifndef INCLUDE_CALC
#define INCLUDE_CALC
#include <math.h>
#include "stack.h"

double calc(char *str){
  stack_calc stk={0};
  int i=0,j;
  double ans=0,tmp,z=0;
  while(str[i] != '\0'){
    if(str[i] >= '0' && str[i] <= '9'){
      j = 0;
      while(str[i] != ' '){
	z = (str[i] - 48)+z*j*10;
	i++;
	j++;
      }
      calc_push(&stk,z);
    }else if(str[i] == '^'){
      calc_pop(&stk,&tmp);
      ans = tmp;
      calc_pop(&stk,&tmp);
      ans = pow(tmp,ans);
      calc_push(&stk,ans);
      i++;
    }else if(str[i] == '*'){
      calc_pop(&stk,&tmp);
      ans = tmp;
      calc_pop(&stk,&tmp);
      ans = ans * tmp;
      calc_push(&stk,ans);
      i++;
    }else if(str[i] == '/'){
      calc_pop(&stk,&tmp);
      ans = tmp;
      calc_pop(&stk,&tmp);
      ans = tmp / ans;
      calc_push(&stk,ans);
      i++;
    }else if(str[i] == '+'){
      calc_pop(&stk,&tmp);
      ans = tmp;
      calc_pop(&stk,&tmp);
      ans = ans + tmp;
      calc_push(&stk,ans);
      i++;
    }else if(str[i] == '-'){
      calc_pop(&stk,&tmp);
      ans = tmp;
      calc_pop(&stk,&tmp);
      ans = tmp - ans;
      calc_push(&stk,ans);
      i++;
    }
    i++;
  }
  return ans;  
}

#endif