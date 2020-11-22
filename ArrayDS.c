#include <stdio.h>


void bin(unsigned n)
{
	unsigned i;
	for (i = 1 << 31; i > 0; i = i / 2)
		(n & i) ? printf("1") : printf("0");
	printf("\n");
}

int main()
{
	int arr[11] = {1,6,2,3,1,3,5,5,4,2,6};
	int res = 0;
	for (int i = 0; i < 11; i++)
	{
		bin(arr[i]);
		bin(res);
		res = res ^ arr[i];
		bin(res);
		printf("\n");
	}
	printf("\n%d", res);
	return 0;
}

