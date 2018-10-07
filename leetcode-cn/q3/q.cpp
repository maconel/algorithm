#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlen = 0;
        memset(c2i, 0xff, sizeof(c2i));
        
        int len = s.length();
        for (int i=0; i<len; ++i) {
            if (maxlen > len-i)
                break;
            int j = i;
            int begin = i;
            for (; j<len; ++j) {
                int prevRepeatPos = checkRepeat(s, j);
                if (prevRepeatPos >= 0) {
                    i = prevRepeatPos;
                    break;
                }
            }
            int uniqueLen = j-begin;
            maxlen = maxlen > uniqueLen ? maxlen : uniqueLen;
        }
        
        return maxlen;
    }
    
    int checkRepeat(const string& s, int curr) {
        char c = s[curr];
        if (c2i[c] >= 0) {
            int prevRepeatPos = c2i[c];
            memset(c2i, 0xff, sizeof(c2i));
            return prevRepeatPos;
        }
        c2i[c] = curr;
        return -1;
    }
private:
    int c2i[256];
};
