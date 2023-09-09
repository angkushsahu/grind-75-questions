#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(const int _data) {
        this->data = _data;
        this->next = nullptr;
    }
};

void free_memory(Node*& root) {
    if (!root) return;

    free_memory(root->next);
    delete root;
    root = nullptr;
}

void print_list(Node*& root) {
    if (!root) {
        cout << endl;
        return;
    }

    cout << root->data << " ";
    print_list(root->next);
}

Node* merge_sorted(Node* root1, Node* root2) {
    Node* merged_root = nullptr;

    if (!root1) return root2;
    if (!root2) return root1;

    if (root1->data < root2->data) {
        merged_root = root1;
        root1 = root1->next;
    } else {
        merged_root = root2;
        root2 = root2->next;
    }

    Node* current_insert_node = merged_root;

    while (root1 && root2) {
        if (root1->data < root2->data) {
            current_insert_node->next = root1;
            root1 = root1->next;
        } else {
            current_insert_node->next = root2;
            root2 = root2->next;
        }
        current_insert_node = current_insert_node->next;
    }

    while (root1) {
        current_insert_node->next = root1;
        root1 = root1->next;
        current_insert_node = current_insert_node->next;
    }

    while (root2) {
        current_insert_node->next = root2;
        root2 = root2->next;
        current_insert_node = current_insert_node->next;
    }

    return merged_root;
}

int main() {
    Node* root1 = new Node(1);
    root1->next = new Node(2);
    root1->next->next = new Node(3);
    Node* root2 = new Node(1);
    root2->next = new Node(2);
    root2->next->next = new Node(3);

    Node* merged_root = merge_sorted(root1, root2);
    print_list(merged_root);

    free_memory(root1);
    free_memory(root2);
    free_memory(merged_root);

    return 0;
}
