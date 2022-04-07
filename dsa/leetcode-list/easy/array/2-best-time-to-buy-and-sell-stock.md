**1. [Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)**

**Approach 1:**

- ex: arr = `[7, 1, 5, 3, 6, 4]`
- We'll iterate from the end and store the `max` element until that place, so the mx array would be:
- mx: arr = `[7, 6, 6, 6, 6, 4]`
- Now we'll iterate the original array and update `maxProfit` to get the max profit.

**Approach 2:**

- Instead of maxSoFar from the end of the array we'll try to sell it everytime, hence `minSoFar` with `maxProfit`
- arrayGiv = 3 1 4 8 7 2 5
- minSoFar = 3 1 1 1 1 1 1
- maxProft = 0 0 3 7 6 1 4

---

<details><summary>Code:</summary>

```cpp
class Solution {
public:
    /*************** Approach 1: **************************/
    int maxProfit(vector<int>& prices) {
        vector<int> mx(prices.size());
        mx[prices.size() - 1] = prices[prices.size() - 1];

        for(int i= prices.size() - 2; i>= 0; i--){
            if(prices[i] > mx[i + 1]){
                mx[i] = prices[i];
            } else {
                mx[i] = mx[i + 1];
            }
        }

        int maxProfit(0);

        for(int i = 0; i<prices.size(); i++){
            maxProfit = max(abs(mx[i] - prices[i]), maxProfit);
        }
        return maxProfit;
    }

    /*************** Approach 2: **************************/
    int maxProfit(vector<int>& prices) {
        int minSoFar(INT_MAX), maxProfit(0);
        for(int i=0; i<prices.size(); i++){
            if(prices[i] < minSoFar){
                minSoFar = prices[i];
            }
            maxProfit = max(maxProfit, (prices[i] - minSoFar));
        }
        return maxProfit;
    }
};
```

</details>

**1. [Best Time to Buy and Sell Stock 2](https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/564/)**

**Approach**

- Buy at local minima, and sell at local maxima
- Local Minima: When to the right is greater and to the left is also greater
- Local Maxima: When to the right is lesser and to the left is also lesser

<details><summary>Code:</summary>

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit(0);
        for(int i=1; i<prices.size(); i++){
            if(prices[i] > prices[i - 1]){
                profit += prices[i] - prices[i - 1];
            }
        }
        return profit;
    }
};
```

</details>
