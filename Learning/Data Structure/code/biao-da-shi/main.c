#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef int ElemType;

typedef struct {
    ElemType *data;
    int top;
}Stack; //创建栈

typedef enum {
    LEFT_PARE,RIGHT_PARE,ADD,SUB,MUL,DIV,MOD,EOS,NUM
}contentType;//左括号，右括号，加减乘除，\0,数字

// char expr [] = "82/2+56*-"; //需要求值的后缀表达式
char expr [] = "x/(i-j)*y"; //需要转换的的中缀表达式

//动态内存分配初始化栈
Stack* initStack() {
    Stack *s = (Stack*)malloc(sizeof(Stack));
    s->data = (ElemType*)malloc(sizeof(ElemType)*MAXSIZE);
    s->top = -1;
    return s;
}

//判断栈是否为空

int isEmpty(Stack *s) {
    if (s == NULL)
        return 2;
    else if (s->top == -1) {
        // printf("空\n");
        return 1;
    }
    else
        return 0;
}

//进栈

int push(Stack *s,ElemType e) {
    if (s == NULL)
        return 2;
    else if (s->top == MAXSIZE-1) {
        printf("栈满\n");
        return 0;
    }
    else {
        s->top++;
        s->data[s->top] = e;
        return 1;
    }
}

//出栈
int pop(Stack *s,ElemType *e) {
    if (isEmpty(s)) {
        printf("栈空\n");
        return 0;
    }
    else {
        *e = s->data[s->top];
        s->top--;
        return 1;
    }
}

//获得栈顶元素

int getTop(Stack *s,ElemType *e) {
    if (isEmpty(s)) {
        printf("栈空\n");
        return 0;
    }
    else {
        *e = s->data[s->top];
        return 1;
    }
}

//用来获得表达式里的字符
contentType getToken(char *symbol,int *index) {
    *symbol = expr[*index]; //获取表达式里的字符
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

void postfix(Stack *s) { //用于判断运算符的优先级
    //下面的优先级与上面的枚举元素一一对应
    int in_stack[] = {0,19,12,12,13,13,13,0};// 符号在栈内的优先级
    int out_stack[] = {20,19,12,12,13,13,13,0};//符号在栈外的优先级
    contentType token;
    int index = 0;
    s->data[0] = EOS; //把EOS压入栈底，因为后缀表达式的最后一个符号是\0
    char  symbol;
    ElemType e;

    token = getToken(&symbol,&index); //逐一获取表达式的符号给token

    while (token != EOS) {
        if (token == NUM) {
            printf("%c",symbol);
        }
        else if (token == RIGHT_PARE) {
            while (s->data[s->top] != LEFT_PARE) {//如果栈顶元素不是左括号，则出栈
                pop(s,&e);
                print_token(e);
            }
            pop(s,&e);
        }
        else { //既不是数字也不是括号，那么就是运算符需要判断优先级

                while (!isEmpty(s) && in_stack[s->data[s->top]] >= out_stack[token]) {
                    pop(s,&e);  //若栈顶元素大于扫描的当前符号，则出栈
                    print_token(e);//并且打印出栈顶元素
                }
                push(s,token); //不管当前符号是否大于栈顶元素，都把当前符号压入栈中
            }
            token = getToken(&symbol,&index);
        }

}

int eval(Stack *s) {
    char symbol; //用来记表达式里的符号
    int op1,op2;//用来记表达式的数值
    int index = 0;//表达式下标

    contentType token;//枚举变量
    token = getToken(&symbol,&index);
    ElemType result;
    while (token != EOS) {//开始扫描表达式
        if (token == NUM) {
            push(s,symbol - '0'); //这里利用ASCII表，将字符转换为了数值，并进行压栈
        }
        else {
            pop(s,&op2); //栈顶元素是op2
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