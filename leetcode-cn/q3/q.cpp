#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string>
#include <iostream>

using namespace std;

static const auto _____ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlen = 0;
        int c2i[256];
        memset(c2i, 0xff, sizeof(c2i));
        
        int len = s.length();
        int begin = 0;
        int i = 0;
        for (; i<len; ++i) {
            char c = s[i];
            if (c2i[c] >= begin) {
                maxlen = max(maxlen, i - begin);
                begin = c2i[c] + 1;
            }
            c2i[c] = i;
        }
        if (i == len) {
            maxlen = max(maxlen, i - begin);
        }
        
        return maxlen;
    }
};
