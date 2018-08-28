#include <iostream>
using namespace std;

int main(){
  int cnt;
  cin >> cnt;
  for(int i = 0; i < cnt; i++){
    for(int j=0; j<cnt-i-1; j++){
      cout << " ";
    }
    for(int k=0; k<=i; k++){
      cout << "*";
    }
    cout <<"\n";
  }
  return 0;
}
