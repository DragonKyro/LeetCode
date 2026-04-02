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
    bool primeSubOperation(vector<int>& nums) {
        vector<bool> isP(1001, true); isP[0]=isP[1]=false;
        for (int i=2;i*i<=1000;i++) if (isP[i]) for (int j=i*i;j<=1000;j+=i) isP[j]=false;
        int prev = 0;
        for (int n : nums) {
            int best = n;
            for (int p=2;p<n;p++) if (isP[p]&&n-p>prev) { best=n-p; break; }
            if (best <= prev) return false;
            prev = best;
        }
        return true;
    }
};
