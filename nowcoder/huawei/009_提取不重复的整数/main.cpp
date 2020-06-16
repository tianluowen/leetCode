// date: 2020-06-16
// desc: 输入一个int型整数，按照从右向左的阅读顺序，返回一个不含重复数字的新的整数。
//       输入描述:
//       输入一个int型整数
//       输出描述:
//       按照从右向左的阅读顺序，返回一个不含重复数字的新的整数

#include <iostream>

using namespace std;

int main(void)
{
    int num;
    int data[10] = {0};
    int temp = 0;
    int count = 0; 
    
    cin >> num;
    
    while (num)
    {
        temp = num % 10;
        int flag = 0;
        for (int i = 0; i < count; i++)
        {
            if (temp == data[i])
            {
                flag = 1;
                break;
            }
        }
        
        if (!flag)
        {
            data[count++] = temp;
        }
        
        num /= 10;
    }
    
    int result = 0;
    for (int i = 0; i < count; i++)
    {
        result = result * 10 + data[i];
    }
    
    cout << result << endl;
    
    return 0;
}
