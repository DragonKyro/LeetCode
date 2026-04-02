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
    bool areSentencesSimilar(string sentence1, string sentence2) {
        auto split = [](string& s) {
            vector<string> res;
            istringstream iss(s);
            string w;
            while (iss >> w) res.push_back(w);
            return res;
        };
        auto w1 = split(sentence1), w2 = split(sentence2);
        if (w1.size() > w2.size()) swap(w1, w2);
        int n1 = w1.size(), n2 = w2.size();
        int left = 0;
        while (left < n1 && w1[left] == w2[left]) left++;
        int right = 0;
        while (right < n1 - left && w1[n1 - 1 - right] == w2[n2 - 1 - right]) right++;
        return left + right >= n1;
    }
};
