#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main(){
//cnt is count of loop
//num is the number entering to arr
  int cnt, num, index=0;
  queue<string> op; //for '+' and '-'
  int arr[1000000]; //for num data
  int test[1000000]={0,};
  stack<int> n;
  cin >> cnt;
  //entering the input number in list stack
  for(int i=0; i<cnt; i++){
    cin >> num;
    if(test[num-1]==1){
      cout <<"NO\n";
      return 0;
    }else{
      test[num-1] = 1;
    }
    if(num > cnt){
      cout << "NO\n";
      return 0;
    }
    else{
      arr[i] = num;
      }
    }

  for(int i=1; i<=cnt; i++){
    n.push(i);
    op.push("+");
    while(!n.empty() && arr[index]==n.top()){
      index++;
      n.pop();
      op.push("-");
    }
  }
  if(!n.empty()){
    cout << "NO\n";
  }
  else{
    while(!op.empty()){
      cout << op.front() << "\n";
      op.pop();
    }
  }
  return 0;
}
