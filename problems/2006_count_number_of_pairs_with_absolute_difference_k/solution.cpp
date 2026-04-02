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
    int countKDifference(vector<int>& nums, int k) {
        int count = 0;
        unordered_map<int, int> freq;
        for (int num : nums) {
            if (freq.count(num - k)) count += freq[num - k];
            if (freq.count(num + k)) count += freq[num + k];
            freq[num]++;
        }
        return count;
    }
};
