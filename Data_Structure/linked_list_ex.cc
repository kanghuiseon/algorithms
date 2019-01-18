#include <stdio.h>
#include <stdlib.h>

typedef struct _Node{
  int data;
  struct _Node* next;
}node;
node* head;

void InitList(){
  head = (node*)malloc(sizeof(node));
  head->next = NULL;
}

void PutNode(node* bnode, node* tmpnode, int input){
  node* New = (node*)malloc(sizeof(node));
  *New = *tmpnode;
  New->data = input;
  New->next = bnode->next;
  bnode->next = New;
}

int main(){
  node* bnode, *tmp;
  int input;
  InitList();
  bnode = head;

  for(int i=0; ;i++){
    printf("input : ");
    scanf("%d",&input);
    if(input == -2){
      break;
    }
    PutNode(bnode, &tmp, input);
    

  }
}
