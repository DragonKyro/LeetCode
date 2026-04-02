#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <climits>
#include <queue>
#include <stack>
#include <cmath>
#include <numeric>
#include <set>
#include <map>
using namespace std;

class Solution {
public:
    int daysBetweenDates(string date1, string date2) {
        return abs(toDays(date1) - toDays(date2));
    }
    bool isLeap(int y) { return y%4==0 && (y%100!=0 || y%400==0); }
    int toDays(string date) {
        int y = stoi(date.substr(0,4)), m = stoi(date.substr(5,2)), d = stoi(date.substr(8,2));
        int months[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
        int days = 0;
        for (int i = 1; i < y; i++) { days += 365; if (isLeap(i)) days++; }
        for (int i = 1; i < m; i++) { days += months[i]; if (i == 2 && isLeap(y)) days++; }
        return days + d;
    }
};
