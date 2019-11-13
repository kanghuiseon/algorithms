#include <string>
#include <iostream>
#include <vector>
using namespace std;
int answer = 0;
int compare(string a, string b){
  int com = 0;
  for(int i=0; i<a.length(); i++){
    if(a[i] != b[i])
      com++;
  }
  if(com == 1)
    return 1;
  else
    return 0;
}
int solution(string begin, string target, vector<string> words) {
    int i;
    //target이랑 words의 값이 다르면 넘어가고 같으면 break;
    //words에서 i는 target이 위치한 index
    for(i=0; i < words.size(); i++){
      if(words[i] != target)
        continue;
      else
        break;
    }
  //  printf("i : %d\n",i);
    //words에 target이 없으면 return 0;
    if(i == words.size())
      return 0;
    while(1){
      int j=0;
      //그 begin이 target이랑 1차이 날 수 있으므로
      //그것도 체크해준다.
      if(compare(begin , words[i])){
    //      printf("f\n");
          return answer += 1;
      }
      //현재 begin이랑 words의 단어랑 비교해서 1차이가 나면 words[j]가 begin이 되고
      //answer++해준다.
      else{
        if(compare(begin, words[j])){
          begin = words[j];
    //      printf("%s\n",begin.c_str());
          words.erase(words.begin());
      //    printf("%s\n",words.begin()->c_str());
          i--;
      //    printf("i: %d\n",i);
          answer++;

        //  printf("answer : %d\n",answer);
        }
        else{
          string tmp = words.begin()->c_str();
          words.erase(words.begin());
          words.push_back(tmp);
          i = words.size()-1;
        }
      }
    }
    return answer;
}

int main(){
  vector<string> words;
  // words.push_back("hhh");
  // words.push_back("hht");
  words.push_back("hot");
  words.push_back("dot");
  words.push_back("dog");
  words.push_back("lot");
  words.push_back("log");
  words.push_back("cog");

  string begin = "hit";
  string target = "cog";
  int result = solution(begin, target, words);
  cout << result << endl;
}
