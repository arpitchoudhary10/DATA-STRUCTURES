#include <bits/stdc++.h>
using namespace std;

class tree{    // tree node is defined
	public:
	int data;
	tree *left;
	tree *right;
};

void levelorder( tree *root){
	queue<tree*> q;  // using stl
	tree* temp;
	q.push(root);
	while(!q.empty()){
		temp=q.front();
		q.pop();
		cout<<temp->data<<" ";  //process node
		if(temp->left)
			q.push(temp->left); //EnQueue
		if(temp->right)
			q.push(temp->right); //EnQueue
	}
}
tree* newnode(int data)  // creating new node
{
    tree* node = (tree*)malloc(sizeof(tree));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return(node);
}


int main()
{
    //**same tree is builted as shown in example**
    tree *root=newnode(2);
    root->left= newnode(7);
    root->right= newnode(5);
    root->right->right=newnode(9);
    root->right->right->left=newnode(4);
    root->left->left=newnode(2);
    root->left->right=newnode(6);
    root->left->right->left=newnode(5);
    root->left->right->right=newnode(11);

    cout<<"Level Order traversal of binary tree is :"<<endl;
    levelorder(root);

    return 0;
}
