//
// Created by M. Shahid Shakeel on 21/12/2020.
//

#include "../headers/WordList.h"

/**
 * Complexity Analysis
 * OMEGA(1)
 */

WordList::WordList() {
	this->head = nullptr;
	this->size = 0;
}

/**
 * Complexity Analysis
 * Best Case - Ω(N)
 * Average Case - Θ(1)
 * Worst Case - O(N)
 */
void WordList::add(const string &word) {
	if (head == nullptr){
		head = new Node(word);
		this->size++;
		return;
	}
  if (head->word == word)
    return;

	Node *curr = head;
	while (curr->next != nullptr){
    if (curr->word == word)
      return;
		curr = curr->next;
	}

	curr->next = new Node(word);
	this->size++;
}

/**
 * Complexity Analysis
 * OMEGA(1)
 */
unsigned int WordList::getSize() const {
  return this->size;
}

/**
 * Complexity Analysis
 * OMEGA(N)
 */
string WordList::info() {
  string inf;
  Node *curr = head;
  while (curr != nullptr){
    inf += curr->word + " --> ";
    curr = curr->next;
  }
  return inf;
}

/**
 * Complexity Analysis
 * OMEGA(N)
 * need to fetch all available nodes
 */
string *WordList::getAll() {
  auto *words = new string[size];
  Node *curr = head;
  for (int i = 0; i < size; ++i) {
    words[i] = std::move(curr->word);
    curr = curr->next;
  }
  return words;
}
