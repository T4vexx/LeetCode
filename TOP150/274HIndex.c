// Approach
/*
  I followed the definition of H-index that was:
  max{i∈N:f(i)≥i}
  So you just need to put the arr in descending order
*/

// Complexity
// Time complexity: O(n log n)
// Space complexity: O(1)
int max(int a, int b)
{
  return (a > b) ? a : b;
}

int compare(const void *a, const void *b)
{
  return (*(int *)b - *(int *)a);
}

int hIndex(int *citations, int citationsSize)
{
  int i = 0, old = 0, h_index = 0;
  qsort(citations, citationsSize, sizeof(int), compare);
  while (i < citationsSize)
  {
    if (citations[i] > i)
    {
      h_index = max(old, i);
      old = i;
    }
    i++;
  }
  if (h_index == 0)
    return 0;
  return h_index + 1;
}
