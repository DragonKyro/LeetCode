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
    int addMinimum(string word) {
        string t = "abc";
        int ans = 0, j = 0, i = 0;
        while (i < word.size()) {
            if (word[i] == t[j]) i++;
            else ans++;
            j = (j+1)%3;
        }
        return ans + (3-j)%3;
    }
};
