/*
 * Linear
 * Elements can be stored as memory available
 * Can access elements in a linear fashion only
 * Stores homogeneous elements (same type)
 * Dynamic in size
 * Easy insertion and deletion
 * Starting element or node is generally termed the head
*/

/*
 * === Advantages ===
 * Dynamic in size
 * No wastages (size and capacity always equal)
 * Easy insertion and deletion (1 link manipulation is required)
 * Efficient memory allocaton
 *
 * === Disadvantages ===
 * If head node is lost, linked list is lost
 * No random access possible
 *
 * === Application ===
 * Where memory is limited
 * Programs that require frequent insertion and deletion
*/

// Beginning

#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *next;
};

void display(struct Node* n)
{
	while (n != NULL)
	{
		printf("%d", n->data);
		n = n->next;
	}
}

void findMiddle(struct Node* head)
{
	struct Node* slow = head;
	struct Node* fast = head;
	if (head != NULL)
	{
		while (fast != NULL && fast->next != NULL)
		{
			fast = fast->next->next;
			slow = slow->next;
		}
		printf("Middle Element Data: %d", slow->data);
	}
}

int main()
{
	// Initializing
	struct Node* head = NULL;
	struct Node* second = NULL;
	struct Node* third = NULL;

	head = malloc(sizeof(struct Node));
	second = malloc(sizeof(struct Node));
	third = malloc(sizeof(struct Node));
	
	// Assigning data
	head->data = 10;
	second->data = 20;
	third->data = 30;

	// Linking Nodes
	head->next = second;
	second->next = third;
	third->next = NULL;

	display(head);
	printf("\n");
	findMiddle(head);
	return 0;
}

