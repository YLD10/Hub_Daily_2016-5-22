#include <stdio.h>
#include <stdlib.h>
#include "binarytree.h"

int Max(TreeNode *btl, TreeNode *btr);
int Deep(TreeNode *bt);

//计算二叉树叶子
int Leaf(TreeNode *bt) {
    if (bt == NULL)
        return 0;
    else if (bt->leftChild == NULL && bt->rightChild == NULL)
            return 1;
        else
            return Leaf(bt->leftChild) + Leaf(bt->rightChild);
}
//找左右子树中最大的深度
int Max(TreeNode *btl, TreeNode *btr) {
	int l = Deep(btl), r = Deep(btr);
    if (l > r)
        return l + 1;
    else
        return r + 1;
}
//计算二叉树的深度
int Deep(TreeNode *bt) {
    if (bt == NULL)
        return 0;
    else if (bt->leftChild == NULL && bt->rightChild == NULL)
            return 1;
        else
            return Max(bt->leftChild,bt->rightChild);
}

int main() {
    TreeNode *bt;

    puts("\n请输入先序二叉树（若输错，请键入$$结束）:\n");
    MakeCharTree2(&bt);
    puts("");
    PrintBiTree(bt,1);

    printf("\nLeafNumber:%d\n",Leaf(bt));
    printf("\nDeepNumber:%d\n",Deep(bt));

    return 0;
}
