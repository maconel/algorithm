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
        int currRepeatPos = 0;
        for (int i=0; i<len; ++i) {
            if (maxlen > len-i)
                break;
            int j = i > currRepeatPos ? i : currRepeatPos;
            int begin = i;
            for (; j<len; ++j) {
                int prevRepeatPos = checkRepeat(s, begin, j);
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
    
    int checkRepeat(const string& s, int begin, int curr) {
        char c = s[curr];
        if (c2i[c] >= 0) {
            int prevRepeatPos = c2i[c];
            c2i[c] = curr;
            /*
            for (int i=0; i<256; ++i) {
                if (c2i[i] < prevRepeatPos)
                    c2i[i] = -1;
            }
            */
            for (int i=begin; i<prevRepeatPos; ++i) {
                c2i[s[i]] = -1;
            }
            return prevRepeatPos;
        }
        c2i[c] = curr;
        return -1;
    }
private:
    int c2i[256];
};
