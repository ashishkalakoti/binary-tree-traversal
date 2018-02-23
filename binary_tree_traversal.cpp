#include<iostream>
using namespace std;
struct node
{
    int value;
    node *left,*right;
}*root=NULL;

void create ()
{
    int value,check=0;
    cout<<"\nEnter value: ";
    cin>>value;
    node* temp=new node;
    if(root==NULL)
    {
        temp->value=value;
        temp->left=NULL;
        temp->right=NULL;
        root=temp;
    }
    else
    {
        temp=root;
        while(1)
        {
            if(temp->value>value)
            {
                if(temp->left==NULL)
                {
                    node *temp1=new node;
                    temp1->value=value;
                    temp1->left=NULL;
                    temp1->right=NULL;
                    temp->left=temp1;
                    break;
                }
                else
                    temp=temp->left;
            }
            else
            {
                if(temp->right==NULL)
                {
                    node *temp1=new node;
                    temp1->value=value;
                    temp1->left=NULL;
                    temp1->right=NULL;
                    temp->right=temp1;
                    break;
                }
                else
                    temp=temp->right;
            }
        }
    }
}
void inorder(node *p)
{
    node *temp=new node;
    temp=p;
    if(temp!=NULL)
    {
        inorder(temp->left);
        cout<<temp->value<<endl;
        inorder(temp->right);
    }
}

void preorder(node *p)
{
    if(p!=NULL)
    {
        cout<<p->value<<endl;
        preorder(p->left);
        preorder(p->right);
    }
}

void postorder(node *p)
{
    if(p!=NULL)
    {
        postorder(p->left);
        postorder(p->right);
        cout<<p->value<<endl;
    }
}

int main()
{
    int choice;
    while(1)
    {
        cout<<"\n1. Add node to tree 2. Inorder traversal 3. Preorder traversal 4. Postorder traversal 5. EXIT: ";
        cin>>choice;
        switch(choice)
        {
            case 1: create();
                    break;
            case 2: inorder(root);
                    break;
            case 3: preorder(root);
                    break;
            case 4: postorder(root);
                    break;
            case 5: break;
            default: cout<<"\nINVALID INPUT";
        }
        if (choice==5)
            break;
    }
}
