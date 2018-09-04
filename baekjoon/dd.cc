#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
    int key;
    struct _node *next;
} node;

node *head;

// 1부터 k까지의 값을 가지는 환형 연결 리스트 구성
void insert_nodes(int k){

    node *t;
    int i;
    t = (node*)malloc((sizeof(node)));
    t->key = 1;
    head = t;

    for (i = 2; i < k; i++){
        t->next = (node*)malloc(sizeof(node));
        t = t->next;
        t->key = i;
    }

    t->next = head;    // 마지막을 처음으로 물림 환형
}

void delete_after(node *t){

    node *s;
    s = t->next;
    t->next = t->next->next;
    free(s);
}

// 요셉의 문제 n 개의 노드를 m 간격으로
void josephus(int n, int m){

    node *t;
    int i;
    insert_nodes(n);
    t = head;
    printf("\nAnswer : ");

    while (t != t->next){
        for (i = 0; i < m - 1; i++){
            t = t->next;
        }
        printf("%d ", t->next->key);
        delete_after(t);
    }
    printf("%d", t->key);
}

int main(void){

    int n, m;
    printf("\nIf you want to quit, enter 0 or minus value");
    while (1){
        printf("\nEnter N and M ->");
        scanf("%d %d", &n, &m);
        if (n <= 0 || m <= 0)
            return 0;
        josephus(n, m);
    }
    return 0;
}
