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
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> res = {folder[0]};
        for (int i = 1; i < (int)folder.size(); i++) {
            string prev = res.back() + "/";
            if (folder[i].substr(0, prev.size()) != prev)
                res.push_back(folder[i]);
        }
        return res;
    }
};
