#ifndef INCLUDE_STACK
#define INCLUDE_STACK

#include <complex.h>
#define STACK_SIZE 100

struct stack_c{
  int n;
  char data[STACK_SIZE];
};

struct stack_d{
  int n;
  double data[STACK_SIZE];
};

struct stack_cmp{
  int n;
  double complex data[STACK_SIZE];
};


typedef struct stack_c stack_rpn;

typedef struct stack_d stack_calc;
typedef struct stack_cmp stack_ccalc;

int rpn_push(stack_rpn *stk, char push_data){
  if(stk->n >= STACK_SIZE) return -1;
  stk->data[stk->n] = push_data;
  stk->n++;
  return 0;
}

int rpn_pop(stack_rpn *stk, char *pop_data){
  if(stk->n < 1) return -1;
  stk->n--;
  *pop_data = stk->data[stk->n];
  return 0;
}

char rpn_top(stack_rpn *stk){
  if(stk->n < 1) return -1;
  return stk->data[stk->n-1];
}

static void rpn_print(stack_rpn *stk){
  int i;

  printf("stack : [");
  for(i = 0; i < stk->n; i++){
    printf("%c ",stk->data[i]);
  }
  printf("]\n");
}

static void rpn_init(stack_rpn *stk){
  stk->n = 0;
}

int calc_push(stack_calc *stk, double push_data){
  if(stk->n >= STACK_SIZE) return -1;
  stk->data[stk->n] = push_data;
  stk->n++;
  return 0;
}

int ccalc_push(stack_ccalc *stk, double complex push_data){
  if(stk->n >= STACK_SIZE) return -1;
  stk->data[stk->n] = push_data;
  stk->n++;
  return 0;
}

int calc_pop(stack_calc *stk, double *pop_data){
  if(stk->n < 1) return -1;
  stk->n--;
  *pop_data = stk->data[stk->n];
  return 0;
}

int ccalc_pop(stack_ccalc *stk, double complex *pop_data){
  if(stk->n < 1) return -1;
  stk->n--;
  *pop_data = stk->data[stk->n];
  return 0;
}

static void calc_print(stack_calc *stk){
  int i;

  printf("stack : [");
  for(i = 0; i < stk->n; i++){
    printf("%lf ",stk->data[i]);
  }
  printf("]\n");
}
#endif
