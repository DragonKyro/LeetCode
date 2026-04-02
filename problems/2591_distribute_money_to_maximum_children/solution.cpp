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
    int distMoney(int money, int children) {
        money -= children;
        if (money < 0) return -1;
        int ans = min(money / 7, children);
        money -= ans * 7;
        if ((ans == children && money > 0) || (ans == children - 1 && money == 3)) ans--;
        return max(ans, 0);
    }
};
