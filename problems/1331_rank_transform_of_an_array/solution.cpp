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
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> sorted_arr = arr;
        sort(sorted_arr.begin(), sorted_arr.end());
        sorted_arr.erase(unique(sorted_arr.begin(), sorted_arr.end()), sorted_arr.end());
        unordered_map<int,int> rank;
        for (int i = 0; i < (int)sorted_arr.size(); i++) rank[sorted_arr[i]] = i + 1;
        vector<int> res;
        for (int x : arr) res.push_back(rank[x]);
        return res;
    }
};
