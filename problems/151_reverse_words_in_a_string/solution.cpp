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
    string reverseWords(string s) {
        istringstream iss(s);
        string word, result;
        vector<string> words;
        while (iss >> word) words.push_back(word);
        for (int i = words.size() - 1; i >= 0; i--) {
            result += words[i];
            if (i > 0) result += ' ';
        }
        return result;
    }
};
