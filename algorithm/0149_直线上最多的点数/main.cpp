// date: 2020-04-20
// desc: 直线上最多的点数

#include <vector>
#include <iostream>

using namespace std;
        
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int max_point = 0;
        int cur_point = 0;
        int curpointx;
        int curpointy;
        int size = points.size();
        int sameponit = 0;
        int currkx = 0;
        int currky = 0;

        if (size < 3)
        {
            return size;
        }

        // 从第一个点开始，依次向下
        for (int i = 0; i < size; i++)
        {
            sameponit = 0;
            curpointx = points[i][0];
            curpointy = points[i][1];

            // 取下一个点组成一条线
            for (int j = i + 1; j < size; j++)
            {
                cur_point = 1;
                
                // 下一个点同第一个点 相同的点计数
                if (points[j][1] == curpointy && points[j][0] == curpointx)
                {
                    sameponit++;
                    if ((sameponit + cur_point) > max_point)
                        max_point = sameponit + cur_point;
                    continue;
                }
                else
                {
                    // 依次判断后面的点
                    cur_point++;
                    currkx = points[j][0] - curpointx;
                    currky = points[j][1] - curpointy;
                
                    for (int k = j+ 1; k < size; k++)
                    {
                        if (points[k][0] == curpointx && points[k][1] == curpointy)
                        {
                            ++cur_point;
                            continue;
                        }

                        if (is_equal(currkx, currky, points[k][0] - curpointx, points[k][1] - curpointy))
                        { 
                            ++cur_point;
                        }
                    }

                    cur_point += sameponit;
                    if (cur_point > max_point)
                    {
                        max_point = cur_point;
                    }
                    cur_point = 1;
                }
                
            }
        }
        return max_point;
    }

    // 判断该点是不是在直线上
    int is_equal(int a, int b, int c, int d)
    {
        int ab = gcd(a, b);
        int cd = gcd(c, d);
        a = a / ab;
        b = b / ab;
        c = c / cd;
        d = d / cd;
        if (a == c && b == d)
            return 1;
        else
            return 0;
    }

    // 求最大公约数
    int gcd(int x, int y)
    {
        if (y == 0)
            return x;
        else
            return gcd(y, x % y);
    }
};




int main(void)
{
    Solution s;
    vector<vector<int>> v {{1,1}, {2,2}, {3,3}};
    cout << "resoult: " << s.maxPoints(v) << endl;

    return 0;
}
