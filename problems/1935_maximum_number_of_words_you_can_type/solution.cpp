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
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char> broken(brokenLetters.begin(), brokenLetters.end());
        int count = 0;
        istringstream iss(text);
        string word;
        while (iss >> word) {
            bool ok = true;
            for (char c : word) if (broken.count(c)) { ok = false; break; }
            if (ok) count++;
        }
        return count;
    }
};
