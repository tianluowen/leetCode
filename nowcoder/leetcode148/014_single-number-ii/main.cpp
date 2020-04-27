// date: 2020-04-26
// desc: 现在有一个整数类型的数组，数组中素只有一个元素只出现一次，其余的元素都出现两次

#include <iostream>

using namespace std;
        
class Solution {
public:
        int singleNumber(int A[], int n) {
        int seen_once = 0;
        int seen_twice = 0;
        for (int i = 0; i < n; i++)
        {
            seen_once = ~seen_twice & (seen_once ^ A[i]);
            seen_twice = ~seen_once & (seen_twice ^ A[i]);
        }
        
        return seen_once;
    }
};
        
int main(void)
{
    Solution s;

    int A[] {2, 2, 2, 1};

    int result = s.singleNumber(A, 3);

    cout << "A = [2, 2, 1]" << endl;
    cout << "result = " << result << endl;


    return 0;
}
