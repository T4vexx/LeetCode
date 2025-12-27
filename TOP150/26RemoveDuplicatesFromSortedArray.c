// Approach
/*
First i tried to do pushing every value forward, but that away was so slow and generate a lot of colateral effect,
after think for while and understand more the challenge i realize that its just have 2 pointer with one where you want to swap and other walking through the array
finding the different values if this check nums[j] != nums[i-1].
*/

// Complexity
// Time complexity:
/* O(n) */

// Space complexity:
/* O(1) */

#include <stdio.h>
#include <stdlib.h>

int removeDuplicates(int *nums, int numsSize)
{
  int i = 1, j = 1;
  while (j < numsSize)
  {
    if (nums[j] != nums[i - 1])
    {
      nums[i] = nums[j];
      i++;
      j++;
    }
    else
    {
      j++;
    }
  }

  return i;
}

// This thing works but its too slow and complex
// if (numsSize == 0)
//   return 0;
// if (numsSize == 1)
//   return 1;

// int i = 0, j = 0, c = 0, k = 0;
// while (i < numsSize - 1 && nums[i] == nums[i + 1])
//   i++;
// if (i == numsSize - 1)
//   return 1;

// for (i = 0; i < numsSize - c; i++)
// {
//   j = i + 1;

//   while (j < numsSize && nums[i] == nums[j])
//   {
//     c++;
//     j++;
//   }

//   k = i + 1;
//   if (k != j && j < numsSize)
//   {
//     while (k < numsSize - 1 && j < numsSize)
//     {
//       nums[k] = nums[j];
//       k++;
//       j++;
//     }
//     for (int l = numsSize - 1; l >= numsSize - c; l--)
//     {
//       nums[l] = -9999;
//     }
//   }
// }

// return numsSize - c;