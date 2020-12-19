#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get(int val, int pos){
    return ((val >> pos) & 1);
}

int main(int argc, char* argv[])
{

    unsigned short val = atoi(argv[1]);
  

       int i =0;
       int j = 15;

        int status  = 1;

       while(i < j){

      if(get(val,i) != get(val,j)){
          status = 0;
        break;
        
       }

          i++;
           j--;

       }


if(status){
    printf("%s\n","Is-Palindrome");

}else{
printf("%s\n","Not-Palindrome");
}
    return 0;
}
