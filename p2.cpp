//Aidan Ahmad
//p2.cpp
//Description:

#include <iostream>
#include "stack.h"

using namespace std;

int const SIZE = 5;
int const ARR[SIZE] = {3, 17, 20, 53, 13};

int main(){
  Stack stack;
  cout << endl;

  cout << "Attempting to push values onto the stack: " << endl;
  cout << "3 17 20 53 13" << endl;

  for(int i = 0; i < SIZE; i++){
    stack.push(ARR[i]);
  }
  
  cout << "Testing the copy constructor..." << endl;
  Stack stack2(stack);
  cout << "stack2 has been created... now testing pop function" << endl;
  cout << "The values 13 53 17 3 will appear: " << endl;
  for(int i = 0; i < 4; i++){
    cout << stack.pop() << " ";
  }

  cout << endl << "Now attempting to pop empty stack..." << endl;
  try{
    stack.pop();
  }
  catch(Stack::EmptyStack){
    cout << endl << "Empty Stack" << endl;
  }

  cout << "Now attempting to use assignment operator function..." << endl;
  stack=stack2;
  cout << "Peeking at the top of the stack. Value should be 4 " << endl;
  cout << "for count of numbers in the stack: " << endl;
  cout << stack.peek() << endl;

  cout << endl;
  return 0;
}