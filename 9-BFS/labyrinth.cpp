#include <iostream>
#include <queue>
using namespace std;
struct location
{
    int x;
    int y;
    int step; //记录步数
};            //记录在每一格上的状态
char labyrinth[][7] = {
    {'B', 'O', 'O', 'O', 'O', 'O', 'O'},
    {'O', 'X', 'X', 'X', 'X', 'X', 'O'},
    {'O', 'O', 'O', 'O', 'O', 'X', 'O'},
    {'O', 'O', 'O', 'O', 'O', 'O', 'O'},
    {'X', 'X', 'X', 'O', 'O', 'O', 'O'},
    {'O', 'O', 'O', 'O', 'X', 'O', 'X'},
    {'X', 'O', 'O', 'O', 'O', 'O', 'E'}}; //迷宫部分

int pass[8][8] = {0};                              //记录迷宫上的每一格是否被走过
int dir[][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}}; //记录x,y走向：上，下，左，右
bool judge(int x, int y)                           //判断(x,y)能不能走
{
    if (x < 0 || x > 6 || y < 0 || y > 6)
    {
        return false;
    } //越格，不能走
    if (labyrinth[x][y] == 'X')
    {
        return false;
    } //碰到"X“不能走
    if (pass[x][y])
    {
        return false;
    } //走过的格子不能走
    return true;
}

int BFS(location B)
{
    if (labyrinth[B.x][B.y] == 'E')
    {
        return 0;
    } //注意，要判断起点是不是 同时为终点
    queue<struct location> que;
    que.push(B);
    location saveData; //接受来自队首的数据
    while (!que.empty())
    {
        saveData = que.front();
        que.pop();
        for (int i = 0; i < 4; i++)
        {
            location middle = saveData; //middle用来接收数据然后移动
            middle.x += dir[i][0];
            middle.y += dir[i][1];         //移动
            if (judge(middle.x, middle.y)) //如果(x,y)能走
            {
                if (labyrinth[middle.x][middle.y] == 'E')
                {
                    return middle.step + 1;
                }                             //找到终点，返回步数
                middle.step++;                //记录步数，先加了后放队列
                que.push(middle);             //没找到，这把该格子放到队列，等待下一次移动
                pass[middle.x][middle.y] = 1; //并记录格子已走
            }
        }
    }
}
int main()
{
    location B; //起点位置
    B.x = 0;
    B.y = 0;
    B.step = 0;
    cout << BFS(B) << endl;
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            cout << pass[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
