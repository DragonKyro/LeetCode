class Solution {
    public int[] vowelStrings(String[] words, int[][] queries) {
        String v = "aeiou";
        int[] pre = new int[words.length+1];
        for (int i = 0; i < words.length; i++)
            pre[i+1] = pre[i] + (v.indexOf(words[i].charAt(0))>=0 && v.indexOf(words[i].charAt(words[i].length()-1))>=0 ? 1 : 0);
        int[] ans = new int[queries.length];
        for (int i = 0; i < queries.length; i++) ans[i] = pre[queries[i][1]+1] - pre[queries[i][0]];
        return ans;
    }
}
