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
    string simplifyPath(string path) {
        vector<string> stack;
        stringstream ss(path);
        string part;
        while (getline(ss, part, '/')) {
            if (part == "..") { if (!stack.empty()) stack.pop_back(); }
            else if (!part.empty() && part != ".") stack.push_back(part);
        }
        string result;
        for (auto& s : stack) result += "/" + s;
        return result.empty() ? "/" : result;
    }
};
