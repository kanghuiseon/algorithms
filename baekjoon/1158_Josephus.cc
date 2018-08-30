#include <iostream>

using namespace std;

typedef struct Node{
  int num;
  struct Node *next;
}node;

class linked_list{
  node *head, *tail;
public:
  linked_list(){
    head = new node();
    tail = head;
    head->next = NULL;
  }

  int empty(){
    if(head->next == NULL){
      return 1;
    }
    else{
      return 2;
    }
  }

  void add_node(int n){
      node *tmp = new node();
      tmp->num = n;
      tmp->next = NULL;

      tail->next = tmp;
      tail = tmp;
  }

  void del_node(int m){
    int i=0;
    node *tmp;
    node *del;
    while(1){
      for(tmp=head; tmp != tail; tmp = tmp->next){
        if(i==m-1){
          break;
        }
        i++;
      }
      del = tmp->next;
      cout << del->num <<", ";
      tmp->next = tmp->next->next;
      head = tmp->next;
      free(del);
    }
  }
};

int main(){
  int N, M;
  linked_list list;
  cin >> N;
  cin >> M;
  for(int i=1; i<=N; i++){
    list.add_node(i);
  }
  cout << "<";
  while(list.empty() != 1){
    list.del_node(M);
  }
  cout << ">";
  return 0;
}
