#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
  int data;
  struct Node *next;
}node;

node *head;

void insert_node(int N){
  node *t;
  int i;
  t = (node*)malloc(sizeof(node));
  t->data = 1;
  head = t;

  for(i=2; i<=N; i++){
    t->next = (node*)malloc(sizeof(node));
    t->next->data = i;
    t = t->next;
  }
  t->next = head;
}

void delete_node(node *t){
  node* del_node;
  del_node = t->next;
  t->next = t->next->next;
  free(del_node);
}

void josephus(int N, int M){
  node *t;
  int i;
  insert_node(N);
  t = head;
  while(t != t->next){
    for(i=0; i<M-1; i++){
      t = t->next;
    }
    printf("%d, ",t->next->data);
    delete_node(t);
  }
  printf("%d",t->data);
}

int main(){
  int n,m;
  scanf("%d %d",&n,&m);
  printf("<");
  josephus(n,m);
  printf(">\n");
  return 0;
}
