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
    int minPatches(vector<int>& nums, int n) {
        int patches = 0, i = 0;
        long reach = 0;
        while (reach < n) {
            if (i < nums.size() && nums[i] <= reach + 1) {
                reach += nums[i++];
            } else {
                reach += reach + 1;
                patches++;
            }
        }
        return patches;
    }
};
