//Aidan Ahmad
//Header file for a min heap class

#include<iostream>

class Heap
{
  private:
  int *heap;
  int capacity;
  int heap_size;

  void percDown(int index);

  void resize();

  public:

  Heap(int capacity);

  Heap(Heap const& other);

  void operator=(Heap const& other);

  ~Heap();

  void flush(int val);

  int deleteMin();

  void insert(int key);

  bool isEmpty();
};