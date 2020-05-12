// date: 2020-05-12
// desc: 给定n个非负整数a1，a2，…，an，其中每个数字表示坐标(i, ai)处的一个点。以（i，ai）和（i，0）（i=1,2,3...n）为端点画出n条直线。你可以从中选择两条线与x轴一起构成一个容器，最大的容器能装多少水？

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int size = height.size();
        int maxv = 0;

        int temp = 0;
        for (int i = 0, j = size - 1; i < j;)
        {
            temp = min(height[i], height[j]) * (j - i);
            maxv = max(maxv, temp);
            if (height[i] <= height[j])
                i++;
            else
                j--;
        }

        return maxv;
    }
};


int main(void)
{
    Solution s;
    vector<int> height {1, 8, 6, 2, 5, 4, 8, 3, 7};

    int result = s.maxArea(height);

    cout << "1, 8, 6, 2, 5, 4, 8, 3, 7" << endl;
    cout << "maxArea = " << result << endl; 

    return 0;
}
