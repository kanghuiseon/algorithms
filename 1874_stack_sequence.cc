#include <stdio.h>
#include <iostream>
#include <stack>
using namespace std;

int main(){
  //k is for index of list
  //j is value entering to n
  int count, num, k=0, j=1, pcnt=0, mcnt=0;
  int list[10000];
  stack<int> n;
  cin >> count;
  //entering the input number in list stack
  for(int i=0; i<count; i++){
    cin >> num;
    if(num > count){
      cout << "No" << endl;
      return 0;
    }
    else{
      list[i] = num;
    }
}

  for(int i=0; i<count; i++){
    n.push(j);
    pcnt++;
    while(list[k]==n.top()){
      n.pop();
      mcnt++;
      k++;
    }
    j++;
  }

  cout << "success" << endl;

  if(pcnt != mcnt){
  cout << "No" << endl;
  return 0;
  }
/*  for(int i=0; i<count; i++){
    n.push(j+1);
    cout<<"+"<<endl;
    while(true){
      if(list[k] == n.top()){
        n.pop();
        cout << "-" << endl;
        k++;
      }
      else{
        break;
      }
    }
    j++;
  }
  */
  return 0;
}
