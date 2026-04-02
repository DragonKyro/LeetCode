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
    vector<string> findWords(vector<string>& words) {
        string rows[] = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};
        unordered_map<char, int> mp;
        for (int i = 0; i < 3; i++)
            for (char c : rows[i]) mp[c] = i;
        vector<string> result;
        for (auto& word : words) {
            int row = mp[tolower(word[0])];
            bool valid = true;
            for (char c : word) {
                if (mp[tolower(c)] != row) { valid = false; break; }
            }
            if (valid) result.push_back(word);
        }
        return result;
    }
};
