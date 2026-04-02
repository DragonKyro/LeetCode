import java.util.*;

class Solution {
    public List<List<String>> suggestedProducts(String[] products, String searchWord) {
        Arrays.sort(products);
        List<List<String>> res = new ArrayList<>();
        String prefix = "";
        int start = 0;
        for (char c : searchWord.toCharArray()) {
            prefix += c;
            start = lowerBound(products, prefix, start);
            List<String> matches = new ArrayList<>();
            for (int i = start; i < Math.min(start + 3, products.length); i++) {
                if (products[i].startsWith(prefix)) matches.add(products[i]);
                else break;
            }
            res.add(matches);
        }
        return res;
    }
    int lowerBound(String[] arr, String target, int lo) {
        int hi = arr.length;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (arr[mid].compareTo(target) < 0) lo = mid + 1;
            else hi = mid;
        }
        return lo;
    }
}
