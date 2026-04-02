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
    int maximumLength(vector<int>& nums) {
        int even=0, odd=0;
        for (int x : nums) { if (x%2==0) even++; else odd++; }
        int alt=0, last=-1;
        for (int x : nums) {
            if (last==-1 || x%2!=last) { alt++; last=x%2; }
        }
        return max({even, odd, alt});
    }
};
