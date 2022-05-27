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
        if (nums1.size() == nums2.size() && (*nums1.rbegin()) < (*nums2.begin()))
            return ((*nums1.rbegin()) + (*nums2.begin())) / 2.0;

        vector<int>* middleArray = NULL;
        int beginPos = 0;
        int endPos = 0;
        
        if (nums1.size() <= nums2.size()) {
            endPos = findMiddleArrayPosWhen1IsSmall(nums1, nums2);
            middleArray = &nums2;
        } else if (nums1.size() > nums2.size()) {
            beginPos = findMiddleArrayPosWhen2IsSmall(nums1, nums2);
            endPos = nums1.size() - 1;
            middleArray = &nums1;
        }
        
        double median = 0;
        int middleArrayLen = endPos - beginPos;
        if ((middleArrayLen) % 2 == 0) {
            median = (*middleArray)[beginPos + middleArrayLen / 2];
        } else {
            int middlePos = beginPos + (middleArrayLen - 1) / 2;
            median = ((*middleArray)[middlePos] + (*middleArray)[middlePos+1]) / 2.0;
        }
        
        return median;
    }
    
    int findMiddleArrayPosWhen1IsSmall(vector<int>& nums1, vector<int>& nums2) {
        int coincidePosInNums1 = findElement(nums1, nums2[0], 1);
        return nums2.size() - coincidePosInNums1 - 1;
    }
    
    int findMiddleArrayPosWhen2IsSmall(vector<int>& nums1, vector<int>& nums2) {
        int coincidePosInNums2 = findElement(nums2, nums1[nums1.size() - 1], -1);
        return nums2.size() - (coincidePosInNums2 + 1);
    }
    
    int findElement(vector<int>& nums, int value, int firstOfLast) {
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
                if (firstOfLast < 0)
                    end = pos;
                else if (firstOfLast > 0)
                    begin = pos = pos + 1;
                else
                    break;
            }
        }

        return nums[pos] <= value ? pos : pos - 1;
    }
};
