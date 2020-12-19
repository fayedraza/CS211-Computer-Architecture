#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{

unsigned short val = atoi(argv[1]);



int countOfPairs = 0;
int numberOf1Bits = 0;
int status = 0;

while(val){
    if(val & 1){
        
        numberOf1Bits++;

        if(status == 0){
           status = 1;
        }else{
          countOfPairs= countOfPairs +1;
          status = 0;
        }

    }else{
      status = 0;

    }
     
     val  = val >> 1;
}

if(numberOf1Bits % 2  == 0){
  printf("Even-Parity\t%d\n",countOfPairs);
}else{
  printf("Odd-Parity\t%d\n",countOfPairs); 
}
   


    return 0;
}
