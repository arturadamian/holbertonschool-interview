#ifndef SLIDE_LINE_H
#define SLIDE_LINE_H

#include <stdlib.h>
#include <stdio.h>

#define SLIDE_LEFT 1
#define SLIDE_RIGHT 2


int slide_line(int *line, size_t size, int direction);
int slide_it(int *line, size_t size);
int findTarget(int *line, int x, int stop);
void reverse(int *line, size_t size);

#endif
