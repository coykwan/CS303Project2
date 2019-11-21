//
//  main.cpp
//  CS303Project2
//
//  Created by Coy Kwan on 11/21/19.
//  Copyright © 2019 Coy Kwan. All rights reserved.
//

#include "bst.hpp" 
#include <iostream>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::fstream;

int main(void) {

    char c = '\0';
    fstream Convert;
    Convert.open("/Users/coy/Development/CS303Project2/CS303Project2/Convert.txt");
    Bst Tree;
    Tree.print();
    cout << endl << endl;
    while (!Convert.eof()) {
        Convert >> c;

        Tree.search(c);


    }

    cout << endl;

    if (Convert.is_open()) {
        Convert.close();
    }
}
