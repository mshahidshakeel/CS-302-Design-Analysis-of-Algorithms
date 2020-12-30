//
// Created by M. Shahid Shakeel on 21/12/2020.
//

/**
 * Complexity Analysis
 *
 */


#ifndef ALGO_WORDLIST_H
#define ALGO_WORDLIST_H

#include <string>

using namespace std;

class WordList {
		struct Node {
				string word;
				Node *next;

				Node() {}

				Node(const string &pWord) {
					this->word = pWord;
					this->next = nullptr;
				}
		};


		Node *head;
		unsigned int size;

public:
		WordList();
		void add(const string &word);
    unsigned int getSize() const;
    string info();
    string *getAll();
};


#endif //ALGO_WORDLIST_H
