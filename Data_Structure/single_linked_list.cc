#include <stdio.h>
#include <stdlib.h>

typedef struct _Node{
  char Data;
  struct _Node *Next;
}Node;

Node *head, *end, *temp;
Node *temp1, *temp2, *temp3, *temp4;

void initialize(){
    Node *ptr;
    head = (Node *)malloc(sizeof(Node));
    end = (Node *)malloc(sizeof(Node));

    temp1 = (Node *)malloc(sizeof(Node));
    temp1->Data = 'A';
    head->Next = temp1;
    temp1->Next = end;
    end->Next = end;
    ptr = temp1;

    temp2 = (Node*)malloc(sizeof(Node));
    temp2->Data = 'B';
    ptr->Next = temp2;
    temp2->Next = end;
    ptr = temp2;

    temp3 = (Node*)malloc(sizeof(Node));
    temp3->Data = 'D';
    ptr->Next = temp3;
    temp3->Next = end;
    ptr = temp3;

    temp4 = (Node*)malloc(sizeof(Node));
    temp4->Data = 'E';
    ptr->Next = temp4;
    temp4->Next = end;
    ptr = temp4;
}
//Insert node in linked list
void Insert(Node * ptr){
  Node *Indexptr;
  for(Indexptr=head; Indexptr!=end; Indexptr = Indexptr->Next){
    if(Indexptr->Next->Data > ptr->Data){
      break;
    }
  }
  ptr->Next = Indexptr->Next;
  Indexptr->Next = ptr;
}

void Delete(Node* ptr){
    Node* indexptr;
    Node* deleteptr;

    for(indexptr = head; indexptr != end; indexptr = indexptr->Next){
      if(indexptr->Next->Data == ptr->Data){
        deleteptr = indexptr->Next;
        break;
      }
    }
    indexptr->Next = indexptr->Next->Next;
    free(deleteptr);
}



int main(){
  Node* ptr;
  int i=0;
  initialize();

  ptr = head->Next;
  printf("Before inserting 'c'\n");
  for(i=0; i<4; i++){
    printf("%2c",ptr->Data);
    ptr = ptr->Next;
  }

  printf("\n");
  temp = (Node*)malloc(sizeof(Node));
  temp->Data = 'C';

  Insert(temp);

  ptr = head->Next;
  printf("After inserting 'c'\n");
  for(i=0; i<5; i++){
    printf("%2c",ptr->Data);
    ptr = ptr->Next;
  }
  printf("\n");

  Delete(temp);
  ptr = head->Next;

  printf("After deleting 'c'\n");
  for(i=0; i<4; i++){
    printf("%2c",ptr->Data);
    ptr = ptr->Next;
  }
  printf("\n");

}
