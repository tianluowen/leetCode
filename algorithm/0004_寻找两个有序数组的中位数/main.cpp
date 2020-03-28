// date: 2020-03-28
// desc: 寻找两个有序数组的中位数

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int sizea = nums1.size();
        int sizeb = nums2.size();
        int sizesum = sizea + sizeb;
        // std::cout << sizea << "  " <<  sizeb << std::endl;


        if (sizesum % 2 == 1)
        {
            sizesum = sizesum / 2;
            int i = 0;
            int j = 0;
            int k = 0;

            for (; i < sizesum;)
            {
                if (j >= sizea)
                {
                    k++;
                    i++;
                    std::cout << "k = " << k << "\t i = " << i << std::endl;
                    continue;
                }
                if (k >= sizeb)
                {
                    j++;
                    i++;
                    continue;
                }
                if (nums1[j] < nums2[k])
                    j++;
                else
                    k++;
            
                i++;
            }

            // std::cout << "i = " << i << "\t j = " << j << "\t k = " << k << std::endl;
             
            if (j >= sizea)
            return nums2[k];

            if (k >= sizeb)
            return nums1[j];

            return nums1[j] < nums2[k] ? nums1[j] : nums2[k];

        }
        else
        {
            sizesum = sizesum / 2 - 1;
            int i = 0;
            int j = 0;
            int k = 0;

            for (; i < sizesum;)
            {
                if (j >= sizea)
                {
                    k++;
                    i++;
                    continue;
                }
                if (k >= sizeb)
                {
                    j++;
                    i++;
                    continue;
                }
                if (nums1[j] < nums2[k])
                    j++;
                else
                    k++;
            
                i++;
            }
            // std::cout << "i = " << i << "\t j = " << j << "\t k = " << k << std::endl;
            
            if (j >= sizea)
            return (nums2[k+1] + nums2[k]) / 2.0;

            if (k >= sizeb)
            return (nums1[j] + nums1[j+1]) / 2.0;

            double result = 0;
            for (i = 0; i < 2;)
            {
                 if (j >= sizea)
                {
                    result += nums2[k];
                    k++;
                    i++;
                    
                    continue;
                }
                if (k >= sizeb)
                {
                    result += nums1[j];
                    j++;
                    i++;
                    continue;
                }
                if (nums1[j] < nums2[k])
                {
                    result += nums1[j];
                    j++;
                }
                    
                else
                {
                    result += nums2[k];
                    k++;
                }
                i++;
            }

            return result / 2.0;
        }

        return 0;
    }
};


int main(void)
{
    Solution s;
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    double d = s.findMedianSortedArrays(nums1, nums2);

    cout << "num1 = [1, 3], num2 = [2]\n中位数 = " << d << endl;

    return 0;
}
