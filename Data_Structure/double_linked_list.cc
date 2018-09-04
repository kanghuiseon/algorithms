#include <stdio.h>
#include <stdlib.h>

typedef struct _NODE{
  char data;
  struct _NODE *Next;
  struct _NODE *Prev;
}Node;

Node *head, *end, *temp;
Node *temp1, *temp2, *temp3, *temp4;

void initialize(){
  Node *ptr;
  head = (Node*)malloc(sizeof(Node));
  end = (Node*)malloc(sizeof(Node));

  temp1 = (Node*)malloc(sizeof(Node));
  temp1->data = 'A';
  head->Next = temp1;
  temp1->Next = end;
  temp1->Prev = head;
  end->Next = end;
  ptr = temp1;

  temp2 = (Node*)malloc(sizeof(Node));
  temp2->data = 'B';
  ptr->Next = temp2;
  temp2->Next = end;
  temp2->Prev = ptr;
  ptr = temp2;

  temp3 = (Node*)malloc(sizeof(Node));
  temp3->data = 'D';
  ptr->Next = temp3;
  temp3->Next = end;
  temp3->Prev = ptr;
  ptr = temp3;

  temp4 = (Node*)malloc(sizeof(Node));
  temp4->data = 'E';
  ptr->Next = temp4;
  temp4->Next = end;
  temp4->Prev = ptr;
  ptr = temp4;
}
void InserNode(Node *ptr){
  Node *Indexptr;
  for(Indexptr = head->Next; Indexptr!= end; Indexptr=Indexptr->Next){
    if(Indexptr->data < ptr->data && Indexptr->Next->data > ptr->data){
      break;
    }
  }
  ptr->Next = Indexptr->Next;
  Indexptr->Next->Prev = ptr;
  Indexptr->Next = ptr;
  ptr->Prev = Indexptr;
}

void DeleteNode(Node *ptr){
  Node *indexptr;
  Node *deleteptr;
  for(indexptr=head; indexptr != end; indexptr = indexptr->Next){
    if(indexptr->Next->data == ptr->data){
      deleteptr = indexptr->Next;
      break;
    }
  }
  indexptr->Next = indexptr->Next->Next;
  indexptr->Next->Next->Prev = indexptr;
  free(deleteptr);
}


int main(){
  Node *ptr;
  int i=0;
  initialize();

  printf("노드 C의 삽입 전\n");
  ptr = head->Next;
  for(i=0; i<4; i++){
    printf("%2c",ptr->data);
    ptr = ptr->Next;
  }
  temp = (Node*)malloc(sizeof(Node));
  temp->data = 'C';

  InserNode(temp);

  printf("\n노드 C의 삽입 후\n");
  ptr = head->Next;

  for(i=0; i<5; i++){
    printf("%2c", ptr->data);
    ptr = ptr->Next;
  }

  DeleteNode(temp);

  printf("\n노드 C의 삭제 후\n");
  ptr = head->Next;

  for(i=0; i<4; i++){
    printf("%2c",ptr->data);
    ptr = ptr->Next;
  }
  printf("\n");

}
