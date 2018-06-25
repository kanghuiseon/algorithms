#include <iostream>
using namespace std;
int front = -1;
int back = 0;
int queue[10000000];

void push(){

}
int pop(){

}
int size(){

}
int empty(){

}
int front(){

}
int back(){

}

int main(){
  int cnt, num;
  string cmd;

  for(int i=0; i<cnt; i++){
    cin >> cmd;
    if(cmd == "push"){
      cin >> num;
      push(num);
    }
    else if(cmd == "pop"){
      pop();
    }
    else if(cme == "size"){
      size();
    }
    else if(cmd == "empty"){
      empty();
    }
    else if(cmd == "front"){
      front();
    }
    else if(cmd == "back"){
      back();
    }
    else{
      return 0;
    }
  }
}
