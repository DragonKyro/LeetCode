import java.util.*;

class Solution {
    public List<Integer> findNumOfValidWords(String[] words, String[] puzzles) {
        Map<Integer, Integer> wordMasks = new HashMap<>();
        for (String word : words) {
            int mask = 0;
            for (char c : word.toCharArray()) mask |= 1 << (c - 'a');
            if (Integer.bitCount(mask) <= 7) wordMasks.merge(mask, 1, Integer::sum);
        }
        List<Integer> result = new ArrayList<>();
        for (String puzzle : puzzles) {
            int first = 1 << (puzzle.charAt(0) - 'a');
            int mask = 0;
            for (char c : puzzle.toCharArray()) mask |= 1 << (c - 'a');
            int count = 0;
            for (int sub = mask; sub > 0; sub = (sub - 1) & mask) {
                if ((sub & first) != 0) count += wordMasks.getOrDefault(sub, 0);
            }
            result.add(count);
        }
        return result;
    }
}
