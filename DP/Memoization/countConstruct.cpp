#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

int countConstruct(string target, vector<string> wordBank, unordered_map<string, int> &memo)
{
    if (memo.find(target) != memo.end()) return memo[target];
    if (target == "") return 1;

    int counter = 0;

    for (string word : wordBank)
    {
        if (target.find(word) == 0)
        {
            int numWays = countConstruct(target.substr(word.length()), wordBank, memo);
            counter += numWays;
        }
    }
    memo[target] = counter;
    return counter;
}

int main()
{
    vector<pair<string, vector<string>>> tests{
        {"purple", {"purp", "p", "ur", "le", "purpl"}},                                                 // 2
        {"abcdef", {"ab", "abc", "cd", "def", "abcd"}},                                                 // 1
        {"skateboard", {"bo", "rd", "ate", "t", "ska", "sk", "boar"}},                                  // 0
        {"enterapotentpot", {"a", "p", "ent", "enter", "ot", "o", "t"}},                                // 4
        {"eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", {"e", "ee", "eee", "eeee", "eeeee", "eeeeee"}}     // 0
    };

    for (auto test : tests)
    {
        unordered_map<string, int> memo;
        cout << boolalpha << countConstruct(test.first, test.second, memo) << endl;
    }
}
