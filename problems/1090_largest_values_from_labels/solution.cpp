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
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        int n = values.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b) { return values[a] > values[b]; });
        unordered_map<int,int> count;
        int ans = 0, picked = 0;
        for (int i : idx) {
            if (picked >= numWanted) break;
            if (count[labels[i]] < useLimit) {
                ans += values[i];
                count[labels[i]]++;
                picked++;
            }
        }
        return ans;
    }
};
