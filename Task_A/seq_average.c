#include <stdio.h>

int a[500000];
int n;

int main()
{
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &a[i]);
  }
  int sum = 0;
  for (int i = 0; i < n; i++)
  {
    sum += a[i];
  }
  printf("%d\n", sum / n);
  return 0;
}