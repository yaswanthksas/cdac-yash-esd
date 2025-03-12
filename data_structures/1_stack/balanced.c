#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct sta{
    char *c;
    int size;
    int tos;
};
struct sta st;
int full(){
    if(st.tos == st.size-1){
        return 1;
    }
    return 0;
}
int empty(){
    if(st.tos == -1){
        return 1;
    }
    return 0;
}
void push(int num){
    if(!full()){
        st.tos++;
        st.c[st.tos] = num;
    }
    else{
        printf("stack is full\n");
    }
}
int pop(){
    int x;
    if(!empty()){
        x = st.c[st.tos];
        st.tos--;
    }
    else{
        printf("Stack is empty\n");
    }
    return x;
}
int peep(){
    int x;
    if(!empty()){
        x = st.c[st.tos];
    }
    else{
        printf("Stack is empty\n");
    }
    return x;
}
char str[] = "{a+b-[d*e/g]}";
int main(){
    int l;
    l = strlen(str);
    st.c = (char *)malloc(sizeof(char)*l);
    st.size = l;
    st.tos = -1;
    char ch;
    int i;
    int flag = 0;
    for(i=0;i<l;i++){
        ch = str[i];
        switch(ch){
            case '{':
            case '[':
            case '(':
                push(ch);
                break;
            case '}':
            case ']':
            case ')':
                if((ch == ']' && peep() == '[') || (ch == '}' && peep() == '{') || (ch == ')' && peep() == '('))
                {
                    int x;
                    x =pop();
                }
                else
                {
                    flag = 1;
                    break;
                }
            default:
                ;

        }
        if(flag == 1){
            break;
        }
    }
    if(i == l && empty())
    {
        printf("Balanced \n");
    }
    else
    {
        printf("Not balanced \n");
    }

    return 0;
}