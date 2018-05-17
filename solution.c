#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdio.h>

#define INPUT 1

int main(int argc, char* argv[]){
  size_t size = sqrt(strlen(argv[INPUT]));
  char(*matrix)[size] = malloc(sizeof(char[size][size]));
  /*
     Transfer values from argv to matrix
  */
  for(size_t i=0; i<size; ++i)
    for(size_t j=0; j<size; ++j)
      matrix[i][j] = argv[INPUT][i*size + j];
  /*
     Rotate matrix 180 degrees in-place
  */
  for (size_t index1 = 0, cntSwap = 0, maxSwap = (size*size) /2; cntSwap < maxSwap; ++index1){
    for (size_t index2 = 0; index2 < size && cntSwap < maxSwap; ++index2, ++cntSwap){
        char temp = matrix[index1][index2];
        matrix[index1][index2] = matrix[size - index1 - 1][ size - index2 - 1];
        matrix[size - index1 - 1][ size - index2 - 1] = temp;
    }
  }
  /*
     Allocate output matrix
  */
  char *spiral = malloc(sizeof(char) * size*size);
  int u = 0, d = size - 1, l = 0, r = size - 1, k = 0;
  /*
     Perform conversion from rotated spiral matrix to unspiraled char array
  */
  while (1) {
      // up
      for (int col = l; col <= r; col++) spiral[k++] = matrix[u][col];
      if (++u > d) break;
      // right
      for (int row = u; row <= d; row++) spiral[k++] = matrix[row][r];
      if (--r < l) break;
      // down
      for (int col = r; col >= l; col--) spiral[k++] = matrix[d][col];
      if (--d < u) break;
      // left
      for (int row = d; row >= u; row--) spiral[k++] = matrix[row][l];
      if (++l > r) break;
  }
  printf("%s", spiral);
  free(matrix);
  free(spiral);
}
