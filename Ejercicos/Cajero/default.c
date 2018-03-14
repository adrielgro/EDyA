#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct fecha {
	unsigned dia, mes, anio;
};

struct tiempo {
	unsigned hh, mm, ss;
};

struct registro_operaciones {
	long cuenta;
	float cantidad;
	int tipo_operacion;
	struct fecha f;
	struct tiempo t;
};

struct registro_operaciones entrada();

int main(int argc, char **argv) {
	struct registro_operaciones arrayCuentas[100];
	
	static const char filename[] = "db.txt";
	FILE *file = fopen(filename,"r");
	if (file != NULL)
	{
		char line[128];
		int i = 0;
		while (fgets(line, sizeof line, file) != NULL) {
			//fputs (line, stdout);
			//printf("%s", line);
			
			
			/*printf("Num. Cuenta: %ld\n", atoll(strtok(line, "|")));
			printf("Tipo Operacion: %d\n", atoi(strtok(NULL, "|")));
			printf("Cantidad: %.2f\n\n", atof(strtok(NULL, "|")));*/
			
			
			arrayCuentas[i].cuenta = atoll(strtok(line, "|"));
			arrayCuentas[i].tipo_operacion = atoi(strtok(NULL, "|"));
			arrayCuentas[i].cantidad = atof(strtok(NULL, "|"));
			
			//printf("Cuenta: %ld\n", arrayCuentas[i].cuenta);
			i++;
		}
		fclose (file);
	}
	else {
		perror( filename);
	}
	
	struct registro_operaciones w;
	w = entrada();
	
	printf("\tNum. Cuenta: %ld\n", w.cuenta);
	
	switch(w.tipo_operacion) {
		case 1:
			printf("\tTipo Operacion: Deposito\n");
			printf("\tDeposito: $%.2f\n", w.cantidad);
			break;
		case 2:
			printf("\tTipo Operacion: Retiro\n");
			printf("\tRetiro: $%.2f\n", w.cantidad);
			break;
		case 3:
			printf("\tTipo Operacion: Estado de cuenta\n");
			printf("\tCantidad actual: $%.2f\n", w.cantidad);
			break;
		default:
			break;
	}
	
	FILE *f = fopen("db.txt", "a");
	if (f == NULL)
	{
		printf("Error al abrir archivo!\n");
		exit(1);
	}
	
	fprintf(f, "%ld|%d|%.2f;", w.cuenta, w.tipo_operacion, w.cantidad);
	
	
	//printf("\tFecha: %d-%d-%d", w.f.dia, w.f.mes, w.f.anio);
	//printf("\tHora: %d:%d", w.t.hh, w.t.mm);
	
	return 0;
}

struct registro_operaciones entrada() {
	//struct tiempo t;
	struct fecha f;
	struct registro_operaciones una;
	int op = 0;
	
	printf("Dame un numero de cuenta: ");
	scanf("%ld", &una.cuenta);
	
	
	
	while(op < 1 || op > 3) {
		printf("1.-Deposito\n");
		printf("2.-Retiro\n");
		printf("3.-Estado de cuenta\n\n");
		
		printf("Operaciones que desea realizar: ");
		scanf("%d", &op);
	}
	una.tipo_operacion = op;
	
	switch(op) {
		case 1:
			printf("Inserta la cantidad de deposito: ");
			scanf("%f", &una.cantidad);
			break;
		case 2:
			printf("Inserta la cantidad a retirar: ");
			scanf("%f", &una.cantidad);
			break;
		case 3:
			printf("==========[Estado de cuenta]==========");
			break;
		default:
			break;
	}
	printf("\nOperacion realizada.\n\n");
	
	struct tm *tiempo;
	time_t fecha_sistema;
	time(&fecha_sistema);
	tiempo=localtime(&fecha_sistema);
	
	f.dia = tiempo->tm_mday;
	f.mes = tiempo->tm_mon + 1;
	f.anio = tiempo->tm_year + 1900;

	return una;
};

