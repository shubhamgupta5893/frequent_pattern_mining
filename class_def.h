//
// Created by sahil on 07/08/19.
//
#include <memory>
#include<vector>

using namespace std;
#ifndef UNTITLED_STRUC_DEF_H
#define UNTITLED_STRUC_DEF_H

#endif //UNTITLED_STRUC_DEF_H

#include <map>
#include <vector>
#include <algorithm>

class Bucket{
public:
    int numb;
    int numbC;
    shared_ptr<Bucket> next_same_numb_ptr; //
    //vector<shared_ptr<Bucket>> child_bucket_vector;
    unordered_map<int,shared_ptr<Bucket>> child_bucket_dict;
   shared_ptr<Bucket> parent_bucket_ptr;

 Bucket(int numb, shared_ptr<Bucket> parent_bucket_ptr, int numbC=1) {
     this->numb = numb;
     this->numbC = numbC
             ;
     this->parent_bucket_ptr = parent_bucket_ptr;
        this->next_same_numb_ptr=NULL;
 }

};


typedef std::pair<int,int> pair_;

class Tree{
public:

    unordered_map<int,shared_ptr<Bucket>> dictionary_first_bucket;
    ////unordered_map<int, shared_ptr<Bucket>> dictionary_most_recent_bucket;
    shared_ptr<Bucket> tree_root;
    vector<pair_> vec_freq_num_sorted_dec;
};
