#include<iostream>
#include"node.cpp"
using namespace std;

Node* insert(Node* head,int i,int data)
{
    Node* newNode= new Node(data);
    int count=0;
    Node* temp=head;
    if(i==0)
    {
        newNode->next=head;
        head=newNode;
    }
    while(temp!=NULL && count<i-1)
    {
        temp=temp->next;
        count++;
    }
    if(temp!=NULL)
    {
    Node* a=temp->next;
    temp->next=newNode;
    newNode->next=a;
    }
    return head;
}
Node* deleteNode(Node* head,int j)
{
    Node* temp=head;
    int count=0;
    if(head==NULL)
    {
        return head;
    }
    if(j==0)
    {
        head=head->next;
        return head;
    }
    while(temp!=NULL && count<j-1)
    {
        temp=temp->next;
        count++;
    }
    if(temp==NULL || temp->next==NULL)
    {
        return head;
    }
    Node* a=temp->next;
    temp->next=temp->next->next;
    delete a;
    
    return head;
}

Node* insertRecursive(Node* head,int data,int i)
{
    
    if(head==NULL)
    {
        if(i==0)
        {
            Node* newNode= new Node(data);
            return newNode;
        }
        return head;
    }
    Node* newNode= new Node(data);
    if(i==0)
    {
        newNode->next=head;
        head=newNode;
        return head;
    }
    head->next=insertRecursive(head->next,data,i-1);
    
    return head;
}

Node* deleteRecursive(Node* head,int i)
{
    if(head==NULL)
    {
        return NULL;
    }
    if(i==0)
    {
        head=head->next;
        return head;
    }
    head->next=deleteRecursive(head->next,i-1);
    return head;
}

Node* midpoint(Node* head)
{
    if(head==NULL)
    {
        return NULL;
    }
    Node* slow=head;
    Node* fast=head->next;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

Node* mergeSortedLL(Node* h1,Node* h2)
{
    Node* fh=NULL;
    Node* ft=NULL;
    if(h1==NULL)
    {
        return h2;
    }
    if(h2==NULL)
    {
        return h1;
    }
    
    if(h1->data<h2->data)
    {
        fh=h1;
        ft=h1;
        h1=h1->next;
    }
    else{
        fh=h2;
        ft=h2;
        h2=h2->next;
    }
    while(h1!=NULL && h2!=NULL)
    {
    if(h1->data<h2->data)
    {
        ft->next=h1;
        ft=h1;
        h1=h1->next;
    }
    else{
        ft->next=h2;
        ft=h2;
        h2=h2->next;
    }
    }
    if(h1)
    {
        ft->next=h1;
    }
    if(h2)
    {
        ft->next=h2;
    }
    return fh;
}
Node* merge(Node* h1, Node* h2)
{
    Node* fh=NULL;
    Node* ft=NULL;
    if(h1==NULL)
    {
        return h2;
    }
    if(h2==NULL)
    {
        return h1;
    }
    
    if(h1->data<h2->data)
    {
        fh=h1;
        ft=h1;
        h1=h1->next;
    }
    else{
        fh=h2;
        ft=h2;
        h2=h2->next;
    }
    while(h1!=NULL && h2!=NULL)
    {
        if(h1->data<h2->data)
        {
            ft->next=h1;
            ft=h1;
            h1=h1->next;
        }
        else{
            ft->next=h2;
            ft=h2;
            h2=h2->next;
        }
    }
    if(h1)
    {
        ft->next=h1;
    }
    if(h2)
    {
        ft->next=h2;
    }
    return fh;
}
Node* findMid(Node* head)
{
    if(head==NULL)
    {
        return NULL;
    }
    Node* slow=head;
    Node* fast=head->next;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
Node * mergeSortLL(Node* head)
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    Node* mid=findMid(head);
    Node* half1=head;
    Node* half2=mid->next;
    mid->next=NULL;
    half1=mergeSortLL(half1);
    half2=mergeSortLL(half2);
    Node* finalhead=merge(half1, half2);
    return finalhead;
}

Node* reverseRec(Node* head)
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    Node* rest=reverseRec(head->next);
    head->next->next=head;
    head->next=NULL;
    return rest;
}

class Pair{
public:
    Node* head;
    Node* tail;
};

Pair reverseLL_2(Node* head)
{
    if(head==NULL || head->next==NULL)
    {
        Pair ans;
        ans.head=head;
        ans.tail=head;
        return ans;
    }
    Pair smallAns= reverseLL_2(head->next);
    
    smallAns.tail->next=head;
    head->next=NULL;
    Pair ans;
    ans.head=smallAns.head;
    ans.tail=head;
    return ans;
}

Node* reverseLL_Better(Node* head)
{
    return reverseLL_2(head).head;
}

Node* reverseLLIterative(Node* head)
{
    if(head==NULL || head->next==NULL)
    {
        return NULL;
    }
    Node* curr=head;
    Node* prev=NULL;
    
    while(curr!=NULL)
    {
        Node* next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}

Node* takeInput()
{
    int data;
    cin>>data;
    Node *head=NULL;
    Node *tail=NULL;
    
    while(data!=-1)
    {
        Node *newNode=new Node(data);
        if(head==NULL)
        {
            head=newNode;
            tail=newNode;
        }
        else
            {
                tail->next=newNode;
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
int main()
{
    
    Node* head=takeInput();
    head=mergeSortLL(head);
    print(head);
    cout<<endl;
    Node* head3=reverseLLIterative(head);
    print(head3);
    
//    int i,data;
//    cin>>i>>data;
//    head=deleteRecursive(head,data,i);
//    print(head);
    
    
//    cout<<"midpoint is:";
//    Node* x=midpoint(head);
//    cout<<x->data;
//
    
//    cout<<"enter the node you want to delete"<<endl;
//    int j;
//    cin>>j;
//    head=deleteNode(head,j);
//    print(head);
    //statically
//    Node n1(1);
//    Node *head= &n1;
//
//    Node n2(2);
//    Node n3(3);
//    Node n4(4);
//    Node n5(5);
//
//    n1.next=&n2;
//    n2.next=&n3;
//    n3.next=&n4;
//    n4.next=&n5;
//
//    print(head);
    
    
    //dynamically
//    Node* n3 = new Node(3);
//    Node*
//    Node* n4=new Node(4);
//
//
//    n3->next=n4;
//
//    cout<<n3->data<<" "<<n4->data<<endl;
    
    
}
