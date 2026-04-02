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
    int fillCups(vector<int>& amount) {
        int result = 0;
        while (true) {
            sort(amount.begin(), amount.end());
            if (amount[2] == 0) break;
            if (amount[1] == 0) { result += amount[2]; break; }
            amount[2]--; amount[1]--; result++;
        }
        return result;
    }
};
