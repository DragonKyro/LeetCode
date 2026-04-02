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
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int lo = 0, hi = removable.size();
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            vector<bool> removed(s.size(), false);
            for (int i = 0; i < mid; i++) removed[removable[i]] = true;
            int j = 0;
            for (int i = 0; i < s.size() && j < p.size(); i++) {
                if (!removed[i] && s[i] == p[j]) j++;
            }
            if (j == (int)p.size()) lo = mid + 1;
            else hi = mid - 1;
        }
        return hi;
    }
};
