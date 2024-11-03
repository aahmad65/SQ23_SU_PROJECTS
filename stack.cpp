#include <iostream>
#include "stack.h"

using namespace std;

Stack::Stack()
{
  top = 0;
}

Stack::Stack(Stack const &other)
{
  size = other.size;
  for(int i = 0; i <= other.top; i++){
    stack[i] = other.stack[i];
  }
  top = other.top;
}

Stack::~Stack()
{
  delete[] stack;
}

void Stack::operator=(Stack const &other)
{
  size = other.size;
  for(int i = 0; i <= other.size; i++){
    stack[i] = other.stack[i];
  }
  top = other.top;
}
bool Stack::isPrime(int num)
{
  for(int i = 2; i * i <= num; i++){
    if(num % i == 0){
      return false;
    }
  }
  return true;
}
void Stack::resize()
{
  if(top >= size - 1){
    int new_size = (size * 1.5);
    int *temp = new int[new_size];
    for(int i = 0; i < size; i++){
      temp[i] = stack[i];
    }
    delete[] stack;
    size = new_size;
    stack = temp;
  }
}
void Stack::push(int num)
{
  resize();
  if(isPrime(num)){
    stack[top++] = num;
  }
}
int Stack::pop()
{
  if(isEmpty()){
    throw EmptyStack();
  }else{
    int value = stack[--top];
    return value;
  }
}
bool Stack::isEmpty()
{
  return (top == 0);
}
int Stack::peek()
{
  return stack[top-1];
}