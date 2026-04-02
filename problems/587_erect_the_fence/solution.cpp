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
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        sort(trees.begin(), trees.end());
        int n = trees.size();
        if (n <= 1) return trees;
        auto cross = [](vector<int>& o, vector<int>& a, vector<int>& b) {
            return (a[0]-o[0])*(b[1]-o[1]) - (a[1]-o[1])*(b[0]-o[0]);
        };
        vector<vector<int>> hull;
        for (auto& p : trees) {
            while (hull.size() >= 2 && cross(hull[hull.size()-2], hull[hull.size()-1], p) < 0)
                hull.pop_back();
            hull.push_back(p);
        }
        int lower = hull.size();
        for (int i = n - 2; i >= 0; i--) {
            while ((int)hull.size() > lower && cross(hull[hull.size()-2], hull[hull.size()-1], trees[i]) < 0)
                hull.pop_back();
            hull.push_back(trees[i]);
        }
        set<pair<int,int>> seen;
        vector<vector<int>> res;
        for (auto& p : hull)
            if (seen.insert({p[0], p[1]}).second) res.push_back(p);
        return res;
    }
};
