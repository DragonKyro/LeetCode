class Solution {
    public int findWinningPlayer(int[] skills, int k) {
        int curr = 0, wins = 0;
        for (int i = 1; i < skills.length; i++) {
            if (skills[curr] > skills[i]) wins++;
            else { curr = i; wins = 1; }
            if (wins >= k) return curr;
        }
        return curr;
    }
}
