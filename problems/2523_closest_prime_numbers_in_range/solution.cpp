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
    vector<int> closestPrimes(int left, int right) {
        vector<bool> sieve(right+1, true); sieve[0]=sieve[1]=false;
        for (int i=2;i*i<=right;i++) if (sieve[i]) for (int j=i*i;j<=right;j+=i) sieve[j]=false;
        vector<int> p;
        for (int i=left;i<=right;i++) if (sieve[i]) p.push_back(i);
        if (p.size()<2) return {-1,-1};
        vector<int> best={p[0],p[1]};
        for (int i=1;i<(int)p.size()-1;i++) if (p[i+1]-p[i]<best[1]-best[0]) best={p[i],p[i+1]};
        return best;
    }
};
