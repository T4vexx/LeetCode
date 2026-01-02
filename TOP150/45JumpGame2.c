// Approach
/*
  I did a greedy approach trying to maximize the sum of the number in nums[i] + i, the biggest i can reach the better
*/
// Complexity
// Time complexity: O(n)
// Space complexity: O(1)

int jump(int *nums, int numsSize)
{
  if (numsSize == 1)
    return 0;

  int i = 0, k = 0, jumps = 0, bigger, max = nums[0];
  while (i < numsSize)
  {
    bigger = -999;
    for (int j = i + 1; j <= i + max; j++)
    {
      if (j >= numsSize - 1)
      {
        return jumps + 1;
      }
      if (j + nums[j] >= bigger)
      {
        bigger = nums[j] + j;
        k = j;
      }
    }
    jumps++;
    i = k;
    max = nums[i];
  }

  return jumps;
}
