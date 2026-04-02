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
    int expressiveWords(string s, vector<string>& words) {
        int count = 0;
        for (auto& w : words) if (isStretchy(s, w)) count++;
        return count;
    }
    bool isStretchy(string& s, string& w) {
        int i = 0, j = 0;
        while (i < s.size() && j < w.size()) {
            if (s[i] != w[j]) return false;
            int si = i, wj = j;
            while (i < s.size() && s[i] == s[si]) i++;
            while (j < w.size() && w[j] == w[wj]) j++;
            int sLen = i - si, wLen = j - wj;
            if (sLen < wLen || (sLen != wLen && sLen < 3)) return false;
        }
        return i == s.size() && j == w.size();
    }
};
