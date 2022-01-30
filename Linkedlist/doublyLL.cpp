#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
    Node* prev;
    
    Node(int data)
    {
        this->data=data;
        next=NULL;
        prev=NULL;
    }
};


Node* takeInput()
{
    int data;
    cin>>data;
    Node* head=NULL;
    Node* tail=NULL;
    
    while(data!=-1)
    {
        Node *newNode=new Node(data);
        if(head==NULL)
        {
            head=newNode;
            newNode->prev=NULL;
            newNode->data=data;
            newNode->next=NULL;
            tail=newNode;
        }
        else
        {
            newNode->next=head;
            newNode->data=data;
            newNode->prev=NULL;
            head->prev=newNode;
            head=newNode;
           
        }
        cin>>data;
    }
    return head;
}
Node* takeInput2()
{
    int data;
    cin>>data;
    Node* head=NULL;
    Node* tail=NULL;
    
    while(data!=-1)
    {
        Node* newNode = new Node(data);
    if(head==NULL)
    {
        head=newNode;
        newNode->prev=NULL;
        newNode->next=NULL;
        tail=newNode;
    }
    else
    {
        newNode->prev=tail;
        tail->next=newNode;
        newNode->next=NULL;
        tail=newNode;
    }
        cin>>data;
    }
    return head;
}
void print(Node* head)
{
    Node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

Node* deleteNode(Node* head)
{
   if(head==NULL)
   {
       return head;
   }
    Node* temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    Node* tail=temp;
    if(head==tail)
    {
        Node* curr;
        curr=head;
        head=NULL;
        tail=NULL;
        delete curr;
        return head;
    }
    else{
        Node* curr;
        curr=tail;
        tail=tail->prev;
        tail->next=NULL;
        delete curr;
    }
    return head;
}

int main()
{
    
    Node*head=takeInput2();
    print(head);
    head=deleteNode(head);
    cout<<endl;
    print(head);
}

