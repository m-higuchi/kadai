#ifndef PRE_CONVERTER
#define PRE_CONVERTER

#include <string.h>
#include "define.h"
//"sin" => "s"
//"cos" => "c"
//"tan" => "t"
//"asin" => "n"
//"acos" => "o"
//"atan" => "u"
//"exp" => "e"
//"ln" => "l"
//"sqrt" => "q"
//"abs" => "b"
//"arg" => "g"
//"real" => "r"
//"imag" => "i"
//"%i" => "I"
//"%pi" => "P"
int pre_converter(char *s1,char *s2){
  int i=0,j=0,flag=0;
  char tmp[256];

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
    }else if(s1[i] == 's' && s1[i+1] == 'q' && s1[i+2] == 'r' && s1[i+3] == 't'){
      s2[j] = 'q';
      j++;
      i = i+4;
    }else if(s1[i] == 'a' && s1[i+1] == 'c' && s1[i+2] == 'o' && s1[i+3] == 's'){
      s2[j] = 'o';
      j++;
      i = i+4;
    }else if(s1[i] == 'a' && s1[i+1] == 's' && s1[i+2] == 'i' && s1[i+3] == 'n'){
      s2[j] = 'n';
      j++;
      i = i+4;
    }else if(s1[i] == 'a' && s1[i+1] == 't' && s1[i+2] == 'a' && s1[i+3] == 'n'){
      s2[j] = 'u';
      j++;
      i = i+4;
    }else if(s1[i] == 'a' && s1[i+1] == 'r' && s1[i+2] == 'g'){
      s2[j] = 'g';
      j++;
      i = i+3;
    }else if(s1[i] == 'a' && s1[i+1] == 'b' && s1[i+2] == 's'){
      s2[j] = 'b';
      j++;
      i = i+3;
    }else if(s1[i] == 'r' && s1[i+1] == 'e' && s1[i+2] == 'a' && s1[i+3] == 'l'){
      s2[j] = 'r';
      j++;
      i = i+4;
    }else if(s1[i] == 'i' && s1[i+1] == 'm' && s1[i+2] == 'a' && s1[i+3] == 'g'){
      s2[j] = 'i';
      j++;
      i = i+4;
    }else if(s1[i] == 'c' && s1[i+1] == 'o' && s1[i+2] == 'n' && s1[i+3] == 'j'){
      s2[j] = 'j';
      j++;
      i = i+4;
    }else if(s1[i] == '%' && s1[i+1] == 'i'){
      s2[j] = 'I';
      j++;
      i = i+2;
    }else if(s1[i] == '%' && s1[i+1] == 'p' && s1[i+2] == 'i'){
      s2[j] = 'P';
      j++;
      i = i+3;
    }else{
      s2[j] = s1[i];
      j++;
      i++;
    }
    if(flag == 1){
      break;
    }
  }
  return 0;
}
#endif
