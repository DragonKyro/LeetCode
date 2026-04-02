class Solution {
    public int numFriendRequests(int[] ages) {
        int[] count = new int[121];
        for (int a : ages) count[a]++;
        int[] prefix = new int[121];
        for (int i = 1; i <= 120; i++) prefix[i] = prefix[i-1] + count[i];
        int result = 0;
        for (int age = 15; age <= 120; age++) {
            if (count[age] == 0) continue;
            int lo = age / 2 + 7;
            result += count[age] * (prefix[age] - prefix[lo]) - count[age];
        }
        return result;
    }
}
