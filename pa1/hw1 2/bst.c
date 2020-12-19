g7i#include <stdio.h>
#include <stdlib.h>


struct node{
    int data;
    struct node * left;
    struct node * right;
};

 struct node *root = NULL;

int findNode(struct node * root, int target){
    if(root == NULL)
    return 0;

if(root->data == target){
        return 1;
    }

    if(root -> data > target){
    return findNode( root -> left, target );
    }

    findNode( root -> right, target);

    return 0;
}

void insert(int value){
    if(root == NULL){
        root = malloc(sizeof(struct node *) * 3 );
        root -> data = value;
        root -> left = NULL;
        root -> right = NULL;
    }else{
      struct node * ptr = root;

      while(ptr != NULL){
          if(ptr -> data  > value){
                   if(ptr -> left == NULL){
                        ptr -> left = malloc(sizeof(struct node *) * 3 );
                        ptr -> left -> data = value;
                        ptr -> left -> left = NULL;
                        ptr -> left -> right = NULL;
                        break;
                   }else{
                       ptr = ptr-> left;
                   }
          }else if(ptr -> data  < value){
                 if(ptr -> right == NULL){
                        ptr -> right = malloc(sizeof(struct node *) * 3 );
                        ptr -> right -> data = value;
                        ptr -> right -> left = NULL;
                        ptr -> right -> right = NULL;
                        break;
                   }else{
                        ptr = ptr-> right;
                   }
          }
      }
    }
}

void printTree(struct node *root ){

if(root == NULL){

}else{
   printTree(root -> left);
   printf("%d\t", root -> data);;
  printTree(root -> right);
}

}


int main(int argc, char* argv[])
{

    FILE *fp = fopen(argv[1],"r");

 char InsertOrDelete;
   int value;
int count =0;


if(fp == NULL){
printf("error\n");
}else{

   


 char InsertOrDelete;
int value;
int s =1;
while(fscanf(fp,"%c\t%d\n", &InsertOrDelete, &value) == 2) {
s=0;
    
       if(!findNode(root, value)){
           insert(value);
       }

      
}

if(s){
	printf("\n");
	return 0;
}
printTree(root);
printf("\n");
fclose(fp);

}
    

return 0;
}




