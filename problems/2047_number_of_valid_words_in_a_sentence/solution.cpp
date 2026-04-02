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
    int countValidWords(string sentence) {
        int count = 0;
        istringstream iss(sentence);
        string token;
        while (iss >> token) {
            if (isValid(token)) count++;
        }
        return count;
    }
    bool isValid(const string& token) {
        int hyphen = 0;
        for (int i = 0; i < (int)token.size(); i++) {
            char c = token[i];
            if (isdigit(c)) return false;
            if (c == '-') {
                hyphen++;
                if (hyphen > 1) return false;
                if (i == 0 || i == (int)token.size() - 1) return false;
                if (!isalpha(token[i - 1]) || !isalpha(token[i + 1])) return false;
            }
            if (string("!.,;").find(c) != string::npos && i != (int)token.size() - 1) return false;
        }
        return true;
    }
};
