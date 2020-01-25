#ifndef Trie

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define NUM_LETTERS ((int) 26)
typedef enum {FALSE=0, TRUE=1} boolean;
#define Line 256

// struct node
typedef struct node
{ 
char letter;                                // the letter
long unsigned int count;                    // the number of times the sign have been shown
struct node* children[NUM_LETTERS];         // pointer to the array of the children (26-alphabet num)
boolean last;                               // boolean variable- to know if this is the last letter of the word
} node;

char toLowerCase(char c);
node *getNode();
void insert(node **root, char *word);
void DeleteTrie(node **root);
void printWord(node **head, char word[], int height);
void printReverse(node **head, char word[], int height);

#endif