#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5;
//有n个人，60种技能点，如果第i个人会第j种技能a[i]的二进制表示的第j位就是1，第i个人的价值是b[i]
//如果有若干种技能i会j不会，i就会鄙视j
//求一种至少两个人的选人方案使得价值和最大，而且不存在一个人鄙视剩余所有人
ll arr1[N],arr2[N],vis[N];
map<ll,ll> cnt;
vector<ll> arr;

int main()
{
    ll n,l;
    ll ans=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        scanf("%I64d",&arr1[i]);
        cnt[arr1[i]]++;
    }

    for(int i=0;i<n;i++)
    {
        scanf("%I64d",&arr2[i]);
        if(cnt[arr1[i]]>=2)
        {
            vis[i]=1;
            arr.push_back(arr1[i]);
            ans=ans+arr2[i];
        }
    }

    for(int i=0;i<n;i++)
    {
        if(vis[i]==0)
        {
            l=arr.size();
            for(int j=0;j<l;j++)
            {
                if(arr1[i]<arr[j]&&((arr1[i]&arr[j])==arr1[i]))
                {
                    arr.push_back(arr1[i]);
                    ans=ans+arr2[i];
                    break;
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
