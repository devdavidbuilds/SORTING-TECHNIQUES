#include <stdio.h>  // Used for printf and scanf
#include <stdlib.h> // Used for exit()

class MinHeap {
private:
    int* heap;       
    int capacity;    
    int heapSize;    

    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }

    void resize() {
        capacity *= 2;
        int* newHeap = new int[capacity];
        for (int i = 0; i < heapSize; ++i) {
            newHeap[i] = heap[i];
        }
        delete[] heap;
        heap = newHeap;
    }

    int parent(int i) { return (i - 1) / 2; }
    int left(int i)   { return (2 * i) + 1; }
    int right(int i)  { return (2 * i) + 2; }

    void heapifyUp(int index) {
        while (index > 0 && heap[parent(index)] > heap[index]) {
            swap(heap[parent(index)], heap[index]);
            index = parent(index);
        }
    }

    void heapifyDown(int index) {
        int leftChild = left(index);
        int rightChild = right(index);
        int smallest = index;

        if (leftChild < heapSize && heap[leftChild] < heap[smallest]) {
            smallest = leftChild;
        }
        if (rightChild < heapSize && heap[rightChild] < heap[smallest]) {
            smallest = rightChild;
        }

        if (smallest != index) {
            swap(heap[index], heap[smallest]);
            heapifyDown(smallest);
        }
    }

public:
    MinHeap(int initialCapacity = 4) {
        capacity = initialCapacity;
        heapSize = 0;
        heap = new int[capacity];
    }

    ~MinHeap() {
        delete[] heap;
    }

    void insert(int key) {
        if (heapSize == capacity) {
            resize();
        }
        heap[heapSize] = key;
        heapSize++;
        heapifyUp(heapSize - 1);
    }

    int getMin() const {
        if (heapSize == 0) {
            return -1; // Return safe error flag if empty
        }
        return heap;
    }

    int extractMin() {
        if (heapSize == 0) {
            return -1; // Return safe error flag if empty
        }

        int root = heap;
        heap = heap[heapSize - 1];
        heapSize--;

        if (heapSize > 0) {
            heapifyDown(0);
        }

        return root;
    }

    void printHeap() const {
        if (heapSize == 0) {
            printf("Heap is empty.\n");
            return;
        }
        printf("Heap Array: [ ");
        for (int i = 0; i < heapSize; ++i) {
            printf("%d ", heap[i]);
        }
        printf("]\n");
    }

    int size() const { return heapSize; }
    bool empty() const { return heapSize == 0; }
};

int main() {
    MinHeap minHeap;
    int choice = 0;
    int val = 0;

    printf("=== Min Heap Interactive Menu ===\n");
    
    while (1) {
        printf("\n1. Insert Element\n");
        printf("2. Get Minimum\n");
        printf("3. Extract Minimum\n");
        printf("4. Print Heap Array\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        
        // Scanf reads integer input from user
        if (scanf("%d", &choice) != 1) {
            printf("Invalid system input. Exiting...\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter integer value to insert: ");
                scanf("%d", &val);
                minHeap.insert(val);
                printf("%d inserted successfully.\n", val);
                break;

            case 2:
                if (minHeap.empty()) {
                    printf("Heap is empty!\n");
                } else {
                    printf("Minimum element: %d\n", minHeap.getMin());
                }
                break;

            case 3:
                if (minHeap.empty()) {
                    printf("Heap is empty! Nothing to extract.\n");
                } else {
                    printf("Extracted minimum element: %d\n", minHeap.extractMin());
                }
                break;

            case 4:
                minHeap.printHeap();
                break;

            case 5:
                printf("Exiting application.\n");
                return 0;

            default:
                printf("Invalid choice! Please choose between 1 and 5.\n");
        }
    }

    return 0;
}
