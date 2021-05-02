class Solution {
    public int maxProfit(int[] prices) {
        int max = 0;
        int min = 0x7fffffff;
        int len = prices.length;

        for (int i = 0; i < len; i++) {
            if (prices[i] < min)
                min = prices[i];
            else if (prices[i] - min > max)
                max = prices[i] - min;
        }

        return max;
    }
}