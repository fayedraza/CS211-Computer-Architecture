/* 
 * 
 * This code calculates the house price of a house by learing from
 * training data. It uses pseudo inverse of a given matrix to find the 
 * weight of different features.
 * 
 * Predicted Price : Y = W0 + W1*x1 + W2*X2 + W3*X3 + W4*X4
 * Weight Matrix : W = pseudoInv(X)*Y
 * pseudoInv(X) = inverse(transpose(X)*X) * transpose(X)  
 * 
 * weight(w) = pseudoInv(X) * Y
 * 			where	X = Input data matrix
 * 					Y = Target vector
 * 
 */
 
#include<stdio.h>
#include<stdlib.h>

// all methods declarations
double** multiplyMatrix(double **matA, double **matB, int r1, int c1, int r2, int c2);
double** transposeMatrix(double** mat, int row, int col);
double** inverseMatrix(double **matA, int dimension);

double** makeArray(int rows, int columns){
	 double** matrix = (double**) malloc(rows*sizeof(double*));
	 for(int  i =0; i < rows; i++){
		 matrix[i] = (double*) malloc(columns*sizeof(double*));
	 }

	 return matrix;
}

// main method starts here
int main(int argc, char** argv){

    // your code goes here

     FILE *fp1 = fopen(argv[1],"r");
     FILE *fp2 = fopen(argv[2],"r");


  if(fp1 == NULL || fp2 == NULL){
        printf("Error\n");

    if(fp1)
    fclose(fp1);

    if(fp2)
    fclose(fp2);
        return 0;
    }



    int numberOfRows;
    int numberOfColumns;
     
    fscanf(fp1,"%d\n", &numberOfColumns);
    fscanf(fp1,"%d\n", &numberOfRows);
    
   int numberORowsInTest;

   fscanf(fp2,"%d\n", &numberORowsInTest);

   
numberOfColumns = numberOfColumns  +1;
  
     if(numberOfRows == 0 || numberORowsInTest == 0){


    if(fp1)
    fclose(fp1);

    if(fp2)
    fclose(fp2);

        return 0;
    }

    double** matrixX = makeArray(numberOfRows,numberOfColumns);
    double** matrixY = makeArray(numberOfRows,1);



    for(int i=0; i < numberOfRows; i++){
        matrixX[i][0] = 1;
    }

    for(int i=0; i < numberOfRows; i++){
        for(int j=1; j <= numberOfColumns;j++){
             if(j == numberOfColumns){
               fscanf(fp1,"%lf%*[,]",&matrixY[i][0]);
            }else{
            fscanf(fp1,"%lf%*[,]",&matrixX[i][j]);
          
            }
        }

    }

  

   

double** matrixTest = makeArray(numberORowsInTest,numberOfColumns);

/*for(int i=0; i < numberORowsInTest; i++){
         
          matrixTest[i] = (double*) malloc((numberOfColumns)*sizeof(double*)); 
}*/

for(int i=0; i < numberORowsInTest; i++){
        matrixTest[i][0] = 1;
    }

     for(int i=0; i < numberORowsInTest; i++){
        for(int j=1; j < numberOfColumns;j++){
            fscanf(fp2,"%lf%*[,]",&matrixTest[i][j]);     
        }

      
    }


  


    double** matrixTranspoed = transposeMatrix(matrixX, numberOfRows, numberOfColumns);

   /* for(int i=0; i < numberOfColumns; i++){
         
          matrixTranspoed[i] = (double*) malloc(numberOfRows*sizeof(double*)); 
    }*/

  //    matrixTranspoed = transposeMatrix(matrixX, numberOfRows, numberOfColumns);
  


double** multipliedMatrix = multiplyMatrix(matrixTranspoed,matrixX, numberOfColumns, numberOfRows, numberOfRows, numberOfColumns);

    /*for(int i=0; i < numberOfColumns; i++){
         
          multipliedMatrix[i] = (double*) malloc(numberOfColumns*sizeof(double*)); 
    }*/

   // multipliedMatrix = multiplyMatrix(matrixTranspoed,matrixX, numberOfColumns, numberOfRows, numberOfRows, numberOfColumns);

 

double** inversedMatrix = inverseMatrix(multipliedMatrix,numberOfColumns);

/*for(int i=0; i < numberOfColumns; i++){
         
  inversedMatrix[i] = (double*) malloc(numberOfColumns*sizeof(double*)); 
}*/




//inversedMatrix = inverseMatrix(multipliedMatrix,numberOfColumns);



double** inverseTransposed = multiplyMatrix(inversedMatrix,matrixTranspoed, numberOfColumns, numberOfColumns, numberOfColumns, numberOfRows);

/*for(int i=0; i < numberOfColumns; i++){
         
  inverseTransposed[i] = (double*) malloc(numberOfRows*sizeof(double*)); 
}*/

//inverseTransposed = multiplyMatrix(inversedMatrix,matrixTranspoed, numberOfColumns, numberOfColumns, numberOfColumns, numberOfRows);

    double** matrixW = multiplyMatrix(inverseTransposed,matrixY, numberOfColumns, numberOfRows, numberOfRows, 1);

/*for(int i=0; i < numberOfColumns; i++){
         
  matrixW[i] = (double*) malloc(sizeof(double*)); 
}*/

//matrixW = multiplyMatrix(inverseTransposed,matrixY, numberOfColumns, numberOfRows, numberOfRows, 1);


for(int i=0; i < numberORowsInTest; i++){
         double sum = 0;
        for(int j=0; j < numberOfColumns;j++){
            sum =  sum + (matrixW[j][0] * matrixTest[i][j]);
        }

           printf("%0.0lf\n", sum);
    }
   


    fclose(fp1);
    fclose(fp2);

    for(int i=0; i < numberOfColumns; i++){


               free(matrixW[i]);



    }

    free(matrixW);
      
         for(int i=0; i < numberOfRows; i++){
        
             
               free(matrixX[i]);
            
        

    }
      
    free(matrixX);
      for(int i=0; i < numberOfRows; i++){


               free(matrixY[i]);



    }

    free(matrixY);

    for(int i=0; i < numberORowsInTest; i++){

         free(matrixTest[i]); 
}
    free(matrixTest);
          for(int i=0; i < numberOfColumns; i++){


               free(matrixTranspoed[i]);



    }


    free(matrixTranspoed);
             for(int i=0; i < numberOfColumns; i++){


               free(multipliedMatrix[i]);



    }
    free(multipliedMatrix);

     for(int i=numberOfColumns-1; i>=0; i--){
	     


               free(inverseTransposed[i]);



    }

    free(inverseTransposed);

        for(int i=0; i < numberOfColumns; i++){

               
               free(inversedMatrix[i]);



    }

    free(inversedMatrix);


   
	
	return 0;
}









double** multiplyMatrix(double **matA, double **matB, int r1, int c1, int r2, int c2)
{
    if(c1 !=  r2){
        return NULL;
    }

    double** result=malloc(r1*sizeof(double*)); 
    
    for(int i=0; i < r1; i++){
        result[i] = malloc(c2*sizeof(double*)); 
    }

    for(int i=0; i < r1; i++){
      for(int j=0; j < c2; j++){
                 double sum =0;
                 int x=0;
                while( x < r2){
                   sum =  sum + (matA[i][x] * matB[x][j]);
                   x++;
                }

                result[i][j] = sum;
      }
    }
  
    // your code goes here
    
    return result;
}


double** transposeMatrix(double** mat, int row, int col)
{
  
	double** matTran=malloc(col*sizeof(double*)); 

     for(int  i =0; i < col; i++){
         matTran[i] = malloc(row*sizeof(double*)); 
     }

     for(int  i =0; i < col; i++){
        for(int  j =0; j < row; j++){
             matTran[i][j] =  mat[j][i]; 
        }
     }
    // your code goes here
    
    return matTran;        
}


double** inverseMatrix(double **matA, int dimension)
{

    double** matI=malloc(dimension*sizeof(double*)); 

    // your code goes here

    for(int i=0; i < dimension; i++){
        matI[i] = malloc(dimension*sizeof(double*));
    }

    int t =0;
    for(int i=0; i<dimension; i++){
         for(int j=0; j<dimension; j++){
          if(t == j){
               matI[i][j] = 1;
              
          }else{
              matI[i][j] = 0;
              
          }
    }
   
        t++;

    }

  
    int p =0;
    while(p < dimension ){
        double point = matA[p][p];
        for(int ptr =0; ptr < dimension; ptr++){
            matI[p][ptr] =  matI[p][ptr] / point;
            matA[p][ptr] =  matA[p][ptr] / point;
        }
        for(int i= p+1; i < dimension; i++){

            double point2 = matA[i][p];
            for(int ptr =0; ptr < dimension; ptr++){
            matA[i][ptr] =  matA[i][ptr] - (matA[p][ptr]*point2);
            matI[i][ptr] =  matI[i][ptr] - (matI[p][ptr] * point2);

          
        }
        }

             p++;

    }

    for(int k=dimension-1; k > 0; k--){
        for(int l=k-1; l > -1; l--){

          double point3 = matA[l][k];

        for(int ptr =0; ptr < dimension; ptr++){ 
            matA[l][ptr] =  matA[l][ptr] - (matA[k][ptr]*point3);
          matI[l][ptr] =  matI[l][ptr] - (matI[k][ptr]*point3);

        }

    }
    }


  


    
	return matI;
}
