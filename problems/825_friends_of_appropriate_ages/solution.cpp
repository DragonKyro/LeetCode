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
    int numFriendRequests(vector<int>& ages) {
        int count[121] = {}, prefix[121] = {};
        for (int a : ages) count[a]++;
        for (int i = 1; i <= 120; i++) prefix[i] = prefix[i-1] + count[i];
        int result = 0;
        for (int age = 15; age <= 120; age++) {
            if (!count[age]) continue;
            int lo = age / 2 + 7;
            result += count[age] * (prefix[age] - prefix[lo]) - count[age];
        }
        return result;
    }
};
