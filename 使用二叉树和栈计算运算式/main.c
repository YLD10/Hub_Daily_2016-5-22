#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "binarytree.h"

void Visit(DataType elm, Stack *st) {
    ElemType bp1, bp2, result;
    printf("%c    ", elm);
    if (elm != '+' && elm != '-' && elm != '*' && elm != '/')
        Push(st,elm-'0');
    else {
      	if (elm == '+') {
          Pop(st,&bp1);
          Pop(st,&bp2);
          result = bp1 + bp2;
          Push(st,result);
        }
        if (elm == '-') {
          Pop(st,&bp1);
          Pop(st,&bp2);
          result = bp2 - bp1;
          Push(st,result);
        }
        if (elm == '*') {
          Pop(st,&bp1);
          Pop(st,&bp2);
          result = bp1 * bp2;
          Push(st,result);
        }
        if (elm == '/') {
          Pop(st,&bp1);
          Pop(st,&bp2);
          result = bp2 / bp1;
          Push(st,result);
        }
    }
}

void RecPostOrder(TreeNode *bt, void Visit(DataType elm, Stack *st), Stack *st) {
    if (bt != NULL) {
        RecPostOrder(bt->leftChild,Visit,st);
        RecPostOrder(bt->rightChild,Visit,st);
        Visit(bt->data,st);
    }
}

int main() {
    TreeNode *bt;
    Stack *st;

    InitStack(&st);
    puts("\nÇëÊäÈëÏÈÐòÔËËãÊ½£¨ÈôÊä´í£¬Çë¼üÈë$$½áÊø£©:\n");
    MakeCharTree2(&bt);
    puts("");
    PrintBiTree(bt,1);
    puts("");
    RecPostOrder(bt,Visit,st);
    puts("");
    printf("\nThe result is %.2f\n", st->a[0]);

    return 0;
}
