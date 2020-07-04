// date: 2020-07-04
// desc: 题目描述
//       通过以上对两台计算机IP地址与子网掩码的AND运算后，我们可以看到它运算结果是一样的。均为 192.168.0.0，所以这二台计算机可视为是同一子网络。

#include <iostream>

using namespace std;

int main(void)
{
    unsigned int a1, a2, a3, a4, a = 0;
    unsigned int b1, b2, b3, b4, b = 0;
    unsigned int c1, c2, c3, c4, c = 0;
    char ch;
    
    
    while (cin >> a1 >> ch >> a2 >> ch >> a3 >> ch >> a4
               >> b1 >> ch >> b2 >> ch >> b3 >> ch >> b4
               >> c1 >> ch >> c2 >> ch >> c3 >> ch >> c4)
    {
        a += (a1 << 24) + (a2 << 16) + (a3 << 8) + a4;
        b += (b1 << 24) + (b2 << 16) + (b3 << 8) + b4;
        c += (c1 << 24) + (c2 << 16) + (c3 << 8) + c4;
        
        if (a & b == a & c)
            cout << 0 << endl;
        else
            cout << 2 << endl;
    }
    
    return 0;
}
