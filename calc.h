#ifndef INCLUDE_CALC
#define INCLUDE_CALC
#include <math.h>
#include "stack.h"

double calc(char *str){
  stack_calc stk={0};
  int i=0,j=0;
  double ans=0,tmp,z=0;
  //printf("str = %s\n",str);
  while(str[i] != '\0'){
    if(str[i] >= '0' && str[i] <= '9'){
      j = 0;
      while(str[i] != ' '){
	//	printf("%c",str[i]);
	if(str[i] == '.'){
	  j = -1;
	  i++;
	}
	if(j == 0){
	  z = (str[i] - 48)+z*10;
	  i++;
	}else{
	  z = z + (str[i]-48)*pow(10,j);
	  i++;
	  j--;
	}
      }
      calc_push(&stk,z);
      z = 0;
    }else if(str[i] == 's'){
      calc_pop(&stk,&tmp);
      ans = sin(tmp);
      calc_push(&stk,ans);
      i++;
    }else if(str[i] == 'c'){
      calc_pop(&stk,&tmp);
      ans = cos(tmp);
      calc_push(&stk,ans);
      i++;
    }else if(str[i] == 't'){
      calc_pop(&stk,&tmp);
      ans = tan(tmp);
      calc_push(&stk,ans);
      i++;
    }else if(str[i] == 'e'){
      calc_pop(&stk,&tmp);
      ans = exp(tmp);
      calc_push(&stk,ans);
      i++;
    }else if(str[i] == 'l'){
      calc_pop(&stk,&tmp);
      ans = log(tmp);
      calc_push(&stk,ans);
      i++;
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
  calc_pop(&stk,&ans);
  return ans;  
}

#endif
