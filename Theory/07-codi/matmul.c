// Exemple de l'assignatura de Software Concurrent
// Matrices are stored in row-major order:
// M(row, col) = *(M.elements + row * M.width + col)

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/time.h>

void MatMulCPU(
  float *A, int A_width, int A_height, 
  float *B, int B_width, int B_height, 
  float *C, int C_width, int C_height)
{
  int row, col, e;

  struct timeval start, end;
  float mtime, seconds, useconds;
     
  float val;

  gettimeofday(&start, NULL);
  
  for(row = 0; row < C_height; row++)
    for(col = 0; col < C_width; col++)
    {
      val = 0.0;    
      for(e = 0; e < A_width; e++)
	     val += A[row * A_width + e] * B[e * B_width + col];

      C[row * C_width + col] = val;
    }
    
  gettimeofday(&end, NULL);	
  seconds = end.tv_sec - start.tv_sec;
  useconds = end.tv_usec - start.tv_usec;
  mtime = ((seconds) * 1000 + useconds / 1000.0);
   
  printf("Execution time in milliseconds = %0.3f ms\n", mtime);
}


int main() 
{
  int i;

  float *A = NULL;  // Input array
  float *B = NULL;  // Input array
  float *C = NULL;  // Output array

  // Size of the matrix
  const int size = 2048;
  const int elements = size * size;

  // Compute the size of the data 
  size_t datasize = sizeof(float) * elements;

  // Allocate space for input/output data
  A = (float *) malloc(datasize);
  B = (float *) malloc(datasize);
  C = (float *) malloc(datasize);

  // Initialize the input data
  for(i = 0; i < elements; i++) {
    A[i] = 1;
    B[i] = 1;
  }

  MatMulCPU(A, size, size, B, size, size, C, size, size);
  
  free(A);
  free(B);
  free(C);
}

