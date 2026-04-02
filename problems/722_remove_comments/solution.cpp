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
    vector<string> removeComments(vector<string>& source) {
        vector<string> result;
        bool inBlock = false;
        string newLine;
        for (auto& line : source) {
            int i = 0;
            if (!inBlock) newLine = "";
            while (i < (int)line.size()) {
                if (!inBlock && i + 1 < (int)line.size() && line[i] == '/' && line[i+1] == '*') {
                    inBlock = true; i += 2;
                } else if (inBlock && i + 1 < (int)line.size() && line[i] == '*' && line[i+1] == '/') {
                    inBlock = false; i += 2;
                } else if (!inBlock && i + 1 < (int)line.size() && line[i] == '/' && line[i+1] == '/') {
                    break;
                } else if (!inBlock) {
                    newLine += line[i++];
                } else { i++; }
            }
            if (!inBlock && !newLine.empty()) result.push_back(newLine);
        }
        return result;
    }
};
