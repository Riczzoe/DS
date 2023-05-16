#include    "queue.h"

int main() {
    queue_t queue;
    int result;
    Elemtype element;

    // Initialize the queue
    result = initQueue(&queue);
    printf("Initialization result: %d\n", result);

    // Test isQueueEmpty() when the queue is empty
    result = isQueueEmpty(&queue);
    printf("isQueueEmpty() result (empty queue): %d\n", result);

    // Enqueue elements
    enQueue(&queue, 10);
    enQueue(&queue, 20);
    enQueue(&queue, 30);

    // Test isQueueEmpty() when the queue is not empty
    result = isQueueEmpty(&queue);
    printf("isQueueEmpty() result (non-empty queue): %d\n", result);

    // Test getQueueSize()
    int size = getQueueSize(&queue);
    printf("Queue size: %d\n", size);

    // Test getHead()
    getHead(&queue, &element);
    printf("Head of the queue: %d\n", element);

    // Test getLast()
    getLast(&queue, &element);
    printf("Last element of the queue: %d\n", element);

    // Test deQueue()
    deQueue(&queue, &element);
    printf("Dequeued element: %d\n", element);

    // Print the queue
    printf("Queue contents: ");
    printQueue(&queue);
    printf("\n");

    // Enqueue more elements
    enQueue(&queue, 40);
    enQueue(&queue, 50);
    enQueue(&queue, 60);

    // Print the queue after enqueueing more elements
    printf("Queue contents: ");
    printQueue(&queue);
    printf("\n");

    // Test deQueue() multiple times
    deQueue(&queue, &element);
    printf("Dequeued element: %d\n", element);
    deQueue(&queue, &element);
    printf("Dequeued element: %d\n", element);
    deQueue(&queue, &element);
    printf("Dequeued element: %d\n", element);

    // Print the queue after multiple dequeues
    printf("Queue contents: ");
    printQueue(&queue);
    printf("\n");

    // Test isQueueEmpty() after dequeuing all elements
    result = isQueueEmpty(&queue);
    printf("isQueueEmpty() result (non-empty queue): %d\n", result);

    // dequeue all elements
    deQueue(&queue, &element);
    printf("Dequeued element: %d\n", element);
    deQueue(&queue, &element);
    printf("Dequeued element: %d\n", element);
    result = isQueueEmpty(&queue);
    printf("isQueueEmpty() result (empty queue): %d\n", result);

    // Test deQueue() when the queue is empty
    deQueue(&queue, &element);


    printf("Attempting to dequeue an empty queue...\n");
    // Enqueue more elements atfer dequeuing all elements
    enQueue(&queue, 70);
    enQueue(&queue, 80);
    enQueue(&queue, 90);

    // Print the queue after enqueueing more elements
    printf("Queue contents: ");
    printQueue(&queue); 

    deQueue(&queue, &element);
    printf("Dequeued element: %d\n", element);
    enQueue(&queue, 100);
    printf("Queue contents: ");
    printQueue(&queue);

    // Free the memory allocated for the queue
    freeQueue(&queue);

    return 0;
}
