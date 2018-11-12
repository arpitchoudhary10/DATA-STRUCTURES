#include<iostream>
using namespace std;

bool c=false;

struct node
{
	int data;
	node* left;
	node* right;
};

struct node* getNode(int data)
{
	node* newNode=new node();
	newNode->data=data;
	newNode->left=NULL;
	newNode->right=NULL;
	return newNode;
}

void inorder(struct node* root)
{
    if (root != NULL)
     {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

node* findMin(node*root)
{
    while(root->left!=NULL)
    {
        root=root->left;
    }
    return root;
}

struct node* Insert(struct node* root, int data)
{
	if (root == NULL)
		return getNode(data);

	if (data < root->data)
		root->left  = Insert(root->left, data);
	else if (data > root->data)
		root->right = Insert(root->right, data);

	return root;
}

bool Search(node*root,int value)
{
	if(root==NULL)
		return false;
	else if(root->data == value)
	{
		return true;
	}
	else if(value < root-> data)
		Search(root->left,value);
	else if(value > root->data)
		Search(root->right,value);
}


node* Delete( node* root,int value)
{
	c=Search(root,value);
	if(root==NULL)
		return root;
	else if(value< root->data)
	{
		root->left= Delete(root->left,value);
	}
	else if(value> root->data)
	{
		root->right= Delete(root->right,value);
	}

	// Node deletion
	else
	{
		//case 1: Leaf Node
		if(root->left==NULL&&root->right==NULL)
		{
			delete root;
			root=NULL;
			return root;
		}
		//case 2: one child
		else if(root->left==NULL)
		{
			struct node* temp=root;
			root=root->right;
			delete temp;
			return root;
		}
		else if(root->right==NULL)
		{
			struct node* temp=root;
			root=root->left;
			delete temp;
			return root;
		}
		//case 3: 2 child
		else
		{
			struct node*temp=findMin(root->right);
			root->data=temp->data;
			root->right=Delete(root->right,temp->data);
		}
	}
	return root;

}


int main()
{
	node* root=NULL;
	root=Insert(root,20);
	Insert(root,15);
	Insert(root,25);
	Insert(root,18);
	Insert(root,10);
	Insert(root,16);
	Insert(root,19);
	Insert(root,17);

	cout<<"Before Deletion: "<<endl;
	cout<<"Inorder: ";
	inorder(root);
	cout<<endl<<endl;

	Delete(root,15);

	if(c)
	{
		cout<<"Node Deleted"<<endl;
		cout<<"\nAfter Deletion: "<<endl;
		cout<<"Inorder: ";
		inorder(root);
		cout<<endl;
	}
	else
		cout<<"Node Not Found"<<endl;

	return 0;

}
