// date: 2020-03-29
// desc: 对于给定的n个位于同一二维平面上的点，求最多能有多少个点位于同一直线上
//       Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.

#include <iostream>
#include <vector>

using namespace std;

// Definition for a point.
struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};



class Solution {
public:
    int maxPoints(vector<Point> &points) {

        int max_point = 0;
        int cur_point = 0;
        Point curpoint;
        Point nextpoint;
        int size = points.size();
        double currk = 0;
        double nextcurrk = 0;

        // 从第一个点开始，一次向下
        for (int i = 0; i < size; i++)
        {
            curpoint = points[i];
            cur_point = 1;
            for (int j = i + 1; j < size; j++)
            {
                nextpoint = points[j];
                cur_point = 2;
                currk = ((double)nextpoint.x - curpoint.x) / (nextpoint.y - curpoint.y); 
                for (int k = j+ 1; k < size; k++)
                {
                    nextpoint = points[k];
                    nextcurrk = ((double)nextpoint.x - curpoint.x) / ((double)nextpoint.y - curpoint.y); 
                    if (nextcurrk == currk)
                    {
                        ++cur_point;
                    }

                }
                if (cur_point > max_point)
                {
                    // cout << "enter cur_point = " << cur_point << "max_point " << max_point << endl;
                    max_point = cur_point;
                }
            }
            if (cur_point > max_point)
            {
                max_point = cur_point;
            }
        }
        return max_point;
    }
};        


int main(void)
{
    Solution s;

    vector<Point> point = {Point(0, 0), Point(1, 1), Point(2, 2)};
    int result = s.maxPoints(point);

    cout << "逆波兰表达式输入为: [(0, 0), (1, 1), (2, 2)]" << endl;
    cout << "计算结果 = " << result << endl;

    return 0;
}
