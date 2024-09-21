#include "testQueue.h"

void test_queue_size() {
    queue q(3);

    // Test when queue is initially empty
    if (q.size() != 0) {
        std::cout << "Test failed: queue size is not 0" << std::endl;
        return;
    } else {
        std::cout << "Test passed: queue size is 0" << std::endl;
    }
    // Enqueue elements and check size
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    if (q.size() != 3) {
        std::cout << "Test failed: queue size should be 3" << std::endl;
        return;
    } else {
        std::cout << "Test passed: queue size is 3" << std::endl;
    }

    std::cout << "All size tests passed." << std::endl;
}

void test_queue_is_empty() {
    queue q(3);

    // Test when queue is initially empty

    if (!q.isEmpty()) {
        std::cout << "Test failed: queue should be seen as empty" << std::endl;
        return;
    } else {
        std::cout << "Test passed: queue is empty" << std::endl;
    }


    // Enqueue an element and check if the queue is still empty
    q.enqueue(1);

    if (q.isEmpty()) {
        std::cout << "Test failed: queue is not empty" << std::endl;
        return;
    } else {
        std::cout << "Test passed: queue is not empty" << std::endl;
    }


    std::cout << "All isEmpty tests passed." << std::endl;
}

void test_queue_is_full() {
    queue q(3);

    // Test when queue is initially empty
    bool x = q.isFull();

    if (x) {
        std::cout << "Test failed: queue is not full" << std::endl;
        return;
    } else {
        std::cout << "Test passed: queue is not full" << std::endl;
    }

    // Enqueue elements and check if the queue is full
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    if (!q.isFull()) {
        std::cout << "Test failed: queue is full" << std::endl;
        return;
    } else {
        std::cout << "Test passed: queue is full" << std::endl;
    }

    std::cout << "All isFull tests passed." << std::endl;
}

void test_queue_peek() {
    queue q;

    // Test when queue is initially empty
    int x = q.peek();

    if (x != std::numeric_limits<int>::min()) {
        std::cout << "Test failed: queue is empty" << std::endl;
        return;
    } else {
        std::cout << "Test passed: queue is empty" << std::endl;
    }

    // Enqueue elements and check if peek returns the front element
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    if (q.peek() != 1) {
        std::cout << "Test failed: peek should return 1" << std::endl;
        return;
    } else {
        std::cout << "Test passed: peek returns 1" << std::endl;
    }

    std::cout << "All peek tests passed." << std::endl;
}

void test_queue_peek_empty() {
    queue q;

    // Test when queue is initially empty
    int x = q.peek();

    if (x != std::numeric_limits<int>::min()) {
        std::cout << "Test failed: queue is empty so peek should not work" << std::endl;
        return;
    } else {
        std::cout << "Test passed: queue is empty and peek functioned properly" << std::endl;
    }

    std::cout << "All peek tests passed." << std::endl;
}

void test_queue_enqueue() {
    queue q(3);

    // Test when queue is initially empty
    q.enqueue(1);

    if (q.size() != 1) {
        std::cout << "Test failed: queue size should be 1" << std::endl;
        return;
    } else {
        std::cout << "Test passed: queue size is 1" << std::endl;
    }

    // Enqueue elements and check if the queue is full
    q.enqueue(2);
    q.enqueue(3);

    if (!q.isFull()) {
        std::cout << "Test failed: queue is full" << std::endl;
        return;
    } else {
        std::cout << "Test passed: queue is full" << std::endl;
    }

    std::cout << "All enqueue tests passed." << std::endl;
}

void test_queue_enqueue_full() {
    queue q(3);

    // Test when queue is initially empty
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    // Test when queue is full
    q.enqueue(4);

    if (q.size() != 3) {
        std::cout << "Test failed: queue size should be 3" << std::endl;
        return;
    } else {
        std::cout << "Test passed: queue size is 3" << std::endl;
    }

    std::cout << "All enqueue tests passed." << std::endl;
}

void test_queue_dequeue() {
    queue q(3);

    // Test when queue is initially empty
    q.dequeue();

    // Enqueue elements and check if dequeue removes the front element
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    q.dequeue();

    if (q.size() != 2) {
        std::cout << "Test failed: queue size should be 2" << std::endl;
        return;
    } else {
        std::cout << "Test passed: queue size is 2" << std::endl;
    }

    std::cout << "All dequeue tests passed." << std::endl;
}
void test_queue_dequeue_empty() {
    queue q(3);

    // Test when queue is initially empty
    q.dequeue();

    if (q.size() != 0) {
        std::cout << "Test failed: queue size should be 0" << std::endl;
        return;
    } else {
        std::cout << "Test passed: queue size is 0" << std::endl;
    }

    std::cout << "All dequeue tests passed." << std::endl;
}