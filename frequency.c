#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


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


void insert(struct node *head, char* str)
{
    // start from root node
    struct node* p = head;
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


/*
void printAll(struct node *root){  
    for(int j=0;j<26;j++){
        char st[]="" ;
        printAllRec(root->children[j],st);
    }

}
*/
void printAllRec(struct node *root, char* s,int level){
    //printf("%d \n", level);
    if(root==NULL)
        return;
    char c = root->letter;
    if(c!='!'){
       strncat(s, &c,1); 
    }
    
    
    if(root->flag){
        printf("%s %d\n",s, root->count);

        s[level]='\0';
        level++;       
    }
    
    for(int j=0;j<26;j++)
        printAllRec(root->children[j],s,level);

    
}


int main(){
    char buffer[LINE];
    //int len = 0;
    struct node* root = newNode('!');

    while(fgets(buffer, LINE, stdin) != NULL){
        printf("%s\n",buffer);
        int end = strlen(buffer);
        for(int j=0; j < end; j++){
            char c [LINE];
            int i = 0;
            while(*(buffer+j) >= 'a'&&*(buffer+j) <= 'z'){
                c[i] = *(buffer+j);
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
    printAllRec(root,st,0);

    free(root);
    return 0;
}















