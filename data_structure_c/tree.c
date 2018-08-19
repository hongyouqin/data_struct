/*
 * 树的相关术语
 * 节点的度：树上任一节点所拥有的子数的数目
 * 叶子：度为0的节点（白话就是，节点下面没有子节点）
 * 数的度：一棵树中所有节点的度最大值（白话：某一个节点所带子节点最多的）
 * 下面的树采用双亲表示法
 * */
#include <stdio.h>

#define DataType char
#define DefaultCount 30

typedef struct TreeNode {
   DataType data;
   int parent;
} Node;

//有序树
typedef struct OrderTree {
    Node node[DefaultCount]; //节点树
    int count; //节点的个数
} Tree;

//找双亲
void Parent(Tree *tree, DataType child) {
    for (int index = 0; index < tree->count; ++index) {
        if (tree->node[index].data == child) {
            int parent = tree->node[index].parent;
            if (parent == -1) {
                printf("节点:%c是根节点\n", tree->node[index].data);
            } else {
                printf("节点:%c的双亲是:%c\n", tree->node[index].data, tree->node[parent].data);
            }
            return;
        }
    }
    
    printf("树上面没有此节点:%c\n", child);
}

//创建树
/*
 *   |下标|data|parent|
 *   | 0  | A  |  -1  |
 *   | 1  | B  |  0   |
 *   | 2  | C  |  0   |
 *   | 3  | D  |  1   |
 *   | 4  | E  |  2   |
 *   | 5  | F  |  2   |
 *   | 6  | G  |  3   |
 *   | 7  | H  |  3   |
 *   | 8  | I  |  3   |
 *   | 9  | J  |  4   |
 *
 *   双亲表示法
 * */
void CreateTree(Tree *tree) {
    tree->node[0].data = 'A';
    tree->node[0].parent = -1; //表示根节点
    tree->node[1].data = 'B';
    tree->node[1].parent = 0;
    tree->node[2].data = 'C';
    tree->node[2].parent = 0;
    tree->node[3].data = 'D';
    tree->node[3].parent = 1;
    tree->node[4].data = 'E';
    tree->node[4].parent = 2;
    tree->node[5].data = 'F';
    tree->node[5].parent = 2;
    tree->node[6].data = 'G';
    tree->node[6].parent = 3;
    tree->node[7].data = 'H';
    tree->node[7].parent = 3;
    tree->node[8].data = 'I';
    tree->node[8].parent = 3;
    tree->node[9].data = 'J';
    tree->node[9].parent = 4;
    
    tree->count = 10;
}

//遍历树
void Traverse(Tree *tree) {
    for (int index = 0; index < tree->count; index++) {
        int parent = tree->node[index].parent;
        if (parent == -1) {
            printf("节点=%c; 双亲=%s\n", tree->node[index].data, "根节点");
        } else {
            printf("节点=%c; 双亲=%c\n", tree->node[index].data, tree->node[parent].data);
        }
    }
}

//剪枝
//查询孩子

int main() {
   Tree tree;
   CreateTree(&tree);
   Traverse(&tree);
   Parent(&tree, 'B');
}


