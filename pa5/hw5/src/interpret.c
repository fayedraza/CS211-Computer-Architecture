#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getValue(char * s, int ax, int bx, int cx, int dx){

        if(strstr(s,"ax") != NULL){
                 return ax; 
        }else if(strstr(s,"bx") != NULL){
                return bx; 
        }else if(strstr(s,"cx") != NULL){
                    return cx; 
        }else if(strstr(s,"dx") != NULL){
             return dx;    
        }else{
                return atoi(s);
        }
}

int main(int argc, char* argv[])
{


 FILE *fp1 = fopen(argv[1],"r");

  if(fp1 == NULL){
       
        return 0;
  }


  char code[100][256];
 

int i=0;
int status = 0;
while(fgets( code[i],256,fp1) != NULL && i < 101)  {
  

   i++;
}




    int ax;
    int bx;
    int cx;
    int dx;
    

   int j = 0;

    while(j < i && j > -1)  {

           int z = j;
         
           char * command = code[j];
        // printf("%s\n",command);

           char tempCommand[strlen(command) + 1];  
            strcpy(tempCommand, code[j]);
            
          
          

      
       if(strstr(command,"read") != NULL){
         j++;

         if(strstr(command,"ax") != NULL){
                 scanf("%d", &ax); 
                
         }else if(strstr(command,"bx") != NULL){
                   scanf("%d", &bx); 
         }else if(strstr(command,"cx") != NULL){
                   scanf("%d", &cx); 
         }else if(strstr(command,"dx") != NULL){
                       scanf("%d", &dx); 
         } 


         

       }else if(strstr(command,"print") != NULL){
            j++; 
             status =1;
        if(strstr(command,"ax") != NULL){
                 printf("%d", ax); 
         }else if(strstr(command,"bx") != NULL){
                   printf("%d", bx); 
         }else if(strstr(command,"cx") != NULL){
                   printf("%d", cx); 
         }else if(strstr(command,"dx") != NULL){
                       printf("%d", dx); 
         } else{
                 char * str  = strtok(command,"  ");
                 str = strtok (NULL, "  ");
                   printf("%d", atoi(str)); 
         }
 
          

       }else if(strstr(command,"mov") != NULL){

               j++;

               char * str  = strtok(command,"  ");
                 str = strtok (NULL, "  ");
                 char * str2 = strtok(NULL, "  ");
                 
               if((str[0]>= '0' && str[0] <= '9') || str[0] == '-'){

               
                  if(strstr(str2,"ax") != NULL){
                    ax = atoi(str);

                   
         }else if(strstr(str2,"bx") != NULL){
                  bx  = atoi(str);

         }else if(strstr(str2,"cx") != NULL){
                   cx = atoi(str); 
         }else if(strstr(str2,"dx") != NULL){
                      dx = atoi(str); 
         } 
               }else{

        if(strstr(str2,"ax") != NULL ){

                
        if(strstr(str,"ax") != NULL){
                   ax=ax;
         }else if(strstr(str,"bx") != NULL){
                 ax=bx;
         }else if(strstr(str,"cx") != NULL){
                   ax=cx;
         }else if(strstr(str,"dx") != NULL){
                ax=dx;      
         } 

         }else if(strstr(str2,"bx") != NULL){

                 if(strstr(str,"ax") != NULL){
                   bx=ax;
         }else if(strstr(str,"bx") != NULL){
                 bx=bx;
         }else if(strstr(str,"cx") != NULL){
                   bx=cx;
         }else if(strstr(str,"dx") != NULL){
                bx=dx;      
         }
                 
         }else if(strstr(str2,"cx") != NULL){

                 if(strstr(str,"ax") != NULL){
                   cx=ax;
         }else if(strstr(str,"bx") != NULL){
                 cx=bx;
         }else if(strstr(str,"cx") != NULL){
                   cx=cx;
         }else if(strstr(str,"dx") != NULL){
                cx=dx;      
         }
                   
         }else if(strstr(str2,"dx") != NULL){

                 if(strstr(str,"ax") != NULL){
                   dx=ax;
         }else if(strstr(str,"bx") != NULL){
                 dx=bx;
         }else if(strstr(str,"cx") != NULL){
                   dx=cx;
         }else if(strstr(str,"dx") != NULL){
                dx=dx;      
         }
                      
         } 
         
                   
      

               }



       }else if(strstr(command,"add") != NULL){

j++;

char * str  = strtok(command,"  ");
                 str = strtok (NULL, "  ");
                 char * str2 = strtok(NULL, "  ");
                 
               if((str[0]>= '0' && str[0] <= '9') || str[0] == '-'){


  if(strstr(str2,"ax") != NULL){
                 
                 int val = atoi(str);
                 ax = ax + val;

         }else if(strstr(str2,"bx") != NULL){
                
                 int val = atoi(str);
                 bx = bx + val;
         }else if(strstr(str2,"cx")  != NULL){
             
                 int val = atoi(str);
                 cx = cx + val;
         }else if(strstr(str2,"dx") != NULL){
               
                 int val = atoi(str);
                 dx = dx + val;    
         } 

               }else{


  if(strstr(str2,"ax") != NULL){


                      if(strstr(str,"ax") != NULL){
                  ax = ax + ax;
         }else if(strstr(str,"bx") != NULL){
                ax = ax + bx;
         }else if(strstr(str,"cx") != NULL){
                   ax = ax + cx;
         }else if(strstr(str,"dx") != NULL){
                  ax = ax + dx;     
         }

         }else if(strstr(str2,"bx") != NULL){

        if(strstr(str,"ax") != NULL){
                  bx = bx + ax;
         }else if(strstr(str,"bx") != NULL){
                bx = bx + bx;
         }else if(strstr(str,"cx") != NULL){
                   bx = bx + cx;
         }else if(strstr(str,"dx") != NULL){
                  bx = bx + dx;     
         }


         }else if(strstr(str2,"cx") != NULL){

        if(strstr(str,"ax")){
                  cx = cx + ax;
         }else if(strstr(str,"bx") != NULL){
                cx = cx + bx;
         }else if(strstr(str,"cx") != NULL){
                   cx = cx + cx;
         }else if(strstr(str,"dx") != NULL){
                  cx = cx + dx;     
         }

         }else if(strstr(str2,"dx") != NULL){

         if(strstr(str,"ax")){
                  dx = dx + ax;
         }else if(strstr(str,"bx") != NULL){
                dx = dx + bx;
         }else if(strstr(str,"cx") != NULL){
                   dx = dx + cx;
         }else if(strstr(str,"dx") != NULL){
                  dx = dx + dx;     
         }   

         }
               } 

               }else if(strstr(command,"sub") != NULL){
 j++; 

 char * str  = strtok(command,"  ");
                 str = strtok (NULL, "  ");
                 char * str2 = strtok(NULL, "  ");
                 
               if((str[0]>= '0' && str[0] <= '9') || str[0] == '-'){


  if(strstr(str2,"ax") != NULL){
           
                 int val = atoi(str);
                 ax = ax - val;

         }else if(strstr(str2,"bx") != NULL){
                  
                 int val = atoi(str);
                 bx = bx - val;
         }else if(strstr(str2,"cx") != NULL){
                 
                 int val = atoi(str);
                 cx = cx - val;
         }else if(strstr(str2,"dx") != NULL){
                   
                 int val = atoi(str);
                 dx = dx - val;    
         } 

               }else{


  if(strstr(str2,"ax") != NULL){

                      if(strstr(str,"ax") != NULL){
                  ax = ax - ax;
         }else if(strstr(str,"bx") != NULL){
                ax = ax - bx;
         }else if(strstr(str,"cx") != NULL){
                   ax = ax - cx;
         }else if(strstr(str,"dx") != NULL){
                  ax = ax - dx;     
         }

         }else if(strstr(str2,"bx")){

                          if(strstr(str,"ax")!= NULL){
                  bx = bx - ax;
         }else if(strstr(str,"bx") != NULL){
                bx = bx - bx;
         }else if(strstr(str,"cx") != NULL){
                   bx = bx - cx;
         }else if(strstr(str,"dx") != NULL){
                  bx = bx - dx;     
         }

         }else if(strstr(str2,"cx") != NULL){

                          if(strstr(str,"ax")!= NULL){
                  cx = cx - ax;
         }else if(strstr(str,"bx")!= NULL){
                cx = cx - bx;
         }else if(strstr(str,"cx")!= NULL){
                   cx = cx - cx;
         }else if(strstr(str,"dx")!= NULL){
                  cx = cx - dx;     
         }

         }else if(strstr(str2,"dx")!= NULL){

                            if(strstr(str,"ax")!= NULL){
                  dx = dx - ax;
         }else if(strstr(str,"bx")!= NULL){
                dx = dx - bx;
         }else if(strstr(str,"cx") != NULL){
                   dx = dx - cx;
         }else if(strstr(str,"dx") != NULL){
                  dx = dx - dx;     
         }   

         } 

               }
 
       }else if(strstr(command,"div") != NULL){
 j++;
     
       char * str  = strtok(command,"  ");
                 str = strtok (NULL, "  ");
                 char * str2 = strtok(NULL, "  ");
                 
               if((str[0]>= '0' && str[0] <= '9') || str[0] == '-'){


  if(strstr(str2,"ax")!= NULL){
              
                 int val = atoi(str);
                 ax =  val / ax;

         }else if(strstr(str2,"bx")!= NULL){
                
                 int val = atoi(str);
                 bx = val / bx;
         }else if(strstr(str2,"cx")!= NULL){
              
                 int val = atoi(str);
                 cx =  val / cx;
         }else if(strstr(str2,"dx")!= NULL){
            
                 int val = atoi(str);
                 dx = val / dx;    
         } 

               }else{


  if(strstr(str2,"ax")!= NULL){

                      if(strstr(str,"ax")!= NULL){
                  ax = ax / ax;
         }else if(strstr(str,"bx")!= NULL){
                ax =  bx / ax ;
         }else if(strstr(str,"cx")!= NULL){
                   ax = cx / ax;
         }else if(strstr(str,"dx")!= NULL){
                  ax = dx / ax;     
         }

}else if(strstr(str2,"bx") != NULL){

        if(strstr(str,"ax") != NULL){
                  bx = ax / bx;
         }else if(strstr(str,"bx")!= NULL){
                bx = bx / bx;
         }else if(strstr(str,"cx")!= NULL){
                   bx = cx / bx;
         }else if(strstr(str,"dx")!= NULL){
                  bx = dx / bx;     
         }

}else if(strstr(str2,"cx")!= NULL){

                          if(strstr(str,"ax")!= NULL){
                  cx = ax / cx;
         }else if(strstr(str,"bx")){
                cx = bx / cx;
         }else if(strstr(str,"cx")!= NULL){
                   cx = cx / cx;
         }else if(strstr(str,"dx")!= NULL){
                  cx = dx / cx;     
         }

}else if(strstr(str2,"dx")!= NULL){

                            if(strstr(str,"ax")!= NULL){
                  dx = ax / dx;
         }else if(strstr(str,"bx")!= NULL){
                dx = bx / dx;
         }else if(strstr(str,"cx") != NULL){
                   dx = cx / dx;
         }else if(strstr(str,"dx")!= NULL){
                  dx = dx / dx;     
         }  

         } 

               } 

       }else if(strstr(command,"mul") != NULL){

j++;
       

          char * str  = strtok(command,"  ");
                 str = strtok (NULL, "  ");
                 char * str2 = strtok(NULL, "  ");
              
                
                 
               if((str[0]>= '0' && str[0] <= '9') || str[0] == '-'){


  if(strstr(str2,"ax") != NULL){
                 
                 int val = atoi(str);
                 ax = ax * val;

         }else if(strstr(str2,"bx") != NULL){
                 
                 int val = atoi(str);
                 bx = bx * val;
         }else if(strstr(str2,"cx") != NULL){
                 
                 int val = atoi(str);
                 cx = cx * val;
         }else if(strstr(str2,"dx") != NULL){
                 
                 int val = atoi(str);
                 dx = dx * val;    
         } 

               }else{


  if(strstr(str2,"ax") != NULL){

                      if(strstr(str,"ax")!= NULL){
                  ax = ax * ax;
         }else if(strstr(str,"bx") != NULL){
                ax = ax * bx;
         }else if(strstr(str,"cx") != NULL){
                   ax = ax * cx;
         }else if(strstr(str,"dx") != NULL){
                  ax = ax * dx;     
         }

 }else if(strstr(str2,"bx") != NULL){

                          if(strstr(str,"ax") != NULL){
                  bx = bx * ax;
         }else if(strstr(str,"bx") != NULL){
                bx = bx * bx;
         }else if(strstr(str,"cx") != NULL){
                   bx = bx * cx;
         }else if(strstr(str,"dx") != NULL){
                  bx = bx * dx;     
         }

         }else if(strstr(str2,"cx") != NULL){
        
                          if(strstr(str,"ax") != NULL){
                  cx = cx * ax;
         }else if(strstr(str,"bx") != NULL){
                cx = cx * bx;
         }else if(strstr(str,"cx") != NULL){
                   cx = cx * cx;
         }else if(strstr(str,"dx") != NULL){
                  cx = cx * dx;     
         }

         }else if(strstr(str2,"dx") != NULL){

                            if(strstr(str,"ax") != NULL){
                  dx = dx * ax;
         }else if(strstr(str,"bx") != NULL){
                dx = dx * bx;
         }else if(strstr(str,"cx") != NULL){
                   dx = dx * cx;
         }else if(strstr(str,"dx") != NULL){
                  dx = dx * dx;     
         }

         }   
        
               }





        }else if(strstr(command,"jmp") != NULL){

                
           char * str  = strtok(command,"  ");
          
                 str  = strtok(NULL,"  ");
               
               j = atoi(str);
               
       }else if(strstr(command,"je") != NULL){
               char * str  = strtok(command,"  ");
                 str  = strtok(NULL,"  ");
                 
                  int tempVar = getValue(str,ax,bx,cx,dx);
                 str  = strtok(NULL,"  ");
               
                  int x = getValue(str,ax,bx,cx,dx);
                str  = strtok(NULL,"  ");
                  
                  int y = getValue(str,ax,bx,cx,dx);

                  if(x == y){
                          j = tempVar;
                  }else{
                          j++;
                  }
                


       }else if(strstr(command,"jne") != NULL){
  char * str  = strtok(command,"  ");
                 str  = strtok(NULL,"  ");
                 
                  int tempVar = getValue(str,ax,bx,cx,dx);
                 str  = strtok(NULL,"  ");
               
                  int x = getValue(str,ax,bx,cx,dx);
                str  = strtok(NULL,"  ");
                  
                  int y = getValue(str,ax,bx,cx,dx);

                  if(x != y){
                          j = tempVar;
                  }else{
                          j++;
                  }



       }else if(strstr(command,"jge") != NULL){
 
 char * str  = strtok(command,"  ");
                 str  = strtok(NULL,"  ");
                 
                  int tempVar = getValue(str,ax,bx,cx,dx);
                 str  = strtok(NULL,"  ");
               
                  int x = getValue(str,ax,bx,cx,dx);
                str  = strtok(NULL,"  ");
                  
                  int y = getValue(str,ax,bx,cx,dx);

                  if(x >= y){
                          j = tempVar;
                  }else{
                          j++;
                  }

       }else if(strstr(command,"jg") != NULL ){

 char * str  = strtok(command,"  ");
                 str  = strtok(NULL,"  ");
                 
                  int tempVar = getValue(str,ax,bx,cx,dx);
                 str  = strtok(NULL,"  ");
               
                  int x = getValue(str,ax,bx,cx,dx);
                str  = strtok(NULL,"  ");
                  
                  int y = getValue(str,ax,bx,cx,dx);

                  if(x > y){
                          j = tempVar;
                  }else{
                          j++;
                  }


       }else if(strstr(command,"jle") != NULL){

 char * str  = strtok(command,"  ");

                 str  = strtok(NULL,"  ");
                

                  int tempVar = getValue(str,ax,bx,cx,dx);
                 str  = strtok(NULL,"  ");

                 
                  int x = getValue(str,ax,bx,cx,dx);
                str  = strtok(NULL,"  ");
                  
                   
                  int y = getValue(str,ax,bx,cx,dx);
             
                  if(x <= y){
                          j = tempVar;
                  }else{
                          j++;
                  }
          
       }else if(strstr(command,"jl") != NULL){
 
  char * str  = strtok(command,"  ");
                 str  = strtok(NULL,"  ");
                 
                  int tempVar = getValue(str,ax,bx,cx,dx);
                 str  = strtok(NULL,"  ");
               
                  int x = getValue(str,ax,bx,cx,dx);
                str  = strtok(NULL,"  ");
                  
                  int y = getValue(str,ax,bx,cx,dx);

                  if(x < y){
                          j = tempVar;
                  }else{
                          j++;
                  }


       }else{
               j++;
       }

  strcpy(code[z], tempCommand);


    }

if(status)
    printf("\n");

  fclose(fp1);
return 0;
}
