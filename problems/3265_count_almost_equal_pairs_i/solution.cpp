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
    int countPairs(vector<int>& nums) {
        int res = 0, n = nums.size();
        for (int i = 0; i < n; i++)
            for (int j = i+1; j < n; j++)
                if (almostEqual(nums[i], nums[j])) res++;
        return res;
    }
    bool almostEqual(int a, int b) {
        if (a == b) return true;
        string sa = to_string(a), sb = to_string(b);
        while (sa.size() < 7) sa = "0" + sa;
        while (sb.size() < 7) sb = "0" + sb;
        vector<int> diff;
        for (int i = 0; i < 7; i++) if (sa[i]!=sb[i]) diff.push_back(i);
        return diff.size()==2 && sa[diff[0]]==sb[diff[1]] && sa[diff[1]]==sb[diff[0]];
    }
};
