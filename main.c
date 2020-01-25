#include "trie.h"

int main(int argc, char* argv[])
{
    node *root = getNode();                         // my root 
    char *word = (char*)malloc(sizeof(char)*Line);  // the word
    int index=0;                                    // index number to fill the word
    int file = Line;                                // allocation file 256
    boolean isReverse = false;                      // if is Reverse mode
    char temp = getchar();                          // the char from the text
    int multi=1;                                    // multiply the alloc

    // check if Print Reverse, or Print regular
    // if is "frequency", or "frequency r"
    if(argc==2 && strcmp(argv[1],"r")==0)
    {
        isReverse=true;
    }
    
    // while i have a text file to read..
    while(temp!=EOF)
    {
        // change to lowercase 
        if(temp >= 'A' && temp <= 'Z'){
            temp += 'a';
        }

        // need to make the array bigger
        if(index==file){
            word=(char*)realloc(word,(Line*multi)*sizeof(char));
        }

        // check if is a proper input
        if(temp>='a' && temp<='z'){
            if(temp !=' ' && temp !='\t' && temp !='\n' && temp !='\0' && temp !='.' && temp!=','){
                if(index!=file){
                    word[index]=temp;
                    index++;
                }
            }
        }

        // end of word 
        if(temp == EOF ||temp ==' ' || temp == '\t' || temp == '\n' || temp == '\0' || temp == '.' || temp == ','){
            word[index] = '\0';
            if(index>=1){
                insert(&root,word);
            }
        }
    }

    // the last check- if is Reverse or not, and print.
    if(isReverse)
    {
        printReverse(&root,word,0);
    } else{
        printWord(&root,word,0);
    }

    // free allocation 
    DeleteTrie(&root);
    free(word);

    return 0;
}
