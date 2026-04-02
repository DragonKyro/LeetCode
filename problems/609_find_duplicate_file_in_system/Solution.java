import java.util.*;

class Solution {
    public List<List<String>> findDuplicate(String[] paths) {
        Map<String, List<String>> map = new HashMap<>();
        for (String path : paths) {
            String[] parts = path.split(" ");
            String dir = parts[0];
            for (int i = 1; i < parts.length; i++) {
                int idx = parts[i].indexOf('(');
                String filename = parts[i].substring(0, idx);
                String content = parts[i].substring(idx + 1, parts[i].length() - 1);
                map.computeIfAbsent(content, k -> new ArrayList<>()).add(dir + "/" + filename);
            }
        }
        List<List<String>> result = new ArrayList<>();
        for (List<String> list : map.values()) {
            if (list.size() > 1) result.add(list);
        }
        return result;
    }
}
