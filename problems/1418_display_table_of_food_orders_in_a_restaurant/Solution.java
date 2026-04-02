import java.util.*;

class Solution {
    public List<List<String>> displayTable(List<List<String>> orders) {
        TreeMap<Integer, Map<String, Integer>> tables = new TreeMap<>();
        TreeSet<String> foods = new TreeSet<>();
        for (List<String> order : orders) {
            int table = Integer.parseInt(order.get(1));
            String food = order.get(2);
            foods.add(food);
            tables.computeIfAbsent(table, k -> new HashMap<>()).merge(food, 1, Integer::sum);
        }
        List<String> foodList = new ArrayList<>(foods);
        List<List<String>> res = new ArrayList<>();
        List<String> header = new ArrayList<>();
        header.add("Table");
        header.addAll(foodList);
        res.add(header);
        for (var entry : tables.entrySet()) {
            List<String> row = new ArrayList<>();
            row.add(String.valueOf(entry.getKey()));
            for (String food : foodList) {
                row.add(String.valueOf(entry.getValue().getOrDefault(food, 0)));
            }
            res.add(row);
        }
        return res;
    }
}
