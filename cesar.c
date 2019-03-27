#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int FindIndex( char a[], int size, char value );

int main (int argc, char *argv[]) 
{

	FILE *f;
	int c;

	// Inicia o alfabeto
	char alfabeto[62] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'}; 

	// Coeficiente para cifra
	int k = atoi(argv[2]);

	f = fopen(argv[3], "r");	

	while ((c = fgetc(f)) != EOF) {

		char chare = (char) c;

		int index = FindIndex(alfabeto, 62, chare);

		char nextChar;

		if (index == -1) 
			nextChar = chare;

		else if (strcmp(argv[1], "c")) 
			nextChar = alfabeto[(index + k) % 62];
		
		else if (strcmp(argv[1], "d")) 
			nextChar = alfabeto[abs(index-k) %62];

		printf("%c", nextChar);
	}

	fclose(f);

	printf("\n");
	
	return 0;
}

int FindIndex( char a[], int size, char value )
{
    int index = 0;

    while ( index < size && a[index] != value ) ++index;

    return ( index == size ? -1 : index );
}
