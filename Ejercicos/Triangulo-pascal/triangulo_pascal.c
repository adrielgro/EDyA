#include <stdio.h>

int main(int argc, char **argv)
{
	int n = 8;
	int pascal[n][n];
	int p = 1;
	
	for (int i = 0; i < n; i++)
	{
		int j = 0;
		for (j = 0; j < (n-i)/2; j++)
		{
			pascal[i][j] = 0;
		}
		
		for (int k = 0; k <= i; k++)
		{
			pascal[i][j++] = p;
		}
		
		for (int l = 0; l < n/2; l++)
		{
			pascal[i][j++] = 0;
		}
		p++;
	}
	
	// Imprimir matriz
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n+1; j++)
		{
			printf("%d", pascal[i][j]);
		}
		printf("\n");
	}
	
	
	return 0;
}

