#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlen = 0;
        memset(m, 0, sizeof(m));
        
        int len = s.length();
        for (int i=0; i<len; ++i) {
            if (maxlen > len-i)
                break;
            int j = i;
            for (; j<len; ++j) {
                if (checkRepeat(s[j])) {
                    break;
                }
            }
            int uniqueLen = j-i;
            maxlen = maxlen > uniqueLen ? maxlen : uniqueLen;
        }
        
        return maxlen;
    }
    
    bool checkRepeat(char c) {
        if (m[c]) {
            memset(m, 0, sizeof(m));
            return true;
        }
        m[c] = 1;
        return false;
    }
private:
    char m[256];
};
