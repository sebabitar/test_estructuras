#include "stack.h"
#include <stdlib.h>
#include <stdio.h>


Stack *stack_init()
{
  /* Aqui agrega tu código */
  //stack_init() = (struct contacto *) malloc(sizeof(struct Stack));
  Stack *stack = malloc(sizeof(Stack));
  stack->first = NULL;
  stack->size = 0;
  return stack;
}

void push(Stack* stack, int color)
{
  Node *new_node = malloc(sizeof(Node));
  new_node->color = color;
  new_node->next = stack->first;
  stack->first = new_node;
  stack->size ++;
  /* Aqui agrega tu código */
}

int pop(Stack* stack)
{
  if (stack->first == NULL) {
    return -1;
  } else {
    stack->size --;
    Node *aux = stack->first;
    if (aux->next == NULL) {
      stack->first = NULL;
    } else {
      stack->first = aux->next;
    }
    int color_return = aux->color;
    free(aux);
    //free(stack->first);
    return color_return;
  }
  /* Aqui agrega tu código */
}

void destroy(Stack *stack)
{
  if (stack->first == NULL) {
    free(stack);
  } else {
    Node *aux = stack->first;
    stack->first = aux->next;
    free(aux);
    destroy(stack);
  }
}

/* A continuación puedes crear cualquier función adicional que ayude en la
  implementación de tu programa */
