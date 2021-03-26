/*
 * The following code verifies if two vectors are similar according to the following
 * definition: two vectors or arrays are called similar if one can be obtained from
 * another by swapping at most one pair of elements in one of the arrays. Testing
 * examples are provided in the main function.
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// Long Version
bool similarVecsLong(vector<int> vec1, vector<int> vec2)
{
    if (vec1.size() != vec2.size()) return false;
    
    unordered_map<int, vector<int>> mymap;
    for (int i = 0; i < vec2.size(); i++) mymap[vec2[i]].push_back(i);

    int counter = 0;
    for (int i = 0; i < vec1.size(); i++)
    {
        if (vec1[i] == vec2[i]) continue;
        else
        {
            counter++;
            if (counter > 1) return false;

            if (mymap[vec1[i]].size() == 0) return false;

            while (vec2[mymap[vec1[i]][0]] == vec1[mymap[vec1[i]][0]])
            {
                if (mymap[vec1[i]].size() == 0) return false;
                mymap[vec1[i]].erase(mymap[vec1[i]].begin());
            }
            swap(vec2[mymap[vec1[i]][0]], vec2[i]);
            mymap[vec1[i]].erase(mymap[vec1[i]].begin());
        }
    }
    return true;
}

// Short (Clever) Version
bool similarVecsShort(vector<int> vec1, vector<int> vec2)
{
    int counter = 0, equal = 1;
    for (int i = 0; i < vec1.size(); i++)
        if (vec1[i] != vec2[i]) counter++;
    
    sort(vec1.begin(), vec1.end());
    sort(vec2.begin(), vec2.end());

    for (int i = 0; i < vec1.size(); i++)
    {
        if (vec1[i] != vec2[i]) equal = 0;
        break;
    }
    return (equal && counter < 3);
}

int main()
{
    cout << boolalpha << similarVecsLong({1, 2, 3}, {1, 2, 3}) << endl;                                    // true
    cout << boolalpha << similarVecsLong({1, 2, 3}, {2, 1, 3}) << endl;                                    // true
    cout << boolalpha << similarVecsLong({1, 2, 2}, {2, 1, 1}) << endl;                                    // false
    cout << boolalpha << similarVecsLong({1, 1, 4}, {1, 2, 3}) << endl;                                    // false
    cout << boolalpha << similarVecsLong({2, 3, 1}, {1, 3, 2}) << endl;                                    // true

    cout << boolalpha << similarVecsShort({832, 998, 148, 570, 533, 561, 894, 147, 455, 279},
                                          {832, 998, 148, 570, 533, 561, 455, 147, 894, 279}) << endl;     // true
    cout << boolalpha << similarVecsShort({832, 998, 148, 570, 533, 561, 894, 147, 455, 279},
                                          {832, 570, 148, 998, 533, 561, 455, 147, 894, 279}) << endl;     // false
    cout << boolalpha << similarVecsShort({1, 2, 2, 2, 2, 2, 3, 4},
                                          {1, 3, 2, 2, 2, 2, 2, 4}) << endl;                               // true
}
