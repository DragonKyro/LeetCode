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
    bool divideArray(vector<int>& nums) {
        unordered_map<int, int> count;
        for (int num : nums) count[num]++;
        for (auto& [k, v] : count) {
            if (v % 2 != 0) return false;
        }
        return true;
    }
};
