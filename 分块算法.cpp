#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
class  Partitioning
{
public:
    Partitioning(vector<int>& arr) :nums(arr), L(arr.size()+1), R(arr.size()+1), sum(arr.size()+1), add(arr.size()+1), pos(arr.size()+1), n(arr.size())
    {}
    void bulid()
    {
        int t = sqrt(n);
        int num = n / t;
        if (n % t)num++;
        for (int i = 1; i <= num; ++i)//确定左右端点下标
        {
            L[i] = (i - 1) * t + 1;
            R[i] = i * t;
            cout << "L[" << i << "]" << ",L[" << i << "]" << endl;
        }
        R[num] = n;
        for (int i = 1; i <= num; ++i)
        {
            for (int j = L[i]; j <= R[i]; ++j)
            {
                pos[j] = i;
                cout << "pos" << "[" << i << "]" << endl;
                sum[i] += nums[j - 1];
            }
            cout << "sum" << "[" << i << "]" << endl;
        }
    }
    void change(int l, int r, int val)
    {
        int p = pos[l];
        int q = pos[r];
        if (p == q)
        {
            for (int i = l; l <= r; ++i)
            {
                nums[i - 1] += val;
            }
            sum[p] += val * (r - l + 1);
        }
        else {
            for (int i = p + 1; i <= q - 1; ++i)add[i] += val;
            for (int i = l; i <= R[p]; ++i)nums[i - 1] += val;
            sum[p] += val * (R[p] - l + 1);
            for (int i = L[q]; i <= r; ++i)nums[i - 1] += val;
            sum[q] += val * (r - L[q] + 1);
        }
    }
    int ask(int l, int r)
    {
        int ans = 0;
        int p = pos[l];
        int q = pos[r];
        if (p == q)
        {
            for (int i = l; i <= r; ++i)
            {
                ans += nums[i - 1];
            }
            ans += add[p] * (r - l + 1);
        }
        else {
            for (int i = p + 1; i <= q - 1; ++i)
            {
               

                ans += (sum[i] + add[i] * (R[i] - L[i] + 1));
            }
            for (int i = l; i <= R[p]; ++i)ans += nums[i - 1];
            ans += add[p] * (R[p] - l + 1);
            for (int i = L[q]; i <= r; ++i)ans += nums[i - 1];
            ans += add[q] * (r - L[q] + 1);
        }
        return ans;
    }
private:
    vector<int>nums;
    vector<int>L;
    vector<int>R;
    vector<int>sum;
    vector<int>add;
    vector<int>pos;
    int n;
};
int main()
{
    vector<int> arr = { 1,2,3,4,5,6 };
    Partitioning p(arr);
    p.bulid();
   // p.change(1, 3, 2);
    cout << p.ask(1, 5)<< endl;
    return 0;
}
