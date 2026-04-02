import java.util.*;

class Solution {
    public List<List<String>> findLadders(String beginWord, String endWord, List<String> wordList) {
        Set<String> wordSet = new HashSet<>(wordList);
        List<List<String>> result = new ArrayList<>();
        if (!wordSet.contains(endWord)) return result;
        Map<String, List<List<String>>> layer = new HashMap<>();
        List<List<String>> initPaths = new ArrayList<>();
        initPaths.add(new ArrayList<>(Arrays.asList(beginWord)));
        layer.put(beginWord, initPaths);
        while (!layer.isEmpty()) {
            Map<String, List<List<String>>> newLayer = new HashMap<>();
            for (String word : layer.keySet()) {
                if (word.equals(endWord)) return layer.get(word);
                char[] chars = word.toCharArray();
                for (int i = 0; i < chars.length; i++) {
                    char orig = chars[i];
                    for (char c = 'a'; c <= 'z'; c++) {
                        chars[i] = c;
                        String newWord = new String(chars);
                        if (wordSet.contains(newWord)) {
                            newLayer.computeIfAbsent(newWord, k -> new ArrayList<>());
                            for (List<String> path : layer.get(word)) {
                                List<String> newPath = new ArrayList<>(path);
                                newPath.add(newWord);
                                newLayer.get(newWord).add(newPath);
                            }
                        }
                    }
                    chars[i] = orig;
                }
            }
            wordSet.removeAll(newLayer.keySet());
            layer = newLayer;
        }
        return result;
    }
}
