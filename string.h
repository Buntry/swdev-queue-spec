//lang::CwC
#pragma once

#include "object.h"
#include <cstdlib>
#include <cstring>
#include <cstdio> 

/**
 * String: a wrapper for char* and constant char* in order to
 *         allow for easy creating and computation of strings
 * 
 * immutable
 * 
 * author: dermer.s@husky.neu.edu / dermer.s@northeastern.edu
 **/
class String : public Object {
public:
    char* val; // owned
    size_t size_;

    String(char* c) {
        size_ = strlen(c);
        val = new char[size_ + 1];
        strcpy(val, c);
    }

    String(const char* c) {
        size_ = strlen(c);
        val = new char[size_ + 1];
        strcpy(val, c);
    }

    ~String() { //destructor
        delete[] val;
    }

    // hash function based on the equivalence specified by <equals>
    size_t hash() {
        size_t res = 0;
        for (size_t i=0; i<size_; i++) {
            res += val[i];
        }
        return res;
    }

    // compares strings based on direct character equivalence
    bool equals(Object *other) {
        if (other == nullptr) return false;
        String *s = dynamic_cast<String*>(other);
        if (s == nullptr) return false;
        return strcmp(val, s->val) == 0;
    }

    // compares the strings based on alphabetical order
    virtual int cmp(String *that) {
        return strcmp(val, that->val);
    }

    // returns a string made up of the concatination of this string and s
    String* concat(String *s) {
        char* res = new char[size_ + s->size_ + 1];
        strcpy(res, val);
        res = strcat(res, s->val);
        String* strres = new String(res);
        delete[] res;
        return strres;
    }

    // getter for the size of this string
    size_t size() { return size_; }
};