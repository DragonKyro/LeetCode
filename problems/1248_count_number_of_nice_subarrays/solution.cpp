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
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        freq[0] = 1;
        int prefix = 0, count = 0;
        for (int x : nums) {
            prefix += x % 2;
            count += freq[prefix - k];
            freq[prefix]++;
        }
        return count;
    }
};
