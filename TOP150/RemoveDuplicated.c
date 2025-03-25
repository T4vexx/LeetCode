int removeDuplicates(int *nums, int numsSize)
{
  int k = 0, rep = 0;
  int *temp = (int *)calloc(numsSize, sizeof(int));

  for (int i = 0; i < numsSize && k < numsSize; i++)
  {
    temp[i] = nums[k];
    k++;
    for (int j = k; j < numsSize && k < numsSize; j++)
    {
      if (temp[i] == nums[j])
      {
        k++;
        rep++;
      }
    }
  }

  for (int i = 0; i < numsSize; i++)
  {
    nums[i] = temp[i];
  }

  return numsSize - rep;
}