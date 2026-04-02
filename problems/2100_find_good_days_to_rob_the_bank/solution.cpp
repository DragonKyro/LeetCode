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
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n = security.size();
        vector<int> dec(n, 0), inc(n, 0);
        for (int i = 1; i < n; i++)
            if (security[i] <= security[i - 1]) dec[i] = dec[i - 1] + 1;
        for (int i = n - 2; i >= 0; i--)
            if (security[i] <= security[i + 1]) inc[i] = inc[i + 1] + 1;
        vector<int> result;
        for (int i = 0; i < n; i++)
            if (dec[i] >= time && inc[i] >= time) result.push_back(i);
        return result;
    }
};
