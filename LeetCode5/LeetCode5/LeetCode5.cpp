// LeetCode5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//https://leetcode.com/problems/longest-palindromic-substring/description/
// slow solution
#include <iostream>
#include <string>

using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {

        // if the string is empty, then the longestPalindrome is epmty too

        if (s.size() == 0) {
            return "";
        }

        // if the string is not empty, the easiest palindrome is one character
        // taking that character as string to comparison while searching for longer palindromes

        string palindrome = s.substr(0, 1);
        string palindrometest = s.substr(0, 1);
        bool is_palindrome = true;

        // Starting from the beginning and end of the string to check for palindromes inside

        for (int i = 0; i < s.size(); i++) {
            for (int j = s.size() - 1; j > i; j--)
            {
                // If number of characters is less then current palindrome, its not worth considering
                    // !!! This may be a point where optimization can be applied

                if (j - i < palindrome.size()) {
                    break;
                }
                if (s[i] == s[j])
                {
                    is_palindrome = true;
                    palindrometest = s.substr(i, j - i + 1);
                    int n = j - 1;

                    // found matching characters, checking if there is palindrom inside

                    for (int k = i + 1; k < n; k++) {
                        if (s[k] != s[n]) {
                            is_palindrome = false;
                            break;
                        }
                        else {
                            n--;
                            is_palindrome = true;
                        }
                    }

                    if (is_palindrome) {

                        // found palindrome, checking if it longer than previous one

                        if (palindrometest.size() > palindrome.size()) {
                            palindrome= palindrometest;
                        }
                    }
                }
            }
        }
        return palindrome;
    }
};
int main()
{
    Solution s;
    cout << s.longestPalindrome("aacabdkacaa");
}

