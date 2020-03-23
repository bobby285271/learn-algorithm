#include <iostream>
#include <cstdlib>
#include <queue>
using namespace std;
struct tree
{
    char saveChar;
    int step;
    struct tree *L;
    struct tree *R;
};
struct tree *c;
struct tree *f;
struct list
{
    struct tree *head;
};
void putin(struct tree *p, struct tree *prep)
{
    if (p->saveChar < prep->saveChar)
    {
        if (prep->L != NULL)
        {
            putin(p, prep->L);
        }
        else
        {
            prep->L = p;
            return;
        }
    }
    if (p->saveChar > prep->saveChar)
    {
        if (prep->R != NULL)
        {
            putin(p, prep->R);
        }
        else
        {
            prep->R = p;
            return;
        }
    }
}
void ShowAndRecord(struct tree *p)
{
    if (p != NULL)
    {
        if (p->saveChar == 'd')
        {
            c = p;
        }
        if (p->saveChar == 'g')
        {
            f = p;
        }
        //cout<<p->saveChar<<endl;
    }
    if (p->L != NULL)
    {
        ShowAndRecord(p->L);
    }
    if (p->R != NULL)
    {
        ShowAndRecord(p->R);
    }
}
//-----------展示部分--------
//struct tree//节点的模板
//{
//char saveChar;//存字母
//struct tree*L;//存节点左边的节点
//struct tree*R;//存节点右边的节点
//};

struct tree *used[50]; //记录放进过队列里的节点
int UsedCount;         //记录放进去过的节点数

bool Used(struct tree *p) //判断节点有没有放进队列，即有没有被探访过，有则返回true,否则false
{
    for (int i = 0; i < UsedCount; i++)
    {
        if (p == used[i])
        {
            return true;
            break;
        }
    }
    return false;
}

void bfs(struct tree *root, char Find) //函数本体,传入根节点和要做的字母
{
    queue<struct tree *> que; //建立一个队列
    que.push(root);           //将第一个节点放进队列，准备让它“发芽”
    used[UsedCount++] = root; //记录用过的节点,这里将第一个节点放进去
    struct tree *saveNode;    //用来储存从队列中拿出来的节点
    int steps = 0;            //记录处理节点的个数
    int ok = 0;               //判断是否能找到
    while (!que.empty())      //一直处理，直到队列中已经没有节点，即树中每一个节点已经被处理完
    {
        saveNode = que.front();         //取出队列中第一个节点
        que.pop();                      //取出了队列里当然就没了
        if (Find == saveNode->saveChar) //如果要找的字母正好是节点里存储的字母
        {
            cout << "找到了" << endl;
            cout << "一个处理了" << steps + 1 << "个节点" << endl;
            ok = 1; //找到了就标记
            break;  //找到了就离开循环，结束寻找
        }
        else
        {
            cout << Find << " 和 " << saveNode->saveChar << endl; //如果不是,看一下是在和谁比较，准备走到树的下一层
            if (saveNode->L != NULL && !Used(saveNode->L))        //如果节点左边还有节点，而且还没放进过队列
            {
                que.push(saveNode->L);           //那就放进去呗
                used[UsedCount++] = saveNode->L; //记录
            }
            if (saveNode->R != NULL && !Used(saveNode->R)) //右边如果由节点，同理
            {
                que.push(saveNode->R);
                used[UsedCount++] = saveNode->R;
            }
        }
        steps++; //一个循环一个节点，处理完毕
    }
    if (!ok)
    {
        cout << "找不到" << endl;
    }
    return;
}

//-----------展示部分--------
int main()
{
    //输入
    //6
    //e
    //b
    //g
    //a
    //d
    //c
    //和一个要找的字母

    int n;
    cin >> n;
    char input;
    struct tree *p;
    struct list L;
    L.head = NULL;
    for (int i = 0; i < n; i++)
    {
        p = (struct tree *)malloc((sizeof(struct tree)));
        cin >> input;
        p->saveChar = input;
        p->L = NULL;
        p->R = NULL;
        if (L.head == NULL)
        {
            L.head = p;
        }
        else
        {
            struct tree *prep = L.head;
            putin(p, prep);
        }
    }
    ShowAndRecord(L.head);
    p = (struct tree *)malloc((sizeof(struct tree)));
    p->saveChar = 'f';
    p->L = NULL;
    p->R = NULL;
    c->R = p;
    f->L = p;
    char Find;
    cout << "请输入要寻找的字母：";
    cin >> Find;
    bfs(L.head, Find);

    return 0;
}
