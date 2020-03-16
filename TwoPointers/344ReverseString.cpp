/*
Write a function that reverses a string. The input string is given as an array of characters char[].

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

You may assume all the characters consist of printable ascii characters.

*/

class Solution {
public:
    void reverseString(vector<char>& s) {
        int size = s.size()-1;
        int l = 0;
        int r = size;
        
        while(l <= r)
        {
            char temp = s[r];
            s[r--] = s[l];
            s[l++] = temp;
            
            // or use swap function 
            // swap(s[r--], s[l++]);
        }
    }
};
