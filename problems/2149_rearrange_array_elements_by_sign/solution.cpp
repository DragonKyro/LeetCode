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
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        int posIdx = 0, negIdx = 1;
        for (int num : nums) {
            if (num > 0) { result[posIdx] = num; posIdx += 2; }
            else { result[negIdx] = num; negIdx += 2; }
        }
        return result;
    }
};
