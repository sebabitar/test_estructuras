#pragma once


typedef struct stack Stack;

typedef struct node Node;


struct node
{
  int color;
  struct node *next;
};

struct stack
{
  struct node *first;
  int size;
};


Stack *stack_init();

void push(Stack* stack, int color);

int pop(Stack* stack);

void destroy(Stack *stack);
