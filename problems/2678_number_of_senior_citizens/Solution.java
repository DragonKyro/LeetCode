class Solution {
    public int countSeniors(String[] details) {
        int cnt = 0;
        for (String d : details) if (Integer.parseInt(d.substring(11, 13)) > 60) cnt++;
        return cnt;
    }
}
