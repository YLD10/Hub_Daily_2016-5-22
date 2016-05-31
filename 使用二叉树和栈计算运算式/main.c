#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "binarytree.h"

void Visit(TreeNode *bt, Stack **st) {
    ElemType bp1, bp2, result;
    DataType elm;
    elm = bt->data;
    printf("%c    ", elm);
    if (elm != '+' && elm != '-' && elm != '*' && elm != '/')
        Push(st,elm-'0');
    else {
        if (bt->leftChild != NULL && bt->rightChild != NULL) {
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
}

void RecPostOrder(TreeNode *bt, void Visit(TreeNode *bt, Stack **st), Stack **st) {
    if (bt != NULL) {
        RecPostOrder(bt->leftChild,Visit,st);
        RecPostOrder(bt->rightChild,Visit,st);
        Visit(bt,st);
    }
}

int main() {
    TreeNode *bt;
    Stack *st, *tmp;

    InitStack(&st);
    tmp = st;
    puts("\n请输入先序运算式（若输错，请键入多个$结束）:\n");
    MakeCharTree2(&bt);
    puts("");
    PrintBiTree(bt,1);
    puts("");
    RecPostOrder(bt,Visit,&st);
    puts("");
    if (tmp != st)
        printf("\nThe result is %.2f\n", st->data);
    else
        puts("\nError!");

    return 0;
}
