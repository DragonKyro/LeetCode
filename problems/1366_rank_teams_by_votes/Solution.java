import java.util.*;

class Solution {
    public String rankTeams(String[] votes) {
        int n = votes[0].length();
        Map<Character, int[]> count = new HashMap<>();
        for (char c : votes[0].toCharArray()) count.put(c, new int[n]);
        for (String vote : votes)
            for (int i = 0; i < n; i++) count.get(vote.charAt(i))[i]++;
        Character[] teams = new Character[n];
        for (int i = 0; i < n; i++) teams[i] = votes[0].charAt(i);
        Arrays.sort(teams, (a, b) -> {
            for (int i = 0; i < n; i++)
                if (count.get(a)[i] != count.get(b)[i]) return count.get(b)[i] - count.get(a)[i];
            return a - b;
        });
        StringBuilder sb = new StringBuilder();
        for (char c : teams) sb.append(c);
        return sb.toString();
    }
}
