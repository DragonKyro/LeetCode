class Solution {
    int[] parent = new int[26];
    public boolean equationsPossible(String[] equations) {
        for (int i = 0; i < 26; i++) parent[i] = i;
        for (String eq : equations)
            if (eq.charAt(1) == '=')
                parent[find(eq.charAt(0) - 'a')] = find(eq.charAt(3) - 'a');
        for (String eq : equations)
            if (eq.charAt(1) == '!')
                if (find(eq.charAt(0) - 'a') == find(eq.charAt(3) - 'a'))
                    return false;
        return true;
    }
    int find(int x) {
        while (parent[x] != x) { parent[x] = parent[parent[x]]; x = parent[x]; }
        return x;
    }
}
