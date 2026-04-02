class Solution {
    public int twoEggDrop(int n) {
        int m = 0, k = 0;
        while (m < n) { k++; m += k; }
        return k;
    }
}
