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
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int base = 0, extra = 0, maxExtra = 0;
        for (int i = 0; i < customers.size(); i++) {
            if (grumpy[i] == 0) base += customers[i];
            if (i < minutes) extra += customers[i] * grumpy[i];
        }
        maxExtra = extra;
        for (int i = minutes; i < (int)customers.size(); i++) {
            extra += customers[i] * grumpy[i];
            extra -= customers[i - minutes] * grumpy[i - minutes];
            maxExtra = max(maxExtra, extra);
        }
        return base + maxExtra;
    }
};
