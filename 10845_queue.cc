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

int main(){
  int cnt, num;
  string cmd;

  for(int i=0; i<cnt; i++){
    cin >> cmd;
    if(cmd == "push"){
      cin >> num;
      queue[front++] = num;
    }
    else if(cmd == "pop"){

    }

  }
}
