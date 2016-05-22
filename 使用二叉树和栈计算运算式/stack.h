#define MAX 100

typedef float ElemType;

typedef struct stack {
    ElemType a[MAX];
    int top;
}Stack;

void InitStack(Stack **p) {
    *p = (Stack *)malloc(sizeof(Stack));
    (*p)->top = -1;
}

int StackFull(Stack *p) {
    return (p->top == MAX-1) ? 1 : 0;
}

int StackEmpty(Stack *p) {
    return (p->top == -1) ? 1 : 0;
}

void Push(Stack *p, ElemType elm) {
    if (!StackFull(p))
        p->a[++(p->top)] = elm;
    else {
        printf("\nStack is full!\n");
        exit(0);
    }
}

void Pop(Stack *p, ElemType *backup) {
    if (!StackEmpty(p)) {
       *backup = p->a[(p->top) --];
    }
    else {
        printf("\nStack is empty!\n");
        exit(0);
    }
}

void StackTop(Stack *p, ElemType *tmp) {
    if (!StackEmpty(p))
        *tmp = p->a[p->top];
}
