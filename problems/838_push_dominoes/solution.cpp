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
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        vector<int> forces(n, 0);
        int f = 0;
        for (int i = 0; i < n; i++) {
            if (dominoes[i] == 'R') f = n;
            else if (dominoes[i] == 'L') f = 0;
            else f = max(f - 1, 0);
            forces[i] += f;
        }
        f = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (dominoes[i] == 'L') f = n;
            else if (dominoes[i] == 'R') f = 0;
            else f = max(f - 1, 0);
            forces[i] -= f;
        }
        string res;
        for (int x : forces) res += (x == 0 ? '.' : (x > 0 ? 'R' : 'L'));
        return res;
    }
};
