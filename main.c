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

  clear_screen(s);
  struct matrix *m1, *m2;

  m1 = new_matrix(4, 4);

  printf("Testing add_edge: Adding (0, 1, 2) and (3, 4, 5)\n");
  add_edge(m1, 0, 1, 2, 3, 4, 5);
  print_matrix(m1);
  printf("\n");

  m2 = new_matrix(4, 4);
  printf("Testing ident: m2 =\n");
  add_edge(m2, 0, 1, 2, 3, 4, 5);
  add_edge(m2, 0, 1, 2, 3, 4, 5);
  ident(m2);
  print_matrix(m2);
  printf("\n");

  printf("Testing ident Matrix mult: m1 * m2 =\n");
  matrix_mult(m1, m2);
  print_matrix(m1);
  printf("\n");

  printf("Testing Matrix mult: m2=\n");
  m2 = new_matrix(4, 4);
  add_edge(m2, 1, 2, 3, 4, 5, 6);
  add_edge(m2, 7, 8, 9, 10, 11, 12);
  matrix_mult(m1, m2);
  print_matrix(m2);
  printf("\n");

  c.red = 256;
  c.green = 128;
  c.blue = 0;
  printf("matrix.png\n");
  struct matrix *cat = new_matrix(4, 10);
  // nose
  add_edge(cat, 245, 250, 0, 255, 250, 0);
  // mouth
  add_edge(cat, 250, 250, 0, 250, 230, 0);
  add_edge(cat, 230, 230, 0, 270, 230, 0);
  // bottom line
  add_edge(cat, 190, 210, 0, 310, 210, 0);
  // bottom side
  add_edge(cat, 190, 210, 0, 130, 270, 0);
  add_edge(cat, 310, 210, 0, 370, 270, 0);
  // top side ear
  add_edge(cat, 130, 270, 0, 190, 330, 0);
  add_edge(cat, 370, 270, 0, 310, 330, 0);
  // down ears
  add_edge(cat, 190, 330, 0, 210, 290, 0);
  add_edge(cat, 310, 330, 0, 290, 290, 0);
  // top line
  add_edge(cat, 210, 290, 0, 290, 290, 0);
  // left eye
  add_edge(cat, 190, 250, 0, 200, 260, 0);
  add_edge(cat, 210, 250, 0, 200, 260, 0);
  // right eye
  add_edge(cat, 290, 250, 0, 300, 260, 0);
  add_edge(cat, 310, 250, 0, 300, 260, 0);
  // left blush
  add_edge(cat, 200, 240, 0, 190, 230, 0);
  add_edge(cat, 210, 240, 0, 200, 230, 0);
  // right blush
  add_edge(cat, 320, 240, 0, 310, 230, 0);
  add_edge(cat, 310, 240, 0, 300, 230, 0);

  draw_lines(cat, s, c);

  save_extension(s, "matrix.png");

  free_matrix( m1);
  free_matrix( m2);
  free_matrix(cat);
}
