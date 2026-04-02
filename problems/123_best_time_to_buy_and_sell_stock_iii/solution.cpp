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
    int maxProfit(vector<int>& prices) {
        int buy1 = INT_MAX, buy2 = INT_MAX;
        int profit1 = 0, profit2 = 0;
        for (int price : prices) {
            buy1 = min(buy1, price);
            profit1 = max(profit1, price - buy1);
            buy2 = min(buy2, price - profit1);
            profit2 = max(profit2, price - buy2);
        }
        return profit2;
    }
};
