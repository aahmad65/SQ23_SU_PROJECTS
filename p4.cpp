//Aidan Ahmad
//p4.cpp
//Testing the methods of heap class

#include<iostream>
#include "heap.h"
#include<cstdlib>

using namespace std;

int const TRACK = 3;

int main()
{
  Heap test1(15);
  srand(time(0));
  cout << endl;
  cout << "Inserting values" << endl;

  for(int i = 0; i < 20; i++){
    int random = (1 + rand() % 50);
    test1.insert(random);
    cout << random << " inserted, ";
    if(i == 4 || i == 9 || i == 14){
      cout << endl;
    }
  }
  cout << endl << endl;
  cout << "Inserting four of the number 3 to test flush later" << endl;
  test1.insert(TRACK);
  test1.insert(TRACK);
  test1.insert(TRACK);
  test1.insert(TRACK);
  cout << endl;

  cout << "Copying first heap for later with the copy constructor" << endl;
  Heap test2(test1);

  cout << endl << "Deleting the min value: " << endl << endl;

  cout << test1.deleteMin() << " deleted " << endl;

  cout << endl << "Flushing the value 3" << endl << endl;
  test1.flush(3);

  int count = 0;

  cout << "Emptying first heap: " << endl << endl;
  while(!test1.isEmpty()){
    cout << test1.deleteMin() << " removed ";
    count++;
    if(count == 3){
      cout << endl;
      count = 0;
    }
  }
  count = 0;
  cout << endl << endl << "Checking if heap is empty: " << endl;
  if(test1.isEmpty()){
    cout << "Heap is empty!" << endl;
  }else{
    cout << "It didn't work!" << endl;
  }

  cout << endl << endl;
  cout << "Now, we will test the assignment operator using the first empty"
       << endl << "heap and assigning it to the second." << endl;
  test1 = test2;
  cout << endl;

  cout << "Now showing copy constructor by deleting copied second heap: ";
  cout << endl << endl;
  while(!test2.isEmpty()){
    cout << test2.deleteMin() << " removed ";
    count++;
    if(count == 3){
      cout << endl;
      count = 0;
    }
  }
  cout << endl;
  count = 0;

  cout << endl;
  cout << "And finally, removing all data from the first heap we " << endl;
  cout << "just copied into: " << endl << endl;
  while(!test1.isEmpty()){
    cout << test1.deleteMin() << " removed ";
    count++;
    if(count == 3){
      cout << endl;
      count = 0;
    }
  }
  cout << endl;
  return 0;
}
