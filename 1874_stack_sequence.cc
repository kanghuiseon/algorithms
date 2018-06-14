#include <iostream>
#include <stack>
using namespace std;

int main(){
  //k is for index of list
  //j is for index of n
  int count, num, k=0, j=0;
  int list[10000];
  stack<int> n;
  cin >> count;
  //entering the input number in list stack
  for(int i=0; i<count; i++){
    cin >> num;
    list[i] = num;
  }
  for(int i=0; i<count; i++){
    n.push(j+1);
    cout<<"+"<<endl;
    while(1){
      int a = n.top();
      //cout << a << endl;
      //cout << list[k] << endl;
      if(list[k] == a){
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
  return 0;
}
