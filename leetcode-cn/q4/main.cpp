
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string>
#include <vector>
#include <sstream>

#include "q.cpp"

using namespace std;

vector<int> makeVector(int size, ...) {
    vector<int> v;
    va_list ap;
    va_start(ap, size);
    for (int i=0; i<size; ++i) {
        v.push_back(va_arg(ap, int));
    }
    va_end(ap);
    return v;
}

string vectorToString(vector<int>& nums) {
    ostringstream oss;
    for (int i=0; i<nums.size() - 1; ++i) {
        oss << nums[i] << ",";
    }
    oss << nums[nums.size()-1] << endl;
    return oss.str();
}

void check(int rightAnswer, int myAnswer) {
    bool judge = rightAnswer == myAnswer;
    printf("%c, rightAnswer=%d, myAnswer=%d\n", judge?'y':'n', rightAnswer, myAnswer);
}

void check2(double rightAnswer, double myAnswer) {
    bool judge = (rightAnswer - myAnswer) < 0.001;
    printf("%c, rightAnswer=%f, myAnswer=%f\n", judge?'y':'n', rightAnswer, myAnswer);
}

int main(int argc, char* argv[]) {
    Solution s;
    vector<int> v;
    vector<int> v1;
    vector<int> v2;

    printf("find match or left\n");
    v = makeVector(3, 1, 2, 3);
    for (int i=0; i<v.size(); ++i) {
        check(i, s.findElement(v, v[i], -1));
    }
    printf("\n");

    v = makeVector(7, 1, 6, 13, 24, 35, 46, 57);
    for (int i=0; i<v.size(); ++i) {
        check(i, s.findElement(v, v[i], -1));
    }
    printf("\n");

    v = makeVector(7, 1, 2, 2, 3, 3, 3, 3);
    check(0, s.findElement(v, 1, -1));
    check(1, s.findElement(v, 2, -1));
    check(3, s.findElement(v, 3, -1));
    printf("\n");

    v = makeVector(3, 1, 3, 5);
    check(0, s.findElement(v, 2, -1));
    check(1, s.findElement(v, 4, -1));
    check(2, s.findElement(v, 6, -1));
    printf("\n");

    printf("find match or right\n");
    v = makeVector(3, 1, 2, 3);
    for (int i=0; i<v.size(); ++i) {
        check(i, s.findElement(v, v[i], 1));
    }
    printf("\n");

    v = makeVector(7, 1, 6, 13, 24, 35, 46, 57);
    for (int i=0; i<v.size(); ++i) {
        check(i, s.findElement(v, v[i], 1));
    }
    printf("\n");

    v = makeVector(7, 1, 2, 2, 3, 3, 3, 3);
    check(0, s.findElement(v, 1, 1));
    check(2, s.findElement(v, 2, 1));
    check(6, s.findElement(v, 3, 1));
    printf("\n");

    v = makeVector(3, 1, 3, 5);
    check(0, s.findElement(v, 2, 1));
    check(1, s.findElement(v, 4, 1));
    check(2, s.findElement(v, 6, 1));
    printf("\n");



    printf("find median\n");
    v1 = makeVector(2, 0, 2);
    v2 = makeVector(1, 1);
    check2(1, s.findMedianSortedArrays(v1, v2));

    v1 = makeVector(2, 1, 2);
    v2 = makeVector(2, 3, 4);
    check2(2.5, s.findMedianSortedArrays(v1, v2));

    v1 = makeVector(3, 1, 2, 3);
    v2 = makeVector(2, 2, 5);
    check2(2.5, s.findMedianSortedArrays(v1, v2));

    v1 = makeVector(3, 1, 2, 4);
    v2 = makeVector(3, 2, 5, 6);
    check2(4, s.findMedianSortedArrays(v1, v2));

    v1 = makeVector(3, 1, 2, 4);
    v2 = makeVector(4, 2, 3, 5, 6);
    check2(3.5, s.findMedianSortedArrays(v1, v2));

    v1 = makeVector(0);
    v2 = makeVector(1, 1);
    check2(0.5, s.findMedianSortedArrays(v1, v2));

    return 0;
}
