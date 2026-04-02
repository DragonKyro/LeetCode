import java.util.*;

class Solution {
    public List<String> findAllConcatenatedWordsInADict(String[] words) {
        Set<String> wordSet = new HashSet<>(Arrays.asList(words));
        List<String> result = new ArrayList<>();
        for (String word : words) {
            if (word.isEmpty()) continue;
            boolean[] dp = new boolean[word.length() + 1];
            dp[0] = true;
            for (int i = 1; i <= word.length(); i++) {
                for (int j = 0; j < i; j++) {
                    if (dp[j] && wordSet.contains(word.substring(j, i)) && !word.substring(j, i).equals(word)) {
                        dp[i] = true;
                        break;
                    }
                }
            }
            if (dp[word.length()]) result.add(word);
        }
        return result;
    }
}
