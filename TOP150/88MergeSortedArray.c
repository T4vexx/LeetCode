// Intuition
/* I just followed the basic merge sort structure learned on my university */

// Approach
/* The standard divide by conquer */

// Complexity
// Time complexity:
/* O(m + n) */

// Space complexity:
/* O(m) */

#include <stdio.h>
#include <stdlib.h>

void merge(int *nums1, int nums1Size, int m, int *nums2, int nums2Size, int n)
{
  if (m == 1 && n == 0)
    return;
  if (m == 0 && n >= 1)
  {
    int i = 0;
    while (i < n)
    {
      nums1[i] = nums2[i];
      i++;
    }
    return;
  }

  int numaux[m];
  for (int i = 0; i < m; i++)
  {
    numaux[i] = nums1[i];
  }

  int i = 0, j = 0, k = 0;
  while (j < m && i < n)
  {
    if (numaux[j] <= nums2[i])
    {
      nums1[k] = numaux[j];
      j++;
    }
    else
    {
      nums1[k] = nums2[i];
      i++;
    }
    k++;
  }

  while (j < m)
  {
    nums1[k] = numaux[j];
    k++;
    j++;
  }

  while (i < n)
  {
    nums1[k] = nums2[i];
    i++;
    k++;
  }
}
