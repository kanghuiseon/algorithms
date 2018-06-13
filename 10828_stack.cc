#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;
int list[10000];
int top = -1;

void push(int n){
  list[++top]=n;
}
int empty(){
  if(top == -1){
    return 1;
  }
  else{
    return 0;
  }
}
void pop(){
  if(empty()==1){
    cout << "-1" << endl;
  }
  else{
    cout << list[top] << endl;
    list[top--] = 0;
}
}
void size(){
  cout << top+1 << endl;
}

int main(){
  //count : count of a loop, num : the number to enter the stack
  int count, num;
  string command;
  cin >> count;
  for(int i=0; i<count; i++){
    cin >> command;

    if(command == "push"){
      cin >> num;
      push(num);
    }
    else if(command == "empty"){
      cout << empty() << endl;
    }
    else if(command == "pop"){
      pop();
    }
    else if(command == "size"){
      size();
    }
    else if(command == "top"){
      if(empty()==1)
        cout<< "-1" << endl;
      else{
        cout << list[top] << endl;
      }
    }
    else{
      break;
    }
  }
  return 0;
}
