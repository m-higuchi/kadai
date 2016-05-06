#include <stdio.h>
#include <stdlib.h>

#include "define.h"
#include "converter.h"
#include "calc.h"
#include "check.h"

int main(void){
  char buf[256],s[256];
  double ans;
  fgets(buf,sizeof(buf),stdin);

  if(check(buf) != 0){
    printf("input error\n");
    exit(-1);
  }
  converter(buf,s);

  printf("reverse polish notation : %s\n",s);
  ans = calc(s);
  printf("ans = %lf\n",ans);

  return 0;
}
