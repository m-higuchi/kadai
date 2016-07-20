#include <stdio.h>
#include <stdlib.h>
#include <complex.h>

#include "define.h"
#include "converter.h"
#include "pre_converter.h"
#include "calc.h"
#include "check.h"

int main(void){
  char buf[256],s1[256],s2[256],err;
  double complex ans=0+0i;
  fgets(buf,sizeof(buf),stdin);

  err = check(buf);
  if(err != 0){
    printf("input error(%d)\n",err);
    exit(-1);
  }

  pre_converter(buf,s1);
  
  converter(s1,s2);
  //printf("reverse polish notation : %s\n",s2);
  ans = calc(s2);
  if(cimag(ans) == 0){
    printf("= %f\n",creal(ans));
  }else if(creal(ans) == 0){
    printf("= %fi\n",cimag(ans));
  }else{
    printf("= %f%+fi\n",creal(ans),cimag(ans));
  }
  return 0;
}

