#include "pch.h"
#include <iostream>
#include "binary_tree.h"
#include <Windows.h>
using namespace std;

int main(){

    srand(time(0));

    int min = 1;
    int max = 500;

    binary_tree tree;

    string* x = new string[20];
    x[0] = "abc";
    x[1] = "b";
    x[2] = "a";
    x[3] = "c";
    x[4] = "ac";
    x[5] = "adasd";
    x[6] = "ads";
    x[7] = "assss";
    x[8] = "ab";
    x[9] = "b";
    x[10] = "a";
    x[11] = "c";
    x[12] = "aabc";
    x[13] = "aabc";
    x[14] = "aabc";
    x[15] = "aabc";
    x[16] = "aabc";
    x[17] = "aabc";
    x[18] = "aabc";
    x[19] = "aabc";

    tree.setRoot(x[0]);
    for(int i = 1; i < 20; i++){
        tree.add(x[i]);
    }


    tree.pretty_print_rotate();
}