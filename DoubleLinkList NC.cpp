#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};

int main(){
    Node *node1 = new Node;
    Node *node2 = new Node;
    Node *node3 = new Node;
    
    node1->data = 10;
    node1->next = node2;
    node1->prev = node3;
    
    node2->data = 20;
    node2->next = node3;
	node2->prev = node1;
	
    node3->data = 30;
    node3->next = node1;
    node3->prev = node2;

    // Traversal Forward (circular)
    Node *nodeSekarang = node1;
    int i = 1;

    cout << "Traversal Forward\n";
    do {
        cout << "Data Ke - " << i++ << ": " << nodeSekarang->data << endl;
        cout << endl;
        nodeSekarang = nodeSekarang->next;
    } while (nodeSekarang != node1);

    // Traversal Backward (circular)
    cout << "\nTraversal Backward\n";
    nodeSekarang = node3;
    i = 1;

    do {
        cout << "Data Ke - " << i++ << ": " << nodeSekarang->data << endl;
        cout << endl;
        nodeSekarang = nodeSekarang->prev;
    } while (nodeSekarang != node3);

    return 0;
}
