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
    int mostWordsFound(vector<string>& sentences) {
        int maxWords = 0;
        for (const string& s : sentences) {
            int words = count(s.begin(), s.end(), ' ') + 1;
            maxWords = max(maxWords, words);
        }
        return maxWords;
    }
};
