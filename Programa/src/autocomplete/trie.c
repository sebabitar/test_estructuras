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
  for(int i=0;i<26;i++){
    trie->children[i] = NULL;
  }
  trie->end_of_word = false;
  trie->frequencia = 0;
  return trie;
}


void insert(Trie *root, char *word, int freq)
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
            actual->children[index] = trie_init();
        actual = actual->children[index];
    }
    actual->end_of_word = true;
    actual->frequencia = freq;
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
