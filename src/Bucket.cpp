//
// Created by M. Shahid Shakeel on 20/12/2020.
//

#include "../headers/Bucket.h"

/**
 * Complexity Analysis
 * Best Case - Ω(N^2)
 * Average Case - Θ(N^2)
 * Worst Case - O(N^2)
 */
Bucket::Bucket(const string &pWord) {
  this->keyword = getSortedWord(pWord);
  this->list = new WordList();
  this->add(pWord);
}

/**
 * Complexity Analysis
 * Best Case - Ω(1)
 * Average Case - Θ(1)
 * Worst Case - O(N)
 */
void Bucket::add(const string &pWord) {
  this->list->add(pWord);
}

/**
 * Complexity Analysis
 * OMEGA(1)
 */
const string &Bucket::getKeyword() const {
  return keyword;
}

/**
 * Complexity Analysis
 * OMEGA(1)
 */
void Bucket::setKeyword(const string &pKeyword) {
  Bucket::keyword = pKeyword;
}

/**
 * Complexity Analysis
 * OMEGA(1)
 */
unsigned int Bucket::getSize() const {
  if (list == nullptr)
    return 0;
  return list->getSize();
}

/**
 * Complexity Analysis
 * Best Case - Ω(N^2)
 * Average Case - Θ(N^2)
 * Worst Case - O(N^2)
 */
string Bucket::getSortedWord(const string &pWord) {
  string sorted = pWord;

  for (unsigned int i = 0; i < sorted.size(); ++i) {
    unsigned int hIndex = i;
    for (unsigned int j = i + 1; j < sorted.size(); ++j) {
      if (sorted[j] < sorted[hIndex])
        hIndex = j;
    }

    char temp = sorted[hIndex];
    sorted[hIndex] = sorted[i];
    sorted[i] = temp;
  }
  return sorted;
}

/**
 * Complexity Analysis
 * OMEGA(N)
 */
string Bucket::info() {
  string inf = this->keyword + ": ";
  inf += this->list->info();
  return inf;
}

/**
 * Complexity Analysis
 * OMEGA(N)
 */
string *Bucket::getWords(unsigned int *size) {
  *size = this->list->getSize();
  return this->list->getAll();
}
