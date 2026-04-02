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
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        unordered_map<int, vector<int>> mp;
        for (auto& p : pieces) mp[p[0]] = p;
        int i = 0;
        while (i < arr.size()) {
            if (mp.find(arr[i]) == mp.end()) return false;
            auto& piece = mp[arr[i]];
            for (int val : piece) {
                if (i >= arr.size() || arr[i] != val) return false;
                i++;
            }
        }
        return true;
    }
};
