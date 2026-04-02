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
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        map<int, int> m;
        for (auto& i : items1) m[i[0]] += i[1];
        for (auto& i : items2) m[i[0]] += i[1];
        vector<vector<int>> result;
        for (auto& [k, v] : m) result.push_back({k, v});
        return result;
    }
};
