// https://leetcode.com/problems/implement-strstr/

// pattern searching: KMP https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/


// solution 2: KMP O(n) for string pattern searching
// whenever we detect a mismatch (after some matches), we already know some of the characters in the text of the next window.

    class Solution {
        public:
            int strStr(string haystack, string needle) {
                int m = haystack.size(), n = needle.size();
                if (!n) {
                    return 0;
                }
                vector<int> lps = kmpProcess(needle);
                int i = 0, j = 0;
                while(i < m) {
                    if (haystack[i] == needle[j]) { 
                        i++, j++;
                    }
                    if (j == n) {
                        return i - j;
                    }
                    else if (i < m && haystack[i] != needle[j]) {
                        if (j != 0)
                            j = lps[j-1];
                        else
                            i++;
                    }
                }
                return -1;
            }
            
        private:
            vector<int> kmpProcess(string needle) {
                int n = needle.size();
                vector<int> lps(n, 0);
                int len = 0; // length of the longest proper prefix suffix of (i-1) substring
                int i = 1;
                while(i < n) {
                    if (needle[i] == needle[len]) {
                        len++;
                        lps[i] = len;
                        i++;
                    } 
                    else{  // not equal 
                        if (len != 0) 
                            len = lps[len - 1]; // update to be next longest prefix suffix length
                        else {
                            lps[i] = 0;
                            i++;
                        }
                    }
                }
                return lps;
            }
        };
        // class Solution {
        // public:
        //     int strStr(string haystack, string needle) {
                
                
        //         if (needle == "")
        //             return 0;
                
                
        //         int res = -1;
        //         int p = 0; // represent needle index
        //         for(int i = 0; i < haystack.length(); i++) {
        //             if(haystack[i] == needle[p]){
        //                 res = i;
        //                 while(p < needle.length()){
        //                     if (needle[p++] != haystack[i++]){
        //                         i = res;
        //                         res = -1;
        //                         break;
        //                     }
        //                 }
                        
        //                 if (res != -1)
        //                     return res;
                        
        //                 p = 0;
        //             }
                        
        //         }
                
        //         return res;
        //     }
        // };