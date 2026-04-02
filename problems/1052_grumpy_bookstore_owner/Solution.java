class Solution {
    public int maxSatisfied(int[] customers, int[] grumpy, int minutes) {
        int base = 0, extra = 0, maxExtra = 0;
        for (int i = 0; i < customers.length; i++) {
            if (grumpy[i] == 0) base += customers[i];
            if (i < minutes) extra += customers[i] * grumpy[i];
        }
        maxExtra = extra;
        for (int i = minutes; i < customers.length; i++) {
            extra += customers[i] * grumpy[i];
            extra -= customers[i - minutes] * grumpy[i - minutes];
            maxExtra = Math.max(maxExtra, extra);
        }
        return base + maxExtra;
    }
}
