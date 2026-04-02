#include<stdio.h>
#include<stdlib.h>

// part 2
// this is a procedure for the inputs
void input( int A[100][100],int rows , int columns){
    for(int i =0 ; i<rows;i++){
       for(int j=0;j<columns;j++) {
        scanf("%d",&A[i][j]);
        
      }  
    }
    
    
    
    
}
// this is a procedure for display 
void display(int A[100] [100 ], int rows, int columns){
     int i,j;
     printf("the matrix elements are:\n");
    
    for( i=0;i<rows;i++){
        for(j=0;j<columns;j++){
           printf("%d  ",A[i][j]) ;
       
        }
        printf("\n");
    }
    
}
// this is a function for calculate the sum
int sum(int A[100][100], int rows , int columns){
    int s=0,i,j;
    for(i=0;i<rows;i++){
    for(j=0;j<columns;j++){
        s+=A[i][j];     
    }
}
return s;
}
//this is a procedure for calculate the transpose of a given matrix
void matrixtranspose(int A[100][100],int row, int columns,int B[100][100]){
for(int i =0; i < row; i++ ){
    for(int j=0;j<columns;j++){
        B[j][i]=A[i][j];
    }
}

}
void transposedisplay( int B[100][100],int row , int columns){
   printf("the transpose matrix is:\n");
     for(int i=0;i<columns;i++){
        for(int j=0;j<row;j++){
         printf("%d ",B[i][j]) ; 
        }
        printf("\n");
     }
}
// The main program
int main()
{
int matrix[100][100],N,M,matrix2[100][100]; 
printf("enter the number of rows\n");
scanf("%d",&N);
printf("enter the number of columns\n");
scanf("%d",&M);
input(matrix,N,M); 
display(matrix,N,M);
int s= sum(matrix,N,M);
printf("the sum of the elements of this matrix is %d\n",s);
matrixtranspose(matrix,N,M,matrix2);
transposedisplay(matrix2,N,M);
 return 0;
}