// Approach
/*
  Everytime that the values go up you just buy (add in lucro counter), simple as that.
*/

// Complexity
// Time complexity: O(n)
// Space complexity: O(1)

int maxProfit(int *prices, int pricesSize)
{
  if (pricesSize <= 1)
    return 0;

  int lucro = 0, i = 1;
  while (i < pricesSize)
  {
    if (prices[i] - prices[i - 1] > 0)
    {
      lucro += prices[i] - prices[i - 1];
    }
    i++;
  }

  return lucro;
}