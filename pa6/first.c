#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

 typedef struct linkedList{

   char variableName[256];
   struct linkedList *next;
   int val;

}linkedList;

void freeList(struct linkedList * temp){
    struct linkedList * head;

    while(temp != NULL){
        head = temp;
     temp=temp->next;
     free(head);
    }

}



 /*struct linkedList * addNode(struct linkedList * tempList, char * name, int val){

   

        struct linkedList * temp = malloc(sizeof(struct linkedList *) * 3 );
        temp->next = NULL;
        strcpy(temp->variableName,name);
        temp->val = val;

          return temp;

}*/

struct linkedList * addNodetotheEnd(struct linkedList * tempList, char * name, int val){

   

        struct linkedList * temp = (struct linkedList *) malloc(sizeof(struct linkedList) );
        
       strcpy(temp->variableName,name);
        temp->next = NULL;
        temp->val = val;

        if(tempList == NULL){
            tempList = temp;
              return tempList;
        }

         linkedList * tempList2 = tempList;
       

          while(tempList2->next != NULL){
              tempList2=tempList2->next;
          }
          tempList2->next = temp;

          return tempList;




}

struct linkedList * addNodetotheEnd2(struct linkedList * tempList, char * name, int val){

   

        struct linkedList * temp = (struct linkedList *) malloc(sizeof(struct linkedList) );
        
           
        temp->next = NULL;
      
        strcpy(temp->variableName,name);
   
        temp->val = val;

  //printf("%d", temp->variableName == name);
        if(tempList == NULL){
            tempList = temp;
              return tempList;
        }

         linkedList * tempList2 = tempList;
       

          while(tempList2->next != NULL){
              tempList2=tempList2->next;
          }
          tempList2->next = temp;

          return tempList;



}


struct linkedList * combineLists(struct linkedList * tempList, struct linkedList * tempList3){
      linkedList * tempList2 = tempList;

          while(tempList2->next != NULL){
              tempList2=tempList2->next;
          }
          tempList2->next = tempList3;

          return tempList;


}

int stringEquals(char * target, char * target2){

   

    for(int i=0;i <strlen(target); i++ ){
        printf("%c%c\n",target[i],target2[i]);
        if(target[i] != target2[i]){
            return 0;
        }
    }
    

    return 1;
}

 int searchForVal (struct linkedList * tempList, char target[256]){

   linkedList * temp = tempList;
   while(temp != NULL){

   // printf("%s %s %d\n",target,temp->variableName,strcmp(temp->variableName, target));

//printf("%s:%d ",temp->variableName,temp->val);
       
      if(  strcmp(temp->variableName, target) == 10 || strcmp(temp->variableName, target) == 0){
           return 1;
       }
       
       
      
        temp = temp->next;
   }

//printf("\n");




   return 0;
   

}

struct linkedlist * clear(struct linkedList * tempList){
    free(tempList);
    return NULL;
}


int main(int argc, char* argv[]){

   FILE *fp1 = fopen(argv[1],"r");


if(fp1  == NULL){
        
    return 0;
}


int i=0;

char hello[256];
char hello2[256];
char hello3[256];
char hello4[256];

fgets( hello,256,fp1);
fgets( hello2,256,fp1);

 char * str  = strtok(hello,"  ");
str = strtok(NULL, "  ");


int input = atoi(str);
str = strtok(NULL, "  ");

 char * str2  = strtok(hello2,"  ");
str2 = strtok(NULL, "  ");

int output = atoi(str2);
str2 = strtok(NULL, "  ");



  struct linkedList * values[(unsigned long int)pow(2,input)];

  for(int j=0; j <(unsigned long int)pow(2,input); j++ ){
      values[j]=NULL;
      
  }

 char * delimiters= " \n\t\0";
  struct linkedList * values2[( int)pow(2,input)];

  for(int j=0; j <( int)pow(2,input); j++ ){
      values2[j] = NULL;
  }

int num  =0;

rewind(fp1);



for(int j=0; j <(unsigned long int)pow(2,input); j++ ){

    


fgets( hello,256,fp1);
 char * str  = strtok (hello, delimiters);
str = strtok (NULL, "  ");
str = strtok (NULL, "  ");



  int l=input-1;
 int i=0;
    while(str!=NULL){
 
     //  printf("%s ",str);
        values2[j] = addNodetotheEnd2(values2[j],str,(num >> l) & 1);
               str = strtok (NULL, delimiters);

            i++;   
        l--;
    }
//printf("\n");
num++;



fgets( hello2,256,fp1);
 char * str2  = strtok (hello2, delimiters);
str2 = strtok (NULL, delimiters);
str2 = strtok (NULL, delimiters);


   
    //int p=0;
    while(str2 != NULL){
     
      values[j] = addNodetotheEnd(values[j],str2,0);
         str2 = strtok(NULL, delimiters);
      
       /* if(p == output-2){
            str2[strlen(str2)-1] = '\0';

        }

       p++;*/
    }
    
  

 
    
 
   // printf("\n");

     /*for(int j=0; j <(unsigned long int)pow(2,input); j++ ){

      for(struct linkedList * temp12 = values2[j]; temp12 != NULL; temp12 =  temp12->next){
          printf("%d ", temp12->val);
      }

     
      
  }*/
  

    

   rewind(fp1);

   
   
}

     rewind(fp1);


      struct linkedList * temp = NULL;

  for(int j=0; j <(unsigned long int)pow(2,input); j++ ){

      char he[256];
      while(fgets(he,256,fp1)){
         
          if(strstr(he, "INPUTVAR") != NULL){
                continue;
          }else if (strstr(he, "OUTPUTVAR") != NULL){
               continue;
          }else if (strstr(he, "NOT") != NULL){
 
               char * str3  = strtok (he, delimiters);
              
              str3 = strtok (NULL, delimiters);
              char * input1 = str3;
                
                 str3 = strtok (NULL,delimiters);
                      char * output1 = str3;

            
       

               if(searchForVal(values2[j], input1)){
                
               

                  for (linkedList * tempList = values2[j]; tempList != NULL; tempList = tempList -> next){
       
       if(strcmp(tempList -> variableName,input1) ==0 || strcmp(tempList -> variableName,input1) == 10 ){


  if(searchForVal(values[j], output1)){

 
       for (linkedList * tempList2 = values[j]; tempList2 != NULL; tempList2 = tempList2 -> next){

          if(strcmp(tempList2 -> variableName,output1)  ==0 || strcmp(tempList2 -> variableName,output1) == 10){
              tempList2->val = !(tempList->val);
          }
       }
 
  }else if(searchForVal(temp,output1)){
      
    for (linkedList * tempList2 = temp; tempList2 != NULL; tempList2 = tempList2 -> next){

          if(strcmp(tempList2 -> variableName,output1)==0 || strcmp(tempList2 -> variableName,output1) ==0){
             

             // printf("%d",tempList -> val);
              tempList2->val =!(tempList->val);
          }
       }

  }else{



temp = addNodetotheEnd(temp,output1,!(tempList->val));
  }


       }
                  }








//remeber this is the one




               }else{


                        for (linkedList * tempList = temp; tempList != NULL; tempList = tempList -> next){

       if(strcmp(tempList -> variableName,input1)==0 || strcmp(tempList -> variableName,input1)==10){

  if(searchForVal(values[j],output1)){


       for (linkedList * tempList2 = values[j]; tempList2 != NULL; tempList2 = tempList2 -> next){

          if(strcmp(tempList2 -> variableName,output1)==0 || strcmp(tempList2 -> variableName,output1)==10){
              tempList2->val = !(tempList->val);
          }
       }
 
  }else if(searchForVal(temp, output1)){
    for (linkedList * tempList2 = temp; tempList2 != NULL; tempList2 = tempList2 -> next){

          if(strcmp(tempList2 -> variableName,output1)==0 || strcmp(tempList2 -> variableName,output1)==10){
              tempList2->val =!(tempList->val);
          }
       }

  }else{

printf("%s",output1);


temp = addNodetotheEnd(temp,output1,!(tempList->val));
  }


       }
                  }









               }








          }else{
            
       
              char * str3  = strtok (he, delimiters);
              
              str3 = strtok (NULL, delimiters);
              char * input1 = str3;
                
                 str3 = strtok (NULL, delimiters);
              char * input2 = str3;
              
        
        
                     str3 = strtok (NULL, delimiters);
               char * output = str3;
                  
  
                    

              if(searchForVal(values2[j],input2) && searchForVal(values2[j],input1)){
    
   

                
                   
          for (linkedList * tempList = values2[j]; tempList != NULL; tempList = tempList -> next){

       if(strcmp(tempList -> variableName,input1)==0 || strcmp(tempList -> variableName,input1)==10){
       
            for (linkedList * temp2 = values2[j]; temp2 != NULL; temp2 = temp2 -> next){

       if(strcmp(temp2 -> variableName,input2)==0 || strcmp(temp2 -> variableName,input2)==10 ){
            if(searchForVal(values[j],output)){

                 for (linkedList * temp4 = values[j]; temp4 != NULL; temp4 = temp4 -> next){
                     if(strcmp(temp4 -> variableName,output)==0 || strcmp(temp4 -> variableName,output)==10){
                    
                     if(strcmp(he, "NAND") == 0){
                         temp4 -> val = !(tempList -> val && temp2 -> val);
                   }else if(strcmp(he, "OR") == 0){
                          temp4 -> val = tempList -> val || temp2 -> val;
                   }else if(strcmp(he,"AND")==0){
                
                          temp4 -> val = tempList -> val && temp2 -> val;
                   }else if(strcmp(he, "NOR") == 0){
                          temp4 -> val = !(tempList -> val || temp2 -> val);
                   }else if(strcmp(he, "XOR") == 0){
                         temp4 -> val = tempList -> val ^ temp2 -> val;
                   }

                     }
                 }








                  
                }else if (searchForVal(temp,output)){




             for (linkedList * temp4 = temp; temp4 != NULL; temp4 = temp4 -> next){
                     if(strcmp(temp4 -> variableName,output) ==0 || strcmp(temp4 -> variableName,output) ==10){

                             if(strcmp(he, "NAND") == 0){
                                  temp4 -> val = !(temp -> val && temp2 -> val);
                    
                   }else if(strcmp(he, "OR") == 0){
                          temp4 -> val = temp -> val || temp2 -> val;
                   }else if(strcmp(he, "AND") == 0){
                              temp4 -> val = temp -> val && temp2 -> val;
                   }else if(strcmp(he, "NOR") == 0){
                          temp4 -> val = !(temp -> val || temp2 -> val);
                   }else if(strcmp(he, "XOR") == 0){
                         temp4 -> val = temp -> val ^ temp2 -> val;
                   }
                     }
                 }
               }else{

                   if(strcmp(he, "NAND") == 0){
                       temp = addNodetotheEnd(temp,output,!(tempList -> val && temp2 -> val));
                     
                   }else if(strcmp(he, "OR") == 0){
                       temp = addNodetotheEnd(temp,output,tempList -> val || temp2 -> val);
                   }else if(strcmp(he, "AND") == 0){
                           temp = addNodetotheEnd(temp,output,tempList -> val && temp2 -> val);
                   }else if(strcmp(he, "NOR") == 0){
                       temp = addNodetotheEnd(temp,output,!(tempList -> val || temp2 -> val));
                   }else if(strcmp(he, "XOR") == 0){
                       temp = addNodetotheEnd(temp,output,tempList -> val ^ temp2 -> val);
                   }

                    


               }
       }
      
   }
       }
      
   }




        





              }else if(searchForVal(values2[j],input1)){

                 
                    





          
          for (linkedList * tempList = values2[j]; tempList != NULL; tempList = tempList -> next){

       if(strcmp(tempList -> variableName,input1) ==0 || strcmp(tempList -> variableName,input1) ==10 ){
            
            for (linkedList * temp2 = temp; temp2 != NULL; temp2 = temp2 -> next){

       if(strcmp(temp2 -> variableName,input2)==0 || strcmp(temp2 -> variableName,input2)==10){
          
            if(searchForVal(values[j],output)){
                     
                 for (linkedList * temp4 = values[j]; temp4 != NULL; temp4 = temp4 -> next){
                     if(strcmp(temp4 -> variableName,output)==0 || strcmp(temp4 -> variableName,output)==10){
                              
                             if(strcmp(he, "NAND") == 0){
                                  temp4 -> val = !(tempList -> val && temp2 -> val);
        
                   }else if(strcmp(he, "OR") == 0){
                          temp4 -> val = tempList -> val || temp2 -> val;
                   }else if(strcmp(he, "AND") == 0){
                                          temp4 -> val = tempList -> val && temp2 -> val;
                   }else if(strcmp(he, "NOR") == 0){
                          temp4 -> val = !(tempList -> val || temp2 -> val);
                   }else if(strcmp(he, "XOR") == 0){
                         temp4 -> val = tempList -> val ^ temp2 -> val;
                   }

                     }
                 }








                  
                }else if (searchForVal(temp,output)){




             for (linkedList * temp4 = temp; temp4 != NULL; temp4 = temp4 -> next){
                     if(strcmp(temp4 -> variableName,output)==0 || strcmp(temp4 -> variableName,output)==10){

                             if(strcmp(he, "NAND") == 0){
                                          temp4 -> val = !(temp -> val && temp2 -> val);
                         
                   }else if(strcmp(he, "OR") == 0){
                          temp4 -> val = temp -> val || temp2 -> val;
                   }else if(strcmp(he, "AND") == 0){
                 temp4 -> val = temp -> val && temp2 -> val;
                   }else if(strcmp(he, "NOR") == 0){
                          temp4 -> val = !(temp -> val || temp2 -> val);
                   }else if(strcmp(he, "XOR") == 0){
                         temp4 -> val = temp -> val ^ temp2 -> val;
                   }
                     }
                 }
               }else{
  
                 
                   if(strcmp(he, "NAND") == 0){
                       temp = addNodetotheEnd(temp,output,!(tempList -> val && temp2 -> val));
                         
                   }else if(strcmp(he, "OR") == 0){
                       temp = addNodetotheEnd(temp,output,tempList -> val || temp2 -> val);
                   }else if(strcmp(he, "AND") == 0){
                       temp = addNodetotheEnd(temp,output,tempList -> val && temp2 -> val);
                   }else if(strcmp(he, "NOR") == 0){
                       temp = addNodetotheEnd(temp,output,!(tempList -> val || temp2 -> val));
                   }else if(strcmp(he, "XOR") == 0){
                       temp = addNodetotheEnd(temp,output,tempList -> val ^ temp2 -> val);
                   }

                    


               }
       }
      
   }
       }
      
   }















































              }else if(searchForVal(values2[j],input2)){
                  


          for (linkedList * tempList = values2[j]; tempList != NULL; tempList = tempList -> next){

       if(strcmp(tempList -> variableName,input2)==0 || strcmp(tempList -> variableName,input2)==10){
            for (linkedList * temp2 = temp; temp2 != NULL; temp2 = temp2 -> next){

       if(strcmp(temp2 -> variableName,input1)==0 || strcmp(temp2 -> variableName,input1)==10){
            if(searchForVal(values[j],output)){

                 for (linkedList * temp4 = values[j]; temp4 != NULL; temp4 = temp4 -> next){
                     if(strcmp(temp4 -> variableName,output)==0 || strcmp(temp4 -> variableName,output)==10){
                              
                             if(strcmp(he, "NAND") == 0){
                                 temp4 -> val = !(tempList -> val && temp2 -> val);
                        
                   }else if(strcmp(he, "OR") == 0){
                          temp4 -> val = tempList -> val || temp2 -> val;
                   }else if(strcmp(he, "AND") == 0){
                           temp4 -> val = tempList -> val && temp2 -> val;
                   }else if(strcmp(he, "NOR") == 0){
                          temp4 -> val = !(tempList -> val || temp2 -> val);
                   }else if(strcmp(he, "XOR") == 0){
                         temp4 -> val = tempList -> val ^ temp2 -> val;
                   }

                     }
                 }








                  
                }else if (searchForVal(temp,output)){




             for (linkedList * temp4 = temp; temp4 != NULL; temp4 = temp4 -> next){
                     if(strcmp(temp4 -> variableName,output)==0 || strcmp(temp4 -> variableName,output)==10){

                             if(strcmp(he, "NAND") == 0){
                                  temp4 -> val = !(temp -> val && temp2 -> val);
                         
                   }else if(strcmp(he, "OR") == 0){
                          temp4 -> val = temp -> val || temp2 -> val;
                   }else if(strcmp(he, "AND") == 0){
                         temp4 -> val = temp -> val && temp2 -> val;
                   }else if(strcmp(he, "NOR") == 0){
                          temp4 -> val = !(temp -> val || temp2 -> val);
                   }else if(strcmp(he, "XOR") == 0){
                         temp4 -> val = temp -> val ^ temp2 -> val;
                   }
                     }
                 }
               }else{

                   if(strcmp(he, "NAND") == 0){
                               temp = addNodetotheEnd(temp,output,!(tempList -> val && temp2 -> val));
                        
                   }else if(strcmp(he, "OR") == 0){
                       temp = addNodetotheEnd(temp,output,tempList -> val || temp2 -> val);
                   }else if(strcmp(he, "AND") == 0){
                       temp = addNodetotheEnd(temp,output,tempList -> val && temp2 -> val);
                   }else if(strcmp(he, "NOR") == 0){
                       temp = addNodetotheEnd(temp,output,!(tempList -> val || temp2 -> val));
                   }else if(strcmp(he, "XOR") == 0){
                       temp = addNodetotheEnd(temp,output,tempList -> val ^ temp2 -> val);
                   }

                    


               }
       }
      
   }
       }
      
   }



































           
           










              }else{

                 
          for (linkedList * tempList = temp; tempList != NULL; tempList = tempList -> next){


//printf("results:%s %s %d\n",tempList -> variableName,input1,strcmp(tempList -> variableName,input1));
       if(strcmp(tempList -> variableName,input1)==0 || strcmp(tempList -> variableName,input1)==10){
      
            for (linkedList * temp2 = temp; temp2 != NULL; temp2 = temp2 -> next){
             
       if(strcmp(temp2 -> variableName,input2) ==0 || strcmp(temp2 -> variableName,input2) ==10){
 
        
         
            if(searchForVal(values[j],output)){
                           
                           
                 for (linkedList * temp4 = values[j]; temp4 != NULL; temp4 = temp4 -> next){
                     if(strcmp(temp4 -> variableName,output) == 0){
                              
                             if(strcmp(he, "NAND") == 0){
                                  temp4 -> val = !(tempList -> val && temp2 -> val);
                        
                   }else if(strcmp(he, "OR") == 0){
                         
                          temp4 -> val = tempList -> val || temp2 -> val;
                   }else if(strcmp(he, "AND") == 0){
                          temp4 -> val = tempList -> val && temp2 -> val;
                   }else if(strcmp(he, "NOR") == 0){
                          temp4 -> val = !(tempList -> val || temp2 -> val);
                   }else if(strcmp(he, "XOR") == 0){
                         temp4 -> val = tempList -> val ^ temp2 -> val;
                   }

                     }
                 }








                  
                }else if (searchForVal(temp,output)){

               


             for (linkedList * temp4 = temp; temp4 != NULL; temp4 = temp4 -> next){
                     if(strcmp(temp4 -> variableName,output)==0 || strcmp(temp4 -> variableName,output)==10){

                             if(strcmp(he, "NAND") == 0){

                                               temp4 -> val = !(temp -> val && temp2 -> val);
                        
                   }else if(strcmp(he, "OR") == 0){
                          temp4 -> val = temp -> val || temp2 -> val;
                   }else if(strcmp(he, "AND") == 0){
                     temp4 -> val = temp -> val && temp2 -> val;
                   }else if(strcmp(he, "NOR") == 0){
                          temp4 -> val = !(temp -> val || temp2 -> val);
                   }else if(strcmp(he, "XOR") == 0){
                         temp4 -> val = temp -> val ^ temp2 -> val;
                   }
                     }
                 }
               }else{
 
           
                   if(strcmp(he, "NAND") == 0){
                  
                       temp = addNodetotheEnd(temp,output,tempList -> val && temp2 -> val);
                   }else if(strcmp(he, "OR") == 0){
                       temp = addNodetotheEnd(temp,output,tempList -> val || temp2 -> val);
                   }else if(strcmp(he, "AND") == 0){
                              temp = addNodetotheEnd(temp,output,!(tempList -> val && temp2 -> val));
                   }else if(strcmp(he, "NOR") == 0){
                       temp = addNodetotheEnd(temp,output,!(tempList -> val || temp2 -> val));
                   }else if(strcmp(he, "XOR") == 0){
                       temp = addNodetotheEnd(temp,output,tempList -> val ^ temp2 -> val);
                   }

                    


               }
       }
      
   }
       }
      
   }

              }

        
            
            
          }
           
 
     /*for(struct linkedList * temp12 = values3combined[j]; temp12 != NULL; temp12 =  temp12 -> next){
          
      }*/

      }

   /* struct linkedList * head;

   /* while(temp != NULL){
        head = temp;
     temp=temp->next;
     free(head);
    }*/

    temp=NULL;
    rewind(fp1);
      
  }



    for(int j=0; j <(unsigned long int)pow(2,input); j++ ){

      for(struct linkedList * temp12 =  values2[j]; temp12 != NULL; temp12 =  temp12->next){
          printf("%d ", temp12->val);
      }

       for(struct linkedList * temp12 =  values[j]; temp12 != NULL; temp12 =  temp12->next){
          printf("%d ", temp12->val);
      }
      printf("\n");

     
      
}

 for(int j=0; j <(unsigned long int)pow(2,input); j++ ){

      
freeList(values[j]);
     freeList(values2[j]);
      
}


}
