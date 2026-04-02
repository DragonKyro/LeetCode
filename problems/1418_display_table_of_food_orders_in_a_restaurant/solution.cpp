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
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        map<int, map<string, int>> tables;
        set<string> foods;
        for (auto& o : orders) {
            int t = stoi(o[1]);
            tables[t][o[2]]++;
            foods.insert(o[2]);
        }
        vector<string> foodList(foods.begin(), foods.end());
        vector<vector<string>> res;
        vector<string> header = {"Table"};
        for (auto& f : foodList) header.push_back(f);
        res.push_back(header);
        for (auto& [t, m] : tables) {
            vector<string> row = {to_string(t)};
            for (auto& f : foodList) row.push_back(to_string(m[f]));
            res.push_back(row);
        }
        return res;
    }
};
