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
    int lengthLongestPath(string input) {
        vector<int> stack;
        int maxLen = 0;
        stringstream ss(input);
        string line;
        while (getline(ss, line, '\n')) {
            int level = 0;
            while (level < line.size() && line[level] == '\t') level++;
            string name = line.substr(level);
            while ((int)stack.size() > level) stack.pop_back();
            int length = (stack.empty() ? 0 : stack.back()) + name.size() + 1;
            stack.push_back(length);
            if (name.find('.') != string::npos) maxLen = max(maxLen, length - 1);
        }
        return maxLen;
    }
};
