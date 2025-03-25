#include <iostream>
#include <queue>

using namespace std;

int main() {
    priority_queue<int> pq;

    pq.push(10);
    pq.push(40);
    pq.push(30);
    pq.push(50);

    cout << "Priority Queue (Max Heap Order): ";
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }

    return 0;
}