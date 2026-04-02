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
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> ban(banned.begin(), banned.end());
        unordered_map<string, int> count;
        for (auto& c : paragraph) c = isalpha(c) ? tolower(c) : ' ';
        istringstream iss(paragraph);
        string word, res;
        int maxCnt = 0;
        while (iss >> word) {
            if (!ban.count(word) && ++count[word] > maxCnt) {
                maxCnt = count[word]; res = word;
            }
        }
        return res;
    }
};
