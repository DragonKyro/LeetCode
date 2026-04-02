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
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int> masks(n, 0);
        for (int i = 0; i < n; i++)
            for (char c : words[i])
                masks[i] |= 1 << (c - 'a');
        int res = 0;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if ((masks[i] & masks[j]) == 0)
                    res = max(res, (int)(words[i].size() * words[j].size()));
        return res;
    }
};
