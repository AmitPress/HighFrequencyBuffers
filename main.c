#include<stdio.h>
#include "ringbuffer.h"



int main(int argc, char** argv)
{
    RingBuffer rb;

    if(rb_init(&rb, 10))
    {
        printf("Ring Buffer Initiated Successfully\n");
        for(int i=0; i<3; ++i) {
            int x;
            scanf("%d",&x);
            int pushed_value = rb_push(&rb, x);
            printf("Pushed: %d\n", pushed_value);
        }
        int popped_value;
        rb_pop(&rb, &popped_value);
        printf("Popped: %d\n", popped_value);
        rb_pop(&rb, &popped_value);
        printf("Popped: %d\n", popped_value);
    }
    if(rb_deinit(&rb)) 
    {
        printf("Ring Buffer Deinitiated Successfully");
    }
    return 1;
}