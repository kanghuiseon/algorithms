#include <iostream>
#include <stdio.h>
#include <stack>
#include <string>
using namespace std;
int main(){
  string answer;
  stack<char> s;
  getline(cin, answer);
  int i=0, sum=0;
  while(answer[i] != '\0'){
    if(answer[i] == ')' && answer[i-1] == '('){
      s.pop();
      sum += s.size();
      i++;
      continue;
    }
    else if(answer[i] == ')' && s.top() == '('){
      s.pop();
      sum += 1;
      i++;
      continue;
    }
    else{
      s.push(answer[i]);
      i++;
    }
  }
  printf("%d\n",sum);
  return 0;
}
