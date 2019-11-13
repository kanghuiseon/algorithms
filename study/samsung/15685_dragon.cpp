#include <iostream>
#include <vector>
using namespace std;
int main(){
  int num,x,y,d,g,cnt=0;
  int check[105][105]={0,};
  vector<pair<int,int> > dragon;
  cin >> num;
  for(int i=0; i<num; i++){
    cin>>x>>y>>d>>g;
    dragon.clear();
    check[y][x]=1;
    dragon.push_back(make_pair(y,x));
    if(d==0){
      check[y][x+1]=1;
      dragon.push_back(make_pair(y,x+1));
    }
    else if(d==1){
      check[y-1][x]=1;
      dragon.push_back(make_pair(y-1,x));
    }
    else if(d==2){
      check[y][x-1]=1;
      dragon.push_back(make_pair(y,x-1));
    }
    else{
      check[y+1][x]=1;
      dragon.push_back(make_pair(y+1,x));
    }

    for(int i=0; i<g; i++){
      int b_x = dragon.back().first;
      int b_y = dragon.back().second;
      int sz = dragon.size()-1;
      for(int j=sz-1; j>=0; j--){
        int f_x = dragon[j].first;
        int f_y = dragon[j].second;
        int n_x = f_y - b_y;
        int n_y = b_x - f_x;
        dragon.push_back(make_pair(n_x+b_x, n_y+b_y));
        check[n_x+b_x][n_y+b_y]=1;
      }
    }
  }
  for(int k=0; k<105; k++){
    for(int t=0; t<105; t++){
      if(check[k][t]==1){
        if(check[k+1][t]==1 && check[k+1][t+1]==1 && check[k][t+1]==1)
          cnt++;
      }
    }
  }
  cout << cnt << endl;
  return 0;
}
