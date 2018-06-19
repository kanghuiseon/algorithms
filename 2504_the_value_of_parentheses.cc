#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
  stack<char> stack;
  string par;
  int sum = 0;
  cin >> par;
  for(int i=0; i<par.length(); i++){
    if(stack.empty() || par[i] == '(' || par[i] == '['){
      stack.push(str[j]);
    }
    else if(stack.top() == '('){
      stack.pop();
      sum += 2;
    }
    else if(stack.top() == '['){
      stack.pop();
      sum += 3;
    }
  }
}
