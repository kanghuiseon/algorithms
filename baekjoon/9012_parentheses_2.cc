#include <iostream>
#include <string>

using namespace std;
int main(){
  int cnt, p_cnt=0;
  string par;
  cin >> cnt;
  for(int i = 0; i < cnt; i++){
    cin >> par;
    p_cnt = 0;
    for(int j=0; j < par.length() && p_cnt >= 0; j++){
      if(par[j] == '('){
        p_cnt++;
      }
      else{
        p_cnt--;
      }
    }
    if(p_cnt == 0){
      cout << "YES" << endl;
    }
    else{
      cout << "NO" << endl;
    }
  }
  return 0;
}
