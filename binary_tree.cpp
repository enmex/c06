#include "pch.h"
#include "binary_tree.h"

binary_tree::binary_tree() : root(nullptr), size(1) {
    height = 0;
    btree = new treenode;
    btree->field = "";
    btree->deleted = false;
    btree->num = 0;
    btree->right = nullptr;
    btree->left = nullptr;
    root = btree;
}

binary_tree::binary_tree(const binary_tree& tree) : btree(tree.btree), root(tree.btree), size(tree.size), height(tree.height) {}

binary_tree::binary_tree(binary_tree&& tree) : btree(tree.btree), root(tree.root), size(tree.size), height(tree.height) {
    tree.btree = nullptr;
    tree.root = nullptr;
    tree.size = 0;
    tree.height = 0;
}
binary_tree::~binary_tree(){
    btree = nullptr;
    root = nullptr;
    height = 0;
    size = 0;
    delete btree;
    delete root;
}

binary_tree binary_tree::operator=(const binary_tree& tree){
    btree = tree.btree;
    root = tree.root;
    size = tree.size;
    height = tree.height;
    return *this;
}

void binary_tree::setRoot(std::string x){
    root->field = x;
}

void binary_tree::add(std::string x){
    add(root, x);
}
int binary_tree::clearLeaves(treenode* &point){
    if(point->left==nullptr && point->right==nullptr){
        point = nullptr;
        delete point;
        return 0;
    }
    if(point->left!=nullptr){
        clearLeaves(point->left);
    }
    if(point->right!=nullptr){
        clearLeaves(point->right);
    }
    return 0;
}
void binary_tree::clearLeaves(){
    clearLeaves(root);
}

void binary_tree::find(std::string x, treenode* point, std::vector<int>& path){
    if(!point){ return; }
    if(point->field == x){
        throw TreeException("");
    }
    if(point->left){
        path.emplace_back(0);
        find(x, point->left, path);
    }
    if(point->right!=nullptr){
        path.emplace_back(1);
        find(x, point->right, path);
    }
    if (path.size() != 0) {
        path.pop_back();
    }
    return;
}
std::vector<int> binary_tree::find(std::string x){
    std::vector<int> path;
    try{
        find(x, root, path);
    }
    catch(TreeException e){
        return path;
    }
    return {-1};
}

void binary_tree::pretty_print_rotate(treenode* point, int level){
    if(point){
        pretty_print_rotate(point->right, level+1);
        for(int i = 0; i < level; i++) {std::cout << "\t";}
        if (!point->deleted) {
            std::cout << point->field.c_str() << "(" << point->num << ")" << std::endl;
        }
        pretty_print_rotate(point->left, level+1);
    }
}

void binary_tree::add(treenode* node, std::string x)
{
    if (node->field == x) {
        node->num++;
        return;
    }
    if (node->left && x < node->field) { add(node->left, x); }
    if (node->right && x > node->field) { add(node->right, x); }
    treenode* temp = new treenode;
    if (node->left == nullptr && x < node->field) {
        temp->field = x;
        temp->num = 1;
        temp->right = temp->left = nullptr;
        temp->deleted = false;
        node->left = temp;
    }
    if (node->right == nullptr && x > node->field) {
        temp->field = x;
        temp->num = 1;
        temp->right = temp->left = nullptr;
        temp->deleted = false;
        node->right = temp;
    }
    temp = nullptr;
}

void binary_tree::pretty_print_rotate(){
    pretty_print_rotate(root, 1);
}

bool binary_tree::del(std::string x)
{
    std::vector<int> path;
    find(x, root, path);
    if (path[0] == -1) {
        return false;
    }
    btree = root;
    for (int i = 0; i < path.size(); i++) {
        if (path[i] && btree->right) {
            btree = btree->right;
        }
        if (!path[i] && btree->left) {
            btree = btree->left;
        }
    }
    btree->deleted = true;
    return true;
}
