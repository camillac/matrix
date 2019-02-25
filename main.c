#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"

int main() {

  screen s;
  struct matrix *edges;

  edges = new_matrix(4, 4);

  double counter = 0.0;
  for (int i = 0; i < edges->rows; i++){
    for (int j = 0; j < edges->cols; j++){
      edges->m[i][j] = counter;
      counter++;
    }
  }

  counter = 0.0;
  struct matrix * b;
  b = new_matrix(4, 2);
  add_point(b, 0, 1, 2);
  add_point(b, 0, 1, 2);
  add_point(b, 0, 1, 2);

  ident(edges);
  print_matrix(edges);
  printf("\nprinting b\n");
  print_matrix(b);
  printf("\n");
  matrix_mult(edges, b);
  print_matrix(b);
  printf("\n");

  free_matrix( edges );
}
