#ifndef HEADER_FILE
#define HEADER_FILE

#include <stdlib.h>
#include <stdio.h>

#define SLIDE_LEFT  ('\074')
#define SLIDE_RIGHT  ('\076')


int slide_line(int *line, size_t size, int direction);
int slide_it(int *line, size_t size);
int findTarget(int *line, int x, int stop);
void reverse(int *line, size_t size);

#endif
