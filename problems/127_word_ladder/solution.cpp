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
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (wordSet.find(endWord) == wordSet.end()) return 0;
        queue<string> q;
        q.push(beginWord);
        unordered_set<string> visited = {beginWord};
        int length = 1;
        while (!q.empty()) {
            int size = q.size();
            for (int s = 0; s < size; s++) {
                string word = q.front(); q.pop();
                for (int i = 0; i < word.size(); i++) {
                    char orig = word[i];
                    for (char c = 'a'; c <= 'z'; c++) {
                        word[i] = c;
                        if (word == endWord) return length + 1;
                        if (wordSet.count(word) && !visited.count(word)) {
                            visited.insert(word);
                            q.push(word);
                        }
                    }
                    word[i] = orig;
                }
            }
            length++;
        }
        return 0;
    }
};
