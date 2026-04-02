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
    int getMaxLen(vector<int>& nums) {
        int pos = 0, neg = 0, res = 0;
        for (int n : nums) {
            if (n > 0) {
                pos++;
                neg = neg > 0 ? neg + 1 : 0;
            } else if (n < 0) {
                int newPos = neg > 0 ? neg + 1 : 0;
                neg = pos + 1;
                pos = newPos;
            } else {
                pos = neg = 0;
            }
            res = max(res, pos);
        }
        return res;
    }
};
