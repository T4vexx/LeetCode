// Intuition
/*
  You only have to see if the position of the next and store them, so you can change with the old value, use the mod logic so that you dont have to rotate
  every value, just reposition value, this means, with you have to rotate a 6 size arr 70 times, you only need to move the number 70 mod 6 places, in this case 4 places ahead,
  this saves a lot of time and memory !
  You can do this very easily using another array, but the memory complexity will not be O(1) like this solution !
  CHOICES
*/

// Complexity
// Time complexity : O(numsSize)
// Space complexity : O(1)

#include <stdio.h>
#include <stdlib.h>

int mdc(int a, int b)
{
  if (b == 0)
  {
    return a;
  }
  return mdc(b, a % b);
}

int cycleWindow(int a, int b)
{
  if (a > b)
    return a / b;
  return b / a;
}

void rotate(int *nums, int numsSize, int k)
{
  int inv;
  inv = k % numsSize;

  if (numsSize == 1 || k == 0 || inv == 0 || inv == numsSize)
    return;

  int i = 0, tmp, tmp2, c = 0, d, e, ciclos, window;
  ciclos = mdc(k, numsSize);
  tmp = nums[0];
  if (ciclos > 1)
  {
    window = cycleWindow(ciclos, numsSize);
    while (ciclos > 0)
    {
      for (int j = 0; j < window; j++)
      {
        d = inv + i;
        if (d < numsSize)
        {
          tmp2 = nums[d];
          nums[d] = tmp;
          tmp = tmp2;
          i = d;
        }
        else
        {
          e = d - numsSize;
          tmp2 = nums[e];
          nums[e] = tmp;
          tmp = tmp2;
          i = e;
        }
      }
      i++;
      if (i < numsSize)
        tmp = nums[i];
      ciclos--;
    }
  }
  else
  {
    while (c < numsSize)
    {
      d = inv + i;
      if (d < numsSize)
      {
        tmp2 = nums[d];
        nums[d] = tmp;
        tmp = tmp2;
        i = d;
      }
      else
      {
        e = d - numsSize;
        tmp2 = nums[e];
        nums[e] = tmp;
        tmp = tmp2;
        i = e;
      }
      c++;
    }
  }
}

int main()
{
  int nums[4] = {-1, -100, 3, 99};
  rotate(nums, 4, 2);
}

/* Good time but not O(1) memory
- Time complexity: O(numsSize)
- Space complexity: O(numsSize)
if (numsSize == 1)
    return;

  int nums2[numsSize], i = 0, c, d;
  while (i < numsSize)
  {
    c = k % numsSize;
    d = i + c;
    if (d < numsSize)
    {
      nums2[d] = nums[i];
      i++;
    }
    else
    {
      nums2[(i + c) - numsSize] = nums[i];
      i++;
    }
  }

  size_t bytes_to_copy = sizeof(nums2);
  memcpy(nums, nums2, bytes_to_copy);

*/