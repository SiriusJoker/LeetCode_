// LeetCode6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
        string converted_str = "";
        if (numRows == 1 || s.size() == 1) {
            return s;
        }
        for (int cur_row = 1; cur_row <= numRows; cur_row++) {
            int i = cur_row - 1;
            if (i >= s.size())
                break;
            converted_str += s[i];
            while (i < s.size()) {
                if (cur_row == 1 || cur_row == numRows) {
                    i += (numRows - 2) * 2 + 2;
                    if (i < s.size())
                        converted_str += s[i];
                    else
                        break;
                }
                else
                {
                    i += 2 + (numRows - cur_row - 1) * 2;
                    if (i < s.size())
                        converted_str += s[i];
                    else
                        break;
                    i += (cur_row - 2) * 2 + 2;
                    if (i < s.size())
                        converted_str += s[i];
                    else
                        break;
                }
            }
        }
        return converted_str;
    }
};
int main()
{
    Solution s;
    std::cout << s.convert("AB",3) << "\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
