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
    int findLucky(vector<int>& arr) {
        unordered_map<int,int> cnt;
        for (int x : arr) cnt[x]++;
        int res = -1;
        for (auto& [val, freq] : cnt) if (val == freq) res = max(res, val);
        return res;
    }
};
