/*
 * @Author: 快出来了哦
 * @Date: 2022-11-02 03:03:28
 * @LastEditors: 快出来了哦
 * @LastEditTime: 2022-11-12 03:32:39
 * @FilePath: /c++/algorithm/algorithm/AC自动机.cpp
 * @Description: 
 */

#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;
struct node
{
    node* fail;
    vector<node*> children;
    int cnt;
    node():children(26)
    {
        fail = nullptr;
        cnt = 0;
    }
};
class AC_Tree
{
public:
    AC_Tree():root(new node),superroot(new node)
    {
        superroot->cnt=-1;
        root->fail=superroot;
    }  
    /**
     * @description: 构建字典树
     * @return {*}
     */    
    void bulid_tree(vector<string>&nums)
    {
        for(auto num:nums)insert(num);
    }
    /**
     * @description: 字典树插入
     * @param {string&} s
     * @return {*}
     */
    void insert(string& s)
    {
        node* t = root;
        for(int i = 0; i < s.size(); ++i)
        {
            int x=s[i]-'a';
            if(t->children[x] == nullptr)
            {
                t->children[x] = new node();
            }
            t = t->children[x];
        }
        t->cnt++;
    }
    /**
     * @description: 构建ac自动机
     * @return {*}
     */    
    void bulid_ac()
    {
        queue<node*> q;
        q.push(root);
        while(!q.empty())
        {
            node* t = q.front();
            q.pop();
            for(int i = 0; i < 26; ++i)
            {
                if(t->children[i]!= nullptr)
                {
                    t->children[i]->fail =t ->fail->children[i];
                    q.push(t->children[i]);
                }else{
                    t->children[i] = t->fail->children[i];
                }
            }
        }
    }
    /**
     * @description: 查询单词个数
     * @param {string&} s
     * @return {*}
     */    
    int query(string& s)
    {
        int ans=0;
        node* t = root;
        for(int i = 0; i < s.size(); ++i)
        {
            int x=s[i]-'a';
            t =t->children[x];
            for(node* u=t;u->cnt!=0;u=u->fail)
            {
                ans+=u->cnt;
                u->cnt =-1;
            }
        }
        return ans;
    }
private:
    node * superroot;
    node * root ;

};
int main()
{
    AC_Tree ac;
    vector<string>nums={"he","she","tu"};
    ac.bulid_tree(nums);
    ac.bulid_ac();

    return 0;
}