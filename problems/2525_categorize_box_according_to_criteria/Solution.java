class Solution {
    public String categorizeBox(int l, int w, int h, int mass) {
        boolean bulky = l>=10000||w>=10000||h>=10000||(long)l*w*h>=1000000000L;
        boolean heavy = mass >= 100;
        if (bulky&&heavy) return "Both";
        if (bulky) return "Bulky";
        if (heavy) return "Heavy";
        return "Neither";
    }
}
