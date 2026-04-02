class Solution {
    public int numberOfEmployeesWhoMetTarget(int[] hours, int target) {
        int cnt = 0;
        for (int h : hours) if (h >= target) cnt++;
        return cnt;
    }
}
