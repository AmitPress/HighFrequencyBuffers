#ifndef __RINGBUFFER_H
#define __RINGBUFFER_H
/*
The idea is that the ring buffer would only have integer data
*/

// there will be a ring buffer struct 
typedef struct{
    int* data;
    int head;
    int tail;
    int capacity;
    int count;
} RingBuffer;
// handle buffer lifecycle
int rb_init(RingBuffer*, int);
int rb_deinit(RingBuffer*);

// handle push and pop mechanism
int rb_push(RingBuffer*, int); // places an item in the buffer
int rb_pop(RingBuffer*, int*); // removes an item from the buffer


// print the full buffer
void rb_print(RingBuffer* rb);
// clear the buffer
int rb_clear(RingBuffer*);

#endif
