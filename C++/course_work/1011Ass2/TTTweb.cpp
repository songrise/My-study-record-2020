//#pragma comment(linker, "/STACK:102400000,102400000")
#include <cstdio>
#include <cmath>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <conio.h>
#include <time.h>
using namespace std;
#define mz(array) memset(array, 0, sizeof(array))
#define mf1(array) memset(array, -1, sizeof(array))
#define minf(array) memset(array, 0x3f, sizeof(array))
#define REP(i, n) for (i = 0; i < (n); i++)
#define FOR(i, x, n) for (i = (x); i <= (n); i++)
#define FORD(i, x, y) for (i = (x); i >= (y); i--)
#define RD(x) scanf("%d", &x)
#define RD2(x, y) scanf("%d%d", &x, &y)
#define RD3(x, y, z) scanf("%d%d%d", &x, &y, &z)
#define WN(x) printf("%d\n", x);
#define RE freopen("D.in", "r", stdin)
#define WE freopen("huzhi.txt", "w", stdout)
#define mp make_pair
#define pb push_back
#define pf push_front
#define ppf pop_front
#define ppb pop_back
typedef long long ll;
typedef unsigned long long ull;

const char CHESS[3] = {'-', '@', '#'};

struct Board
{
    int a[3][3];
    inline void Init()
    {
        memset(a, 0, sizeof(a));
    }
    inline void operator=(Board b)
    {
        int i, j;
        REP(i, 3)
        REP(j, 3)
        a[i][j] = b.a[i][j];
    }
};

int GetInput(string s, int maxNum)
{
    int t;
    char c;
    while (1)
    {
        cout << s;
        c = getch();
        t = c - '0';
        if (t >= 0 && t < maxNum)
            break;
        else
        {
            puts("输入错误，请重新输入！");
        }
    }
    puts("");
    return t;
}

void OutBoard(Board bod)
{
    int i, j;
    printf("   ");
    REP(i, 3)
    printf("%2d", i);
    puts("\n   ======");
    REP(i, 3)
    {
        printf("%2d|", i);
        REP(j, 3)
        {
            printf("%2c", CHESS[bod.a[i][j]]);
        }
        puts("");
    }
}

void PlayerMove(Board &bod)
{
    int x, y;
    OutBoard(bod);
    while (true)
    {
        printf("该你了，请输入你要下%c的横纵坐标（用空格隔开的两个数）：", CHESS[1]);
        scanf("%d%d", &x, &y);
        if (!(x >= 0 && x <= 2 && y >= 0 && y <= 2))
        {
            puts("输入错误！请重新输入！横纵坐标都要是0或者1或者2。");
            continue;
        }
        if (bod.a[x][y] != 0)
        {
            puts("下错了，这个位置有棋！请选择其他位置。");
            continue;
        }
        break;
    }
    bod.a[x][y] = 1;
    //OutBoard(bod);
    printf("你下到了(%d,%d)位置。\n", x, y);
    puts("");
    //    puts("(按回车键继续)");
    //    getch();
    //    system("cls");
}

inline int Evaluate(const Board &bod)
{
    int i, j;
    int cnt[3];
    int re = 0;
    REP(i, 3)
    {
        mz(cnt);
        REP(j, 3)
        cnt[bod.a[i][j]]++;
        if (cnt[1] == 3)
            return 1000;
        if (cnt[2] == 3)
            return -1000;
        if (cnt[1] == 2 && cnt[0] == 1)
            re += 50;
        else if (cnt[1] == 1 && cnt[0] == 2)
            re += 10;
        if (cnt[2] == 2 && cnt[0] == 1)
            re -= 50;
        else if (cnt[2] == 1 && cnt[0] == 2)
            re -= 10;
        mz(cnt);
        REP(j, 3)
        cnt[bod.a[j][i]]++;
        if (cnt[1] == 3)
            return 1000;
        if (cnt[2] == 3)
            return -1000;
        if (cnt[1] == 2 && cnt[0] == 1)
            re += 50;
        else if (cnt[1] == 1 && cnt[0] == 2)
            re += 10;
        if (cnt[2] == 2 && cnt[0] == 1)
            re -= 50;
        else if (cnt[2] == 1 && cnt[0] == 2)
            re -= 10;
    }
    mz(cnt);
    REP(i, 3)
    {
        cnt[bod.a[i][i]]++;
    }
    if (cnt[1] == 3)
        return 1000;
    if (cnt[2] == 3)
        return -1000;
    if (cnt[1] == 2 && cnt[0] == 1)
        re += 50;
    else if (cnt[1] == 1 && cnt[0] == 2)
        re += 10;
    if (cnt[2] == 2 && cnt[0] == 1)
        re -= 50;
    else if (cnt[2] == 1 && cnt[0] == 2)
        re -= 10;
    mz(cnt);
    REP(i, 3)
    {
        cnt[bod.a[i][2 - i]]++;
    }
    if (cnt[1] == 3)
        return 1000;
    if (cnt[2] == 3)
        return -1000;
    if (cnt[1] == 2 && cnt[0] == 1)
        re += 50;
    else if (cnt[1] == 1 && cnt[0] == 2)
        re += 10;
    if (cnt[2] == 2 && cnt[0] == 1)
        re -= 50;
    else if (cnt[2] == 1 && cnt[0] == 2)
        re -= 10;
    return re;
}

Board boa;

inline int dfs(const int &depth, const int &nowWho)
{
    int i, j, t, ma = -100000, mi = 100000, ok = 0;
    int eva = Evaluate(boa);
    if (depth == 0 || (eva >= 1000) || (eva <= -1000))
    {
        return eva;
    }

    REP(i, 3)
    {
        REP(j, 3)
        {
            if (boa.a[i][j] != 0)
                continue;
            ok = 1;
            boa.a[i][j] = nowWho + 1;
            t = dfs(depth - 1, nowWho ^ 1);
            boa.a[i][j] = 0;
            ma = max(t, ma);
            mi = min(t, mi);
        }
    }
    if (!ok)
        return eva;
    if (nowWho == 0)
        return ma;
    if (nowWho == 1)
        return mi;
}

void ComputerMove(Board &bod)
{
    int x, y, i, j;
    boa = bod;
    puts("电脑：“该我啦！看我思考一下...”");
    vector<pair<int, pair<int, int>>> v;
    v.clear();
    REP(i, 3)
    REP(j, 3)
    {
        if (boa.a[i][j] != 0)
            continue;
        boa.a[i][j] = 2;
        v.pb(mp(dfs(9, 0), mp(i, j)));
        boa.a[i][j] = 0;
    }
    sort(v.begin(), v.end());
    j = 1;
    while (j < v.size() && v[j].first == v[0].first)
        j++;
    if (j > 1)
        printf("电脑：“想完啦！我有%d种不同的效果差不多的棋可以走，看我随便走一个！”\n", j);
    else
        printf("电脑：“想完啦！看我要走出这步惊天之棋了！”\n");
    if (v.size() > j && v[j].first == 1000)
        puts("电脑：“要是我走除此之外的棋我就输了，我已经看出来了。”");
    if (v[0].first == -1000)
        puts("电脑：“现在，高下立判，你输定了！”");
    j = rand() % j;
    x = v[j].second.first;
    y = v[j].second.second;
    bod.a[x][y] = 2;
    //OutBoard(bod);
    printf("电脑：“经过我的精确思考，我下到了(%d,%d)位置。”\n", x, y);
    puts("");
}

int WhoWin(Board bod)
{
    int i, j, k = 0;
    int t = Evaluate(bod);
    if (t == 1000)
        return 1;
    if (t == -1000)
        return 2;
    REP(i, 3)
    REP(j, 3)
    if (bod.a[i][j] != 0)
        k++;
    if (k == 9)
        return 3;
    return 0;
}

void Game()
{
    int playerFirst, nowMove, whoWin, continueGame = 1;
    Board now;
    int t;
    int step;
    srand(time(NULL));
    while (continueGame)
    {
        system("cls");
        puts("欢迎来到 【带鱼人工智能博弈树井字棋游戏】！");
        playerFirst = GetInput("请选择玩家先后手（0先手，1后手）：", 2);
        if (playerFirst == 0)
        {
            puts("电脑：“就算你选先手，我也不会输，不信走着瞧！”");
        }
        else
            puts("电脑：“居然敢选后手，要是你稍有不慎，就输定了！”");
        now.Init();
        printf("（棋盘说明：%c是空位，%c是你的棋子，%c是电脑的棋子，上面是横坐标，左边是纵坐标）\n\n", CHESS[0], CHESS[1], CHESS[2]);
        nowMove = playerFirst;
        whoWin = 0;
        step = 0;
        while (!whoWin)
        {
            printf("【第%d手】\n", ++step);
            if (nowMove == 0)
            {
                PlayerMove(now);
            }
            else
            {
                ComputerMove(now);
            }
            whoWin = WhoWin(now);
            if (whoWin != 0)
            {
                OutBoard(now);
                if (whoWin == 1)
                {
                    printf("电脑：“哇，你居然赢了，真是不敢相信！我输了！”\n");
                }
                if (whoWin == 2)
                {
                    printf("电脑：“蛤铪哈！我赢了，你太弱啦！”\n");
                }
                if (whoWin == 3)
                {
                    printf("电脑：“平局！你还是有点实力，但是我是绝对不会输的！”\n");
                }
            }
            nowMove ^= 1;
        }
        continueGame = GetInput("是否继续游戏？（0结束游戏，1重新开始）：", 2);
    }
}

int main()
{
    Game();
    return 0;
}