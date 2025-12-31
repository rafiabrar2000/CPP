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

bool isPalindrome(ListNode *left)
{
    if (left == NULL)
       return true;

    // Find rightmost node
    ListNode *right = left;
    while (right->next != NULL)
        right = right->next;

    while (left != right)
    {
        if (left->val != right->val)
            return false;

        left = left->next;
        right = right->prev;
    }

    return true;
}

int main()
{
    InsertLast(1);
    InsertLast(2);
    InsertLast(3);
    InsertLast(2);
    InsertLast(1);

    printf("Checking Palindrome--->\n");
    if (isPalindrome(head))
        printf("It is Palindrome\n");
    else
        printf("Not Palindrome\n");

    printf("Printing forward list--->\n");
    printList();
    printf("Printing reverse list--->\n");
    printReverseList();

}


