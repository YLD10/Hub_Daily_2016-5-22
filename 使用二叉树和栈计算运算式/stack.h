#define MAX 100
typedef float ElemType;

typedef struct stack {
    ElemType data;
    struct stack *next;
}Stack;

//��ʼ����ջ
void InitStack(Stack **pp) {
    (*pp) = NULL;
}

//�ж�ջ�Ƿ�Ϊ��
int StackEmpty(Stack *p) {
    return p == NULL;
}

//ȡջ��Ԫ��
int StackTop(Stack *p , ElemType *q) {
    if (!StackEmpty(p)) {  //��ջ��Ϊ��
        *q = p->data;   //ȡջ��Ԫ��
        return 1;   //����1
    }
    else    //���򷵻�0
        return 0;
}

//Ԫ����ջ����
void Push(Stack **pp, ElemType x) {
    Stack *s;

    s = (Stack *)malloc(sizeof(Stack));   //Ϊ�½��������ڴ�ռ�
    s->data = x;    //Ԫ�ش����½��
    s->next = (*pp);    //�½����ͷָ����ָ��Ľ���ַ
    (*pp) = s;  //ͷָ��ָ���½��ĵ�ַ
}

//ջ��Ԫ�س�ջ����
int Pop(Stack **pp, ElemType *q) {
    Stack *saved;

    saved = (*pp);  //����ջ�����ĵ�ַ

    if (!StackEmpty(*pp)) { //��ջ��Ϊ��
        *q = (*pp)->data;   //����ջ��Ԫ��
        *pp = (*pp)->next;  //ͷָ������ƶ�һ�����
        free(saved);    //�ͷ�ԭջ�����ռ�ݵ��ڴ�ռ�
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
