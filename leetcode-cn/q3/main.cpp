
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string>

#include "q.cpp"

void check(int rightAnswer, int myAnswer) {
    bool judge = rightAnswer == myAnswer;
    printf("%c, rightAnswer=%d, myAnswer=%d\n", judge?'y':'n', rightAnswer, myAnswer);
}

int main(int argc, char* argv[]) {
    Solution s;
    check(3, s.lengthOfLongestSubstring("abcabcbb"));
    check(0, s.lengthOfLongestSubstring(""));
    check(1, s.lengthOfLongestSubstring(" "));
    check(2, s.lengthOfLongestSubstring("cdd"));
    check(1, s.lengthOfLongestSubstring("bbbbb"));
    check(2, s.lengthOfLongestSubstring("abba"));
    check(3, s.lengthOfLongestSubstring("pwwkew"));
    return 0;
}
