package Leetcode.String.Easy;

public class MostWordsFound {
    public int mostWordsFound(String[] sentences) {
        int maxCountWords = 0;

        for (String sentence : sentences) {
            int countWords = sentence.split(" ").length;

            if (maxCountWords < countWords) {
                maxCountWords = countWords;
            }
        }

        return maxCountWords;
    }

    public static void main(String[] args) {
        MostWordsFound m = new MostWordsFound();
        String[] input = new String[]{"alice and bob love leetcode", "i think so too", "this is great thanks very much"};

        System.out.println(m.mostWordsFound(input));
    }
}
