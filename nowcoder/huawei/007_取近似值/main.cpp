// date: 2020-06-16
// desc: 写出一个程序，接受一个正浮点数值，输出该数值的近似整数值。如果小数点后数值大于等于5,向上取整；小于5，则向下取整。
//       输入描述:
//       输入一个正浮点数值
//       输出描述:
//       输出该数值的近似整数值
//       示例1
//       输入
//       复制
//       5.5
//       输出
//       复制
//       6

#include <iostream>

using namespace std;

int main(void)
{
    double num;
    
    cin >> num;
    cout << (int)(num + 0.5) << endl;
    
    return 0;
}
