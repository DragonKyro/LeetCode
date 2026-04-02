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
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (wordSet.find(endWord) == wordSet.end()) return {};
        unordered_map<string, vector<vector<string>>> layer;
        layer[beginWord] = {{beginWord}};
        while (!layer.empty()) {
            unordered_map<string, vector<vector<string>>> newLayer;
            for (auto& [word, paths] : layer) {
                if (word == endWord) return paths;
                string temp = word;
                for (int i = 0; i < temp.size(); i++) {
                    char orig = temp[i];
                    for (char c = 'a'; c <= 'z'; c++) {
                        temp[i] = c;
                        if (wordSet.count(temp)) {
                            for (auto& path : paths) {
                                vector<string> newPath = path;
                                newPath.push_back(temp);
                                newLayer[temp].push_back(newPath);
                            }
                        }
                    }
                    temp[i] = orig;
                }
            }
            for (auto& [w, _] : newLayer) wordSet.erase(w);
            layer = newLayer;
        }
        return {};
    }
};
