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
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        vector<int> pairs(n-1);
        for (int i=0;i<n-1;i++) pairs[i]=weights[i]+weights[i+1];
        sort(pairs.begin(), pairs.end());
        long long diff = 0;
        for (int i=0;i<k-1;i++) diff += pairs[n-2-i]-pairs[i];
        return diff;
    }
};
