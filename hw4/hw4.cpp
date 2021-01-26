#include <iostream>
#include <cstring>
using namespace std;

void init(bool **bits, int m, int r, int **a, int **b, int p)
{
    *bits = (bool *)malloc(sizeof(bool) * m); //開bits空間
    *a = (int *)malloc(sizeof(int) * r); //a亂數陣列空間
    srand(1); //設亂數種子
    for (int i = 0; i < r; i++) 
    {
        *(*a + i) = (rand() % (p - 1)) + 1; //設[1,p-1]間的亂數
    }
    *b = (int *)malloc(sizeof(int) * r); //b亂數陣列空間
    srand(2); //設亂數種子
    for (int i = 0; i < r; i++)
    {
        *(*b + i) = (rand() % (p - 1)) + 1; //設[1,p-1]間的亂數
    }
}

int myhash(char *str, int count, int m, int p, int *a, int *b)
{
    hash<string> hashing;
    return (a[count] * hashing(str) + b[count]) % p % m; //回傳hash位置
}

void insert(bool *bits, int m, int r, int p, char *str, int *a, int *b)
{
    for (int count = 0; count < r; count++)
    {
        bits[myhash(str, count, m, p, a, b)] = 1; //將回傳位置的bit改為1
    }
}

bool query(bool *bits, int m, int p, int r, char *str, int *a, int *b)
{
    for (int count = 0; count < r; count++)
    {
        if (bits[myhash(str, count, m, p, a, b)] != 1) //判斷丟進hash是否存在，若有bit=0則為不存在
            return 0; //不存在即回傳0
    }
    return 1;
}

int main()
{
    char instr[100][1000]; //input string
    char outstr[100][1000]; //for sure this string is exist
    bool *bits; //用在存bit是0、1
    int *a, *b; //a亂數和b亂數
    int m, r, input, output, p; //開幾個bit、幾個hash_function、要存入的文字、要判斷是否存在的文字、test_prime
    cin >> m >> r >> input >> output >> p; 
    init(&bits, m, r, &a, &b, p); //初始化
    for (int i = 0; i < input; i++)
    {
        cin >> instr[i]; //輸入要存入的文字
        insert(bits, m, r, p, instr[i], a, b); //存入hash_map
    }

    for (int i = 0; i < output; i++)
    {
        cin >> outstr[i]; //輸入要判斷的文字
        bool num = query(bits, m, p, r, outstr[i], a, b); //判斷是否存在
        if (num == 1)
            cout << outstr[i] << ": true" << endl; //如果回傳是存在的(true)輸出"true"
        else
            cout << outstr[i] << ": false" << endl; //不是就回傳false
    }
}