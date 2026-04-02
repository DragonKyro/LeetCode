class Solution {
    public double calculateTax(int[][] brackets, int income) {
        double tax = 0;
        int prev = 0;
        for (int[] b : brackets) {
            int taxable = Math.min(income, b[0]) - prev;
            if (taxable <= 0) break;
            tax += taxable * b[1] / 100.0;
            prev = b[0];
        }
        return tax;
    }
}
