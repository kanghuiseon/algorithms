#include <iostream>
#include <string>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int cnt;
  int A, B;
  cin >> cnt;
  for(int i=0; i<cnt; i++){
    cin >> A;
    cin >> B;
    cout << A+B << "\n";
  }
  return 0;

}
