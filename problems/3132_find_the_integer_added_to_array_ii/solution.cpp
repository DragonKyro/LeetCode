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
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int n = nums1.size(), res = INT_MAX;
        for (int i = 0; i < n; i++)
            for (int j = i+1; j < n; j++) {
                vector<int> rem;
                for (int k = 0; k < n; k++) if (k!=i&&k!=j) rem.push_back(nums1[k]);
                int x = nums2[0] - rem[0];
                bool ok = true;
                for (int k = 0; k < (int)nums2.size(); k++)
                    if (rem[k]+x != nums2[k]) { ok = false; break; }
                if (ok) res = min(res, x);
            }
        return res;
    }
};
