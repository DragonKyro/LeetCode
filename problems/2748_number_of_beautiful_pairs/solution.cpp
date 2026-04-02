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
    int countBeautifulPairs(vector<int>& nums) {
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
            for (int j = i+1; j < nums.size(); j++) {
                int f = to_string(nums[i])[0] - '0';
                int l = nums[j] % 10;
                if (__gcd(f, l) == 1) count++;
            }
        return count;
    }
};
