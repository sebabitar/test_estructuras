#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// Definir struct aca

typedef struct trie Trie;

// Headers de funciones aca

struct trie
{
  struct trie *children[27]; //cantidad de palabras en el abecedario + espacio
  bool end_of_word;
  int frequencia;
  int freq_max;
};

Trie *trie_init();

void insert(Trie *root, char *word, int freq);

void destroy(Trie *root);

char * search(Trie *root, char *word);

char * mas_popular(Trie *root);
