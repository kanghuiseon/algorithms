#include <stdio.h>
#include <stdlib.h>

typedef struct _NODE{
  int Data;
  struct _NODE *Next;
}node;

node *head, *end;
node *ptrNode;
void InitializeStack(){
  head = (node*)malloc(sizeof(node));
  end = (node*)malloc(sizeof(node));
  head->Next = end;
  end->Next = end;
}

void Push(int num){
  ptrNode = (node*)malloc(sizeof(node));
  ptrNode->Data = num;
  ptrNode->Next = head->Next;
  head->Next = ptrNode;
}

int Pop(){
  int ret;
  ptrNode = head->Next;
  head->Next = head->Next->Next;
  ret = ptrNode->Data;
  free(ptrNode);

  return ret;
}

void DisplayStack(){
  node *indexNode;
  printf("head -> ");
  for(indexNode=head->Next; indexNode != end; indexNode = indexNode->Next){
    printf("%d -> ", indexNode->Data);
  }

  printf("end\n");
}

int main(){
  int ret;
  InitializeStack();
  Push(1);
  Push(3);
  Push(10);
  Push(21);
  Push(12);

  printf("다섯 번의 Push() 함수 호출 후 실행 결과\n");
  DisplayStack();
  Pop();
  Pop();
  Pop();
  printf("세번의 Pop() 함수 호출 후 실행 결과\n");
  DisplayStack();

  return 0;

}
