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
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> count;
        for (int num : nums) count[num]++;
        sort(nums.begin(), nums.end(), [&](int a, int b) {
            return count[a] != count[b] ? count[a] < count[b] : a > b;
        });
        return nums;
    }
};
