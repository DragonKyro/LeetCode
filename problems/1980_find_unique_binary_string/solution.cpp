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
    string findDifferentBinaryString(vector<string>& nums) {
        string result;
        for (int i = 0; i < nums.size(); i++) {
            result += (nums[i][i] == '0') ? '1' : '0';
        }
        return result;
    }
};
