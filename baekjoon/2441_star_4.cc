#include <iostream>
using namespace std;

int main(){
  int cnt;
  cin >> cnt;
  for(int i=0; i<cnt; i++){
    for(int j=0; j<i; j++){
      cout <<" ";
    }
    for(int k=0; k<cnt-i; k++){
      cout <<"*";
    }
    cout << "\n";
  }
  return 0;
}
