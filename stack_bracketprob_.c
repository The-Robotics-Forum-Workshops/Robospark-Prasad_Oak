#include<stdio.h>
#include<stdlib.h>
#include <string.h>


typedef struct Stack{
    int top;
    int* array;
    int capacity;
}ss;

ss* create(int capacity){
    ss* stack = (ss*)malloc(sizeof(ss));
    stack->top=-1;
    stack->capacity=capacity;
    stack->array=(int*)malloc(stack->capacity*sizeof(int));
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

int balancedbrackets(char* arr, char* arr1)
{
 int i, k,v;
 ss* stack = create(strlen(arr));
 for (i = 0, k = -1; arr[i]; ++i){
    if (arr[i] == '(' || arr[i] == '{' || arr[i] == '[') push(stack, arr[i]);
    else if (arr[i] == ')' && peek(stack) == '('){
        arr[++k]=pop(stack);
        arr[++k]=arr[i];
    }
    else if (arr[i] == '}' && peek(stack) == '{'){
        arr[++k]=pop(stack);
        arr[++k]=arr[i];
    }
    else if (arr[i] == ']' && peek(stack) == '['){
        arr[++k]=pop(stack);
        arr[++k]=arr[i];
    }
    else push(stack, arr[i]);
 }

 while (!isEmpty(stack)) {
    v=stack->top;
    arr1[v] = pop(stack);
 }

 arr[++k] ='\0';
 printf("Balanced bracket : %s\n", arr);
 printf("Unbalanced bracket : %s", arr1);

}

int main()
{
    char arr[]="({}[({})]}]";
    char arr1[100];

    balancedbrackets(arr,arr1);
    return 0;
}