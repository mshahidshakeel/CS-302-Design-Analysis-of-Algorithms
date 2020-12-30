#include "../headers/AnagramDictionary.h"
#include <iostream>
#include <fstream>

using namespace std;

int main() {
  cout << "Building Anagram Dictionary" << endl;
  AnagramDictionary h(34019);

   string dataPath = "/Users/m.shahidshakeel/Documents/workspace/c++/algo/data/";
  ifstream fin;
  fin.open(dataPath + "words.txt");

  if (!fin.is_open()) {
    cerr << "file cannot be opened! " << strerror(errno) << endl;
    return -1;
  }

  unsigned int max= 0;
  string line;
  while (!fin.eof()) {
    getline(fin, line);
    line.pop_back();
    if (line.empty())
      continue;
    bool valid = true;
    for (int i = 0; i < line.size() && valid; ++i) {
      if (line[i] >= 'a' && line[i] <= 'z')
        continue;
      if (line[i] >= 'A' && line[i] <= 'Z')
        line[i] += ' ';
      else
        valid = false;
    }
    if (valid) {
      unsigned int tempMax = h.add(line);
      if (tempMax > max)
        max = tempMax;
    }
  }

  fin.close();
  cout << "Max Collisions: " << max << endl;
  cout << "Bucket: " << h.printMaxBucketSize() << endl;
  cout << "Dictionary Built\n";
  cout << "Reading input\n";
  cout << "Writing Output\n";

  fin.open(dataPath + "input.txt");
  if (!fin.is_open()) {
    cerr << "file cannot be opened! " << strerror(errno) << endl;
    return -1;
  }

  ofstream fout(dataPath + "output.txt");
  if (!fout.is_open()) {
    cerr << "file cannot be opened! " << strerror(errno) << endl;
    return -1;
  }

  while (!fin.eof()) {
    getline(fin, line);
    if (line[line.size() - 1] == '\r')
      line.pop_back();
    if (line.empty())
      continue;
    bool valid = true;
    for (int i = 0; i < line.size() && valid; ++i) {
      if (line[i] >= 'a' && line[i] <= 'z')
        continue;
      if (line[i] >= 'A' && line[i] <= 'Z')
        line[i] += ' ';
      else
        valid = false;
    }
    if (valid) {
      unsigned int size = 0;
      string *words = h.getWords(line, &size);
      fout << line << " " << size << " ";
      if (words != nullptr) {
        for (int i = 0; i < size; ++i) {
          fout << words[i] << " ";
        }
      }
      fout << endl;
    }

  }

  fin.close();
  fout.close();
  cout << "Completed\n";
  return 0;
}

// Algorithm

/**
 * Since, we will be performing multiple anagram queries, our first step is to
 * load all of the (25,000) words in the dictionary into an appropriate data
 * structure. A primary requirement is that one must be able to efficiently search
 * this data structure to look for anagrams of a given word. A clever trick that we
 * will use to facilitate this is to first sort the letters of every word we insert
 * into our data structure (you may use any sort you wish to produce a key for each
 * word. For example, the key for the string "toxic" is "ciotx", similarly the key
 * for both "star" and "rats" is "arst". We will then use a hash table to store pairs
 * of strings, where the pair consists of the original word and its key.
 */


/**
 * Data Structure for Storing Words:
 * 	Need to keep in mind:
 * 		Efficient Search
 * 	Proposed Solution:
 * 		Hash Table
 * 		:Hash Function Proposition
 * 			Sort letters of word, then calculate
 *
 * 			rats -> arst -> 97+114+115+116 = 442 => 442%100 = 42
 * 			it can also be calculated without
 *
 *
 * 		Binary Tree, Sorted Word as a key
 *
 * 		like
 * 					a										c
 * 				   / \										 \
 * 				      r										  i
 * 				       \									   \
 * 				        s										o
 * 				         \										 \
 * 				          t -> rats -> star						  t
 * 				          										   \
 * 				          										    x -> toxic
 *
 */


/**
 * When performing insertions into the hash table, we will compute the hash of
 * the key of the word to compute the correct bucket (location in the hash table).
 * This approach guarantees that all words which are anagrams of one another are
 * stored in the same bucket of the hash table. Similarly, when we are searching
 * for anagrams, we will first compute the key of the word we are searching for,
 * then hash the key, then search that bucket for anagram matches. You should feel
 * free to use any method for appropriate hash function for hashing strings
 * (but please cite any source which you use in the project report). Also, make sure
 * your function is efficient and does not hash completely unrelated sets of anagrams
 * to the same bucket *if possible*. If it does, handle the collisions as you see fit
 * (e.g. linked processing). Also note that if you must probe for a given set of
 * anagrams in time greater than or equal to O(lgn), then you must revise your hash
 * function. You will be graded heavily on the performance of the efficiency of your function.
 *
*/


/**
 * 1. Why probing greater than O(lnN)?
 *
 */


/**
 * if we have abd, then key will be 97+98+100 = 295
 * then we have acc, the key will be 97+99+99 = 295
 *
 * what if we use 128 radix notation?
 *
 * Both have the same key but are not the anagrams of each other
 * So, there will be collision in hash table, we need to solve that
 * We were using chaining to store all anagrams at same bucket
 * new, we can used double hashing (open addressing) to resolve conflicts
 *
 * I am thinking of using two different nodes
 * One in hashTable main array that will also contains a sorted word
 * then that can can point to the chain of words
 */