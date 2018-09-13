/*
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "trie.h"

// Esta linea permite usar MAX_LENGTH como una constante en el programa
// Uso 101 para considerar el caracter que indica el fin de un string
#define MAX_LENGTH 101

int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		printf("Modo de uso: ./solver [database.txt] [queries.txt] [output.txt]\n");
		return 0;
	}
	FILE *database = fopen(argv[1], "r");
	FILE *queries  = fopen(argv[2], "r");
	FILE *output   = fopen(argv[3], "w");

	if (!database || !queries || !output)
	{
		printf("¡Error abriendo los archivos!");
		return 2;
	}

	//// Ejemplo de lectura de strings:
	Trie *trie = trie_init();

	// Leo el numero de entradas en la base de datos
	int n;
	fscanf(database, "%d", &n);

	// Para cada entrada:
	for (int i = 0; i < n; i++)
	{
		// Obtengo la frecuencia y el largo
		int freq, length;
		// Ojo que incluyo un espacio en el formato para que no lo considere como parte del string
		fscanf(database, "%d %d ", &freq, &length);
		printf("freq = %d, length = %d\n", freq, length);

		// Leo el string aprovechando que se el largo maximo
		char chars[MAX_LENGTH];
		fgets(chars, MAX_LENGTH, database);
		printf("%s\n", chars);

		insert(trie, chars, freq);

	}
	int m;
	fscanf(queries, "%d", &m);

	for (int i = 0; i < m; i++) {
		int length;
		fscanf(queries, "%d", &length);
		char chars[MAX_LENGTH];
		fgets(chars, MAX_LENGTH, queries);
		char * respuesta;
		if (length == 0){
			continue;
			//respuesta = mas_popular(trie);
		}
		else {
			respuesta = search(trie, chars);
			printf("me salio: %s\n", respuesta);
		}
		fprintf(output, "%s\n", respuesta);
	}
	destroy(trie);
	fclose(database);
	fclose(queries);
	fclose(output);
	return 0;
}

*/




#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "trie.h"
#define ARRAY_SIZE(a) sizeof(a) / sizeof(a[0])

// Esta linea permite usar MAX_LENGTH como una constante en el programa
// Uso 101 para considerar el caracter que indica el fin de un string

int main()
{
	Trie *trie = trie_init();
	char keys[][8] = { "the", "a", "there", "answer",
                       "any", "by", "bye", "their" };


  // Inserting keys in Trie
  for (int j = 0; j < ARRAY_SIZE(keys); j++)
      insert(trie, keys[j], 5);

  char * str;
	char key[20] = "th";
	str = search(trie, key);

	printf("%s\n", str);



	destroy(trie);
	return 0;
}
