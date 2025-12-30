// Approach
/*
  First i tried to adapt the other challenge that was the same but you had to leave only one, but i could not, so i tried the 2 pointer again but looking not only for
  the last but the 2 last ones, it is simple but i take some time to realize
*/

// Complexity
// Time complexity: O(n)
// Space complexity: O(1)

int removeDuplicates(int *nums, int numsSize)
{
  int i = 2, j = 2;
  while (j < numsSize)
  {
    if (nums[j] == nums[i - 1] && nums[j] == nums[i - 2])
    {
      j++;
    }
    else
    {
      nums[i] = nums[j];
      i++;
      j++;
    }
  }

  return i;
}