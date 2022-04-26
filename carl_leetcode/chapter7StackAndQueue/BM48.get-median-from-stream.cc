/**
 * BM48 数据流中的中位数
 * 如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。我们使用Insert()方法读取数据流，使用GetMedian()方法获取当前读取数据的中位数。
*/

#include <queue>

using namespace std;

class Solution {
public:
    void Insert(int num) {
        if(max_que.size() > min_que.size())     // 插入到小根堆
        {
            if( num < max_que.top())        // 当前数替换到大跟堆
            {
                min_que.push(max_que.top());
                max_que.pop();
                max_que.push(num);
            }else{      // 不需要替换
                min_que.push(num);
            }
        }else  // 插入到大根堆  max_que.size() <= min_que.size()
        {
            if( !max_que.empty() && num > min_que.top())
            {
                max_que.push(min_que.top());
                min_que.pop();
                min_que.push(num);
            }else
                max_que.push(num);

        }
    }

    double GetMedian() { 
        if(max_que.size() > min_que.size())
            return max_que.top();
        else if(max_que.size() < min_que.size())
            return min_que.top();
        else
            return double(max_que.top() + min_que.top())/2;
    }
private:
    priority_queue<int,vector<int>,greater<int>> min_que;   // 小根堆，前 k 大个元素
    priority_queue<int, vector<int>, less<int>> max_que;   // 大根堆，前 k 小个元素
};