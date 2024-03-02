#include <bits/stdc++.h>
using namespace std;
char a[25][25];
bool vis[25][25];
vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int n, m;
int ans;
bool valid(int i, int j)
{
    if (i < 0 || i >= m || j < 0 || j >= n)
        return false;
    return true;
}
void dfs(int si, int sj)
{
    ans++;
    vis[si][sj] = true;
    for (int i = 0; i < 4; i++)
    {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;
        if (valid(ci, cj) == true && vis[ci][cj] == false && a[ci][cj]=='.')
        {
            dfs(ci, cj);
        }
    }
}
int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cin >> n >> m;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> a[i][j];
            }
        }
        // for (int i = 0; i < m; i++)
        // {
        //     for (int j = 0; j < n; j++)
        //     {
        //         cout<<a[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

        
        memset(vis, false, sizeof(vis));
        ans=0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if(a[i][j]=='@')
                {
                    dfs(i,j);
                    break;
                }
            }
        }
       
        cout<<"Case "<<i<<": "<<ans<<endl;

    }
    return 0;
}