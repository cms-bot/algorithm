#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
class St_table
{
public:
    St_table(vector<int>arr):nums(arr),n(arr.size()){
        F=vector<vector<int>>(arr.size()+1,vector<int>(arr.size(),0));
    }
    void bulid()
    {
       for(int i=1;i<=n;i++)//初始化 
		F[i][0]=nums[i-1];
    	int k=log2(n);  //log(n)/log(2);
	   for(int j=1;j<=k;j++)
		for(int i=1;i<=n-(1<<j)+1;i++)//n-2^j+1
			F[i][j]=max(F[i][j-1],F[i+(1<<(j-1))][j-1]);
    }
    int ask(int l,int r)
    {
        int k=log2(r-l+1);
	   return max(F[l][k],F[r-(1<<k)+1][k]);//取两个区间最值 
    }
private:
    int n;
    vector<int>nums;
    vector<vector<int>>F;

};
int main()
{
    vector<int>arr={1,2,3,4};
    St_table s(arr);
    s.bulid();
    cout<<s.ask(1,3)<<endl;
}