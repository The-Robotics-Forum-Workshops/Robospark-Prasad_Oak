// C program to convert infix expression to postfix
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Stack type
typedef struct Stack {
 int top;
 unsigned capacity;
 int* array;
}ss;

// Stack Operations
ss* create(unsigned capacity)
{
 ss* stack = (ss*)malloc(sizeof(ss));

 stack->top = -1;
 stack->capacity = capacity;
 stack->array = (int*)malloc(stack->capacity * sizeof(int));

 return stack;
}

int isEmpty(ss* stack)
{
 return stack->top == -1;
}

char peek(ss* stack)
{
 return stack->array[stack->top];
}

char pop(ss* stack)
{
 if (!isEmpty(stack))
  return stack->array[stack->top--];
 return '$';
}

void push(ss* stack, char op)
{
 stack->array[++stack->top] = op;
}

//to check if the given character is operand
int isOperand(char ch)
{
 return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

//to return precedence of a given operator
int Prec(char ch)
{
 switch (ch) {
 case '+':
 case '-':
  return 1;

 case '*':
 case '/':
  return 2;

 case '^':
  return 3;
 }
 return -1;
}

// The main function that converts given infix expression
// to postfix expression.
int infixToPostfix(char* exp)
{
 int i, k;

 // Create a stack 
 ss* stack = create(strlen(exp));

 for (i = 0, k = -1; exp[i]; ++i) {
  if (isOperand(exp[i])) exp[++k] = exp[i];
   
  else if (exp[i] == '(') push(stack, exp[i]);
  
  else if (exp[i] == ')') 
  {
   while (!isEmpty(stack) && peek(stack) != '(') exp[++k] = pop(stack);

   if (!isEmpty(stack) && peek(stack) != '(')
    return -1; // invalid expression
   else
    pop(stack);
  }

  else // an operator is encountered
  {
   while (!isEmpty(stack) && Prec(exp[i]) <= Prec(peek(stack)))
    exp[++k] = pop(stack);
   push(stack, exp[i]);
  }
 }

 // pop all the operators from the stack
 while (!isEmpty(stack)) exp[++k] = pop(stack);

 exp[++k] = '\0';
 printf("%s", exp);
}


int main()
{
 char exp[] = "((a+b)-c*(d/e))+f";
 
 // Function call
 infixToPostfix(exp);
 return 0;
}
