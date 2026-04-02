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
    bool isCircularSentence(string sentence) {
        vector<string> words;
        stringstream ss(sentence);
        string w;
        while (ss >> w) words.push_back(w);
        for (int i = 0; i < words.size(); i++) {
            if (words[i].back() != words[(i+1) % words.size()].front()) return false;
        }
        return true;
    }
};
