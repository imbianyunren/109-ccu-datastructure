#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct node{
    double x;
    double y;
    double num;
    int degree; //鄰點數
    double output;
};

void getlocation(struct node *, int);
void degree(struct node *, int, int);

int main()
{
    int numofnode, round;
    scanf("%d%d", &numofnode, &round); //點的個數、循環次數
    struct node *nodes = (struct node *)malloc(sizeof(struct node) * numofnode);
    getlocation(nodes, numofnode);
    degree(nodes, numofnode, round);
}

void getlocation(struct node nodes[], int numofnode)
{
    int order;
    for (int i = 0; i < numofnode; i++){
        scanf("%d%lf%lf%lf", &order, &nodes[i].x, &nodes[i].y, &nodes[i].num);
        nodes[i].degree = 0; //預設每個點degree數為0
    }
    return;
}

void degree(struct node nodes[], int numofnode, int round)
{

    double distance;
    int **neighbor = calloc(numofnode, sizeof(int *)); //用於紀錄每個點的鄰點是誰
    double iequalj[numofnode];  //用於i=j時要乘的數
    printf("%d %d\n", numofnode, round);

    for (int i = 0; i < numofnode; i++){
        if (i != 0) printf(" ");
        printf("%.2lf", nodes[i].num); //輸出原始數字
        nodes[i].output = 0;  //初始最後輸出數=0
        iequalj[i] = 1; //初始i=j要乘的數=1
        for (int j = i; j < numofnode; j++){
            if (i == j) continue; //遇到相同點跳過
            distance = sqrt(pow(nodes[i].x - nodes[j].x, 2) + pow(nodes[i].y - nodes[j].y, 2)); //計算距離
            if (distance < 1){
                nodes[i].degree++;
                nodes[j].degree++;
                neighbor[i] = realloc(neighbor[i], sizeof(int) * nodes[i].degree);
                neighbor[j] = realloc(neighbor[j], sizeof(int) * nodes[j].degree);
                neighbor[i][nodes[i].degree - 1] = j;
                neighbor[j][nodes[j].degree - 1] = i;
            }
        }
    }
    printf("\n");

    double forminiequalj; //用於方便計算出iequalj
    for (int i = 0; i < round - 1; i++){ //round
        for (int j = 0; j < numofnode; j++){ //跑每個點
            if (j != 0) printf(" ");
            nodes[j].output = 0; //初始output=0
            for (int r = 0; r < nodes[j].degree; r++){ //跑此點的鄰點
                //first round要跑這個鄰點的基數
                if (nodes[j].degree > nodes[neighbor[j][r]].degree){
                    nodes[j].output += nodes[neighbor[j][r]].num / (2 * nodes[j].degree);
                    if (i < 1) forminiequalj = 2 * nodes[j].degree; 
                }
                else{
                    nodes[j].output += nodes[neighbor[j][r]].num / (2 * nodes[neighbor[j][r]].degree);
                    if (i < 1) forminiequalj = 2 * nodes[neighbor[j][r]].degree;
                }
                if (i < 1){
                    forminiequalj = 1 / forminiequalj;
                    iequalj[j] -= forminiequalj;
                }
            }
            nodes[j].output += nodes[j].num * iequalj[j];
            printf("%.2lf", nodes[j].output);
            if (j == numofnode - 1){
                for (int p = 0; p < numofnode; p++) nodes[p].num = nodes[p].output;
            } //要換round時刷新num值
        }
        printf("\n");
    }
}