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
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
            return a[1] != b[1] ? a[1] < b[1] : a[0] > b[0];
        });
        vector<int> res;
        for (auto& iv : intervals) {
            int s = iv[0], e = iv[1];
            if (res.empty() || res.back() < s) {
                res.push_back(e - 1); res.push_back(e);
            } else if (res[res.size() - 2] < s) {
                res.push_back(e);
            }
        }
        return res.size();
    }
};
