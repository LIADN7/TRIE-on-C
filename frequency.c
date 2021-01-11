#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define NUM_LETTERS ((int)26)
#define LINE 256



typedef struct node {
    char letter;
    bool flag;
    int count;
    struct node* children[NUM_LETTERS];

}node;


node* newNode(char c){
    node *temp= (node*)malloc(sizeof(node));
    temp->letter = c;
    temp->flag=false;    
    for(int i=0;i<26;i++)
        temp->children[i]=NULL;
    return temp;
}


void insert(node *head, char* str)
{
    // start from root node
    node* p = head;
    int end = strlen(str);
    for(int i =0;i<end;i++){
        char c=*(str+i);
        // create a new node if path doesn't exists
        if (p->children[c - 'a'] == NULL){
            p->children[c - 'a'] = newNode(c);
        }
        // go to next node
        p = p->children[c - 'a'];
 
        
    }
    p->flag = true;
    p->count++;
}



void display(node *root, char str[], int level) { 
    if (root->flag)  { 
        str[level] = '\0'; 
        printf("%s %d\n",str , root->count);
    } 
  
    for (int i = 0; i < NUM_LETTERS; i++)  {  
        if (root->children[i])  { 
            str[level] = i + 'a'; 
            display(root->children[i], str, level + 1); 
        } 
    } 
} 


void displayR(node *root, char str[], int level) { 
    if (root->flag)  { 
        str[level] = '\0'; 
        printf("%s %d\n",str , root->count);
    }  
  
    for (int i = NUM_LETTERS-1; i >= 0; i--)  {  
        if (root->children[i])  { 
            str[level] = i + 'a'; 
            displayR(root->children[i], str, level + 1); 
        } 
    } 

}


void trieFree(node *root){
    if(root != NULL){
        for(int i = 0; i < NUM_LETTERS; i++){
            if(root->children[i] != NULL){
                trieFree(root->children[i]);
            }
        }
        free(root);
    }
}

int main(int argc, char const *argv[]){
    char buffer[LINE];
    node* root = newNode('!');

    while(fgets(buffer, LINE, stdin) != NULL){
        int end = strlen(buffer);
        for(int j=0; j < end; j++){
            char c [LINE];
            int i = 0;
            while((*(buffer+j) >= 'a'&&*(buffer+j) <= 'z')||(*(buffer+j) >= 'A'&&*(buffer+j) <= 'Z')){
                char tempLow = tolower(*(buffer+j));
                c[i] = tempLow;
                j++;
                i++;
            }
            while(*(buffer+j) < 'a'||*(buffer+j) > 'z'){
                j++;
            }
            j--;
            c[i] = '\0';
            insert(root, c);
        }

    }
    char st[]="" ;
    if(argc>1){
        char strs = argv[1][0];     
        if(strs == 'r' && strlen(argv[1])==1){
            displayR(root,st,0);
        }
        else
            printf("%s is a wrong argoment",argv[1]);
    }
    else
        display(root,st,0);
    
    trieFree(root);
    return 0;
}















