#include <bits/stdc++.h>
using namespace std;


struct ListNode
{
    char val;
    ListNode *next;
    ListNode(char v)
    {
        val = v;
        next = NULL;
    }
};

void insertAtBeginning(ListNode *&head, char data)
{
    ListNode *newNode = new ListNode(data);
    newNode->next = head;
    head = newNode;
}
void deleteFromBeginning(ListNode *&head)
{
    if(head==NULL){
        return;
    }
    ListNode *temp=head;
    cout<<"Deleted Node is "<<temp->val<<"\n";
    head=temp->next;
}
void insertAtEnd(ListNode *&head, char data)
{

    ListNode *newNode = new ListNode(data);
    if(head==NULL){
        insertAtBeginning(head,data);
        return;
    }
    ListNode *temp = head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next = newNode;
}
void deleteFromEnd(ListNode *&head)
{   
    if(head==NULL)
        return;
    if (head->next == NULL)
    {
        deleteFromBeginning(head);
        return;
    }
    ListNode *prevNode = head;
    while (prevNode != NULL && prevNode->next != NULL
           && prevNode->next->next != NULL)
    {
        prevNode = prevNode->next;
    }
    ListNode *temp = prevNode->next;
    prevNode->next = NULL;
    cout<<"Deleted Node is "<<temp->val<<"\n";
    delete temp;

}
void insertAtIndex(ListNode *&head,int index,char data){
    if(head==NULL||index<=0){
        insertAtBeginning(head,data);
    }
    ListNode *newNode = new ListNode(data);
    ListNode *temp = head;
    for(int i=0;i<index-1;i++){
        if(temp==NULL){
            return;
        }
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next=newNode;

}
void deleteAtIndex(ListNode *&head, int index)
{
    if (head == NULL || index < 0)
        return;
    if (index == 0)
    {
        deleteFromBeginning(head);
        return;
    }
    ListNode *prevNode = head;
    for (int i=0; i < index-1; ++i)
    {
        if (prevNode == NULL)
            return;
        prevNode = prevNode->next;
    }
    if (prevNode->next == NULL)
        return;
    ListNode *temp = prevNode->next;
    prevNode->next = prevNode->next->next;
    delete temp;
}
void printList(ListNode *head)
{
    while (head != NULL)
    {
        cout << " " << head->val;
        head = head->next;
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
	ListNode *head = NULL;
    insertAtBeginning(head, 'A');
    printList(head); // A

    insertAtEnd(head, 'B');
    printList(head); // A->B
    
    insertAtEnd(head, 'C');
    printList(head); // A->B->C
    
    insertAtBeginning(head, 'D');
    printList(head); // D->A->B->C
    
    insertAtBeginning(head, 'E');
    printList(head); // E->D->A->B->C
    
    insertAtIndex(head, 2, 'F');
    printList(head); // E->D->F->A->B->C
    
    deleteFromBeginning(head);
    printList(head); // D->F->A->B->C
    
    deleteAtIndex(head, 2);
    printList(head); // D->F->B->C
    
    deleteFromEnd(head);
    printList(head); // D->F->B
    
    deleteAtIndex(head, 1);
    printList(head); // D->B
    
    deleteAtIndex(head, 0);
    printList(head); // B
    
    deleteAtIndex(head, 5);
    printList(head); // B
	return 0;
}