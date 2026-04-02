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
    string findLongestWord(string s, vector<string>& dictionary) {
        sort(dictionary.begin(), dictionary.end(), [](auto& a, auto& b) {
            return a.size() != b.size() ? a.size() > b.size() : a < b;
        });
        for (auto& word : dictionary) {
            int i = 0;
            for (int j = 0; j < (int)s.size() && i < (int)word.size(); j++)
                if (word[i] == s[j]) i++;
            if (i == (int)word.size()) return word;
        }
        return "";
    }
};
