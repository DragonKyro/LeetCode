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
    string alphabetBoardPath(string target) {
        string result;
        int r = 0, c = 0;
        for (char ch : target) {
            int idx = ch - 'a';
            int tr = idx / 5, tc = idx % 5;
            while (r > tr) { result += 'U'; r--; }
            while (c > tc) { result += 'L'; c--; }
            while (r < tr) { result += 'D'; r++; }
            while (c < tc) { result += 'R'; c++; }
            result += '!';
        }
        return result;
    }
};
