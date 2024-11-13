// LeetCode6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// https://leetcode.com/problems/zigzag-conversion/description/
#include <iostream>
#include <string>

using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
        string converted_str = "";
        if (numRows == 1 || s.size() == 1 || s.size()<=numRows) {
            return s;
        }
        for (int cur_row = 1; cur_row <= numRows; cur_row++) {
            int i = cur_row - 1;
            if (i >= s.size())
                break;

            // first element of each row is s[number of row -1]

            converted_str += s[i];
            while (i < s.size()) {

                //processing boundary conditions first and last row
                // every other row will have two elements 
                // before finding current element to add to converted_str

                if (cur_row == 1 || cur_row == numRows) {
                    i += (numRows - 2) * 2 + 2;
                    if (i < s.size())
                        converted_str += s[i];
                    else
                        break;
                }
                else

                    //processing inner rows
                    // last and first rows will have 1 element
                    // while the inner rows will have two elements 
                    // before finding current element to add to converted_str

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
