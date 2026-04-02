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
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        set<int> s1(nums1.begin(),nums1.end()), s2(nums2.begin(),nums2.end());
        for (int n : s1) if (s2.count(n)) return n;
        int a = *s1.begin(), b = *s2.begin();
        return min(a*10+b, b*10+a);
    }
};
