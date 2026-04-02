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
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> map;
        for (int n : nums1) map[n]++;
        vector<int> res;
        for (int n : nums2) {
            if (map[n] > 0) {
                res.push_back(n);
                map[n]--;
            }
        }
        return res;
    }
};
