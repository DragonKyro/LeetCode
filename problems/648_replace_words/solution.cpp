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
    string replaceWords(vector<string>& dictionary, string sentence) {
        set<string> roots(dictionary.begin(), dictionary.end());
        istringstream ss(sentence);
        string word, result;
        while (ss >> word) {
            string replaced = word;
            for (int i = 1; i <= (int)word.size(); i++) {
                if (roots.count(word.substr(0, i))) {
                    replaced = word.substr(0, i);
                    break;
                }
            }
            if (!result.empty()) result += " ";
            result += replaced;
        }
        return result;
    }
};
