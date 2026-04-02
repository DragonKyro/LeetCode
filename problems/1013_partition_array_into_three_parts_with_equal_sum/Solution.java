class Solution {
    public boolean canThreePartsEqualSum(int[] arr) {
        int total = 0;
        for (int a : arr) total += a;
        if (total % 3 != 0) return false;
        int target = total / 3, parts = 0, current = 0;
        for (int a : arr) {
            current += a;
            if (current == target) { parts++; current = 0; }
        }
        return parts >= 3;
    }
}
