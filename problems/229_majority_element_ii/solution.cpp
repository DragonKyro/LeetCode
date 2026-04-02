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
    vector<int> majorityElement(vector<int>& nums) {
        int c1 = 0, c2 = 0, n1 = 0, n2 = 1;
        for (int num : nums) {
            if (num == n1) c1++;
            else if (num == n2) c2++;
            else if (c1 == 0) { n1 = num; c1 = 1; }
            else if (c2 == 0) { n2 = num; c2 = 1; }
            else { c1--; c2--; }
        }
        c1 = c2 = 0;
        for (int num : nums) {
            if (num == n1) c1++;
            else if (num == n2) c2++;
        }
        vector<int> res;
        if (c1 > (int)nums.size() / 3) res.push_back(n1);
        if (c2 > (int)nums.size() / 3) res.push_back(n2);
        return res;
    }
};
