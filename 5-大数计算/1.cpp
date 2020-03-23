#include <stdio.h>
#include <string.h>
int bigcompare(int[], int[], int);
void bigadd(int[], int[], int);
void bigsubtract(int[], int[], int);
void bigmultiply(int[], int[], int, int);
void bigdivide(int[], int[], int, int);
int main()
{
    char a_char[1000] = {0}, b_char[1000] = {0}; //a_char,b_char表示用字符数组储存的大数
    int a_int[1000], b_int[1000];                //a_int,b_int表示用整形数组储存的大数
    int len1, len2, ml;

    scanf("%s", a_char); //分别输入大数a,b
    scanf("%s", b_char);
    len1 = strlen(a_char); //len1，len2分别表示大数a,b的位数
    len2 = strlen(b_char);
    ml = len1 > len2 ? len1 : len2; //ml为len1，len2中较大的位数

    //①将字符变量转化为整形变量并倒序储存在数组中，便于后续计算
    //②并在较小的数前面（数组后面）补齐0直至两数数位相等，便于后续计算
    for (int i = 0, k1, k2; i < ml; i++)
    {
        k1 = len1 - 1 - i;
        k2 = len2 - 1 - i;

        if (k1 >= 0)
            a_int[i] = a_char[k1] - '0';
        else
            a_int[i] = 0;
        if (k2 >= 0)
            b_int[i] = b_char[k2] - '0';
        else
            b_int[i] = 0;
    }

    printf("大小比较：%d\n", bigcompare(a_int, b_int, ml));
    printf("和：");
    bigadd(a_int, b_int, ml);
    printf("差：");
    bigsubtract(a_int, b_int, ml);
    printf("积：");
    bigmultiply(a_int, b_int, len1, len2);
    printf("商：");
    bigdivide(a_int, b_int, len1, len2);
    return 0;
}

int bigcompare(int a_int[], int b_int[], int ml) //返回a_int,b_int大小比较结果
{
    for (int i = ml - 1; i >= 0; i--) //a_int大于b_int返回1，等于返回0，小于返回-1
    {
        if (a_int[i] > b_int[i])
            return 1;
        else if (a_int[i] < b_int[i])
            return -1;
        else if (i == 0)
            return 0;
    }
}

void bigadd(int a_int[], int b_int[], int ml)
{
    int t, carry = 0; //t为计算过程中的临时值，carry表示进位
    char ans[ml + 2];
    ans[ml] = '\0'; //倒数第2个元素赋值为空字符

    for (int i = 0; i < ml; i++)
    {
        t = a_int[i] + b_int[i] + carry;
        if (t < 10)
        {
            ans[ml - 1 - i] = t + '0';
            carry = 0;
        }
        else
        {
            ans[ml - 1 - i] = t % 10 + '0';
            carry = t / 10;
        }
    }

    //若最高位有进位，则将字符数组元素整体后移1个单位，并在最前面放上进位
    if (carry != 0)
    {
        for (int i = ml + 1; i >= 1; i--)
        {
            ans[i] = ans[i - 1];
        }
        ans[0] = carry + '0';
    }
    puts(ans);
    return;
}

void bigsubtract(int a_int[], int b_int[], int ml)
{
    int t, borrow = 0, flag; //t为计算过程中的临时值，borrow表示借位
    int *max, *min;
    char ans[ml + 2];
    ans[ml] = '\0'; //倒数第2个元素赋值为空字符

    flag = bigcompare(a_int, b_int, ml); //flag表示两数大小比较的结果
    if (flag == 0)
    {
        ans[0] = '0';
        ans[1] = '\0';
        puts(ans);
        return;
    }
    else if (flag == 1) //用找出较大的数，随后用较大的数减去较小的数，符号最后再确定
    {
        max = a_int;
        min = b_int;
    }
    else if (flag == -1)
    {
        max = b_int;
        min = a_int;
    }

    for (int i = 0; i < ml; i++) //较大的数减去较小的数
    {
        t = max[i] - min[i] - borrow;
        if (t >= 0)
        {
            ans[ml - 1 - i] = t + '0';
            borrow = 0;
        }
        else
        {
            ans[ml - 1 - i] = t + 10 + '0';
            borrow = 1;
        }
    }

    int i, j; //相当于去除掉差前面多余的0
    for (i = 0; i < ml && ans[i] == '0'; i++)
        ;
    for (j = 0; i < ml; i++, j++)
    {
        ans[j] = ans[i];
    }
    ans[j] = '\0';

    //若结果为负数，则将字符数组元素整体后移一个单位，并在最前面放上负号
    if (flag == -1)
    {
        for (int i = ml + 1; i >= 1; i--)
        {
            ans[i] = ans[i - 1];
        }
        ans[0] = '-';
    }

    puts(ans);
    return;
}

void bigmultiply(int a_int[], int b_int[], int len1, int len2)
{
    int sl = len1 + len2;   //sl为两个大数的位数和
    int digit[sl] = {0}, t; //先不处理进位，digit用于储存按位乘法计算后得出的各数位的量
    int ans_int[sl];
    char ans_char[sl];

    for (int i = 0; i < len1; i++) //按位进行乘法计算
    {
        for (int j = 0; j < len2; j++)
        {
            t = a_int[i] * b_int[j];
            digit[i + j] += t;
        }
    }

    for (int i = 0; i < sl; i++) //最后处理进位
    {
        if (digit[i] < 10)
            ans_int[i] = digit[i];
        else
        {
            ans_int[i] = digit[i] % 10;
            digit[i + 1] += digit[i] / 10;
        }
    }

    int i, j;
    for (i = sl - 1; i >= 1 && ans_int[i] == 0; i--)
        ; //相当于去除掉积前多于的0，并将整形类型的积转化为字符类型
    for (j = 0; i >= 0; i--, j++)
    {
        ans_char[j] = ans_int[i] + '0';
    }
    ans_char[j] = '\0';
    puts(ans_char);
}

void bigdivide(int a_int[], int b_int[], int len1, int len2)
{
    int ml = len1 > len2 ? len1 : len2; //ml为len1，len2中较大的位数
    int dl = len1 - len2;               //dl为两个大数的位数差
    int t, borrow = 0;                  //t为计算过程中的临时值，borrow为运用大数减法时的借位
    int pos = dl;                       //pos表示原数b_int的个位数在b_t数组中的位置，也就是b_t为原数b_int的10^pos倍
    int a_t[10000], b_t[10000];         //a_t和b_t分别表示a_int被减后和b_int放大后的临时数
    int ans_int[ml] = {0};
    char ans_char[ml];

    if (len2 == 1 && b_int[0] == 0) //若b_int为0，则结果无意义
    {
        printf("error");
        return;
    }

    if (bigcompare(a_int, b_int, ml) < 0) //若a_int小于b_int，答案为0
    {
        ans_char[0] = '0';
        ans_char[1] = '\0';
        puts(ans_char);
        return;
    }

    //a_int复制给a_t
    for (int i = 0; i < len1; i++)
        a_t[i] = a_int[i];

    //b_t为原数b_int的10^dl倍
    for (int i = 0; i < dl; i++)
        b_t[i] = 0;
    for (int i = dl, j = 0; i < ml; i++, j++)
        b_t[i] = b_int[j];

    //若a_t小于放大后的b_t，则将b_t整体前移，也就是缩小10倍，并在数字前（数组后）补0
    if (bigcompare(a_t, b_t, ml) == -1 && pos >= 1)
    {
        for (int i = 0; i < ml - 1; i++)
            b_t[i] = b_t[i + 1];
        b_t[ml - 1] = 0;
        pos--;
    }

    while (bigcompare(a_t, b_t, ml) >= 0)
    {
        while (bigcompare(a_t, b_t, ml) >= 0)
        {
            for (int i = 0; i < ml; i++) //a_t减去b_t
            {
                t = a_t[i] - b_t[i] - borrow;
                if (t >= 0)
                {
                    a_t[i] = t;
                    borrow = 0;
                }
                else
                {
                    a_t[i] = t + 10;
                    borrow = 1;
                }
            }
            ans_int[pos]++; //记录商
        }

        //只要b_t比a_t被减后大，b_t就会不停缩小10倍直至小于a_t，但不能缩小到小于原数b_int
        while (pos >= 1 && bigcompare(a_t, b_t, ml) == -1)
        {
            for (int i = 0; i < ml - 1; i++)
                b_t[i] = b_t[i + 1];
            b_t[ml - 1] = 0;
            pos--;
        }
    }

    int i, j;
    for (i = dl; i >= 0 && ans_int[i] == 0; i--)
        ; //相当于去除掉商前多于的0，并将整形类型的商转化为字符类型
    for (j = 0; i >= 0; i--, j++)
    {
        ans_char[j] = ans_int[i] + '0';
    }
    ans_char[j] = '\0';
    puts(ans_char);
    return;
}
