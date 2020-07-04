// date: 2020-07-04
// desc: 题目描述
//       有一只兔子，从出生后第3个月起每个月都生一只兔子，小兔子长到第三个月后每个月又生一只兔子，假如兔子都不死，问每个月的兔子总数为多少？

#include <iostream>

using namespace std;

int main(void)
{
    int num;
    
    while (cin >> num)
    {
        int a = 1;
        int b = 0;
        int c = 0;
        
        while (--num)
        {
            c += b;
            b = a;
            a = c;
        }
        
        cout << a + b + c << endl;
    }
    
    return 0;
}
