#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"

int main() {

  screen s;
  color c;
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
  add_edge( b, 0, 1, 2, 3, 4, 5);

  ident(edges);
  print_matrix(edges);
  printf("\nprinting b\n");
  print_matrix(b);
  printf("\n");
  matrix_mult(edges, b);
  print_matrix(b);
  printf("\n");
  c.red = 0;
  c.green = 256;
  c.blue = 0;
  draw_lines(b, s, c);

  save_extension(s, "matrix.png");

  free_matrix( edges );
}
