#include<stdio.h>
struct list{
    int data;
    struct list *next;
};
typedef struct list node;
int main(){
    node *head;
    head = (node*)malloc(sizeof(node));
    head->data=14;
    head->next=NULL;
    //head->next->data=25;
    //head->next->next->data=33;
    //head->next->next->next->data=47;
    //head->next->next->next=NULL;
    printf("%d",head->data);
    return 0;
}
