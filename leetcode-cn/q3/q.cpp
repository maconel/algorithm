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
            int begin = i;
            for (; j<len; ++j) {
                int lastpos = checkRepeat(s[j], j);
                if (lastpos >= 0) {
                    i = lastpos;
                    break;
                }
            }
            int uniqueLen = j-begin;
            maxlen = maxlen > uniqueLen ? maxlen : uniqueLen;
        }
        
        return maxlen;
    }
    
    int checkRepeat(char c, int pos) {
        if (m[c]) {
            int lastpos = m[c] - 1;
            memset(m, 0, sizeof(m));
            return lastpos;
        }
        m[c] = pos + 1;
        return -1;
    }
private:
    int m[256];
};
