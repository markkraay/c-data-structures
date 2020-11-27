/*
 * Binary heap can be visualised array as complete binary tree
 * Arr[0] element will be treated as root
 * length(A) - size of array
 * heapSize(a) - size of heap
 * Generally used when we are dealing with minimum and maximum elements
 * min heap - root node always less than child
 * max heap - root node always higher than child
 * For ith node
*/ 

/*
 * === Advantages ===
 * Can be of two types: min heap and max heap
 * Min heap keeps smallest and element and top and max keeps largest
 * O(1) for dealing with min or max elements
 *
 * === Disadvantages ===
 * Random access not possible
 * Only min or max element is available for accessiblity
 *
 * === Applications ===
 * suitable for applications dealing with priority
 * Scheduling algorithm 
 * caching
*/

#include <stdio.h>
#include <stdlib.h>

int c, heapsize;
void max_heapify(int a[], int i)
{
	int l, r, largest, temp;
	l = 2 * i;
	r = 2 * i + 1;
	if (l <= heapsize && a[l] > a[i])
	{
		largest = l;
	}
	else
	{
		largest = i;
	}
	if (r <= heapsize && a[r] > a[largest])
		largest = r;
	if (largest != i)
	{
		temp = a[largest];
		a[largest] = a[i];
		a[i] = temp;
		max_heapify(a, largest);
	}
}

void build_max_heap(int a[])
{
	int i;
	for (i = c/2; i >= 1; i--)
		max_heapify(a, i);
}

int maximum(int a[])
{
	return a[1];
}

int extract_max(int a[])
{
	int max, temp;
	max = a[1];
	temp = a[1];
	a[1] = a[heapsize];
	a[heapsize] = temp;
	heapsize--;
	max_heapify(a, 1);
	return max;
}


int main()
{
	int i, val, num;
	int a[11] = {0,4,13,2,16, 9, 10, 14, 8, 7};
	heapsize = c = 10;
	build_max_heap(a);
	val = maximum(a);
	printf("\n\n maximum value = %d", val);
	printf("\n display element of max heap priority queue");
	for (i = 1; i <= c; i++)
	{
		printf("%d ", a[i]);
		val = extract_max(a);
		printf("\n extract maximum value = %d", val);
	}
	return 0;
}

