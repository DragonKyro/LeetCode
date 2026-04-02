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
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int i = 0;
        while (i < (int)words.size()) {
            int j = i, lineLen = 0;
            while (j < (int)words.size() && lineLen + (int)words[j].size() + (j - i) <= maxWidth) {
                lineLen += words[j].size();
                j++;
            }
            int spaces = maxWidth - lineLen;
            int gaps = j - i - 1;
            string line;
            for (int k = i; k < j; k++) {
                line += words[k];
                if (k < j - 1) {
                    int spaceCount;
                    if (j == (int)words.size()) spaceCount = 1;
                    else spaceCount = spaces / gaps + (k - i < spaces % gaps ? 1 : 0);
                    line += string(spaceCount, ' ');
                }
            }
            line += string(maxWidth - line.size(), ' ');
            result.push_back(line);
            i = j;
        }
        return result;
    }
};
