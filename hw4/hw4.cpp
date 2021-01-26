#include <iostream>
#include <cstring>
using namespace std;

void init(bool **bits, int m, int r, int **a, int **b, int p)
{
    *bits = (bool *)malloc(sizeof(bool) * m); //�}bits�Ŷ�
    *a = (int *)malloc(sizeof(int) * r); //a�üư}�C�Ŷ�
    srand(1); //�]�üƺؤl
    for (int i = 0; i < r; i++) 
    {
        *(*a + i) = (rand() % (p - 1)) + 1; //�][1,p-1]�����ü�
    }
    *b = (int *)malloc(sizeof(int) * r); //b�üư}�C�Ŷ�
    srand(2); //�]�üƺؤl
    for (int i = 0; i < r; i++)
    {
        *(*b + i) = (rand() % (p - 1)) + 1; //�][1,p-1]�����ü�
    }
}

int myhash(char *str, int count, int m, int p, int *a, int *b)
{
    hash<string> hashing;
    return (a[count] * hashing(str) + b[count]) % p % m; //�^��hash��m
}

void insert(bool *bits, int m, int r, int p, char *str, int *a, int *b)
{
    for (int count = 0; count < r; count++)
    {
        bits[myhash(str, count, m, p, a, b)] = 1; //�N�^�Ǧ�m��bit�אּ1
    }
}

bool query(bool *bits, int m, int p, int r, char *str, int *a, int *b)
{
    for (int count = 0; count < r; count++)
    {
        if (bits[myhash(str, count, m, p, a, b)] != 1) //�P�_��ihash�O�_�s�b�A�Y��bit=0�h�����s�b
            return 0; //���s�b�Y�^��0
    }
    return 1;
}

int main()
{
    char instr[100][1000]; //input string
    char outstr[100][1000]; //for sure this string is exist
    bool *bits; //�Φb�sbit�O0�B1
    int *a, *b; //a�üƩMb�ü�
    int m, r, input, output, p; //�}�X��bit�B�X��hash_function�B�n�s�J����r�B�n�P�_�O�_�s�b����r�Btest_prime
    cin >> m >> r >> input >> output >> p; 
    init(&bits, m, r, &a, &b, p); //��l��
    for (int i = 0; i < input; i++)
    {
        cin >> instr[i]; //��J�n�s�J����r
        insert(bits, m, r, p, instr[i], a, b); //�s�Jhash_map
    }

    for (int i = 0; i < output; i++)
    {
        cin >> outstr[i]; //��J�n�P�_����r
        bool num = query(bits, m, p, r, outstr[i], a, b); //�P�_�O�_�s�b
        if (num == 1)
            cout << outstr[i] << ": true" << endl; //�p�G�^�ǬO�s�b��(true)��X"true"
        else
            cout << outstr[i] << ": false" << endl; //���O�N�^��false
    }
}