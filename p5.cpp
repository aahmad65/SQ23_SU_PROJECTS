//Aidan Ahmad
//p5.cpp
//Program for implementing a hash table for the book Ulysses by James Joyce

#include<iostream>
#include<fstream>
#include<string>

using namespace std;

const string FILENAME = "ulyss12.txt";
const int MIN_WORD = 5;
const int TABLE_SIZE = 33671;
const string QUIT = "1";

struct HNode
{
  int count;
  string word;
  HNode* next;
};

string preprocess(string input);

unsigned int hashF(string str);

int store(int hashed, HNode* hashTable[], string input);

int find(string word, HNode* hashTable[]);

int main()
{
  ifstream infile;

  string input;
  string request;
  string processed;

  HNode* table[TABLE_SIZE];
  HNode* temp;
  HNode* current = nullptr;

  int collisions = 0;
  int uniqueStored = 0;
  int allStored = 0;
  int wordCount = 0;

  bool choice = true;

  cout << endl;

  for(int i = 0; i < TABLE_SIZE; i++){
    table[i] = new HNode;
    table[i]->next = nullptr;
  }

  infile.open(FILENAME);
  while(infile >> input){
    processed = preprocess(input);
    if(processed.length() > MIN_WORD){
      collisions += store(hashF(processed), table, processed);
      allStored++;
    }
  }
  
  infile.close();
  
  
  for(int i = 0; i < TABLE_SIZE; i++){
    temp = table[i];
    while(temp->next != nullptr){
      uniqueStored++;
      temp = temp->next;
    }
  }

  cout << "Total Items Stored: " << allStored << endl;
  cout << "Unique Items Stored: " << uniqueStored << endl;
  cout << "Total Collisions: " << collisions << endl;
  cout << "Load Factor: " << static_cast<double>(uniqueStored) / static_cast<double>(TABLE_SIZE) << endl;

  cout << "Showing words and their counts..." << endl;

  while(choice == true){
    cout << "Choose a word to find in the list (Enter " 
         << QUIT << " to Finish): ";
    cin >> request;
    wordCount = find(request, table);
    
    if(request == QUIT){
      choice = false;
    }else{
      cout << request << " Count: " << wordCount << endl << endl;
    }
  }

  
  for(int i = 0; i < TABLE_SIZE; i++){
    temp = table[i];
    while(temp != nullptr){
      current = temp;
      temp = temp->next;
      delete current;
    }
  }

  cout << endl;
  return 0;
}

string preprocess(string input)
{
  string output;
  unsigned int count = 0;
  if(input.length() <= MIN_WORD)
    return output;

  while(!isalpha(input[count]) && input.length() > MIN_WORD){
    input.erase(count, 1);
  }
  if(input.length() <= MIN_WORD)
    return output;

  count = input.length();
  while(!isalpha(input[count])){
    input.erase(count, 1);
    count--;
  }

  for(unsigned int i = 0; i < input.length(); i++){
    if(isdigit(input[i]))
      return output;
  }

  for(unsigned int i = 0; i < input.length(); i++){
    input[i] = tolower(input[i]);
  }

  if(input.length() > MIN_WORD){
    output = input;
  }

  return output;
}

unsigned int hashF(string str)
{
  //BKDR Hash Function from Brian Kernighan and Dennis 
  //Ritchie's book "The C Programming Language"
  unsigned int seed = 1313; /* 31 131 1313 13131 131313 etc.. */
  unsigned int hash = 0;
  unsigned int i    = 0;

  for (i = 0; i < str.length(); i++)
  {
    hash = (hash * seed) + str[i];
  }

  return hash % TABLE_SIZE;
}

int store(int hashed, HNode* hashTable[], string input)
{
  int index = hashed;
  int coll = 0;
  HNode* temp = hashTable[index];
  HNode* current;
  while(temp->next != nullptr && temp->word != input){
    temp = temp->next;
    coll++;
  }
  if(temp->word == input){
    temp->count++;
    return 0;
  }else{
    current = new HNode;
    current->count = 1;
    current->word = input;
    current->next = nullptr;
    temp->next = current;
    return coll;
  }
}

int find(string word, HNode* hashTable[])
{
  string processedWord = preprocess(word);
  HNode* temp = hashTable[hashF(processedWord)];
  while(temp->next != nullptr && temp->word != processedWord){
    temp = temp->next;
  }
  if(temp->word == processedWord){
    return temp->count;
  }else{
    return 0;
  }
}