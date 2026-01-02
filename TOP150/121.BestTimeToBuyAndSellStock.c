// Approach
/*
I tried so much things, i have to stop overthinking leetcode challenges, i aways try find global max and local max, but sometimes its just store the subtraction in a variable!
So the resolution is trivial
*/

// Complexity
// Time complexity: O(n)
// Space complexity: O(1)

int maxProfit(int *prices, int pricesSize)
{
  int min = prices[0], lucro = -9999, i = 0;
  while (i < pricesSize)
  {
    if (prices[i] < min)
      min = prices[i];
    if (prices[i] - min > lucro)
    {
      lucro = prices[i] - min;
    }
    i++;
  }
  return lucro;
}