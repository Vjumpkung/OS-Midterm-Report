#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_THREADS 128
#define MAX_N 500000

int partial_sum[MAX_THREADS];
int n, a[MAX_N];
int num_threads;

int main()
{
  int n = 0, sum = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &a[i]);
  }
#pragma omp parallel
  {
    int threadID = omp_get_thread_num(), numThread = omp_get_num_threads(), chunkSize = n / numThread, start, end;
    if (threadID == 0)
    {
      start = 0;
      end = chunkSize;
    }
    else if (threadID == numThread - 1)
    {
      start = threadID * chunkSize;
      end = n;
    }
    else
    {
      start = threadID * chunkSize;
      end = start + chunkSize;
    }
    int i;
    for (i = start; i < end; i++)
    {
      partial_sum[threadID] += a[i];
    }
  }
  int i;
  for (i = 0; i < MAX_THREADS; i++)
  {
    sum += partial_sum[i];
  }
  printf("%d\n", sum / n);
  return 0;
}
