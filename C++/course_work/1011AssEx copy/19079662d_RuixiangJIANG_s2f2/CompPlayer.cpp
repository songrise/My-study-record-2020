#include "TTT.h"
using namespace std;

void easy_comp_move(int *board, int first)
{
    int location;
    while (1)
    {
        if (board[4] == 0)
            location = 5; //First attempt to place at center
        else
            location = (rand() % 9) + 1; //just random choose a location

        //check the validity of the choosen location
        if (location < 1 || location > 9)
        {
            continue;
        }
        else if (board[location - 1] != 0) //already occupied
        {
            continue;
        }
        else //Valid
        {
            GREEN
            printf("                    Processing");
            for (int i = 0; i < 6; i++)
            {

                printf(".");
                fflush(stdout);
                usleep(180000);
            }
            CLOSE
            printf("\r");
            char pos_notice[BUFSIZE];
            sprintf(pos_notice, "AI selected position %d", location);
            msg_box(pos_notice);

            board[location - 1] = next_step(board, first); //update game board
            break;
        }
    }
}

//hardmode
inline int Evaluate(int board[3][3])
{
    //setting weight to each board location
    int i, j;
    int cnt[3];
    int re = 0;
    for (int i = 0; i < 3; i++)
    {
        memset(cnt, 0, sizeof(cnt));
        for (int j = 0; j < 3; j++)
            cnt[board[i][j]]++;

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

        memset(cnt, 0, sizeof(cnt));
        for (int j = 0; j < 3; j++)
            cnt[board[j][i]]++;
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
    memset(cnt, 0, sizeof(cnt));

    for (int i = 0; i < 3; i++)

    {
        cnt[board[i][i]]++;
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
    memset(cnt, 0, sizeof(cnt));

    for (int i = 0; i < 3; i++)
    {
        cnt[board[i][2 - i]]++;
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

inline int dfs(const int &depth, const int &nowWho, int board[3][3])
{

    int i, j, t, max_ = -100000, min_ = 100000, ok = 0;
    int eva = Evaluate(board); //evaluate weight of chess board at this layer
    if (depth == 0 || (eva >= 1000) || (eva <= -1000))
    {
        return eva;
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != 0)
                continue;
            ok = 1;
            board[i][j] = nowWho + 1;
            t = dfs(depth - 1, nowWho ^ 1, board);
            board[i][j] = 0;
            min_ = min(t, min_);
            max_ = max(t, max_);
        }
    }
    if (!ok)
        return eva;
    if (nowWho == 0)
        return max_;
    if (nowWho == 1)
        return min_;
}

void hard_comp_move(int *board, int first)
{
    int x, y, i, j;
    // convert in to 2-D array, for DFS propose
    int boa[3][3] = {{board[0],
                      board[1],
                      board[2]},
                     {board[3],
                      board[4],
                      board[5]},
                     {board[6],
                      board[7],
                      board[8]}};

    vector<pair<int, pair<int, int> > > v;
    v.clear();
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {

            if (boa[i][j] != 0)
                continue;
            boa[i][j] = 2;
            v.push_back(make_pair(dfs(9, 0, boa), make_pair(i, j))); //push optimal place inform of num pair to vector
            boa[i][j] = 0;
        }
    }
    sort(v.begin(), v.end());
    j = 1;
    while (j < v.size() && v[j].first == v[0].first)
        j++;

    j = rand() % j; //random choose an optimal place, as long as it will not lead to lose.
    x = v[j].second.first;
    y = v[j].second.second;
    board[3 * x + y] = 2;
    GREEN
    printf("                    Processing");
    for (int i = 0; i < 6; i++)
    {

        printf(".");
        fflush(stdout);
        usleep(180000);
    }
    CLOSE
    printf("\r");
    char pos_notice[BUFSIZE];
    sprintf(pos_notice, "AI selected position %d", 3 * x + y + 1);
    msg_box(pos_notice);
}
