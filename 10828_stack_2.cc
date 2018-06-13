#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
    int count, num;
    cin >> count;
    stack<int> list;
    string command;

    for(int i = 0; i < count; i++){
      cin >> command;
      if(command == "push"){
        cin >> num;
        list.push(num);
      }
      else if(command == "pop"){
        if(!list.empty()){
          cout << list.top() << endl;
          list.pop();
        }
        else{
          cout << "-1" << endl;
        }
      }
      else if(command == "top"){
        if(!list.empty()){
          cout << list.top() << endl;
        }
        else{
          cout << "-1" << endl;
        }
      }
      else if(command == "empty"){
        if(list.empty()){
          cout << "1" << endl;
        }
        else{
          cout << "0" <<endl;
        }
      }
      else if(command == "size"){
        cout << list.size() << endl;
      }
      else{
        break;
      }
    }
    return 0;
}
