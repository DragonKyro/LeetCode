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
    string largestTimeFromDigits(vector<int>& arr) {
        int result = -1;
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                for (int k = 0; k < 4; k++) {
                    if (i == j || j == k || i == k) continue;
                    int l = 6 - i - j - k;
                    int hours = arr[i] * 10 + arr[j];
                    int minutes = arr[k] * 10 + arr[l];
                    if (hours < 24 && minutes < 60)
                        result = max(result, hours * 60 + minutes);
                }
        if (result == -1) return "";
        char buf[6];
        sprintf(buf, "%02d:%02d", result / 60, result % 60);
        return buf;
    }
};
