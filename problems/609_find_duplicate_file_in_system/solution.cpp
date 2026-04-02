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
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> mp;
        for (auto& path : paths) {
            istringstream ss(path);
            string dir, file;
            ss >> dir;
            while (ss >> file) {
                int idx = file.find('(');
                string filename = file.substr(0, idx);
                string content = file.substr(idx + 1, file.size() - idx - 2);
                mp[content].push_back(dir + "/" + filename);
            }
        }
        vector<vector<string>> result;
        for (auto& [k, v] : mp) {
            if (v.size() > 1) result.push_back(v);
        }
        return result;
    }
};
