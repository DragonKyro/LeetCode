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
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> best;
        for (int i = max(0, k - (int)nums2.size()); i <= min(k, (int)nums1.size()); i++) {
            auto a = maxSingle(nums1, i);
            auto b = maxSingle(nums2, k - i);
            auto candidate = merge(a, b);
            if (candidate > best) best = candidate;
        }
        return best;
    }
    vector<int> maxSingle(vector<int>& nums, int t) {
        int drop = nums.size() - t;
        vector<int> stack;
        for (int num : nums) {
            while (drop && !stack.empty() && stack.back() < num) {
                stack.pop_back(); drop--;
            }
            stack.push_back(num);
        }
        stack.resize(t);
        return stack;
    }
    vector<int> merge(vector<int>& a, vector<int>& b) {
        vector<int> res;
        auto ia = a.begin(), ib = b.begin();
        while (ia != a.end() || ib != b.end()) {
            if (lexicographical_compare(ib, b.end(), ia, a.end()))
                res.push_back(*ia++);
            else
                res.push_back(*ib++);
        }
        return res;
    }
};
