
// Complexity
// Time complexity: O(n)
// Space complexity: O(1)

bool canJump(int *nums, int numsSize)
{
  int i = 0, max = nums[0];
  while (i < numsSize)
  {
    if (i + nums[i] > max && i <= max)
    {
      max = i + nums[i];
    }
    i++;
  }

  if (max >= numsSize - 1)
    return true;

  return false;
}