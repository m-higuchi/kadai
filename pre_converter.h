#ifndef PRE_CONVERTER
#define PRE_CONVERTER

#include <string.h>
#include "define.h"

int pre_converter(char *s1,char *s2){
  int i=0,j=0,flag=0;
  char tmp[256];
  printf("pre_converter started: %s\n",s1);
  while(1){
    if(s1[i] == '\0'){
      flag = 1;
    }
    if(s1[i] == 's' && s1[i+1] == 'i' && s1[i+2] == 'n'){
      s2[j] = s1[i];
      j++;
      i = i + 3;
    }else if(s1[i] == 'c' && s1[i+1] == 'o' && s1[i+2] == 's'){
      s2[j] = s1[i];
      j++;
      i = i+3;
    }else if(s1[i] == 't' && s1[i+1] == 'a' && s1[i+2] == 'n'){
      s2[j] = s1[i];
      j++;
      i = i+3;
    }else if(s1[i] == 'e' && s1[i+1] == 'x' && s1[i+2] == 'p'){
      s2[j] = s1[i];
      j++;
      i = i+3;
    }else if(s1[i] == 'l' && s1[i+1] == 'n'){
      s2[j] = s1[i];
      j++;
      i = i+2;
    }else{
      s2[j] = s1[i];
      j++;
      i++;
    }
    if(flag == 1){
      break;
    }
  }

  printf("pre_converter finished: %s\n",s2);
  return 0;
}
#endif