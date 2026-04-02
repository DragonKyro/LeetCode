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
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> words, result;
        istringstream iss(text);
        string w;
        while (iss >> w) words.push_back(w);
        for (int i = 0; i + 2 < words.size(); i++)
            if (words[i] == first && words[i+1] == second)
                result.push_back(words[i+2]);
        return result;
    }
};
