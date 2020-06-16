// date: 2020-06-16
// desc: 功能:输入一个正整数，按照从小到大的顺序输出它的所有质因子（重复的也要列举）（如180的质因子为2 2 3 3 5 ）
//       最后一个数后面也要有空格
//       输入描述:
//       输入一个long型整数
//       输出描述:
//       按照从小到大的顺序输出它的所有质数的因子，以空格隔开。最后一个数后面也要有空格。

#include <iostream>
#include <string>

using namespace std;

bool is_prime(int num)
{
    for (int i = 2; i < num / 2; i++)
    {
        if (num % 2 == 0)
            return false;
    }
    
    return true;
}

int main(void)
{
    long num;
    cin >> num;
    
    for (int i = 2; i <= num; i++)
    {
        if (is_prime(i) && num % i == 0)
        {
            cout << i << " ";
            num /= i;
            i = 1;
        }
    }
    
    cout << endl;
}
