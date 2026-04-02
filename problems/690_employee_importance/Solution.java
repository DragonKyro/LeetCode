import java.util.*;

class Solution {
    Map<Integer, Employee> map = new HashMap<>();
    public int getImportance(List<Employee> employees, int id) {
        for (Employee e : employees) map.put(e.id, e);
        return dfs(id);
    }
    private int dfs(int id) {
        Employee e = map.get(id);
        int total = e.importance;
        for (int sub : e.subordinates) total += dfs(sub);
        return total;
    }
}
