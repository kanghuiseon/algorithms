#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
  int cnt;
  string par;
  stack<char> stack;
  cin >> cnt;
  for(int i=0; i<cnt; i++){
      cin >> par;
      for(int j=0; j<par.length(); j++){
        if(par[j] =='(' || stack.empty()){
          stack.push(par[j]);
        }
        else if(stack.top() == '('){
          stack.pop();
        }
      }
      if(stack.empty()){
        cout << "YES" << endl;
      }
      else{
        cout << "NO" << endl;
      }
      while(!stack.empty()){
        stack.pop();
      }
  }
  
  return 0;
}
