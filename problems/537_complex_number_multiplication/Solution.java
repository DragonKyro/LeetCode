class Solution {
    public String complexNumberMultiply(String num1, String num2) {
        int[] a = parse(num1), b = parse(num2);
        return (a[0]*b[0] - a[1]*b[1]) + "+" + (a[0]*b[1] + a[1]*b[0]) + "i";
    }
    private int[] parse(String s) {
        String[] parts = s.substring(0, s.length() - 1).split("\\+");
        return new int[]{Integer.parseInt(parts[0]), Integer.parseInt(parts[1])};
    }
}
