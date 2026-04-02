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
    unordered_set<string> seen;
    string result;

    string crackSafe(int n, int k) {
        string start(n - 1, '0');
        dfs(start, k);
        return result + start;
    }

    void dfs(string node, int k) {
        for (int x = 0; x < k; x++) {
            string nei = node + char('0' + x);
            if (!seen.count(nei)) {
                seen.insert(nei);
                dfs(nei.substr(1), k);
                result += char('0' + x);
            }
        }
    }
};
