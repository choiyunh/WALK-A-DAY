package Leetcode.String.Easy;

import java.util.HashMap;

class LongestPalindrome {
    public int solution(String s) {
        HashMap<String, Integer> m = new HashMap<String, Integer>();
        int result = 0;
        int max = 0;

        for (String c : s.split("")) {
            m.merge(c, 1, Integer::sum);
        }

        for (int i : m.values()) {
            if (i % 2 == 0) {
                result += i;
            } else {
                if (i > max) {
                    result += (i - max);
                    max = i;
                }

            }

        }
        return result;
        System.out.println();
    }


    public static void main(String[] args) {

    }
}
