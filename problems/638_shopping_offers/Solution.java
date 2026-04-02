import java.util.*;

class Solution {
    Map<List<Integer>, Integer> memo = new HashMap<>();
    public int shoppingOffers(List<Integer> price, List<List<Integer>> special, List<Integer> needs) {
        return dfs(price, special, needs);
    }
    private int dfs(List<Integer> price, List<List<Integer>> special, List<Integer> needs) {
        if (memo.containsKey(needs)) return memo.get(needs);
        int cost = 0;
        for (int i = 0; i < price.size(); i++) cost += needs.get(i) * price.get(i);
        for (List<Integer> offer : special) {
            List<Integer> newNeeds = new ArrayList<>();
            boolean valid = true;
            for (int i = 0; i < price.size(); i++) {
                if (needs.get(i) < offer.get(i)) { valid = false; break; }
                newNeeds.add(needs.get(i) - offer.get(i));
            }
            if (valid) cost = Math.min(cost, offer.get(price.size()) + dfs(price, special, newNeeds));
        }
        memo.put(needs, cost);
        return cost;
    }
}
