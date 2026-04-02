class Solution {
    public int minTimeToType(String word) {
        int time = 0, curr = 0;
        for (char c : word.toCharArray()) {
            int target = c - 'a';
            int diff = Math.abs(target - curr);
            time += Math.min(diff, 26 - diff) + 1;
            curr = target;
        }
        return time;
    }
}
