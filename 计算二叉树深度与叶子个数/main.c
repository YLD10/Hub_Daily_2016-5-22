#include <stdio.h>
#include <stdlib.h>
#include "binarytree.h"

int Max(TreeNode *btl, TreeNode *btr);
int Deep(TreeNode *bt);

//���������Ҷ��
int Leaf(TreeNode *bt) {
    if (bt == NULL)
        return 0;
    else if (bt->leftChild == NULL && bt->rightChild == NULL)
            return 1;
        else
            return Leaf(bt->leftChild) + Leaf(bt->rightChild);
}
//�������������������
int Max(TreeNode *btl, TreeNode *btr) {
	int l = Deep(btl), r = Deep(btr);
    if (l > r)
        return l + 1;
    else
        return r + 1;
}
//��������������
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

    puts("\n���������������������������$$������:\n");
    MakeCharTree2(&bt);
    puts("");
    PrintBiTree(bt,1);

    printf("\nLeafNumber:%d\n",Leaf(bt));
    printf("\nDeepNumber:%d\n",Deep(bt));

    return 0;
}
