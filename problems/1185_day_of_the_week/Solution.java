class Solution {
    public String dayOfTheWeek(int day, int month, int year) {
        String[] days = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        if (month < 3) { month += 12; year--; }
        int q = day, k = year % 100, j = year / 100;
        int h = (q + (13 * (month + 1)) / 5 + k + k / 4 + j / 4 - 2 * j) % 7;
        return days[((h % 7) + 7) % 7];
    }
}
