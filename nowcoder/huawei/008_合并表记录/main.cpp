// date: 2020-06-16
// desc: 数据表记录包含表索引和数值（int范围的整数），请对表索引相同的记录进行合并，即将相同索引的数值进行求和运算，输出按照key值升序进行输出。
//       输入描述:
//       先输入键值对的个数
//       然后输入成对的index和value值，以空格隔开
//       输出描述:
//       输出合并后的键值对（多行）

#include <iostream>

using namespace std;

int main(void)
{
    int n = 0;
    int data[1000] = {0};
    int tempkey;
    int tempvalue;
    
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> tempkey;
        cin >> tempvalue;
        
        data[tempkey] += tempvalue;
    }
    
    for (int i = 0; i < n; i++)
    {
        if (data[i] != 0)
        {
            cout << i << " " << data[i] << endl;
        }
    }
    
    return 0;
}
