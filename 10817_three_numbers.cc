#include <iostream>
#include <list>
using namespace std;

int main(){
  list<int> li;
  int number;
  for(int i=0; i<3; i++){
    cin >> number;
    li.push_back(number);
    li.sort();
  }
  li.pop_front();
  cout << li.front() << endl;
  return 0;
}
