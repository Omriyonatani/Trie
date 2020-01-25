#include "trie.h"
#define SIZE_TO_ADD 30


int main(int argc, char* argv[]){

   bool isReverse=false;
   char* word = (char*)malloc(sizeof(char)*256);
   int size=256;
   char* temp=NULL;
   int counter=0;
   int check=0;
   char c=getchar();
   node* root = getNode();

   //check if gonna to print the tree in reverse or straight.
     if(argc==2 && strcmp(argv[1],"r")==0)
     isReverse=true;

     while(c!=EOF || (c==EOF && check!=1)){
         if(c>=65 && c<=90){c=c+32;}

         if(c>=97 && c<=122 && c!=' ' && c!= '\n' && c!='\0' && c!='\t'){
             if(counter==size){
                 temp=(char*)realloc(word,(size+SIZE_TO_ADD)*sizeof(char));
                 size+=SIZE_TO_ADD;
                 if(temp==NULL&& word!=NULL){
                     free(word);
                     return -1;
             } 
                word=(char*)calloc(size,sizeof(char));
                strcpy(word,temp);
                free(temp);
             }
        
             word[counter]=c;
             counter++;
            
             
         }
         if((c==' ' || c=='\n' || c=='\t' || c=='\0') || c==EOF){
             word[counter]='\0';
             if(word[0]!=' ' && counter>=1){
             insert(&root,word);
             }
             counter=0;
         }
        if(c==EOF) check=1;
       c=getchar();
     }

    
   if(isReverse) {
       printR(&root,word,0);
   }
   else {
       print(&root,word,0);
   }
    freeTrie(&root);
    free(word);
   

return 0;
}
