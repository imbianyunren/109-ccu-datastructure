#include <stdio.h>
#include <stdlib.h>
typedef struct Node *NodePtr;
typedef struct ListNode *ListNodePtr;
typedef struct Node{
    int id;
    ListNodePtr children;
    NodePtr parent;
};
typedef struct ListNode{
    NodePtr data;
    ListNodePtr link;
};

/*print*/
void print(int **EachRoundArr, int step, int NumOfNodes){
    printf("%d\n", step);
    for (int i = 0; i < step; i++){
        for (int j = 0; j < NumOfNodes - 1; j++){
            printf("%d ", EachRoundArr[i][j]);
        }
        printf("%d\n", EachRoundArr[i][NumOfNodes - 1]);
    }
}

/*insert child nodes*/
ListNodePtr Insert_ChildNodes(ListNodePtr p, NodePtr node){
    p->link = NULL;
    p->data = node; /*store the data of child*/
    return p;
}

struct Node *RemakeLink(struct Node Nodes[], int OutputArr[], int NumOfNodes, int Lastnode, int *step){
    int NextChangeNum = 0;
    int *first = calloc(NumOfNodes, sizeof(int));   
    int *NextChangeNodes = malloc(sizeof(int) * NumOfNodes);    /*store the next round node*/
    int *TmpChangeNodes = malloc(sizeof(int *) * NumOfNodes);   /*store the next-next round node temporary*/ 
    int **EachRoundArr = malloc(sizeof(int **) * 1);
    ListNodePtr p[NumOfNodes];  /*store the current children's location*/
    int TmpNum = 0; /*the num of next-next nodes*/
    int imcomplete = 0; /*sure that the last nodes don't have child then finish rounds*/

    while (1){
        imcomplete = 0;
        TmpNum = 0;
        EachRoundArr = realloc(EachRoundArr, sizeof(int **) * *step);
        EachRoundArr[*step - 1] = malloc(sizeof(int *) * NumOfNodes);

        for (int i = 0; i < NumOfNodes; i++){
            EachRoundArr[*step - 1][i] = Nodes[i].parent->id;   /*store each round to print out*/

            if (*step == 1){
                if (OutputArr[i] == Lastnode){
                    imcomplete = 1; /*child exist*/
                    NextChangeNodes[NextChangeNum++] = i;   /*store the next round node temporary*/
                    Nodes[i].parent->id = Lastnode; /*change the parent node*/
                    
                    /*link the children nodes*/
                    if (first[Nodes[i].parent->id] == 0){
                        if (Nodes[Nodes[i].parent->id].children == NULL){
                            Nodes[Nodes[i].parent->id].children = malloc(sizeof(ListNodePtr));
                        }
                        p[Nodes[i].parent->id] = Insert_ChildNodes(Nodes[Nodes[i].parent->id].children, &Nodes[i]);
                        first[Nodes[i].parent->id] = 1;
                    }
                    else{
                        p[Nodes[i].parent->id]->link = malloc(sizeof(ListNodePtr));
                        p[Nodes[i].parent->id] = Insert_ChildNodes(p[Nodes[i].parent->id]->link, &Nodes[i]);
                    }
                }
            }
            else{
                for (int r = 0; r < NextChangeNum; r++){
                    if (OutputArr[i] == NextChangeNodes[r]){
                        imcomplete = 1;     /*child exist*/
                        Nodes[i].parent = &Nodes[NextChangeNodes[r]]; /*change the parent node*/
                        TmpChangeNodes[TmpNum++] = i;   /*store the next round node temporary*/

                        /*link the children nodes*/
                        if (first[Nodes[i].parent->id] == 0){
                            if (Nodes[Nodes[i].parent->id].children == NULL){
                                Nodes[Nodes[i].parent->id].children = malloc(sizeof(ListNodePtr));
                            }
                            p[Nodes[i].parent->id] = Insert_ChildNodes(Nodes[Nodes[i].parent->id].children, &Nodes[i]);
                            first[Nodes[i].parent->id] = 1;
                        }
                        else{
                            p[Nodes[i].parent->id]->link = malloc(sizeof(ListNodePtr));
                            p[Nodes[i].parent->id] = Insert_ChildNodes(p[Nodes[i].parent->id]->link, &Nodes[i]);
                        }
                        break;
                    }
                }
            }
        }

        if (*step>1 && imcomplete == 1){    /*store the new nextchage nodes*/
            NextChangeNum = TmpNum;
            for (int a = 0; a < TmpNum; a++){
                NextChangeNodes[a] = TmpChangeNodes[a];
            }
        }
        else if(imcomplete == 0){   /*make the node which with no child link = NULL*/
            for (int i = 0; i < NextChangeNum; i++){
                Nodes[NextChangeNodes[i]].children = NULL;
            }
            break;
        }

        *step += 1; /*add steps*/
    }

    print(EachRoundArr, *step, NumOfNodes);
    return Nodes;
}

int main()
{
    int NumOfNodes;
    scanf("%d", &NumOfNodes);

    NodePtr Nodes = malloc(sizeof(*Nodes) * NumOfNodes);
    int *OutputArr = malloc(sizeof(int) * NumOfNodes);
    int LastNode, step = 1;
    ListNodePtr p[NumOfNodes];

    /*預設全部children為NULL*/
    for (int i = 0; i < NumOfNodes; i++){
        Nodes[i].parent = malloc(sizeof(*Nodes));
        Nodes[i].children = NULL;
    }

    /*輸入input節點*/
    for (int i = 0; i < NumOfNodes; i++){
        scanf("%d", &Nodes[i].parent->id);
        Nodes[i].id = i;

        /*link the children nodes*/
        if (Nodes[i].parent->id == -1){
            LastNode = i;
            continue;
        }
        if (Nodes[Nodes[i].parent->id].children == NULL){
            Nodes[Nodes[i].parent->id].children = malloc(sizeof(ListNodePtr));
            p[Nodes[i].parent->id] = Insert_ChildNodes(
                Nodes[Nodes[i].parent->id].children,&Nodes[i]);
        }

        else{
            p[Nodes[i].parent->id]->link = malloc(sizeof(ListNodePtr));
            p[Nodes[i].parent->id] = Insert_ChildNodes(p[Nodes[i].parent->id]->link, &Nodes[i]);
        }
    }

    /*輸入output節點*/
    for (int i = 0; i < NumOfNodes; i++){
        scanf("%d", &OutputArr[i]);
    }

    Nodes = RemakeLink(Nodes, OutputArr, NumOfNodes, LastNode, &step); /*remake the links*/

    return 0;
}
