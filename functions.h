#ifndef functions_h
#define functions_h

#include<iostream>
#include<algorithm>
#include <fstream>
#include <string>  
#include <vector> 
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include<cmath>
#include<string>
#include<sstream>
#include <chrono> 
#include<cstdio>
//#include "functions.h"
using namespace std::chrono; 
using namespace std;

//https://www.geeksforgeeks.org/fast-io-for-competitive-programming/

int nextint_fastio(FILE*fs, int &number , bool &went_to_loop)
{
    number = 0;
    went_to_loop= false;
    int alphabet = getc_unlocked(fs); 
    if(alphabet==EOF)
        return 0; /// file is empty

    bool neg = false;

    if(alphabet=='-'){
        neg =true;
        alphabet = getc_unlocked(fs);
    }
    while((alphabet > 47 && alphabet < 58)){
            went_to_loop = true;
            number = number * 10 + alphabet - 48;
        alphabet=getc_unlocked(fs);
    }
    if(neg)
        number = number*-1;
    if(alphabet == '\n')
            return 1; //// new line has started
    return 2; /// successfully extracted the number
}

  



void print_set(set<int> const &s)
{
    for (auto const& i: s)
        cout << i << " ";
    cout << "\n";
}
int get_time_spent_seconds(high_resolution_clock::time_point start){

    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<seconds>(stop - start); 
    return duration.count();
}
void get_time_spent(high_resolution_clock::time_point start){

    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<microseconds>(stop - start); 
    cout << "Time taken by function: "<< duration.count()*1.00/1000000 << " seconds" << endl; 
    cout << "Time taken by function: "<< duration.count()*1.00/60000000 << " minutes" << endl;

}

vector<string> split(string str, const char delim)
{
    vector<string> substrs;
    std::stringstream ss(str);
	string s;
	while (getline(ss, s, delim)) {
		substrs.push_back(s);
	}

    return substrs;
}

void print_vector_set(vector<set<int> >const &s)
{
    for (auto const& i: s){
        for(auto const&j : i)
            cout << j << " ";
        cout << "\n";
    }
}

void print_vector(vector<int> t){
    for(int i = 0 ; i < t.size();i++){
        cout << t[i] << " ";
    }
    cout << "\n";

}

void print_long_vector(vector<long int> t){
    for(int i = 0 ; i < t.size();i++){
        cout << t[i] << " ";
    }
    cout << "\n";

}
void print_vector_vector(vector<vector<int> > t){
    for(int i = 0 ; i < t.size();i++){
        for (int j = 0; j < t[i].size();j++){
            cout << t[i][j] << " ";

        }
        cout << "\n\n";

    }

}
#endif
