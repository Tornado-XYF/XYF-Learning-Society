#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef int ElemType;

typedef struct {
    ElemType *data;
    int top;
}Stack; //����ջ

typedef enum {
    LEFT_PARE,RIGHT_PARE,ADD,SUB,MUL,DIV,MOD,EOS,NUM
}contentType;//�����ţ������ţ��Ӽ��˳���\0,����

// char expr [] = "82/2+56*-"; //��Ҫ��ֵ�ĺ�׺���ʽ
char expr [] = "x/(i-j)*y"; //��Ҫת���ĵ���׺���ʽ

//��̬�ڴ�����ʼ��ջ
Stack* initStack() {
    Stack *s = (Stack*)malloc(sizeof(Stack));
    s->data = (ElemType*)malloc(sizeof(ElemType)*MAXSIZE);
    s->top = -1;
    return s;
}

//�ж�ջ�Ƿ�Ϊ��

int isEmpty(Stack *s) {
    if (s == NULL)
        return 2;
    else if (s->top == -1) {
        // printf("��\n");
        return 1;
    }
    else
        return 0;
}

//��ջ

int push(Stack *s,ElemType e) {
    if (s == NULL)
        return 2;
    else if (s->top == MAXSIZE-1) {
        printf("ջ��\n");
        return 0;
    }
    else {
        s->top++;
        s->data[s->top] = e;
        return 1;
    }
}

//��ջ
int pop(Stack *s,ElemType *e) {
    if (isEmpty(s)) {
        printf("ջ��\n");
        return 0;
    }
    else {
        *e = s->data[s->top];
        s->top--;
        return 1;
    }
}

//���ջ��Ԫ��

int getTop(Stack *s,ElemType *e) {
    if (isEmpty(s)) {
        printf("ջ��\n");
        return 0;
    }
    else {
        *e = s->data[s->top];
        return 1;
    }
}

//������ñ��ʽ����ַ�
contentType getToken(char *symbol,int *index) {
    *symbol = expr[*index]; //��ȡ���ʽ����ַ�
    *index = *index + 1;
    switch (*symbol) {
        case'(':
            return LEFT_PARE;
        case ')':
            return RIGHT_PARE;
        case '+' :
            return ADD;
        case '-' :
            return SUB;
        case '*' :
            return MUL;
        case '/' :
            return DIV;
        case '%' :
            return MOD;
        case '\0' :
            return EOS;
        default:
            return NUM;

    }
}

int print_token(contentType token) {
    switch (token) {
        case ADD:
            printf("+");
            break;
        case SUB:
            printf("-");
            break;
        case MUL:
            printf("*");
            break;
        case DIV:
            printf("/");
            break;
        case MOD:
            printf("%%");
            break;
        default:
            return 0;
    }
    return 1;
}

void postfix(Stack *s) { //�����ж�����������ȼ�
    //��������ȼ��������ö��Ԫ��һһ��Ӧ
    int in_stack[] = {0,19,12,12,13,13,13,0};// ������ջ�ڵ����ȼ�
    int out_stack[] = {20,19,12,12,13,13,13,0};//������ջ������ȼ�
    contentType token;
    int index = 0;
    s->data[0] = EOS; //��EOSѹ��ջ�ף���Ϊ��׺���ʽ�����һ��������\0
    char  symbol;
    ElemType e;

    token = getToken(&symbol,&index); //��һ��ȡ���ʽ�ķ��Ÿ�token

    while (token != EOS) {
        if (token == NUM) {
            printf("%c",symbol);
        }
        else if (token == RIGHT_PARE) {
            while (s->data[s->top] != LEFT_PARE) {//���ջ��Ԫ�ز��������ţ����ջ
                pop(s,&e);
                print_token(e);
            }
            pop(s,&e);
        }
        else { //�Ȳ�������Ҳ�������ţ���ô�����������Ҫ�ж����ȼ�

                while (!isEmpty(s) && in_stack[s->data[s->top]] >= out_stack[token]) {
                    pop(s,&e);  //��ջ��Ԫ�ش���ɨ��ĵ�ǰ���ţ����ջ
                    print_token(e);//���Ҵ�ӡ��ջ��Ԫ��
                }
                push(s,token); //���ܵ�ǰ�����Ƿ����ջ��Ԫ�أ����ѵ�ǰ����ѹ��ջ��
            }
            token = getToken(&symbol,&index);
        }

}

int eval(Stack *s) {
    char symbol; //�����Ǳ��ʽ��ķ���
    int op1,op2;//�����Ǳ��ʽ����ֵ
    int index = 0;//���ʽ�±�

    contentType token;//ö�ٱ���
    token = getToken(&symbol,&index);
    ElemType result;
    while (token != EOS) {//��ʼɨ����ʽ
        if (token == NUM) {
            push(s,symbol - '0'); //��������ASCII�����ַ�ת��Ϊ����ֵ��������ѹջ
        }
        else {
            pop(s,&op2); //ջ��Ԫ����op2
            pop(s,&op1);

            switch (token) {
                case ADD:
                    push(s,op1+op2);
                    break;
                case SUB:
                    push(s,op1-op2);
                    break;
                case MUL:
                    push(s,op1*op2);
                    break;
                case DIV:
                    push(s,op1/op2);
                    break;
                default:
                    break;
            }
        }
        token = getToken(&symbol,&index);
    }
    pop(s,&result);
    printf("%d\n",result);
    return 1;
}


int main() {
    Stack *s = initStack();
    printf("%s\n",expr);
    // eval(s);
    postfix(s);
    free(s);
    return 0;
}