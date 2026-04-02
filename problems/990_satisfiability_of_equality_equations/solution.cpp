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
    int parent[26];
    int find(int x) {
        while (parent[x] != x) { parent[x] = parent[parent[x]]; x = parent[x]; }
        return x;
    }
public:
    bool equationsPossible(vector<string>& equations) {
        iota(parent, parent + 26, 0);
        for (auto& eq : equations)
            if (eq[1] == '=')
                parent[find(eq[0] - 'a')] = find(eq[3] - 'a');
        for (auto& eq : equations)
            if (eq[1] == '!')
                if (find(eq[0] - 'a') == find(eq[3] - 'a'))
                    return false;
        return true;
    }
};
