class Solution {
    public int daysBetweenDates(String date1, String date2) {
        return Math.abs(toDays(date1) - toDays(date2));
    }
    int toDays(String date) {
        String[] parts = date.split("-");
        int y = Integer.parseInt(parts[0]), m = Integer.parseInt(parts[1]), d = Integer.parseInt(parts[2]);
        int[] months = {0,31,28,31,30,31,30,31,31,30,31,30,31};
        int days = 0;
        for (int i = 1; i < y; i++) { days += 365; if (isLeap(i)) days++; }
        for (int i = 1; i < m; i++) { days += months[i]; if (i == 2 && isLeap(y)) days++; }
        return days + d;
    }
    boolean isLeap(int y) { return y%4==0 && (y%100!=0 || y%400==0); }
}
