#include "trie.h"

// function to cast uppercase letter to lowercase.
char toLowerCase(char c)
{
    if(c >= 'A' && c <= 'Z'){
        c += 32;
    }
    return c;
}



// Returns new trie node (initialized to NULLs)
node *getNode()
{
    node *aloc = (node*)malloc(sizeof(node));
    aloc->last=false;
    aloc->count=0;

    for(int i=0; i<NUM_LETTERS; i++)
    {
        aloc->children[i] = NULL;
    }

    return aloc;
}



// function to insert a word to the trie tree, letter by letter.
void insert(node **root, char *word)
{
    int index=0;
    int len=strlen(word);
    node *temp = *root;
    char c;                             // the letter
    char t;                             // Letter after casting
    int CI;                             // CHAR INDEX
    int height=0;

    for(int i=0; i<len; i++)
    {
        c=word[i];                      // takes the word letter by letter
        t= toLowerCase(c);              // cast the letter to lower case
        CI=(int)t -(int)'a';            // cast from char to the index of char in the array


        for(int j=0; j<height;j++)
        {
            if(!temp->children[CI]){
                temp->children[index] = getNode();
                temp->children[index]->letter = word[height];
            }
            temp=temp->children[index];
        }
        temp->last=true;
        temp->count++;
    }
}



// Recursive function to delete trie and free the memory.
void DeleteTrie(node **root)
{
    node *delete = *root;

    for(int i=0; i<NUM_LETTERS; i++)
    {
        if(delete->children[i] != NULL)
        {
            DeleteTrie(&(delete->children[i]));
        }
    }
    free(delete);
}


// Recursive function to print the word with the count of times that appear
void printWord(node **head, char word[], int height)
{
    node *check= *head;
    // No word
    if(check == NULL)
    {
        return;
    }
    // if End of String
    if(check->last)
    {
        word[height] = '\0';
        printf("%s \t,%ld \n", word, check->count);
    }
    // the recursice call, to print all the letters.
    for(int i=0; i<NUM_LETTERS; i++)
    {
        if(check->children[i])
        {
            word[height] = i+ 'a';     // from index to letter.
            printWord(check->children[i], word, height+1);
        }
    }
}



// Recursive function to print the word REVERSE with the count of times that appear
void printReverse(node **head, char word[], int height)
{
    node *check= *head;
    // No word
    if(check == NULL)
    {
        return;
    }
    // if End of String
    if(check->last)
    {
        word[height] = '\0';
        printf("%s \t,%ld \n", word, check->count);
    }
    // the recursice call, to print all the letters.
    for(int i=NUM_LETTERS; i>=0; i--)
    {
        if(check->children[i])
        {
            word[height] = i+ 'a';     // from index to letter.
            printReverse(check->children[i], word, height+1);
        }
    }
}
