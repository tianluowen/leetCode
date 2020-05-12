// date: 2020-05-12
// desc: 给你 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

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
