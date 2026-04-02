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
    map<vector<int>, int> memo;
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        if (memo.count(needs)) return memo[needs];
        int cost = 0;
        for (int i = 0; i < price.size(); i++) cost += needs[i] * price[i];
        for (auto& offer : special) {
            vector<int> newNeeds;
            bool valid = true;
            for (int i = 0; i < price.size(); i++) {
                if (needs[i] < offer[i]) { valid = false; break; }
                newNeeds.push_back(needs[i] - offer[i]);
            }
            if (valid) cost = min(cost, offer.back() + shoppingOffers(price, special, newNeeds));
        }
        return memo[needs] = cost;
    }
};
