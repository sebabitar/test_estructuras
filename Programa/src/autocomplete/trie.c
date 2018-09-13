#include "trie.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Definir funciones aca
//Basado en codigo de:
// https://www.geeksforgeeks.org/trie-insert-and-search/
// https://gist.github.com/cijogeorge/20b41a0dc7385fbc58c93d2e7837c5ee


#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

Trie *trie_init()
{
  Trie * trie=(Trie*) malloc(sizeof(Trie));
  for(int i=0;i<27;i++){
    trie->children[i] = NULL;
  }
  trie->end_of_word = false;
  trie->frequencia = 0;
  trie->freq_max = 0;
  return trie;
}


void insert(Trie *root, char *word, int freq)
{
    int length = strlen(word);
    int index;
    Trie *actual = root;

    if (freq > root->freq_max){
      root->freq_max = freq;
    }
    for (int i = 0; i < length; i++)
    {
        if (word[i] == ' '){
          index = 26;
        } else {
          index = CHAR_TO_INDEX(word[i]);
        }
        if (!actual->children[index])
            actual->children[index] = trie_init();
        actual = actual->children[index];
        if (freq > actual->freq_max){
          actual->freq_max = freq;
        }
    }
    actual->end_of_word = true;
}

char * search(Trie *root, char *word)
{
  int length = strlen(word);
  int index;
  Trie *actual = root;
  for (int i = 0; i < length; i++)
  {
    if (word[i] == ' '){
      index = 26;
    } else {
      index = CHAR_TO_INDEX(word[i]);
    }
    if (!(actual->children[index])){

      printf("really nigga: %d \n", index);
      return word;
    }
    actual = actual->children[index];
  }
  //reviso si es palabra y si es la mejor
  if (actual->end_of_word){
    bool termine = true;
    for (int j = 0; j < 27; j++){
      if (actual->children[j]){
        if (actual->children[j]->freq_max == actual->freq_max){
          termine = false;
          break;
        }
      }
    }
    if (termine)
      //printf("aqui!!!!\n");
      return word;
  }
  char letra[2];
  bool end = false;
  int k;
  letra[0] = '\0';
  while (!end) {
    for (k = 0; k < 27; k++){
      printf("%d\n", k);
      if (actual->children[k]){
        if (actual->children[k]->freq_max == actual->freq_max) {
          //si entramos, agregamos la letra a la palabra
          //printf("NONONOONOONO\n");
          if (k == 26) {
            letra[0] = ' ';
          } else {
            letra[0] = 'a' + k;
          }
          letra[1] = '\0';
          strcat(word, letra);
          actual = actual->children[k];
          break;
        }
      }
      //no tiene hoja util, estamos en la palabra con mas freq
      if (k == 26){
        end = true;
        break;
      }
    }
  }
  return word;
}

char * mas_popular(Trie *root)
{
  Trie *actual = root;
  char *word;
  char letra[100];
  bool end = false;
  int k;
  int m = 0;
  letra[0] = '\0';
  while (!end) {
    for (k = 0; k < 27; k++){
      if (actual->children[k]){
        if (actual->children[k]->freq_max == actual->freq_max) {
          //si entramos, agregamos la letra a la palabra
          if (k == 26) {
            letra[m] = ' ';
          } else {
            letra[m] = 'a' + k;
          }
          letra[m+1] = '\0';
          actual = actual->children[k];
          m ++;
          break;
        }
      }
      //no tiene hoja util, estamos en la palabra con mas freq
      if (k == 26){
        end = true;
        break;
      }
    }
  }
  word = letra;
  return word;
}

void destroy(Trie *root)
{
  for (int i = 0; i < 27; i++){
    if (root->children[i]){
      destroy(root->children[i]);
    }
  }
  free(root);
}
