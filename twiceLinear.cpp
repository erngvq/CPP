/*
 * Twice Linear
 * -------------------------------------------------------------------------------
 * Consider a sequence u where u is defined as follows:
 *      The number u(0) = 1 is the first one in u.
 *      For each x in u, then y = 2 * x + 1 and z = 3 * x + 1 must be in u too.
 *      There are no other numbers in u.
 * 
 *      Example: u = [1, 3, 4, 7, 9, 10, 13, 15, 19, 21, 22, 27, ...]
 *                
 *               1 gives 3 and 4, then 3 gives 7 and 10, 4 gives 9 and 13,
 *               then 7 gives 15 and 22 and so on...
 * -------------------------------------------------------------------------------
 * Task: Given a parameter n, the function dbl_linear returns the element u(n) of
 * the ordered (with <) sequence u (so, there are no duplicates).
 * -------------------------------------------------------------------------------
 */

#include <iostream>
#include <vector>
using namespace std;

class DoubleLinear
{
public:
    static int dblLinear(unsigned int n)
    {
        vector<int> myvec{1};
        int i = 0, j = 0;

        while (myvec.size() <= n)
        {
            int y = 2 * myvec[i] + 1;
            int z = 3 * myvec[j] + 1;

            if (y < z)
            {
                myvec.push_back(y);
                i++;
            }
            else if (y > z)
            {
                myvec.push_back(z);
                j++;
            }
            else
            {
                myvec.push_back(y);
                i++;
                j++;
            }
        }
        return myvec[n];
    }
};

int main()
{
    DoubleLinear dl;
    cout << dl.dblLinear(10) << endl;
    cout << dl.dblLinear(20) << endl;
    cout << dl.dblLinear(30) << endl;
    cout << dl.dblLinear(40) << endl;
    cout << dl.dblLinear(50) << endl;
    cout << dl.dblLinear(100) << endl;
}
