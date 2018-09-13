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
    actual->frequencia = freq;
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
    if (!actual->children[index])
        return word;
    actual = actual->children[index];
  }
  //reviso si la palabra es la mejor
  if (actual->end_of_word){
    bool termine = true;
    for (int j = 0; j < 27; j++){
      if (actual->children[index]){
        if (actual->children[index]->freq_max >= actual->freq_max)
          termine = false;
      }
    }
    if (termine)
      return word;
  }
  char letra[100] = {0};
  bool end = false;
  int k;
  int m = 0;
  while (!end) {
    for (k = 0; k < 27; k++){
      if (actual->children[k]){
        if (actual->children[k]->freq_max == actual->freq_max) {
          printf("la posicion es %d\n", k);
          if (k == 26) {
            letra[m] = ' ';
          } else {
            if (k == 0){
              letra[m] = 'a';
            } else {
              letra[m] = 'a' + k;
              printf("%c\n", letra[m]);
            }
          }
          letra[m+1] = '\0';
          actual = actual->children[k];
          m ++;
          break;
          }
        }
      }
      if (k == 26){
        end = true;
        printf("la variable letra tiene: %s. nose que onda\n", letra);
        strcat(word, letra);
        break;
      }
    }


  printf("%s\n", word);
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


bool isLeafNode(Trie *root)
{
    return root->end_of_word != false;
}

void display(Trie *root, char str[], int level)
{
    // If node is leaf node, it indiicates end
    // of string, so a null charcter is added
    // and string is displayed
    if (isLeafNode(root))
    {
        str[level] = '\0';
        printf("%s\n", str);
    }

    int i;
    for (i = 0; i < 27; i++)
    {
        // if NON NULL child is found
        // add parent key to str and
        // call the display function recursively
        // for child node
        if (root->children[i])
        {
            str[level] = i + 'a';
            display(root->children[i], str, level + 1);
        }
    }
}
