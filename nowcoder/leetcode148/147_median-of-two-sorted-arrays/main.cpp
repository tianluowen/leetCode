// date: 2020-05-01
// desc: 寻找两个有序数组的中位数

#include <iostream>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int sizesum = m + n;
        
        if (sizesum % 2 == 1)
        {
            sizesum = sizesum / 2;
            
            int i = 0;
            int j = 0;
            int k = 0;
            
            for (; i < sizesum;)
            {
                if (j >= m)
                {
                    k++;
                    i++;
                    continue;
                }
                
                if (k >= n)
                {
                    j++;
                    i++;
                    continue;
                }
                
                if (A[j] < B[k])
                    j++;
                else
                    k++;
                
                i++;
            }
            
            if (j >= m)
            return B[k];
            
            if (k >= n)
                return A[j];
            
            return A[j] < B[k] ? A[j] : B[k];
        }
        else
        {
            sizesum = sizesum / 2 - 1;
            int i = 0;
            int j = 0;
            int k = 0;
            
            for (; i < sizesum;)
            {
                if (j >= m)
                {
                    k++;
                    i++;
                    continue;
                }
                if (k >= n)
                {
                    j++;
                    i++;
                    continue;
                }
                if (A[j] < B[k])
                    j++;
                else
                    k++;
                
                i++;
            }
            
            if (j >= m)
                return (B[k] + B[k + 1]) / 2.0;

            if (k >= n)
                return (A[j] + A[j + 1]) / 2.0;
            
            double result = 0;
            for (i = 0; i < 2;)
            {
                if (j >= m)
                {
                    result += B[k];
                    k++;
                    i++;
                    
                    continue;
                }
                if (k >= n)
                {
                    result += A[j];
                    j++;
                    i++;
                    continue;
                }
                if (A[j] < B[k])
                {
                    result += A[j];
                    j++;
                }
                else
                {
                    result += B[k];
                    k++;
                }
                i++;
            }
            return result / 2.0;
        }
    }
};

int main(void)
{
    Solution s;
    int nums1[] = {1, 3};
    int nums2[] = {2};
    double d = s.findMedianSortedArrays(nums1, 2, nums2, 1);

    cout << "num1 = [1, 3], num2 = [2]\n中位数 = " << d << endl;

    return 0;
}
