#include <iostream>
#include <vector>
#include <functional>




using namespace std;


class Solution {
public:
    int reverse(int x) {
        //int的最大值最小值
        int max = 0x7fffffff, min = 0x80000000;
        //用long类型判断溢出
        long rs = 0;
        

        //逆序，正负通吃，不用单独考虑负值
        while (x) { 
            rs = rs*10 + x%10;
            x /= 10;
        }

        //溢出处理
        return (rs>max || rs<min)? 0:rs; 
    }
};




int main(int argc, char const *argv[])
{
    
   cout << Solution().reverse(123) << endl;
    return 0;
}







