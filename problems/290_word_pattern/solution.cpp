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
    bool wordPattern(string pattern, string s) {
        istringstream ss(s);
        vector<string> words;
        string w;
        while (ss >> w) words.push_back(w);
        if (pattern.size() != words.size()) return false;
        unordered_map<char, string> pToW;
        unordered_map<string, char> wToP;
        for (int i = 0; i < pattern.size(); i++) {
            char p = pattern[i];
            if (pToW.count(p) && pToW[p] != words[i]) return false;
            if (wToP.count(words[i]) && wToP[words[i]] != p) return false;
            pToW[p] = words[i];
            wToP[words[i]] = p;
        }
        return true;
    }
};
