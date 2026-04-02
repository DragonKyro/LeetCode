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
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b) { return score[a] > score[b]; });
        vector<string> res(n);
        vector<string> medals = {"Gold Medal", "Silver Medal", "Bronze Medal"};
        for (int i = 0; i < n; i++) {
            res[idx[i]] = i < 3 ? medals[i] : to_string(i + 1);
        }
        return res;
    }
};
