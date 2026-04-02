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
    int maximumSum(vector<int>& nums) {
        unordered_map<int, int> best;
        int result = -1;
        for (int num : nums) {
            int ds = 0;
            for (int n = num; n > 0; n /= 10) ds += n % 10;
            if (best.count(ds)) {
                result = max(result, best[ds] + num);
                best[ds] = max(best[ds], num);
            } else best[ds] = num;
        }
        return result;
    }
};
