import java.util.*;

class Solution {
    public List<String> validStrings(int n) {
        List<String> res = new ArrayList<>();
        bt(res, new StringBuilder(), n);
        return res;
    }
    void bt(List<String> res, StringBuilder sb, int n) {
        if (sb.length() == n) { res.add(sb.toString()); return; }
        sb.append('1'); bt(res, sb, n); sb.deleteCharAt(sb.length()-1);
        if (sb.length() == 0 || sb.charAt(sb.length()-1) == '1') {
            sb.append('0'); bt(res, sb, n); sb.deleteCharAt(sb.length()-1);
        }
    }
}
