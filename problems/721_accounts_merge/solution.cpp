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
    unordered_map<string, string> parent;

    string find(string x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(string x, string y) {
        parent[find(x)] = find(y);
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, string> emailToName;
        for (auto& acc : accounts) {
            for (int i = 1; i < (int)acc.size(); i++) {
                if (!parent.count(acc[i])) parent[acc[i]] = acc[i];
                emailToName[acc[i]] = acc[0];
                unite(acc[i], acc[1]);
            }
        }
        unordered_map<string, set<string>> groups;
        for (auto& [email, _] : parent) groups[find(email)].insert(email);
        vector<vector<string>> result;
        for (auto& [root, emails] : groups) {
            vector<string> list = {emailToName[root]};
            list.insert(list.end(), emails.begin(), emails.end());
            result.push_back(list);
        }
        return result;
    }
};
