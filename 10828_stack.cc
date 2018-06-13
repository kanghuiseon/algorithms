#include <iostream>
#include <string>
void push(){

}
int pop(){

}
int size(){

}
int empty(){

}
int top(){

}

int main(){
  #count : count of a loop, num : the number to enter the stack
  int count, num;
  string command;
  cin >> count;
  for(int i=0; i<count; i++){
    cin >> command;
    cin >> num;
    switch (command) {
      case push:
        push();
      case pop:
        pop();

    }
  }


}
