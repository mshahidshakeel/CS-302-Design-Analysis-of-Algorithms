//
// Created by M. Shahid Shakeel on 20/12/2020.
//

#ifndef ALGO_BUCKET_H
#define ALGO_BUCKET_H

#include "WordList.h"
#include <string>

using namespace std;


class Bucket {
    WordList *list;
    string keyword;

public:
    Bucket(const string &pWord);

    void add(const string &pWord);

    const string &getKeyword() const;

    void setKeyword(const string &pKeyword);

    unsigned int getSize() const;

    string* getWords(unsigned int *size);

    string info();
private:
    static string getSortedWord(const string &basicString);
};

#endif //ALGO_BUCKET_H
