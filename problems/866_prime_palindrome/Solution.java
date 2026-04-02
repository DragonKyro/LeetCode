class Solution {
    public int primePalindrome(int n) {
        if (n >= 8 && n <= 11) return 11;
        for (int len = 1; len <= 5; len++) {
            for (int root = (int) Math.pow(10, len - 1); root < (int) Math.pow(10, len); root++) {
                String s = String.valueOf(root);
                StringBuilder sb = new StringBuilder(s);
                String pal = s + sb.reverse().substring(1);
                int num = Integer.parseInt(pal);
                if (num >= n && isPrime(num)) return num;
            }
        }
        return -1;
    }
    boolean isPrime(int x) {
        if (x < 2) return false;
        if (x < 4) return true;
        if (x % 2 == 0 || x % 3 == 0) return false;
        for (int i = 5; i * i <= x; i += 6)
            if (x % i == 0 || x % (i + 2) == 0) return false;
        return true;
    }
}
