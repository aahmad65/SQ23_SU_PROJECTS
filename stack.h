using namespace std;

class Stack
{
  private:
  int top;
  int size = 2;
  int *stack = new int[size];

  public:
  class EmptyStack{};
  
  Stack();
  Stack(Stack const &other);
  ~Stack();
  void operator=(Stack const &other);

  void push(int num);
  int pop();
  bool isEmpty();
  bool isPrime(int num);
  void resize();
  int peek();
};