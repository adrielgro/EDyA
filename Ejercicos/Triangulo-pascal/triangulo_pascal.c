#include <stdio.h>

int factorial(int n) {
	if(n < 2)
		return 1;
	else
		return n * factorial(n-1);
}

int combinacion(int n, int r) {
	if(r == 1)
		return n;
	else {
		if(n == r)
			return 1;
		else
			return factorial(n) / (factorial(r) * factorial(n - r));
	}
}

int main(int argc, char **argv)
{
	/*int n = 8;
	int pascal[n][n];
	int p = 1;*/
	
	int n;
	printf("Altura del triangulo: ");
	scanf("%i", &n);
	printf("\n\n");

	for(int i = 0; i <= n; i++) {
		for(int j = 1; j < (n-i)+1; j++)
			printf(" ");
			
		for(int k = 0; k <= i; k++)
			printf	(" %d ", combinacion(i, k));
			
		printf("\n\n");
	}
	printf("\n\n");
	
	
	
	/*
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
	}*/
	
	return 0;
}


