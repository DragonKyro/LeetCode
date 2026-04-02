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
    int isPrefixOfWord(string sentence, string searchWord) {
        istringstream iss(sentence);
        string word;
        int idx = 1;
        while (iss >> word) {
            if (word.substr(0, searchWord.size()) == searchWord) return idx;
            idx++;
        }
        return -1;
    }
};
