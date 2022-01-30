#include<iostream>
#include<queue>
#include"TreeNode.h"
using namespace std;

TreeNode<int>* takeInputLevelWise()
{
    int rootData;
    cout<<"enter root :"<<endl;
    cin>>rootData;
    TreeNode<int>* root=new TreeNode<int> (rootData);
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
  
    while(pendingNodes.size()!=0)
    {
       TreeNode<int>* front=pendingNodes.front();
        pendingNodes.pop();
        cout<<"enter the number of children of "<<front->data<<endl;
        int numChild;
        cin>>numChild;
        for(int i=0;i<numChild;i++)
        {
            int childData;
            cout<<"Enter "<<i<<"th child of "<< front->data<<endl;
            cin>>childData;
            TreeNode<int>* child=new TreeNode<int> (childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}


void printTreeLevelWise(TreeNode<int>* root)
{
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty())
    {
        TreeNode<int>* front=pendingNodes.front();
        pendingNodes.pop();
        cout<<front->data<<":";
    for(int i=0;i<front->children.size();i++)
    {
        if(i<((front->children.size())-1))
        {
            cout<<front->children[i]->data<<",";
        }
        else{
            cout<<front->children[i]->data;
        }
        pendingNodes.push(front->children[i]);
    }
    cout<<"\n";
    }
}

TreeNode<int>* takeInput()
{
    int rootData;
    cout<<"enter root :"<<endl;
    cin>>rootData;
    TreeNode<int>* root= new TreeNode<int>(rootData);
    int n;
    cout<<"enter num of children of "<<rootData<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        TreeNode<int>* child=takeInput();
        root->children.push_back(child);
    }
    return root;
}

void printTree(TreeNode<int>* root)
{
    
    if(root==NULL)
    {
        return;
    }
    
    cout<<root->data<<":";
    for(int i=0;i<root->children.size();i++)
    {
        cout<<root->children[i]->data<<",";
    }
    cout<<endl;
    for(int i=0;i<root->children.size();i++)
    {
        printTree(root->children[i]);
    }
}



int numNodes(TreeNode<int>* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int ans=1;
    for(int i=0;i<root->children.size();i++)
    {
        ans+=numNodes(root->children[i]);
    }
    return ans;
}

int height(TreeNode<int>* root)
{
    int ans=0;
    
    for(int i=0;i<root->children.size();i++)
    {
        int h=height(root->children[i]);
        if(h>ans)
        {
            ans=h;
        }
        
    }
    return ans+1;
}

void printAtLevelK(TreeNode<int>* root,int k)
{
    if(root==NULL)
    {
        return;
    }
    if(k==0)
    {
        cout<<root->data<<endl;
        return;
    }
    for(int i=0;i<root->children.size();i++)
    {
        printAtLevelK(root->children[i],k-1);
    }
}

int getLeafNodeCount(TreeNode<int>* root)
{
    int ans=0;
    if(root->children.size()==0)
    {
        ans++;
    }
    for(int i=0;i<root->children.size();i++)
    {
        ans+=getLeafNodeCount(root->children[i]);
    }
    return ans;
}

void preOrder(TreeNode<int>* root)
{
    cout<<root->data<<" ";
    for(int i=0;i<root->children.size();i++)
    {
        preOrder(root->children[i]);

    }
}

void deleteTree(TreeNode<int>* root)
{
    for(int i=0;i<root->children.size();i++)
    {
        deleteTree(root->children[i]);
    }
    delete root;
}

int main()
{
    
//    1 3 2 3 4 2 5 6 1 7 1 8 0 0 0 0
    
//    TreeNode<int>* root=new TreeNode<int>(1);
//    TreeNode<int>* node1=new TreeNode<int>(2);
//    TreeNode<int>* node2=new TreeNode<int>(3);
//    root->children.push_back(node1);
//    root->children.push_back(node2);
    
    TreeNode<int>* root=takeInputLevelWise();
    printTreeLevelWise(root);

    int a=height(root);
    cout<<a;
    printAtLevelK(root,3);
    int b=getLeafNodeCount(root);
    cout<<endl;
    cout<<b<<endl;
    preOrder(root);
    //TODO Delete Tree
    deleteTree(root);
}
