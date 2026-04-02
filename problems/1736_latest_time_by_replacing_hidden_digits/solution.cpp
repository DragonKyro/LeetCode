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
    string maximumTime(string time) {
        if (time[0] == '?') time[0] = (time[1] == '?' || time[1] <= '3') ? '2' : '1';
        if (time[1] == '?') time[1] = (time[0] == '2') ? '3' : '9';
        if (time[3] == '?') time[3] = '5';
        if (time[4] == '?') time[4] = '9';
        return time;
    }
};
