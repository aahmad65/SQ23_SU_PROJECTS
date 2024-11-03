// Aidan Ahmad
// p1.cpp
// Exercising understanding of linked lists and dynamic memory

#include<iostream>
#include<cstdlib>
#include<iomanip>
#include<ctime>
#include<fstream>

using namespace std;

const int MAX = 9999;

struct Node
{
  int data;
  Node* next;
};

void traverse(Node* list, ofstream& output);
void insert(Node*& list, int num);
Node* remove(Node* head, int num);
void sortList(Node* head);

int main()
{
  srand(time(0));
  int num;
  Node* head = nullptr;
  ofstream myfile;

  insert(head, 1);
  insert(head, 9999);

  for(int i = 1; i <= 75; i++){
    num = rand() % MAX + 1;
    insert(head, num);
  }

  cout << "Linked list created" << endl << endl;

  myfile.open("Original.txt");
  sortList(head);
  traverse(head, myfile);
  myfile.close();

  head = remove(head, 1);
  cout << "First value removed" << endl << endl;
  head = remove(head, 9999);
  cout << "Last value removed" << endl << endl;
  remove(head, 10000);
  
  myfile.open("Updated.txt");
  traverse(head, myfile);
  myfile.close();

  cout << "Linked list updated" << endl << endl;

  while (head != nullptr) {
    Node *temp = head;
    head = head->next;
    delete temp;
  }

  return 0;
}

void traverse(Node* list, ofstream& output)
{
  for(Node* iter = list; iter != nullptr; iter = iter->next){
    output << iter->data << endl;
  }
}

void insert(Node*& list, int num)
{
  Node* temp = new Node;
  temp->data = num;
  temp->next = nullptr;
  Node* current = list;
  if(list == nullptr){
    temp->next = list;
    list = temp;
  }else{
    while(current->next != nullptr){
      current = current->next;
    }
    current->next = temp;
  }
}

Node* remove(Node* head, int num)
{
  if(head == nullptr){
    return nullptr;
  }else if(num == 1){
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
  }else if(num == 9999){
    Node* temp = head;
    while(temp->next->next != nullptr){
      temp = temp->next;
    }
    delete(temp->next);
    temp->next = nullptr;
    return head;
  }
  return head;
}

void sortList(Node* head)
{
  Node* current = head;
  Node* index = nullptr;
  int temp;

  while(current != nullptr){
    index = current->next;
    while(index != nullptr){
      if(current->data > index->data){
        temp = current->data;
        current->data = index->data;
        index->data = temp;
      }
      index = index->next;
    }
    current = current->next;
  }
}