// date: 2020-07-04
// desc: 题目描述
//       假设一个球从任意高度自由落下，每次落地后反跳回原高度的一半; 再落下, 求它在第5次落地时，共经历多少米?第5次反弹多高？
//       最后的误差判断是小数点6位

#include <iostream>

using namespace std;

int main(void)
{
    int n;
    double num;
    double sum = 0;
    double heigh = 0;
    
    while (cin >> n)
    {
        num = n;
        int count = 5;
        while (count--)
        {
            sum += num;
            num /= 2;
            heigh = num;
            sum += heigh;
        }
        
        cout << sum - heigh << endl;
        cout << heigh << endl;
        
    }
    
    
    return 0;
}
