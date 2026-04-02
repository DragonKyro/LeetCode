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
    long long numberOfSubarrays(vector<int>& nums) {
        long long res = 0;
        vector<pair<int,long long>> stk;
        for (int x : nums) {
            while (!stk.empty() && stk.back().first < x) stk.pop_back();
            if (!stk.empty() && stk.back().first == x) {
                stk.back().second++;
                res += stk.back().second;
            } else {
                stk.push_back({x, 1});
                res++;
            }
        }
        return res;
    }
};
