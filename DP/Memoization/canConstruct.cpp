#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

bool canConstruct(string target, vector<string> wordBank, unordered_map<string, bool> &memo)
{
    if (memo.find(target) != memo.end()) return memo[target];
    if (target == "") return true;

    for (string word : wordBank)
    {
        if (target.find(word) != 0) continue;
        
        string tmp = target.substr(word.size());
        
        // string tmp = target;
        // tmp.erase(0, word.size());
        
        if (canConstruct(tmp, wordBank, memo))
        {
            memo[target] = true;
            return true;
        }
    }
    memo[target] = false;
    return false;
}

int main()
{
    vector<pair<string, vector<string>>> tests{
        {"abcdef", {"ab", "abc", "cd", "def", "abcd"}},                                                 // true
        {"skateboard", {"bo", "rd", "ate", "t", "ska", "sk", "boar"}},                                  // false
        {"enterapotentpot", {"a", "p", "ent", "enter", "ot", "o", "t"}},                                // true
        {"eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", {"e", "ee", "eee", "eeee", "eeeee", "eeeeee"}},    // false
        {"eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", {"ef", "ee", "eee", "eeee", "eeeee", "eeeee"}}     // true
    };

    for (auto test : tests)
    {
        unordered_map<string, bool> memo;
        cout << boolalpha << canConstruct(test.first, test.second, memo) << endl;

        // for (auto key : memo)
        //     cout << key.first << " -> " << key.second << endl;
        // cout << endl;
    }
}
