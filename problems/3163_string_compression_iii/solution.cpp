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
    string compressedString(string word) {
        string res;
        int i = 0;
        while (i < word.size()) {
            char c = word[i];
            int cnt = 0;
            while (i < word.size() && word[i] == c && cnt < 9) { cnt++; i++; }
            res += to_string(cnt) + c;
        }
        return res;
    }
};
