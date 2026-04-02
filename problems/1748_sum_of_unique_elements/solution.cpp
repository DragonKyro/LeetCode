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
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int, int> count;
        for (int num : nums) count[num]++;
        int sum = 0;
        for (auto& [k, v] : count) if (v == 1) sum += k;
        return sum;
    }
};
