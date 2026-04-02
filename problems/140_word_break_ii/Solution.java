import java.util.*;

class Solution {
    private Map<Integer, List<String>> memo = new HashMap<>();
    public List<String> wordBreak(String s, List<String> wordDict) {
        Set<String> wordSet = new HashSet<>(wordDict);
        return backtrack(s, wordSet, 0);
    }
    private List<String> backtrack(String s, Set<String> wordSet, int start) {
        if (memo.containsKey(start)) return memo.get(start);
        List<String> result = new ArrayList<>();
        if (start == s.length()) { result.add(""); return result; }
        for (int end = start + 1; end <= s.length(); end++) {
            String word = s.substring(start, end);
            if (wordSet.contains(word)) {
                for (String rest : backtrack(s, wordSet, end)) {
                    result.add(word + (rest.isEmpty() ? "" : " " + rest));
                }
            }
        }
        memo.put(start, result);
        return result;
    }
}
