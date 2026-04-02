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
    int miceAndCheese(vector<int>& r1, vector<int>& r2, int k) {
        int n = r1.size();
        vector<int> idx(n); iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b){ return (r1[a]-r2[a]) > (r1[b]-r2[b]); });
        int ans = 0;
        for (int i = 0; i < n; i++) ans += i < k ? r1[idx[i]] : r2[idx[i]];
        return ans;
    }
};
