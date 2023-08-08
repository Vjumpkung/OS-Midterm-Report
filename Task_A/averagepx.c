#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_THREADS 128
#define MAX_N 500000

int partial_sum[MAX_THREADS];

int main()
{
  for (int i = 0; i < MAX_THREADS; i++)
  {
    partial_sum[i] = 0;
  }
  int sum = 0, n;
  scanf("%d", &n);
  int *a = (int *)malloc(n * sizeof(int));
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &a[i]);
  }
#pragma omp parallel
  {
    int thread_id = omp_get_thread_num();
    int num_threads = omp_get_num_threads();
    int chunk_size = n / num_threads;
    int start = thread_id * chunk_size;
    int end = (thread_id == num_threads - 1) ? n : start + chunk_size;

    int local_sum = 0;
    for (int i = start; i < end; i++)
    {
      local_sum += a[i];
    }

    partial_sum[thread_id] = local_sum;
  }
  for (int i = 0; i < omp_get_max_threads(); i++)
  {
    sum += partial_sum[i];
  }
  printf("%d\n", sum / n);
  return 0;
}
