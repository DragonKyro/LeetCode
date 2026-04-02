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
    bool canCross(vector<int>& stones) {
        unordered_map<int, unordered_set<int>> mp;
        for (int s : stones) mp[s] = {};
        mp[0].insert(0);
        for (int stone : stones) {
            for (int k : mp[stone]) {
                for (int step = k - 1; step <= k + 1; step++) {
                    if (step > 0 && mp.count(stone + step)) {
                        mp[stone + step].insert(step);
                    }
                }
            }
        }
        return !mp[stones.back()].empty();
    }
};
