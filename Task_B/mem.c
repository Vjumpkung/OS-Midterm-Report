#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int a[1];
int b[1];
int c[1];
int count = 0;

void f()
{
  if (count == 3)
  {
    return;
  }
  int d = 0;
  printf("d: %p\n", &d);
  int *e = (int *)malloc(sizeof(int) * 1);
  printf("e: %p\n", e);
  f(count++);
  free(e);
}

void stackOverflowTest()
{
  int a[100000];
  printf("%p\n", &a);
  stackOverflowTest();
}

int main()
{
  printf("Global variables:\n");
  printf("a    : %p\n", &a);
  printf("b    : %p\n", &b);
  printf("c    : %p\n", &c);
  printf("count: %p\n", &count);
  printf("\n");
  f(0);
  printf("\n");
  printf("Stack Overflow Test");
  printf("\n");
  stackOverflowTest();
  return 0;
}