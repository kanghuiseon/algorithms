#include <string>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
int main(){
  int num, sum=0,k;
  string n;
  string str;
  cin >> num;
  cin >> str;
  for(int i=0; i<num; i++){
    n = str[i];
    k = atoi(n.c_str());
    sum += k;
  }
  cout << sum << endl;
  return 0;
}
