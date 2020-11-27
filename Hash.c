/*
 * Uses special hash function
 * Hash function maps element to a address for storage
 * This provides constant time access
 * Collision is handled by collision resolution techniques
 * Collision resolution technique
 * 	Chaining - Linked list
 * 	Open addressing
 * 		Linear
 * 		Quadratic
 * 		Double hash
*/

/*
 * === Advantages ===
 * Hash function helps in fetching elements in a constant time
 * Efficient way to store elements
 *
 * === Disadvantages ===
 * Collision resolution increases complexity
 *
 * === Applications ===
 * Suitable for applications that need constant time for fetching
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 10

struct Item
{
	int data;
	int key;
};

struct Item* hashArray[SIZE];
struct Item* d_Item;
struct Item* item;

int hashCode(int key)
{
	return key % SIZE;
}

struct Item *search(int key)
{
	int hashvalue = hashCode(key);
	while(hashArray[hashvalue] != NULL)
	{
		if (hashArray[hashvalue]->key == key)
		{
			return hashArray[hashvalue];
		}
		hashvalue++;
		hashvalue %= SIZE;
	}
	return NULL;
}

void insert(int key, int data)
{
	struct Item* item = malloc(sizeof(struct Item));
	item->data = data;
	item->key = key;
	int hashvalue = hashCode(key);
	while (hashArray[hashvalue] != NULL && hashArray[hashvalue]->key != -1)
	{
		++hashvalue;
		hashvalue %= SIZE;
	}
	hashArray[hashvalue] = item;
}

struct Item* delete(struct Item* item)
{
	int key = item->key;
	int hashvalue = hashCode(key);
	while (hashArray[hashvalue] != NULL)
	{
		if (hashArray[hashvalue]->key == key)
		{
			struct Item* temp = hashArray[hashvalue];
			hashArray[hashvalue] = d_Item;
			return temp;
		}
		++hashvalue;
		hashvalue %= SIZE;
	}
	return NULL;
}

int main()
{
	d_Item = malloc(sizeof(struct Item));
	d_Item->data = -1;
	d_Item->key = -1;
	insert(1, 20); insert(2, 70);
	insert(42, 80); insert(4,25);
	insert(12, 44); insert(14, 32);
	insert(17, 11); insert(13, 78);
	insert(37, 97); insert(1, 1);


	item = search(37);
	if (item != NULL)
	{
		printf("Element found: %d\n", item->data);
	}
	else
	{
		printf("Element not found\n");
	}
	delete(item);
	item = search(37);
	if (item != NULL)
	{
		printf("Element found: %d", item->data);
	}
	else
	{
		printf("Element not found\n");
	}

	return 0;
}




