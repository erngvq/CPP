#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

vector<vector<string>> allConstruct(string target, vector<string> wordBank,
                                                   unordered_map<string, vector<vector<string>>> &memo)
{
    if (memo.find(target) != memo.end()) return memo[target];
    if (target == "") return {{}};

    vector<vector<string>> ret;

    for (string word : wordBank)
    {
        if (target.find(word) == 0)
        {
            string suff = target.substr(word.size());
            vector<vector<string>> suffWays = allConstruct(suff, wordBank, memo);
        
            vector<vector<string>> targetWays;
            for (vector<string> vec : suffWays)
            {
                vec.insert(vec.begin(), word);
                targetWays.push_back(vec);
            }
            
            for (vector<string> vec : targetWays)
                ret.push_back(vec);
        }
    }
    memo[target] = ret;
    return ret;
}

void print(vector<vector<string>> matrix)
{
    for (vector<string> vec : matrix)
    {
        for (string s : vec)
            cout << s << ", ";
        cout << endl;
    }
}

int main()
{
    vector<pair<string, vector<string>>> tests{
        {"purple", {"purp", "p", "ur", "le", "purpl"}},
        {"abcdef", {"ab", "abc", "cd", "def", "abcd"}},
        {"skateboard", {"bo", "rd", "ate", "t", "ska", "sk", "boar"}},
        {"enterapotentpot", {"a", "p", "ent", "enter", "ot", "o", "t"}},
        {"eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", {"e", "ee", "eee", "eeee", "eeeee", "eeeeee"}}
    };

    for (auto test : tests)
    {
        unordered_map<string, vector<vector<string>>> memo;
        vector<vector<string>> ret = allConstruct(test.first, test.second, memo);
        print(ret);
        cout << "-------------" << endl;
    }
}
