//
//  bst.cpp
//  CS303Project2
//
//  Created by Coy Kwan on 11/21/19.
//  Copyright © 2019 Coy Kwan. All rights reserved.
//

#include "bst.h"

Bst::Bst()
{

    char C ='\0';
    char S[100] = " ";
    pHead = nullptr;
    MorseTable.open("MorseTable.txt");
    while (!MorseTable.eof()) {
        MorseTable >> C;
        MorseTable.getline(S, 100);
        insert(C,S);

    }

}

Bst::~Bst()
{
    if (MorseTable.is_open())
    {

        MorseTable.close();
    }
    destroyBst(pHead);
    //cout << "~Bst()" << endl;

}

void Bst::setHead(BstNode * const newHead)
{
    pHead = newHead;
}

BstNode * Bst::getHead() const
{
    return pHead;
}

void Bst::insert(const char newC, char *const newStr)
{
    insert(pHead, newC, newStr);
}

void Bst::print()
{
    print(pHead);
}

string Bst::search(char c)
{
    string Str;
    Str = search(pHead,c);
    return Str;

}

void Bst::destroyBst(BstNode * TreeHead)
{
    if (TreeHead != nullptr) {
        destroyBst(TreeHead->getLeft());
        destroyBst(TreeHead->getRight());
        //cout << "Destroying Char: " << TreeHead->getChr() << endl;
        delete(TreeHead);
    }

}

BstNode * Bst::makeNode(const char newC, char *const newStr)
{
    BstNode *node = new BstNode(newC, newStr);
    return node;
}

void Bst::insert(BstNode *& newNode, const char C, char * const Str)
{
    if (newNode == nullptr) {
        BstNode *pMem = new BstNode(C, Str);
        newNode = pMem;
    }

    else {
        if ((C < newNode->getChr())) {
            insert((newNode)->getLeft(), C, Str);
        }
        else if(C > newNode->getChr()){
            insert((newNode)->getRight(), C, Str);

        }

    }
}

void Bst::print(BstNode *Tree)
{
    if (Tree != nullptr) {
        //go left
        print(Tree->getLeft());
        // read node
        cout << "Character: " << Tree->getChr() << " Code: " << Tree->getString() << endl;
        // go right
        print(Tree->getRight());
    }
}

string Bst::search(BstNode * Tree, char c)
{
    string Str;
    if (Tree != nullptr) {
        search(Tree->getLeft(),c);
        search(Tree->getRight(), c);
        if (Tree->getChr() == c) {
            Str = Tree->getString();
            cout << Tree->getString();
        }
    }

    return Str;
    /*char Str[100];
    while (Tree->getLeft.getChr() != c && Tree->getLeft.getChr() != c) {
        search(Tree->getLeft(), c);
        cout << "Searching..." << endl;
        search(Tree->getRight(), c);
    }
    cout << "Found!" << endl;
    cout << Tree->getString() << endl;*/


    /*f (Tree != nullptr && (Tree->getChr() == c)) {
        Tree->p
    }*/


}

string Bst::decode(string morseCode)
{
	string decoded;
	decoded = decode2(pHead, morseCode);
	return decoded;
}

string Bst::decode(BstNode * Tree, string morseCode)
{
	string decodedString;
	char decoded;
	if (Tree != nullptr)
	{
		//If a character has been reached, add it to the decoded string
		//Then start over if there's remaining morse code
		decoded = Tree -> getChr();
		decodedString += decoded;
		decodedString += morseCode;

/*		if(morseCode.size() > 0)
		{
			decodedString += decode(pHead, morseCode);
		}*/


	}
	else
	{
		//Otherwise, traverse tree
		//Visit left child for . and right child for _
		char compare = morseCode.at(0);
		morseCode.erase(0);
		if (compare == '.')
		{
			decode(Tree -> getLeft(), morseCode);
		}
		else if (compare == '.')
		{
			decode(Tree -> getRight(), morseCode);
		}
	}

	return decodedString;
}

string Bst::decode2(BstNode * Tree, string morseCode)
{
	string encoded = morseCode;
	string decodedString;
	while (encoded.size() > 0)
	{
		cout << encoded;
		encoded.erase(0);
		BstNode * currentTree = Tree;

		while (currentTree == nullptr)
		{
			char compare = morseCode.at(0);
			encoded = encoded.erase(0);
			if (compare == '_')
			{
				currentTree = currentTree -> getLeft();
			}
			else if (compare == '.')
			{
				currentTree = currentTree -> getRight();
			}
		}
		char decoded = currentTree -> getChr();
		decodedString += decoded;

	}
	return decodedString;
}
