class Solution {
    public double average(int[] salary) {
        int min = Integer.MAX_VALUE, max = Integer.MIN_VALUE, sum = 0;
        for (int s : salary) { min = Math.min(min, s); max = Math.max(max, s); sum += s; }
        return (double)(sum - min - max) / (salary.length - 2);
    }
}
