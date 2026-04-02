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
    string freqAlphabets(string s) {
        string res;
        int i = s.size() - 1;
        while (i >= 0) {
            if (s[i] == '#') {
                int num = stoi(s.substr(i-2, 2));
                res += (char)('a' + num - 1);
                i -= 3;
            } else {
                res += (char)('a' + s[i] - '1');
                i--;
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
