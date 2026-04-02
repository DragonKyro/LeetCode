class Solution {
    public int repeatedStringMatch(String a, String b) {
        int times = (int) Math.ceil((double) b.length() / a.length());
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < times; i++) sb.append(a);
        if (sb.toString().contains(b)) return times;
        sb.append(a);
        if (sb.toString().contains(b)) return times + 1;
        return -1;
    }
}
