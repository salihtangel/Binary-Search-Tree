#include<stdio.h> 
#include<stdlib.h>



	typedef struct n{
	
		int data;
	 	struct	n* right;
		struct	n* left;
	
	}node;
	
	
	
	node *add(node * tree, int x){
	
		if(tree == NULL){
		
			node *root = (node*)malloc(sizeof(node));
			root ->right = NULL;
			root ->left = NULL;
			root -> data = 	x;
			return root;
		}
		
		if(tree->data < x){
	
			tree -> right = add(tree->right,x);
			return tree;
		}

			tree -> left  = add(tree->left,x);
			return tree;

	}

	void traversel(node* tree){
		
		if(tree == NULL)
			return;
		traversel(tree->left);
		printf("%d",tree->data);
		traversel(tree->right);

	}
	
	void main(){
	
		node * tree = NULL;
		tree = add(tree,10);
		tree = add(tree,13);
		tree = add(tree,14);
		tree = add(tree,15);
		tree = add(tree,16);
		tree = add(tree,17);
		tree = add(tree,18);
		tree = add(tree,19);
		traversel(tree);
	
	
	
	}


