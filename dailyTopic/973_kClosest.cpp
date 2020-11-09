#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <queue>

using namespace std;

// https://leetcode-cn.com/problems/k-closest-points-to-origin/
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        // return kClosest_1(points, K);
        // return kClosest_2(points, K);
        return kClosest_3(points, K);
    }


    void quickSort(vector<vector<int>>& points, int left, int right, int K) {
        if(left >= right)
            return;
        int i = left, j = right;
        auto middle = points[left];
        int mid = points[left][0]*points[left][0] + points[left][1]*points[left][1]; // mid中存的就是基准数
        while(i < j)
        {
            //顺序很重要，要先从右边开始找
            while(i < j && (points[j][0]*points[j][0] + points[j][1]*points[j][1]) >= mid)
                j--;
            //再找右边的
            while(i < j && (points[i][0]*points[i][0] + points[i][1]*points[i][1]) <= mid  )
                i++;
            //交换两个数在数组中的位置
            if(i < j) {
                swap(points[i], points[j]);
            }
        }
        //最终将基准数归位
        points[left] = points[i];
        points[i] = middle;

        // 说明第K个距离最小的点在mid左侧
        if (K < i - left + 1) {
            quickSort(points, left, i - 1, K);
        }
        // 说明第K个距离最小的点在mid右侧
        else if (K > i - left + 1) {
            quickSort(points, i + 1, right, K - (i - left + 1));
        }
    }

    // 快排
    vector<vector<int>> kClosest_1(vector<vector<int>>& points, int K) {
        int n = points.size();
        quickSort(points, 0, n - 1, K);
        return {points.begin(), points.begin() + K};
    }

    // 大顶堆解答
    vector<vector<int>> kClosest_2(vector<vector<int>>& points, int K) {
        // 将前 K 个点的编号（为了方便最后直接得到答案）以及对应的距离平方放入优先队列中(大顶堆)
        priority_queue<pair<int, int>> q;
        for (int i = 0; i < K; ++i) {
            q.emplace(points[i][0] * points[i][0] + points[i][1] * points[i][1], i);
        }

        // 如果当前点的距离平方比堆顶的点的距离平方要小，就把堆顶的点弹出，再插入当前的点
        for (int i = K; i < points.size(); ++i) {
            int dis = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            if (dis < q.top().first) {
                q.pop();
                q.emplace(dis, i);
            }
        }


        vector<vector<int>> ans;
        while (!q.empty()) {
            ans.push_back(points[q.top().second]);
            q.pop();
        }
        return ans;
    }

    vector<vector<int>> kClosest_3(vector<vector<int>>& points, int K) {
        vector<vector<int>> num = points;
        // 应用的范围由它的第一个和第三个参数指定
        // 第二个参数是一个指向第 n 个元素的迭代器， n前面的元素都小于n后面的元素  （未整体排序）
        nth_element(num.begin(), num.begin()+K, num.end(), [](const vector<int>& l, const vector<int>& r){return l[0]*l[0]+l[1]*l[1] < r[0]*r[0]+r[1]*r[1];});
        num.resize(K);
        return num;

        // 从小到大排序
        sort(points.begin(), points.end(), [](const vector<int>& u, const vector<int>& v) {
            return u[0] * u[0] + u[1] * u[1] < v[0] * v[0] + v[1] * v[1];
        });
        return {points.begin(), points.begin() + K};
    }
};

int main() {
    // vector<vector<int>> num = {{1,3}, {-2,2}};
    vector<vector<int>> num = {{3,3}, {5,-1}, {-2,4}};
    auto res =  Solution().kClosest(num, 2);

    for (auto i : res) {
        cout  << "[" << i[0] << "," << i[1] << "]\n";
    }
    return 0;
}
