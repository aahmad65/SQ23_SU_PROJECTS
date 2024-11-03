//Aidan Ahmad
//Implementation for heap class

#include<iostream>
#include "heap.h"

using namespace std;

Heap::Heap(int capacity)
{
  heap_size = -1;
  this->capacity = capacity;
  heap = new int[capacity];
}

Heap::Heap(Heap const& other)
{
  this->capacity = other.capacity;
  heap_size = other.heap_size;
  heap = new int[capacity];
  for(int i = 0; i < capacity; i++){
    heap[i] = other.heap[i];
  }
}

void Heap::operator=(Heap const& other)
{
  if(!isEmpty())
    delete[] heap;
  this->capacity = other.capacity;
  heap_size = other.heap_size;
  heap = new int[capacity];
  for(int i = 0; i < capacity; i++){
    heap[i] = other.heap[i];
  }
}

Heap::~Heap()
{
  delete[] heap;
}

void Heap::percDown(int index)
{
  int temp = heap[index];
  while(((2*index + 1) <= heap_size && temp > heap[(2*index + 1)]) || 
  ((2*index + 2) <= heap_size && temp > heap[(2*index + 2)])){
    if((2*index + 2) <= heap_size && heap[(2*index + 2)] < heap[(2*index + 1)]){
      heap[index] = heap[(2*index + 2)];
      index = (2*index + 2);
    }else{
      heap[index] = heap[(2*index + 1)];
      index = (2*index + 1);
    }
  }
  heap[index] = temp;
}

void Heap::flush(int val)
{
  if(isEmpty()){
    return;
  }else{
    for(int i = 0; i < heap_size; i++){
      for(int j = 0; j < heap_size; j++){
        if(heap[j] == val){
          heap[j] = heap[heap_size];
          heap_size--;
          percDown(j);
        }
      }
    }
  }
}

int Heap::deleteMin()
{
  //Using 0th element

  int value = heap[0];

  heap[0] = heap[heap_size];

  heap_size--;

  percDown(0);

  return value;

}

void Heap::insert(int key)
{
  //Using 0th element
  resize();
  int hole = ++heap_size;
  while(hole > 0 && key < heap[(hole-1)/2]){
    heap[hole] = heap[(hole-1)/2];
    hole = (hole-1)/2;
  }
  heap[hole] = key;
}

bool Heap::isEmpty()
{
  if(heap_size == -1)
    return true;
  else
    return false;
}

void Heap::resize()
{
  if(heap_size == capacity - 1){
    Heap temp(capacity*2);
    for(int i = 0; i <= heap_size; i++){
      temp.insert(heap[i]);
    }
    delete[] heap;
    capacity = capacity*2;
    heap = new int[capacity];
    for(int i = 0; i <= temp.heap_size; i++){
      heap[i] = temp.heap[i];
    }
  }
}