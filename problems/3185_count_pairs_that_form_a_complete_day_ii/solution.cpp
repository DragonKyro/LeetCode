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
    long long countCompleteDayPairs(vector<int>& hours) {
        long long cnt[24] = {}, res = 0;
        for (int h : hours) {
            int r = h % 24;
            res += cnt[(24 - r) % 24];
            cnt[r]++;
        }
        return res;
    }
};
