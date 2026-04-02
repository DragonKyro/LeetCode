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
    string reorderSpaces(string text) {
        int spaces = count(text.begin(), text.end(), ' ');
        vector<string> words;
        istringstream iss(text);
        string w;
        while (iss >> w) words.push_back(w);
        if (words.size() == 1) return words[0] + string(spaces, ' ');
        int gap = spaces / (words.size() - 1);
        int extra = spaces % (words.size() - 1);
        string res;
        for (int i = 0; i < (int)words.size(); i++) {
            if (i > 0) res += string(gap, ' ');
            res += words[i];
        }
        res += string(extra, ' ');
        return res;
    }
};
