#include <stdio.h>
int main()
{
	int rows;
	printf("Enter Triangle Number Pattern Rows = ");
	scanf("%d", &rows);
	printf("Printing Triangle Number Pattern\n");
	for (int i = 1; i <= rows; i++)
	{
		for (int j = rows; j > i; j--)
		{
			printf(" ");
		}
		for (int k = 1; k <= i; k++)
		{
			printf("%d ", k);
		}
		printf("\n");
	}
}
