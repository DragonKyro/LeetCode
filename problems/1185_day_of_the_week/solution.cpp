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
    string dayOfTheWeek(int day, int month, int year) {
        vector<string> days = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        if (month < 3) { month += 12; year--; }
        int q = day, k = year % 100, j = year / 100;
        int h = (q + (13 * (month + 1)) / 5 + k + k / 4 + j / 4 - 2 * j) % 7;
        return days[((h % 7) + 7) % 7];
    }
};
