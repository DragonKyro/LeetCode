import java.util.*;

class Solution {
    Map<String, String> parent = new HashMap<>();

    public List<List<String>> accountsMerge(List<List<String>> accounts) {
        Map<String, String> emailToName = new HashMap<>();
        for (List<String> account : accounts) {
            for (int i = 1; i < account.size(); i++) {
                parent.putIfAbsent(account.get(i), account.get(i));
                emailToName.put(account.get(i), account.get(0));
                union(account.get(i), account.get(1));
            }
        }
        Map<String, TreeSet<String>> groups = new HashMap<>();
        for (String email : parent.keySet()) {
            String root = find(email);
            groups.computeIfAbsent(root, x -> new TreeSet<>()).add(email);
        }
        List<List<String>> result = new ArrayList<>();
        for (var entry : groups.entrySet()) {
            List<String> list = new ArrayList<>();
            list.add(emailToName.get(entry.getKey()));
            list.addAll(entry.getValue());
            result.add(list);
        }
        return result;
    }

    private String find(String x) {
        if (!parent.get(x).equals(x)) parent.put(x, find(parent.get(x)));
        return parent.get(x);
    }

    private void union(String x, String y) {
        parent.put(find(x), find(y));
    }
}
