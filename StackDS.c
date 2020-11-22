/*
 *  Linear data structure
 *  LIFO (Last in first out)
 *  Only the top element is accesible
 *  Insertion and deletion take place from the top
 *  4 Operations - All constant time complexity - O(1)
 *  	- push(x) - inserts x at top
 *  	- pop() - removes the top element
 *  	- isEmpty() - returns true if stack is empty
 *  	- peek() - gets the top element of the stack
*/

/*
 * === Advantages ===
 * Maintains data in LIFO manner
 * Last element is ready for use
 * All operations are O(1)
 *
 * === Disadvantages ===
 * Manipulation is restricted to the top of the stack
 * Not much flexibility
 *
 * === Applications ===
 * Recursion
 * Parsing 
 * Browser
 * Editors 
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Stack {
	int top;
	unsigned size;
	int* arr;
};

struct Stack* create(unsigned size)
{
	struct Stack* stack = malloc(sizeof(struct Stack));
	stack->size = size;
	stack->top = -1;
	stack->arr = malloc(stack->size * sizeof(int));
	return stack;
}

int isFull(struct Stack* stack)
{
	return stack->top == stack->size - 1;
}

int isEmpty(struct Stack* stack)
{
	return stack->top == -1;
}

void push(struct Stack* stack, int item)
{
	if (isFull(stack))
		return;
	stack->arr[++stack->top] = item;
}

int pop(struct Stack* stack)
{
	if (isEmpty(stack))
		return -1;
	return stack->arr[stack->top--];
}

int peek(struct Stack* stack)
{
	if (isEmpty(stack))
		return INT_MIN;
	return stack->arr[stack->top];
}

int postfix_evaluator(const char** str_arr, int arr_size)
{	
	struct Stack* stack = create(arr_size);
	for (int i = 0; i < arr_size; i++)
	{
		//printf("%s", str_arr[i]);
		int first = 0;
		int second = 0;
		if (str_arr[i] == "+")
		{
			first = pop(stack);
			second = pop(stack);
			push(stack, first + second);
		}
		else if (str_arr[i] == "-")
		{
			first = pop(stack);
			second = pop(stack);
			push(stack, second - first);
		}
		else if (str_arr[i] == "*")
		{
			first = pop(stack);
			second = pop(stack);
			push(stack, first * second);
		}
		else if (str_arr[i] == "/")
		{
			first = pop(stack);
			second = pop(stack);
			push(stack, second / first);
		}
		else if (str_arr[i] == "==")
		{
			first = pop(stack);
			second = pop(stack);
			push(stack, first == second);
		}
		else
		{
			push(stack, atoi(str_arr[i]));
		}
	}
	return stack->arr[0];
}


int main()
{
	// Basic Functionality
	/*
	struct Stack* stack = create(100);
	push(stack, 10);
	push(stack, 20);
	push(stack, 20);
	printf("%d popped\n", pop(stack));
	printf("%d popped\n", pop(stack));
	(isEmpty(stack)==-1)?printf("Empty"):printf("Not Empty");
	*/

	/*
	 * Postfix Evaluation
	 * 3, 2, + ... evaluates to 3 + 2
	 * Use a stack to solve this problem
	*/

	const char *p[7];
	p[0] = "10";
	p[1] = "2";
	p[2] = "8";
	p[3] = "*";
	p[4] = "+";
	p[5] = "3";
	p[6] = "-";
	printf("%d", postfix_evaluator(p, 7));

	return 0;
}



