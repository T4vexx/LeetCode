int removeDuplicates(int *nums, int numsSize)
{
  int flag = 0, flag2 = 0, j, val = 0;

  for (int i = 0; i < numsSize; i++)
  {
    flag = 1;
    for (int j = i + 1; j < numsSize; j++)
    {
      if (nums[i] != nums[j])
      {
        break;
      }
      if (nums[i] == nums[j])
      {
        flag++;
      }
    }

    if (flag > 2)
    {
      i++;

      for (j = i + 1; j < numsSize - 1; j++)
      {
        nums[j] = nums[j + 1];
      }
    }
    else
    {
      val++;
    }
  }

  return val;
}