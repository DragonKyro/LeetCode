class Solution {
    public int countDigits(int num) {
        int count = 0, n = num;
        while (n > 0) { if (num % (n%10) == 0) count++; n /= 10; }
        return count;
    }
}
