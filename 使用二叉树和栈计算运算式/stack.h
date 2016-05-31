#define MAX 100
typedef float ElemType;

typedef struct stack {
    ElemType data;
    struct stack *next;
}Stack;

//初始化链栈
void InitStack(Stack **pp) {
    (*pp) = NULL;
}

//判断栈是否为空
int StackEmpty(Stack *p) {
    return p == NULL;
}

//取栈顶元素
int StackTop(Stack *p , ElemType *q) {
    if (!StackEmpty(p)) {  //若栈不为空
        *q = p->data;   //取栈顶元素
        return 1;   //返回1
    }
    else    //否则返回0
        return 0;
}

//元素入栈操作
void Push(Stack **pp, ElemType x) {
    Stack *s;

    s = (Stack *)malloc(sizeof(Stack));   //为新结点申请堆内存空间
    s->data = x;    //元素存入新结点
    s->next = (*pp);    //新结点后继头指针所指向的结点地址
    (*pp) = s;  //头指针指向新结点的地址
}

//栈顶元素出栈操作
int Pop(Stack **pp, ElemType *q) {
    Stack *saved;

    saved = (*pp);  //备份栈顶结点的地址

    if (!StackEmpty(*pp)) { //若栈不为空
        *q = (*pp)->data;   //备份栈顶元素
        *pp = (*pp)->next;  //头指针向后移动一个结点
        free(saved);    //释放原栈顶结点占据的内存空间
        return 1;
    }
    else
        return 0;
}
/*
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
*/
