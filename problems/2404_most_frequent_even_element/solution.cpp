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
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int, int> count;
        for (int n : nums) if (n % 2 == 0) count[n]++;
        int result = -1, maxFreq = 0;
        for (auto& [k, v] : count) {
            if (v > maxFreq || (v == maxFreq && k < result)) {
                maxFreq = v; result = k;
            }
        }
        return result;
    }
};
