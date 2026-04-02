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
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int time = 0;
        for (int i = 0; i < (int)tickets.size(); i++) {
            if (i <= k) time += min(tickets[i], tickets[k]);
            else time += min(tickets[i], tickets[k] - 1);
        }
        return time;
    }
};
