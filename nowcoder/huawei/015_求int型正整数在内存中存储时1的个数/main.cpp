// date: 2020-06-17
// desc: 输入一个int型的正整数，计算出该int型数据在内存中存储时1的个数。
//       输入描述:
//        输入一个整数（int类型）
//       输出描述:
//        这个数转换成2进制后，输出1的个数

#include <iostream>

using namespace std;

int main(void)
{
    int num;
    int count = 0;
    cin >> num;
    
    while (num)
    {
        if (num % 2 == 1)
            count++;
        
        num /= 2;
    }
    
    cout << count << endl;
    
    return 0;
}
