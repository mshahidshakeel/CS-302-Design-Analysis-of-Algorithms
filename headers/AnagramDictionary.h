//
// Created by M. Shahid Shakeel on 20/12/2020.
//

#ifndef ALGO_ANAGRAMDICTIONARY_H
#define ALGO_ANAGRAMDICTIONARY_H

#include "Bucket.h"

class AnagramDictionary {
    Bucket **bucketList;
    unsigned int mCapacity;
    unsigned int mSize;
public:
    AnagramDictionary(unsigned int capacity);
    unsigned int add(const string &word);
    string* getWords(const string &word, unsigned int *size);
    string info();
    unsigned int printMaxBucketSize();
private:
    static unsigned int key(const string &word);
    unsigned int hash(unsigned int key) const;
    static unsigned int hash2(unsigned int key) ;
    double loadFactor() const;
    void rehash();
    void rehashAdd(Bucket *bucket);

    static string sortedWord(const string &pWord);
};


#endif //ALGO_ANAGRAMDICTIONARY_H
