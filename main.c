#include <stdio.h>
#include <stdlib.h>

#include "define.h"
#include "converter.h"
#include "pre_converter.h"
#include "calc.h"
#include "check.h"

int main(void){
  char buf[256],s1[256],s2[256],err;
  double ans;
  fgets(buf,sizeof(buf),stdin);

  err = check(buf);
  if(err != 0){
    printf("input error(%d)\n",err);
    exit(-1);
  }

  pre_converter(buf,s1);
  //printf("%s\n",s1);
  
  converter(s1,s2);
  printf("reverse polish notation : %s\n",s2);
  ans = calc(s2);
  
  printf("================\nans. = %lf\n================\n",ans);

  return 0;
}

