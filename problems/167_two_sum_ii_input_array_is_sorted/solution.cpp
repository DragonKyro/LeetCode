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
    vector<int> twoSum(vector<int>& numbers, int target) {
        int lo = 0, hi = numbers.size() - 1;
        while (lo < hi) {
            int s = numbers[lo] + numbers[hi];
            if (s == target) return {lo + 1, hi + 1};
            else if (s < target) lo++;
            else hi--;
        }
        return {};
    }
};
