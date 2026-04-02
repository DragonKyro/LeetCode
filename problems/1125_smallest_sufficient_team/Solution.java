import java.util.*;

class Solution {
    public int[] smallestSufficientTeam(String[] req_skills, List<List<String>> people) {
        int n = req_skills.length;
        Map<String, Integer> skillIdx = new HashMap<>();
        for (int i = 0; i < n; i++) skillIdx.put(req_skills[i], i);
        Map<Integer, List<Integer>> dp = new HashMap<>();
        dp.put(0, new ArrayList<>());
        for (int i = 0; i < people.size(); i++) {
            int mask = 0;
            for (String skill : people.get(i)) {
                if (skillIdx.containsKey(skill)) mask |= 1 << skillIdx.get(skill);
            }
            for (var entry : new ArrayList<>(dp.entrySet())) {
                int newState = entry.getKey() | mask;
                if (!dp.containsKey(newState) || dp.get(newState).size() > entry.getValue().size() + 1) {
                    List<Integer> newTeam = new ArrayList<>(entry.getValue());
                    newTeam.add(i);
                    dp.put(newState, newTeam);
                }
            }
        }
        List<Integer> result = dp.get((1 << n) - 1);
        return result.stream().mapToInt(Integer::intValue).toArray();
    }
}
