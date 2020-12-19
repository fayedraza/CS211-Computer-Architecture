#include <stdio.h>
#include <string.h>


int getKthBit(int num, int k){

    return (num >> k) & 1;
}

int getComplement(int num, int k){
    return (num ^ (1 << k));
}

int setComplement(int num, int k, int j){
    if(j == 0){
      return (num & ~(1 << k));
    }else if(j == 1){
    return (num | (1 << k));
    }

    return 0;
}

int main(int argc, char* argv[])
{


    FILE *fp = fopen(argv[1],"r");


if(fp == NULL){
}else{



    unsigned short number;
    fscanf(fp,"%hd\n", &number);

   // printf("%d\n",number);


char command[5];
int val1;
int val2;

while(fscanf(fp,"%s\t%d\t%d\n", command, &val1, &val2) == 3) {

 //printf("%s\t%d\t%d\n", command, val1, val2);

 if(strcmp("set", command) == 0){
       number = setComplement(number, val1, val2);
        printf("%d\n",number); 
 }else if(strcmp("comp", command) == 0){
        number = getComplement(number,val1);
         printf("%d\n",number); 
 }else if(strcmp("get", command) == 0){
     printf("%d\n",getKthBit(number,val1)); 
 }

}

 


}

fclose(fp);
return 0;

}
