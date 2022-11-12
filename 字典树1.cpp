#include <iostream>
#include <vector>
#include <string>
using namespace std;
const int maxn=100;
const int wn=26;
class Trie
{
public:
    Trie():end(maxn),total(0){
        tree=vector<vector<int>>(maxn,vector<int>(wn,0));
    }
    void insert(string s)
    {
        int len=s.size();
        int p=1;
        for(int i=0;i<len;++i)
        {
            int ch=s[i]-'a';
            if(!tree[p][ch])
            {
                tree[p][ch]=++total;
            }
            p=tree[p][ch];
        }
        end[p]=true;
    }
    bool search(string s)
    {
        int len=s.size();
        int p=1;
        for(int i=0;i<len;++i)
        {
            int ch=s[i]-'a';
            if(!tree[p][ch])
            {
                return false;
            }
            p=tree[p][ch];
        }
        return end[p];
    }
    bool startsWith(string prefix) {
        int p=1;
        int len=prefix.size();
        for(int i=0;i<len;++i)
        {
            int ch=prefix[i]-'a';
            if(!tree[p][ch])return false;
            p=tree[p][ch];
        }
        return true;
    }

private:
    vector<bool> end;
    vector<vector<int>>tree;
    int total;
   

};
int main()
{
   // Tree t;
   // t.insert("")
    return 0;
}