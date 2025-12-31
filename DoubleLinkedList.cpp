#include<bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode* next;
    ListNode* prev;
};

ListNode* head = NULL;
ListNode* tail = NULL;

ListNode* createListNode(int data)
{
    ListNode* temp = new ListNode();
    temp->val = data;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

ListNode* ForwardSearch(int data)
{
    for(ListNode* i=head; i!=NULL; i=i->next)
    {
        if(data==i->val) return i;
    }
    return NULL;
}

ListNode* BackwardSearch(int data)
{
    for(ListNode* i=tail; i!=NULL; i=i->prev)
    {
        if(data==i->val) return i;
    }
    return NULL;
}

void printList()
{
    for(ListNode* i=head; i!=NULL; i=i->next)
    {
        cout << i->val << " ";
    }
    cout << endl;
}

void printReverseList()
{
    for(ListNode* i=tail; i!=NULL; i=i->prev)
    {
        cout << i->val << " ";
    }
    cout << endl;
}

void InsertLast(int data)
{
    if(head==NULL)
    {
        head = createListNode(data);
        tail = head;
    }
    else
    {
        ListNode* temp = createListNode(data);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void InsertFirst(int data)
{
    if(head==NULL)
    {
        head = createListNode(data);
        tail = head;
    }
    else
    {
        ListNode* temp = createListNode(data);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}


void InsertMiddle(int data, int insertAfter)
{
    ListNode* location = ForwardSearch(insertAfter);
    if(location!=NULL)
    {
        ListNode* temp = createListNode(data);
        temp->next = location->next;
        location->next->prev = temp;
        location->next = temp;
        temp->prev = location;
    }
}


void deleteFirst()
{
    ListNode* temp = head;
    head = head->next;
    temp->next = NULL;
    head->prev = NULL;
    delete(temp);
}

void deleteLast()
{
    ListNode* previousLast = head;
    while(previousLast->next->next!=NULL)
    {
        previousLast = previousLast->next;
    }

    previousLast->next = NULL;
    tail->prev = NULL;
    delete(tail);
    tail = previousLast;
}

void deleteMiddle(int data)
{
    ListNode* PreviousNode=NULL;

    ListNode* i=head;
    while(i!=NULL){
        if(i->val==data){
            if(PreviousNode==NULL){
                head=i->next;
            }
            else{
                PreviousNode->next=i->next;
                i->next->prev=PreviousNode;
            }
            break;
        }
        PreviousNode=i;
        i=i->next;
    }
}

int main()
{
    for(int i=1; i<=100; i++)
    {
        InsertLast(i);
    }
    printList();


    printf("After insert first---> \n");

    InsertFirst(1000);
    printList();

    printf("After insert middle ---> \n");
    InsertMiddle(64, 34);
    printList();

    printf("After insert last ---> \n");
    InsertLast(2000);
    printList();


    deleteFirst();
    printf("After deleting first element ---> \n");
    printList();


    deleteLast();
    printf("After deleting last element ---> \n");
    printList();

    deleteMiddle(50);
    printf("After deleting middle element ---> \n");
    printList();
}
