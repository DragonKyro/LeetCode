class Solution {
    public String largestGoodInteger(String num) {
        String result = "";
        for (int i = 0; i <= num.length() - 3; i++) {
            if (num.charAt(i) == num.charAt(i+1) && num.charAt(i+1) == num.charAt(i+2)) {
                String s = num.substring(i, i+3);
                if (s.compareTo(result) > 0) result = s;
            }
        }
        return result;
    }
}
