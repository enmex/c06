#pragma once
#include "pch.h"
#include <iostream>
#include "TreeException.h"
#include <vector>
#include <iomanip>

struct treenode{
    bool deleted;
    std::string field;
    int num;
    treenode *left, *right;
};

class binary_tree {

private:
    treenode* btree;
    treenode* root;
    int size;
    int height;
public:
    binary_tree();
    binary_tree(const binary_tree&);
    binary_tree(binary_tree&&);
    ~binary_tree();
    binary_tree operator=(const binary_tree&);
    void add(std::string);
    void setRoot(std::string);
    void clearLeaves();
    std::vector<int> find(std::string x);
    void pretty_print_rotate();
    bool del(std::string);


private:

    void pretty_print_rotate(treenode*, int);

    void add(treenode* node, std::string x);

    int clearLeaves(treenode* &point);
    void find(std::string x, treenode* point, std::vector<int>&);//указывает на какой ветке (0 или 1)
};