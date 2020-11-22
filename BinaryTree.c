/*
 * Hierarchial Data Structure
 * Topmost element is known as the root of tree
 * Every node can have at most 2 children in binary tree
 * Can access elements randomly using index
 * E.g: File System Hierarchy
 * Common Traversal Methods:
 * 	preorder(root) - print-left-right
 * 	postorder(root) - left-right-print
 * 	inorder(root) - left-print-right
*/

/*
 * === Advantages ===
 * Can represent data with some relationship
 * Insertion and search are much more efficient
 *
 * === Disadvantages ===
 * Sorting is difficult
 * Not very flexible
 *
 * === Applications ===
 * File system hierarchy
 * Multiple variations that are used in a wide variety of applications
*/ 

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct node
{
	int data;
	struct node *left;
	struct node *right;
};

struct node* create(int data)
{
	struct node* node = malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return(node);
}

void postorder(struct node* node)
{
	if (node == NULL)
	{
		return;
	}
	postorder(node->left);
	postorder(node->right);
	printf("%d ", node->data);
}

void inorder(struct node* node)
{
	if (node == NULL)
	{
		return;
	}
	inorder(node->left);
	printf("%d ", node->data);
	inorder(node->right);
}

void preorder(struct node* node)
{
	if (node == NULL)
	{
		return;
	}
	printf("%d ", node->data);
	preorder(node->left);
	preorder(node->right);
}

int main()
{
	struct node *root = create(1);
	root->left = create(2);
	root->right = create(3);
	root->left->left = create(4);
	printf("\nProrder ");
	preorder(root);
	printf("\nInorder ");
	inorder(root);
	printf("\nPostorder ");
	postorder(root);

	return 0;
}
