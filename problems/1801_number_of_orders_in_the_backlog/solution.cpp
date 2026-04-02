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
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        long long MOD = 1e9 + 7;
        priority_queue<pair<int,int>> buy;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> sell;
        for (auto& o : orders) {
            if (o[2] == 0) buy.push({o[0], o[1]});
            else sell.push({o[0], o[1]});
            while (!buy.empty() && !sell.empty() && buy.top().first >= sell.top().first) {
                auto [bp, ba] = buy.top(); buy.pop();
                auto [sp, sa] = sell.top(); sell.pop();
                int matched = min(ba, sa);
                if (ba - matched > 0) buy.push({bp, ba - matched});
                if (sa - matched > 0) sell.push({sp, sa - matched});
            }
        }
        long long total = 0;
        while (!buy.empty()) { total = (total + buy.top().second) % MOD; buy.pop(); }
        while (!sell.empty()) { total = (total + sell.top().second) % MOD; sell.pop(); }
        return total;
    }
};
