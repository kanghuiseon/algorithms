#include <iostream>
#include <string>

using namespace std;
int main(){
  string line;
  cin >> line;
  if(line.length() <=0 || line.length() > 100){
    return 0;
  }
  for(int i=0; i<line.length(); i++){
    cout << line[i];
    if((i+1)%10 == 0){
      cout<<endl;
    }
  }
  return 0;
}
