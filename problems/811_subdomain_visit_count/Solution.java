import java.util.*;

class Solution {
    public List<String> subdomainVisits(String[] cpdomains) {
        Map<String, Integer> map = new HashMap<>();
        for (String cp : cpdomains) {
            String[] parts = cp.split(" ");
            int count = Integer.parseInt(parts[0]);
            String domain = parts[1];
            String[] subs = domain.split("\\.");
            StringBuilder sb = new StringBuilder();
            for (int i = subs.length - 1; i >= 0; i--) {
                if (sb.length() > 0) sb.insert(0, ".");
                sb.insert(0, subs[i]);
                map.merge(sb.toString(), count, Integer::sum);
            }
        }
        List<String> result = new ArrayList<>();
        for (var e : map.entrySet()) result.add(e.getValue() + " " + e.getKey());
        return result;
    }
}
