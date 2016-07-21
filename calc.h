#ifndef INCLUDE_CALC
#define INCLUDE_CALC
#include <math.h>
#include <complex.h>
#include "stack.h"

double complex calc(char *str){
  stack_ccalc stk = {0};
  int i=0,j=0;
  double real,imaginary;
  double complex z = 0+0i,tmp,ans=0+0i;

  while(str[i] != '\0'){
    if(str[i] >= '0' && str[i] <= '9'){
      j = 0;
      while(str[i] != ' '){
	if(str[i] == '.'){
	  j = -1;
	  i++;
	}
	if(j == 0){
	  __real__ z = (str[i] - 48)+creal(z)*10;
	  __imag__ z = 0;
	  i++;
	}else{
	  __real__ z = creal(z) + (str[i]-48)*pow(10,j);
	  __imag__ z = 0;
	  i++;
	  j--;
	}
      }
      ccalc_push(&stk,z);
      z = 0+0i;
    }else if(str[i] == 'I'){
      __real__ z = 0;
      __imag__ z = 1;
      ccalc_push(&stk,z);
      z = 0+0i;
    }else if(str[i] == 'P'){
      __real__ z = M_PI;
      __imag__ z = 0;
      ccalc_push(&stk,z);
      z = 0+0i;
    }else if(str[i] == 's'){
      ccalc_pop(&stk,&tmp);
      ans = csin(tmp);
      ccalc_push(&stk,ans);
      i++;
    }else if(str[i] == 'c'){
      ccalc_pop(&stk,&tmp);
      ans = ccos(tmp);
      ccalc_push(&stk,ans);
      i++;
    }else if(str[i] == 't'){
      ccalc_pop(&stk,&tmp);
      ans = ctan(tmp);
      ccalc_push(&stk,ans);
      i++;
    }else if(str[i] == 'e'){
      ccalc_pop(&stk,&tmp);
      ans = cexp(tmp);
      ccalc_push(&stk,ans);
      i++;
    }else if(str[i] == 'l'){
      ccalc_pop(&stk,&tmp);
      ans = clog(tmp);
      ccalc_push(&stk,ans);
      i++;
    }else if(str[i] == 'q'){
      ccalc_pop(&stk,&tmp);
      ans = csqrt(tmp);
      ccalc_push(&stk,ans);
      i++;
    }else if(str[i] == 'o'){
      ccalc_pop(&stk,&tmp);
      ans = -I*clog(tmp+I*csqrt(1-tmp*tmp));
      i++;
    }else if(str[i] == 'n'){
      ccalc_pop(&stk,&tmp);
      ans = -I*clog(csqrt(1-tmp*tmp)+I*tmp);
      i++;
    }else if(str[i] == 'u'){
      ccalc_pop(&stk,&tmp);
      ans = 0.5*I*clog((I+tmp)/(I-tmp));
      i++;
    }else if(str[i] == 'b'){
      ccalc_pop(&stk,&tmp);
      ans = cabs(tmp);
      i++;
    }else if(str[i] == 'r'){
      ccalc_pop(&stk,&tmp);
      ans = creal(tmp);
      printf("%lf,%lf\n",creal(ans),cimag(ans));
      i++;
    }else if(str[i] == 'i'){
      ccalc_pop(&stk,&tmp);
      ans = cimag(tmp);
      i++;
    }else if(str[i] == 'g'){
      ccalc_pop(&stk,&tmp);
      ans = carg(tmp);
      i++;
    }else if(str[i] == 'j'){
      ccalc_pop(&stk,&tmp);
      ans = conj(tmp);
      i++;
    }else if(str[i] == '^'){
      ccalc_pop(&stk,&tmp);
      ans = tmp;    
      ccalc_pop(&stk,&tmp);
      ans = cpow(tmp,ans);
      ccalc_push(&stk,ans);
      i++;
    }else if(str[i] == '*'){
      ccalc_pop(&stk,&tmp);
      ans = tmp;
      ccalc_pop(&stk,&tmp);
      ans = ans * tmp;
      ccalc_push(&stk,ans);
      i++;
    }else if(str[i] == '/'){
      ccalc_pop(&stk,&tmp);
      ans = tmp;
      if(creal(ans) == 0 && cimag(ans) == 0){
	printf("error\n");
	exit(-1);
      }
      ccalc_pop(&stk,&tmp);
      ans = tmp / ans;
      ccalc_push(&stk,ans);
      i++;
    }else if(str[i] == '+'){
      ccalc_pop(&stk,&tmp);
      ans = tmp;
      ccalc_pop(&stk,&tmp);
      ans = ans + tmp;
      ccalc_push(&stk,ans);
      i++;
    }else if(str[i] == '-'){
      ccalc_pop(&stk,&tmp);
      ans = tmp;
      ccalc_pop(&stk,&tmp);
      ans = tmp - ans;
      ccalc_push(&stk,ans);
      i++;
    }
    i++;
  }
  ccalc_pop(&stk,&ans);
  return ans;  
}

#endif
