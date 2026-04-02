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
    int mostFrequent(vector<int>& nums, int key) {
        unordered_map<int, int> freq;
        for (int i = 0; i < (int)nums.size() - 1; i++) {
            if (nums[i] == key) freq[nums[i + 1]]++;
        }
        int result = 0, maxFreq = 0;
        for (auto& [num, cnt] : freq) {
            if (cnt > maxFreq) { maxFreq = cnt; result = num; }
        }
        return result;
    }
};
