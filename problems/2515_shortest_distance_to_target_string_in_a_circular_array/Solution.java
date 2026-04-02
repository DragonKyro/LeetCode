class Solution {
    public int closetTarget(String[] words, String target, int startIndex) {
        int n = words.length, ans = n;
        for (int i = 0; i < n; i++)
            if (words[i].equals(target))
                ans = Math.min(ans, Math.min(Math.abs(i-startIndex), n-Math.abs(i-startIndex)));
        return ans < n ? ans : -1;
    }
}
