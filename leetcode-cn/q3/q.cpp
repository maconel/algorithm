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
        int currRepeatPos = 0;
        for (int i=0; i<len; ++i) {
            if (maxlen > len-i)
                break;
            int j = i > currRepeatPos ? i : currRepeatPos;
            int begin = i;
            for (; j<len; ++j) {
                int prevRepeatPos = checkRepeat(s[j], j);
                if (prevRepeatPos >= 0) {
                    i = prevRepeatPos;
                    currRepeatPos = j + 1;
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
            m[c] = pos + 1;
            //memset(m, 0, sizeof(m));
            for (int i=0; i<256; ++i) {
                if (m[i] < lastpos + 1)
                    m[i] = 0;
            }
            return lastpos;
        }
        m[c] = pos + 1;
        return -1;
    }
private:
    int m[256];
};
