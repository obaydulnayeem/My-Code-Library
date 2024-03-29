/*
    |parent|left|node id|right|

    node {
        node id (optional)
        left
        right
        parent
    }
*/

#include <bits/stdc++.h>

using namespace std;

class node {
public:
    int id;
    node *Left;
    node *Right;
    node *Parent;
};

// manually inserting node in binary tree and print the tree info
class BinaryTree{
public:
    node* root;
    node* allnode[6];

    BinaryTree() {
        root = NULL;
    }

    node* CreateNewNode(int id) {
        node* newnode = new node;
        newnode->id = id;
        newnode->Left = NULL;
        newnode->Right = NULL;
        return newnode;
    }

    void build_binary_tree() {
        for(int i = 0; i < 6; i++) {
            allnode[i] = CreateNewNode(i);
        }

        allnode[0]->Left = allnode[1];
        allnode[0]->Right = allnode[2];

        allnode[1]->Left = allnode[5];
        allnode[1]->Parent = allnode[0];

        allnode[2]->Left = allnode[3];
        allnode[2]->Right = allnode[4];
        allnode[2]->Parent = allnode[0];

        allnode[5]->Parent = allnode[1];

        allnode[3]->Parent = allnode[2];
        allnode[4]->Parent = allnode[2];

        root = allnode[0];
    }

    void print_tree_info() {
        int p = -1, l = -1, r = -1;

        for(int i = 0; i < 6; i++) {
            if(allnode[i]->Parent != NULL) {
                p = allnode[i]->Parent->id;
            }
            if(allnode[i]->Left != NULL) {
                l = allnode[i]->Left->id;
            }
            if(allnode[i]->Right != NULL) {
                r = allnode[i]->Right->id;
            }
            cout << "Node-" << i << ":  Parent: " << p << ", Left_Child: " << l
                    << ", Right_Child: " << r << "\n";
        }
    }
};

int main() {
    BinaryTree bt;
    bt.build_binary_tree();
    bt.print_tree_info();
return 0;
}
