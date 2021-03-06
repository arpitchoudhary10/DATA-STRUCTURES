#include<iostream>
using namespace std;

/*structure of the tree*/
struct node
{
	int info;
	node *left,*right;
};

/*Method to find the predecessor and successor*/
void find(node *root,node*& pre,node*& suc,int info)
{
	if(root==NULL)
	{
		return ;
	}

	/*if key(the given node) is the root*/
	if(root->info == info )
	{
		if(root->left != NULL)
		{
			node* temp=root->left;
			while(temp->right != NULL)
			{
				temp=temp->right;
			}
			pre=temp;
		}
		if(root->right != NULL)
		{
			node* temp=root->right;
			while(temp->left != NULL)
			{
				temp=temp->left;
			}
			suc=temp;
		}
		return ;
	}

	/*if key is less than current node(root)*/
	if(root->info > info)
	{
		suc=root;
		/*Search the left subtree*/
		find(root->left,pre,suc,info);
	}
	/*if key is greater than current node(root)*/
	else
	{
		pre=root;
		/*Search the right subtree*/
		find(root->right,pre,suc,info);
	}
}

/*Method to create a newNode if a tree does not exist*/
node *newNode(int n)
{
	node *p=new node;
	p->info=n;
	p->left=p->right=NULL;
	return p;
}

/*Method to insert node in the BST */
node *insert(node* node,int info)
{
	if(node==NULL)
	{
		return newNode(info);
	}
	if(info < node->info)
	{
		node->left=insert(node->left,info);
	}
	else
	{
		node->right=insert(node->right,info);
	}
	return node;
}

//main program
int main()
{
	int info,value;
    node* root=NULL;

	int n;
	cin>>n;
	for(int i=0;i<n;i++)
    {
        cin>>value;
	    if(root==NULL)
            root=insert(root,value);
        else
	    insert(root,value);
	}

	node*pre=NULL,*suc=NULL;  /*pre will contain predecessor and suc will contain successor*/
    cin>>info;
	find(root,pre,suc,info);
	if(pre != NULL)
	{
		cout<<"predecessor :"<<pre->info<<endl;
	}
	else
	{
		cout<<"No predecessor"<<endl;
	}

	if(suc != NULL)
	{
		cout<<"successor :"<<suc->info<<endl;
	}
	else
	{
		cout<<"No successor";
	}
	cout<<endl;

	return 0;
}
