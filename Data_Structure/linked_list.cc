#include <stdio.h>
#include <stdlib.h>

typedef struct _Node{
  char data;
  struct _Node *next;
} node;

node* head;

void InitList(){
  head = (node*)malloc(sizeof(node));
  head->next = NULL;
}

node* PutNode(node* bNode, node* tmpNode){
  node* New = (node*)malloc(sizeof(node));
  *New = *tmpNode;

  New->next = bNode->next;
  bNode->next = New;

  return New;
}

bool DelNode(Node *bNode){
  node* del = bNode->next;
  if(del == NULL){
    return false;
  }
  bNode->next=del->next;
  free(del);
  return true;
}


int main(){
  node* bnode;
  node tmp;
  InitList();
  bnode = head;
  for(int i=1; i<=10; i++){
    tmp.data = i;
    bnode = PutNode(bnode, &tmp)
  }
  for(bnode=head->next;bnode;bnode=bnode->next){
    printf("%d\n", bnode->data;)
  }
  return 0;
}
