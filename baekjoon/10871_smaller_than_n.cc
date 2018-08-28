#include <iostream>
using namespace std;

int main(){
  int n, x, number;
  cin >> n >> x;
  for(int i=0; i<n; i++){
    cin >> number;
    if(number < x){
      cout << number << " ";
    }
  }
  cout << endl;
  return 0;
}
