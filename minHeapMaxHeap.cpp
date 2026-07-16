#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
private:
    vector<int> heap;

    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[index] > heap[parent]) {
                swap(heap[index], heap[parent]);
                index = parent;
            } else {
                break;
            }
        }
    }

    void heapifyDown(int index) {
        int size = heap.size();
        while (2 * index + 1 < size) {
            int leftChild = 2 * index + 1;
            int rightChild = 2 * index + 2;
            int largest = leftChild;

            if (rightChild < size && heap[rightChild] > heap[leftChild]) {
                largest = rightChild;
            }

            if (heap[index] < heap[largest]) {
                swap(heap[index], heap[largest]);
                index = largest;
            } else {
                break;
            }
        }
    }

public:
    void insert(int val) {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }

    int extractMax() {
        if (heap.empty()) return -1;
        int maxVal = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return maxVal;
    }

    void printHeap() {
        if (heap.empty()) {
            cout << "Max-Heap is empty" << endl;
            return;
        }
        for (int val : heap) {
            cout << val << " ";
        }
        cout << endl;
    }
};

class MinHeap {
private:
    vector<int> heap;

    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[index] < heap[parent]) {
                swap(heap[index], heap[parent]);
                index = parent;
            } else {
                break;
            }
        }
    }

    void heapifyDown(int index) {
        int size = heap.size();
        while (2 * index + 1 < size) {
            int leftChild = 2 * index + 1;
            int rightChild = 2 * index + 2;
            int smallest = leftChild;

            if (rightChild < size && heap[rightChild] < heap[leftChild]) {
                smallest = rightChild;
            }

            if (heap[index] > heap[smallest]) {
                swap(heap[index], heap[smallest]);
                index = smallest;
            } else {
                break;
            }
        }
    }

public:
    void insert(int val) {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }

    int extractMin() {
        if (heap.empty()) return -1;
        int minVal = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return minVal;
    }

    void printHeap() {
        if (heap.empty()) {
            cout << "Min-Heap is empty" << endl;
            return;
        }
        for (int val : heap) {
            cout << val << " ";
        }
        cout << endl;
    }
};

int main() {
    MaxHeap maxHeap;
    MinHeap minHeap;
    int choice, val, ext;

    do {
        cout << "\n--- MENU ---" << endl;
        cout << "1. Insert into Max-Heap" << endl;
        cout << "2. Extract Max from Max-Heap" << endl;
        cout << "3. Print Max-Heap" << endl;
        cout << "4. Insert into Min-Heap" << endl;
        cout << "5. Extract Min from Min-Heap" << endl;
        cout << "6. Print Min-Heap" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> val;
                maxHeap.insert(val);
                break;
            case 2:
                ext = maxHeap.extractMax();
                if (ext != -1) cout << "Extracted: " << ext << endl;
                else cout << "Heap empty!" << endl;
                break;
            case 3:
                cout << "Max-Heap: ";
                maxHeap.printHeap();
                break;
            case 4:
                cout << "Enter value to insert: ";
                cin >> val;
                minHeap.insert(val);
                break;
            case 5:
                ext = minHeap.extractMin();
                if (ext != -1) cout << "Extracted: " << ext << endl;
                else cout << "Heap empty!" << endl;
                break;
            case 6:
                cout << "Min-Heap: ";
                minHeap.printHeap();
                break;
            case 7:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 7);

    return 0;
}
