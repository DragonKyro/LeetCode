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
    bool xorGame(vector<int>& nums) {
        int x = 0;
        for (int n : nums) x ^= n;
        return x == 0 || nums.size() % 2 == 0;
    }
};
