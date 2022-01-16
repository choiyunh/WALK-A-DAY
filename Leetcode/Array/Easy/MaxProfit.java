package Leetcode.Array.Easy;

public class MaxProfit {
    public int solution(int[] prices) {
        int maxProfit = 0;
        int minBuy = prices[0];

        for (int i = 1; i < prices.length; i++) {
            if (prices[i] < minBuy) {
                minBuy = prices[i];
            }

            if (prices[i] - minBuy > maxProfit) {
                maxProfit = prices[i] - minBuy;
            }
        }

        return maxProfit;
    }

    public static void main(String[] args) {
        MaxProfit mp = new MaxProfit();
        int[] input = new int[]{7, 1, 5, 3, 6, 4};
        System.out.println((mp.solution(input)));
    }
}
