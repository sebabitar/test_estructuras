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

	int level = 0;
  char str[20];
	display(trie, str, level);

	destroy(trie);
	return 0;
}
