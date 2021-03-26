#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> bestSum(int target, vector<int> numbers, unordered_map<int, vector<int>> &memo)
{
    if (memo.find(target) != memo.end()) return memo[target];

    if (target < 0) return {-1};
    if (target == 0) return {};

    vector<int> shortest{-1};

    for (int num : numbers)
    {
        int remainder = target - num;
        vector<int> combination = bestSum(remainder, numbers, memo);
        if (combination.size() == 0 || combination[0] != -1)
        {
            combination.push_back(num);

            if (shortest[0] == -1 || combination.size() < shortest.size())
                shortest = combination;
        }
    }
    memo[target] = shortest;
    return shortest;
}

void print(vector<int> vec)
{
    for (int i : vec) cout << i << " ";
    cout << endl;
}

int main()
{
    vector<pair<int, vector<int>>> tests{{7, {5, 3, 4, 7}},         // [7]
                                         {8, {2, 3, 5}},            // [3, 5]
                                         {8, {1, 4, 5}},            // [4, 4]
                                         {100, {1, 2, 5, 25}}};     // [25, 25, 25, 25]
    for (pair<int, vector<int>> test : tests)
    {
        unordered_map<int, vector<int>> memo;
        print(bestSum(test.first, test.second, memo));
    }
}
