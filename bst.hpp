//
//  bst.hpp
//  CS303Project2
//
//  Created by Coy Kwan on 11/21/19.
//  Copyright © 2019 Coy Kwan. All rights reserved.
//

#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include "bstNode.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::fstream;
using std::ifstream;
using std::ofstream;
using std::ios;
using std::string;

class Bst {
public:
    Bst();
    ~Bst();
    void setHead(BstNode *const newHead);
    BstNode *getHead() const;

    void insert(const char newC, char *const newStr);
    void print();
    string search(char c);
private:
    void destroyBst(BstNode *TreeHead);
    BstNode *makeNode(const char newC, char *const newStr);
    void insert(BstNode *& newNode, const char C, char *const Str);
    void print(BstNode *Tree); // uses inordertraversal
    string search(BstNode *Tree, char c);

    BstNode *pHead;
    fstream MorseTable;
};

