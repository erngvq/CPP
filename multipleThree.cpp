/*
 * Binary Multiples of Three
 * ----------------------------------------------------------------------------------------------
 * Create a regular expression capable of evaluating binary strings (strings with only 1s and 0s)
 * and determining whether the given string represents a number divisible by 3.
 * ----------------------------------------------------------------------------------------------
 * Take into account that:
 * 
 * -- An empty string might be evaluated to true.
 * -- The input should consist only of binary digits, no spaces, alphanumeric characters, etc.
 * -- There might be leading 0s.
 * ----------------------------------------------------------------------------------------------
 * Examples:
 * 
 * multipleThree("000") should print true
 * multipleThree("001") should print false
 * multipleThree("011") should print true
 * ----------------------------------------------------------------------------------------------
 */

#include <iostream>
#include <regex>
using namespace std;

void multipleThree(string binary_str)
{
    regex re("(1(01*0)*1|0)*");

    if (regex_match(binary_str, re)) cout << boolalpha << true << endl;
    else cout << boolalpha << false << endl;
}

int main()
{
    multipleThree("");      // true
    multipleThree(" 0");    // false
    multipleThree("abc");   // false
    multipleThree("000");   // true
    multipleThree("110");   // true
    multipleThree("111");   // false
    multipleThree("011");   // true
    multipleThree("101111000110000101001110"); // 12345678 --> true
}
