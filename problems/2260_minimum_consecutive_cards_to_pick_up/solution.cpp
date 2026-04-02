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
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int, int> lastSeen;
        int result = INT_MAX;
        for (int i = 0; i < cards.size(); i++) {
            if (lastSeen.count(cards[i])) {
                result = min(result, i - lastSeen[cards[i]] + 1);
            }
            lastSeen[cards[i]] = i;
        }
        return result == INT_MAX ? -1 : result;
    }
};
