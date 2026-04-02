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
    int countVowelSubstrings(string word) {
        string vowels = "aeiou";
        int count = 0;
        for (int i = 0; i < (int)word.size(); i++) {
            unordered_set<char> seen;
            for (int j = i; j < (int)word.size(); j++) {
                if (vowels.find(word[j]) == string::npos) break;
                seen.insert(word[j]);
                if (seen.size() == 5) count++;
            }
        }
        return count;
    }
};
