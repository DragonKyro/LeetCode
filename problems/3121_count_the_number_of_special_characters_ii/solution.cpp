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
    int numberOfSpecialChars(string word) {
        vector<int> lastLower(26, -1), firstUpper(26, -1);
        for (int i = 0; i < word.size(); i++) {
            if (islower(word[i])) lastLower[word[i]-'a'] = i;
            else if (firstUpper[word[i]-'A'] == -1) firstUpper[word[i]-'A'] = i;
        }
        int res = 0;
        for (int i = 0; i < 26; i++)
            if (lastLower[i] != -1 && firstUpper[i] != -1 && lastLower[i] < firstUpper[i]) res++;
        return res;
    }
};
