#include <stdio.h>
#include <time.h>

int main(int argc, char **argv)
{
	int cola[1000];
	int tiempo = 0;
	#define MAXPERSONAS 10
	
	srand(time(NULL));
    printf("%d\n", rand() % 10 + 1);
	
	
	
	for (int i = 0; i < MAXPERSONAS; i++)
	{
		printf("[%d:00]Personas formadas: ", ++tiempo);
		int input;
		scanf("%d", &input);
		cola[i] = input;
		
		if(input == -1) {
			printf("Fin de la cola.");
			break;
		}
		else if(i == MAXPERSONAS-1) {
			printf("Cola llena.");
			break;
		}
	}
	
	
	
	return 0;
}
