void merge(int *nums1, int nums1Size, int m, int *nums2, int nums2Size, int n)
{
  int i, j, arr;

  // Case when the first is already the answer
  if (n == 0)
  {
    return;
  }

  // Case when the first arr is empty and the second hold the result
  if (m == 0)
  {
    if (m == 1)
    {
      nums1[0] = nums2[0];
      return;
    }

    j = 0;
    arr = 0;
    while (j < n)
    {
      nums1[arr] = nums2[j];
      j++;
      arr++;
    }
    return;
  }

  int L[m], R[n];
  for (i = 0; i < m; i++)
  {
    L[i] = nums1[i];
  }
  for (j = 0; j < n; j++)
  {
    R[j] = nums2[j];
  }

  arr = 0;
  i = 0;
  j = 0;
  // Copy the right anwser to nums1 array and go forward in the positions of the respective array
  // that provides the number
  while (i < m && j < n)
  {
    if (L[i] <= R[j])
    {
      nums1[arr] = L[i];
      i++;
      arr++;
    }
    else
    {
      nums1[arr] = R[j];
      j++;
      arr++;
    }
  }

  // If the second array is empty and the first hold numbers, here we copy this numbers to the answer
  while (i < m)
  {
    nums1[arr] = L[i];
    i++;
    arr++;
  }

  // If the first array is empty and the second hold numbers, here we copy this numbers to the answer
  while (j < n)
  {
    nums1[arr] = R[j];
    j++;
    arr++;
  }
}