#include <iostream>
#include <stack>
#include <string>
using namespace std;
int top = -1;
void push(int* list, int n){
  list[++top]=n;
}
void empty(){
  if(top == -1){
    cout << "1" << endl;
  }
  else{
    cout << "0" << endl;
  }
}
int pop(int* list){
  if(empty()==1){
    cout << "-1" << endl;
  }
  cout << stack[top] << endl;
  list[top--] = 0;
}
int size(int* list){
  cout << list.size() << endl;
}

int top(){
  cout << top << endl;
}

int main(){
  #count : count of a loop, num : the number to enter the stack
  int count, num;
  int *list = new int;
  string command;
  cin >> count;
  for(int i=0; i<count; i++){
    cin >> command;
    cin >> num;
    switch (command) {
      case push:
        push(list);
      case pop:
        pop(list);
      case top:
        top();
      case size:
        size(list);
      case empty:
        empty();
    }
  }
  delete list;


}
