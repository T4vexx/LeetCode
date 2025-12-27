// Approach
/* 
I just did a substituition between the numbers that was supose to remove with the last ones, using the in-place foundations. 
The worst part is dealing with the colateral cases, when the second pointer k goes negative. 
*/

// Complexity
// Time complexity:
/* O(n) */

// Space complexity:
/* O(1) */

#include <stdio.h>
#include <stdlib.h>

int removeElement(int *nums, int numsSize, int val)
{
  if (numsSize == 1 && nums[0] == val)
    return 0;
  if (numsSize == 1 && nums[0] != val)
    return 1;

  int k = numsSize - 1, temp = 0, count = 0, flag = 0;
  for (int i = 0; i < numsSize; i++)
  {
    if (k <= i)
    {
      if (flag == 0 && k >= 0 && nums[k] == val)
        count++;
      break;
    }

    if (nums[i] == val)
    {
      while (nums[k] == val)
      {
        if (k <= i)
        {
          flag = 1;
          break;
        }
        k--;
        count++;
      }

      temp = nums[i];
      nums[i] = nums[k];
      nums[k] = temp;
      k--;
      count++;
    }
  }

  return numsSize - count;
}