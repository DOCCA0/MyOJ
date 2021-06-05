#include <cstring>
#include <cstdio>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

const int maxn = 10005;
struct node
{
    int to, next;
} edge[maxn*5];
int head[maxn], id[maxn], tot, cnt, time, top;
int dfn[maxn], low[maxn], vis[maxn], stack[maxn], instack[maxn];

void init()
{
    tot = top = 0;//top指向栈顶
    cnt = 0;//强连通分量
    time = 1;//时间戳
    memset (id, 0, sizeof(id));//i所属的连通分量
    memset (stack, 0, sizeof(stack));//dfs到的元素进栈
    memset (instack, 0, sizeof(instack));//i是否在栈中
    memset (head, -1, sizeof(head));
    memset (dfn, 0, sizeof(dfn));//进栈时间
    memset (low, 0, sizeof(low));//i能到达的最早进栈的节点的进栈时间
    memset (vis, 0, sizeof(vis));//强连通分量是否有出度
}
void Add (int from, int to)
{
    edge[tot].to = to;
    edge[tot].next = head[from];
    head[from] = tot++;
}
void Tarjan (int u)
{
    dfn[u] = low[u] = time ++;
    instack[u] = 1;
    stack[top++] = u;
    for (int i=head[u]; i!=-1; i=edge[i].next)
    {
        int v = edge[i].to;
        if (!dfn[v])//v没有dfs到过
            Tarjan(v);
        if (instack[v])//v在栈中
            low[u] = min (low[v], low[u]);
    }
    if (low[u] == dfn[u])
    {//找到一个强连通分量
        cnt ++;
        while (1)
        {//在栈中弹出强连通分量
            int v = stack[--top];
            instack[v] = 0;
            cout<<v<<' ';
            id[v] = cnt;
            if (v == u)
                break;
        }
        cout<<endl;
    }
}


int main(){
    int T;
    cin>>T;
    int n,m;
    while (T--){
        cin>>n>>m;
        init ();
        while (m--)
        {
            int from, to;
            scanf ("%d %d", &from, &to);
            Add (from, to);
        }
        for (int i=1; i<=n; i++)
            if (!dfn[i])//i点没进过栈，i点进栈继续dfs
                Tarjan(i);
        int sum = 0, x;
        for (int i=1; i<=n; i++)
            for (int j=head[i]; j!=-1; j=edge[j].next)
                if (id[i] != id[edge[j].to])//id[i] 到 id[edge[j].to这条边不在强连通分量中，记录id[i]分量有出度
                    vis[id[i]] ++;
        for (int i=1; i<=cnt; i++)
            if (!vis[i])
            {
                sum ++;
                x = i;
            }

        if (sum == 1)
        {
            sum = 0;
            for (int i=1; i<=n; i++)
                if (id[i] == x)
                    sum ++;
            printf ("%d\n", sum);
        }
        else
            printf ("0\n");
    }


    return 0;
}