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
    bool isAlienSorted(vector<string>& words, string order) {
        int map[26];
        for (int i = 0; i < 26; i++) map[order[i] - 'a'] = i;
        for (int i = 0; i < words.size() - 1; i++) {
            for (int j = 0; j < words[i].size(); j++) {
                if (j >= words[i + 1].size()) return false;
                if (words[i][j] != words[i + 1][j]) {
                    if (map[words[i][j] - 'a'] > map[words[i + 1][j] - 'a']) return false;
                    break;
                }
            }
        }
        return true;
    }
};
