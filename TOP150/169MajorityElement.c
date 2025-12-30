// Approach
/*
  Basically, you dont need to count anything, you just have to find the biggest sequence of number, because always will have a number that appers n/2 + 1 times,
  so always this sequence will be victorious
*/

// Complexity
// Time complexity: O(n)
// Space complexity: O(1)

int majorityElement(int *nums, int numsSize)
{
  if (numsSize == 1)
    return nums[0];

  int focus = 0, stren = 0, i = 1;
  focus = nums[0];
  stren = 1;
  while (i < numsSize)
  {
    if (focus == nums[i])
    {
      stren++;
    }
    else
    {
      stren--;
    }

    if (stren < 1)
    {
      focus = nums[i];
      stren = 1;
    }
    i++;
  }

  return focus;
}