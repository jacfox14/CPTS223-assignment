// This code was taken from https://www.techiedelight.com/queue-implementation-cpp/
// The code has been modified from the original to provide opportunities to learn
/**
 * 
 * 1. I do not like the use of the array to store the queue elements. I would prefer to use a linked list or a vector because it is easier to manage the size of the queue
 * and does not put a limit on the size of the queue.
 * 
 * 2. inefficient queue and dequeue functions because they are O(n) time complexity. I would prefer to use a linked list or a vector because they are O(1) time complexity.
 * 
 * 3. The queue is not a template class so it can only store integers. I would prefer to use a template class so that the queue can store any type of data.
 * 
 * 4. I don't like how rear and front are used  because it didn't make sense to me at first to why they were different when the queue is initialized. 
 * Maybe I'm just dumb but it did not seem intuitive to me.
 * 
 * 5. I don't like that there is no copy constructor or assignment operator but there is already a destructor. I would probably add these because they are the rule of three
 * and they would probably be useful for any use of the queue class in the future.
 * 
 */
#include "testQueue.h"

// main function
int main()
{
    // call your test functions here!
    //test_queue_size();
    //test_queue_is_empty();
    //test_queue_is_full();
    test_queue_peek();
    //test_queue_peek_empty();
    //test_queue_enqueue();
    //test_queue_enqueue_full();
    //test_queue_dequeue();
    //test_queue_dequeue_empty();

    return 0;
}

