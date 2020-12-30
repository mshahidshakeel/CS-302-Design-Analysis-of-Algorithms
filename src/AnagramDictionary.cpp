//
// Created by M. Shahid Shakeel on 20/12/2020.
//

#include "../headers/AnagramDictionary.h"
#include <iostream>


AnagramDictionary::AnagramDictionary(unsigned int capacity) {
  this->mCapacity = capacity;
  this->mSize = 0;
  this->bucketList = new Bucket *[this->mCapacity];
  for (int i = 0; i < this->mCapacity; ++i) {
    this->bucketList[i] = nullptr;
  }
}


unsigned int AnagramDictionary::add(const string &word) {
  // getFirst Hash
  string sorted = sortedWord(word);
  unsigned int keyValue = key(sorted);
  unsigned int index = hash(keyValue);

  unsigned int iter = 1;
  while (true) {
    if (bucketList[index] == nullptr) {
      this->bucketList[index] = new Bucket(word);
      this->mSize++;
      break;
    } else {
      if (sorted == bucketList[index]->getKeyword()) {
        bucketList[index]->add(word);
        break;
      }

      index = (index + (iter++ * hash2(keyValue))) % this->mCapacity;
    }
  }

  if (loadFactor() >= 0.75) {
    rehash();
  }

  return iter;
}


// O(N)
unsigned int AnagramDictionary::key(const string &word) {
  unsigned int sum = 0;

  for (char i : word) {
    sum += i;
    sum <<= 1;
  }
  return sum;
}

// O(N)
unsigned int AnagramDictionary::hash(unsigned int key) const {
  return key % mCapacity;
}


string AnagramDictionary::sortedWord(const string &pWord) {
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

unsigned int AnagramDictionary::hash2(unsigned int key) {
  return 3 - (key % 3);
}

/**
 * Complexity Analysis
 * Best Case - Ω(N^2)
 * Average Case - Θ(N^2)
 * Worst Case - O(N^2)
 */
double AnagramDictionary::loadFactor() const {
  return double(mSize) / double(mCapacity);
}


void AnagramDictionary::rehash() {
  cout << mSize << "/" << mCapacity << "=" << double(mSize)/double(mCapacity) << endl;
  this->mCapacity *= 2;
  this->mSize = 0;
  auto *oldBucket = bucketList;
  bucketList = new Bucket *[mCapacity];

  for (int i = 0; i < this->mCapacity / 2; ++i) {
    if (oldBucket[i] != nullptr) {
      rehashAdd(oldBucket[i]);
      oldBucket[i] = nullptr;
    }
  }

  delete oldBucket;
}

void AnagramDictionary::rehashAdd(Bucket *bucket) {
  // getFirst Hash
  unsigned int keyValue = key(bucket->getKeyword());
  unsigned int index = hash(keyValue);

  unsigned int iter = 1;

  while (true) {
    if (bucketList[index] == nullptr) {
      this->bucketList[index] = bucket;
      break;
    }
    index = (index + (iter++ * hash2(keyValue))) % this->mCapacity;
  }

  this->mSize++;
}

string AnagramDictionary::info() {
  string inf;
  for (int i = 0; i < mCapacity; ++i) {
    if (bucketList[i] != nullptr && bucketList[i]->getSize() > 1)
      inf += to_string(i) + ": " + bucketList[i]->info() + "\n";
  }
  inf += to_string(mSize) + "/" + to_string(mCapacity) + "\n";
  inf += "------------------------------------\n";
  return inf;
}

string *AnagramDictionary::getWords(const string &word, unsigned int *size) {
  // getFirst Hash
  string sorted = sortedWord(word);
  unsigned int keyValue = key(sorted);
  unsigned int index = hash(keyValue);

  unsigned int iter = 1;
  while (true) {
    if (bucketList[index] == nullptr) {
      return nullptr;
    } else {
      if (sorted == bucketList[index]->getKeyword()) {
        return bucketList[index]->getWords(size);
      }

      index = (index + (iter++ * hash2(keyValue))) % this->mCapacity;
    }
  }
}

unsigned int AnagramDictionary::printMaxBucketSize() {
  unsigned maxBucketSize =0;
  unsigned int index = 0;
  for (int i = 0; i < mCapacity; ++i) {
    if (bucketList[i] != nullptr && bucketList[i]->getSize() > maxBucketSize) {
      maxBucketSize = bucketList[i]->getSize();
      index = i;
    }
  }
  std::cout << "----------------------\n";
  std::cout << bucketList[index]->info() << std::endl;
  return maxBucketSize;
}
