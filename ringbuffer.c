#include "ringbuffer.h"
#include<stdlib.h>

// init ring buffer
int rb_init(RingBuffer* rb, int capacity) 
{
    rb->capacity = capacity;
    rb->data = malloc(sizeof(int)*capacity);
    rb->head = 0;
    rb->tail = rb->head;
    rb->count = 0;
    return 1;
}

// push to ring buffer
int rb_push(RingBuffer* rb, int elem) 
{
    if(rb->count == rb->capacity) return 0;
    rb->data[rb->head] = elem;
    rb->head = (rb->head + 1) % rb->capacity;
    rb->count++;
    return elem;
}
// pop from ring buffer
int rb_pop(RingBuffer* rb, int* popped_value)
{
    if(rb->count == 0) return 0;
    *popped_value = rb->data[rb->tail];
    rb->tail = (rb->tail + 1) % rb->capacity;
    rb->count--;
    return 1;
}

// deinit ring buffer
int rb_deinit(RingBuffer* rb) 
{
    rb->capacity = 0;
    free(rb->data);
    rb->head = 0;
    rb->tail = rb->head;
    return 1;
}