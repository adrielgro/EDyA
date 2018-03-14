#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum boolean {
    FALSE,TRUE
};

enum boolean pilaLlena(int cima, int longitud){
    if(cima == longitud){
        return TRUE;
    }
    else{
        return FALSE;
    }
}

void imprimirPila(char pila[], int longitud)
{
    printf("Pila\n");
    for(int i = longitud-1 ; i >= 0 ; i--)
    {
        printf("|%c|",pila[i]);
        printf(" - %d\n",i);
    } 
}

int main(int argc, char **argv)
{
	int word_size = 0;
	int cima=-1;
	char palabra[256];
	//char palabra;
	
	// Crear la pila
	for(int i=0; i < (sizeof(palabra)/sizeof(char)); i++)
    {
        palabra[i] = ' ';
    }
    
    // Push
    if(pilaLlena(cima+1, (sizeof(palabra)/sizeof(char))))
    {   
        return printf("La pila se encuentra llena, no puede agregar un elemento");
    }
    else{
        printf("Ingresa el texto a agregar en la pila: ");
        
        char nueva_palabra[256];
        fgets(nueva_palabra, 256, stdin);
        word_size = strlen(nueva_palabra)-1;
        
        int l = 0;
        for(int i = 0; i < word_size; i++) {
			if(nueva_palabra[i] != ' ') {
				//printf("%c", nueva_palabra[i]);
				l++;
			}
		}
		
		int old_size = word_size;
		word_size = l;
        
        for (int i = 0; i < old_size; i++) {
			//printf("%c", nueva_palabra[i]);
			if(nueva_palabra[i] != ' ') {
				palabra[++cima] = toupper(nueva_palabra[i]);
			}
		}
    }
    
    //imprimirPila(palabra, sizeof(palabra)/sizeof(char));
    
    for(int i=0; i < word_size/2; i++) {
		//printf("%c - %c\n", palabra[i], palabra[word_size-i-1]);
		if(palabra[i] != palabra[word_size-i-1]) {
			printf("No es palindromo");
			return 0;
		}
	}
	printf("Es palindromo");
	
	return 0;
}


