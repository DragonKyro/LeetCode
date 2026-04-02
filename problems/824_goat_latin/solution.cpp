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
    string toGoatLatin(string sentence) {
        string vowels = "aeiouAEIOU";
        istringstream iss(sentence);
        string word, result;
        int idx = 1;
        while (iss >> word) {
            if (idx > 1) result += ' ';
            if (vowels.find(word[0]) != string::npos) result += word;
            else result += word.substr(1) + word[0];
            result += "ma" + string(idx, 'a');
            idx++;
        }
        return result;
    }
};
