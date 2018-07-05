#include <iostream>
#include <string>
using namespace std;
#define MAXSIZE 1000000
int f = -1;
int b = -1;
int queue[MAXSIZE];
void push(int num);
int pop();
int size();
void empty();
int front();
int back();

void push(int num){
  if(b >= MAXSIZE){
    return;
  }
  else{
    queue[++b] = num;
  }
}
int pop(){
  if(size() == 0){
    return -1;
  }
  else{
    return queue[++f];
  }
}
int size(){
  return (b-f);
}

void empty(){
  if ((b-f) == 0){
    cout << "1" << endl;
  }
  else{
    cout << "0" << endl;
  }
}
int front(){
  if((b-f) == 0){
    return -1;
  }
  return queue[f+1];
}
int back(){
  if((b-f) == 0){
    return -1;
  }
  return queue[b];
}

int main(){
  int cnt, num;
  string cmd;
  cin >> cnt;
  for(int i=0; i<cnt; i++){
    cin >> cmd;
    if(cmd == "push"){
      cin >> num;
      push(num);
    }
    else if(cmd == "pop"){
      cout << pop() << endl;
    }
    else if(cmd == "size"){
      cout << size() << endl;
    }
    else if(cmd == "empty"){
      empty();
    }
    else if(cmd == "front"){
      cout << front() << endl;
    }
    else if(cmd == "back"){
      cout << back() << endl;
    }
    else{
      return 0;
    }
  }
  return 0;
}
