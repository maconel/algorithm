#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

static const auto _____ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int pInNums2 = 0;
        int pInNums1 = nums1.size() / 2;
        int v = nums1[pInNums1];

        pInNums2 = findElement(nums2, v, -1);
        if (nums2.size() % 2 == 1 && pInNums2 == (nums2.size() / 2) + 1)
            return v;

        if (nums2.size() % 2 == 0) {
            if (pInNums2 == nums2.size() / 2) {
                int v1 = nums1[pInNums1 + 1];
                int v2 = nums2[pInNums2 + 1];
                if (v1 < v2)
                    return (v + v1) / 2.0;
                else
                    return (v + v2) / 2.0;
            }
            if (pInNums2 == (nums2.size() / 2) + 1) {
                int v1 = nums1[pInNums1 - 1];
                int v2 = nums2[pInNums2 - 1];
                if (v1 > v2)
                    return (v + v1) / 2.0;
                else
                    return (v + v2) / 2.0;
            }
        }

        if (pInNums2 < nums2.size() / 2)
            return findMedianInRight(nums1, nums2, pInNums1, pInNums2);
        else
            return findMedianInLeft(nums1, nums2, pInNums1, pInNums2);
    }

    double findMedianInRight(vector<int>& nums1, vector<int>& nums2, int pInNums1, int pInNums2) {
        //
    }

    double findMedianInLeft(vector<int>& nums1, vector<int>& nums2, int pInNums1, int pInNums2) {
        //
    }

    int findElement(vector<int>& nums, int value, int firstOrLast) {
        int begin = 0;
        int end = nums.size() - 1;
        int pos = 0;
        
        while (begin < end) {
            pos = begin + (end - begin) / 2;
            if (nums[pos] > value)
                end = pos = pos - 1;
            else if (nums[pos] < value)
                begin = pos = pos + 1;
            else {
                if (firstOrLast < 0)
                    end = pos;
                else if (firstOrLast > 0)
                    begin = pos = pos + 1;
                else
                    break;
            }
        }

        return nums[pos] <= value ? pos : pos - 1;
    }
};
