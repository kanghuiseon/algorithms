#include <iostream>
using namespace std;

int main(){
  int test;
  cin >> test;

  if(test > 100 || test < 0){
    return 0;
  }
  else if(test >= 90 && test <= 100){
    cout << "A" << endl;
  }
  else if(test >= 80 && test < 90){
    cout << "B" << endl;
  }
  else if(test >= 70 && test < 80){
    cout << "C" << endl;
  }
  else if(test >= 60 && test < 70){
    cout << "D" << endl;
  }
  else{
    cout << "F" << endl;
  }
  return 0;
}
