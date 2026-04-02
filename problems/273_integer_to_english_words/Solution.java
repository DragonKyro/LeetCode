class Solution {
    private String[] ones = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine",
        "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    private String[] tens = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    private String[] thousands = {"", "Thousand", "Million", "Billion"};

    public String numberToWords(int num) {
        if (num == 0) return "Zero";
        StringBuilder sb = new StringBuilder();
        for (int i = 0; num > 0; i++) {
            if (num % 1000 != 0) {
                sb.insert(0, helper(num % 1000) + thousands[i] + " ");
            }
            num /= 1000;
        }
        return sb.toString().trim();
    }

    private String helper(int num) {
        if (num == 0) return "";
        else if (num < 20) return ones[num] + " ";
        else if (num < 100) return tens[num / 10] + " " + helper(num % 10);
        else return ones[num / 100] + " Hundred " + helper(num % 100);
    }
}
