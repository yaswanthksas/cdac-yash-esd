  #include <fcntl.h>           /* For O_* constants */
       #include <sys/stat.h>        /* For mode constants */
       #include <mqueue.h>

#include<stdio.h>
int main(){
    struct mq_attr st;
    st.mq_flags = 0;
    st.mq_maxmsg = 4;
    st.mq_msgsize = 100;
    st.mq_curmsgs = 0;
    mqd_t x;
    x = mq_open("/bie",O_CREAT | O_RDWR, S_IRWXU, &st);
    char ch[100];
    mq_receive(x,ch,sizeof(ch),0);
    printf("%s",ch);
    mq_close(x);

    return 0;
}