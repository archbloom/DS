#include "bits/stdc++.h"

using namespace std;
struct node
{
	int data;
	struct node* left;
	struct node* right;
}*root;

class BSTree
{
public:
	void insert(node*, int);
	//int find(node*,int);
	void inorder(node*);
	//void preorder(node *);
	//void postorder(node *);

	BSTree()
	{
		root = NULL;
	}
};

void BSTree::insert(node *tree, int data)
{
	if(root == NULL)
	{
		root = new node;
		root->data = data;
		root->left = NULL;
		root->right = NULL;
		return;
	}

	if(tree->data == data)
	{
		cout<<"\n\nDuplicate data is not allowed in a BST";
		return;
	}

	if(tree->data > data)
	{
		if(tree->left != NULL)
		{
			insert(tree->left,data);
		}
		else
		{
			node* temp = new node;
			tree->left = temp;
			temp->data = data;
			temp->left = NULL;
			temp->right = NULL;
			return;
		}
	}
	else
	{
		if(tree->right != NULL)
		{
			insert(tree->right,data);
		}
		else
		{
			node* temp = new node;
			tree->right = temp;
			temp->data = data;
			temp->left = NULL;
			temp->right = NULL;
			return;
		}
	}

}
/*
int BSTree::find(node* tree,int key)
{
	if( tree->data == key)
	{
		return 1;
	}
	else if(key > tree->data)
	{
		if(tree->right != NULL)
			find(tree->right,key);
		else
			return 0;
	}
	else if(key < tree->data)
	{
		if(tree->right != NULL)
			find(tree->left,key);
		else
			return 0;
	}
}
*/
void BSTree::inorder(node* tree)
{
	if(root == NULL)
	{
		cout<<"Tree is empty\n";
		return;
	}

	if(tree != NULL)
	{
		inorder(tree->left);
		cout<<tree->data<<"\t";
		inorder(tree->right);
	}
}
int main(int argc, char const *argv[]) {
	BSTree bst;
	char in;
	int data;
	do {
		cout<<"Enter Element : ";
		cin>>data;
		bst.insert(root,data);
		cout<<"Want to insert more data? y/n : ";
		cin>>in;
	} while(in!='n');
	bst.inorder(root);
	return 0;
}
