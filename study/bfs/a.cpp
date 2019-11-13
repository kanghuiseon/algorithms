#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

string str1, str2, str_mix;

bool isTrue(int a, int b, string aa, string bb){
  if(aa[a] == bb[b]) return true;
  else return false;
}

bool find(string a, string b, string c){
  int p1 = 0;
  int p2 = 0;
  int p3 = 0;
  for(int i = 0 ; i < c.size(); i++){
    if(p1 < a.size() || p2 < b.size()){
      if(isTrue(p1, p3, a, c)){
        p1++;
        p3++;
      }
      else if(isTrue(p2, p3, b, c)){
        p2++;
        p3++;
      }
      else return false;
    }
  }
  return true;
}

int main(){
  int n;
  scanf("%d", &n);
  for(int i = 1; i <= n; i++){
    cin >> str1 >> str2 >> str_mix;
    if(find(str1, str2, str_mix) || find(str2, str1, str_mix)){
      printf("Data set %d: yes\n", i);
    }
    else printf("Data set %d: no\n", i);

  }
  return 0;
}
