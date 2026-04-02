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
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> mp;
        for (auto e : employees) mp[e->id] = e;
        function<int(int)> dfs = [&](int id) -> int {
            auto e = mp[id];
            int total = e->importance;
            for (int sub : e->subordinates) total += dfs(sub);
            return total;
        };
        return dfs(id);
    }
};
