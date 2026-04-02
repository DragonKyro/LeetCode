class Solution {
    public int maxVowels(String s, int k) {
        String vowels = "aeiou";
        int count = 0;
        for (int i = 0; i < k; i++) {
            if (vowels.indexOf(s.charAt(i)) >= 0) count++;
        }
        int res = count;
        for (int i = k; i < s.length(); i++) {
            if (vowels.indexOf(s.charAt(i)) >= 0) count++;
            if (vowels.indexOf(s.charAt(i - k)) >= 0) count--;
            res = Math.max(res, count);
        }
        return res;
    }
}
