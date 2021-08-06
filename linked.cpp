// no cout except the answer
#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <algorithm>
using namespace std;
vector<string>
    st_cons,
    end_cons = {""}, // ending_consontants will have "" by default because cin must have characters to work with. This is used to have no ending consonant ie "cha"
    vowels,
    blacklist;

void file_contents_to_vector(string fname, vector<string>& vec) {
    ifstream fin;
    fin.open(fname);
    string raw_input;
    while (fin >> raw_input) vec.push_back(raw_input);
    fin.close();
}
void setup() {
    file_contents_to_vector("st_cons.txt", st_cons);
    file_contents_to_vector("vowels.txt", vowels);
    file_contents_to_vector("end_cons.txt", end_cons);
    file_contents_to_vector("blacklist.txt", blacklist);
    sort(blacklist.begin(), blacklist.end());
}
template<typename T>
T choice(const vector<T>& v) {
    static random_device rng;
    uniform_int_distribution<int> dist(0, v.size()-1);
    return v[dist(rng)];
}
string gen_syllable() {
    string res;
    do {
        res = choice(st_cons) + choice(vowels) + choice(end_cons);
    } while (binary_search(blacklist.begin(), blacklist.end(), res));
    return res;
}
int main() {
    setup();
    int targ;
    cin >> targ; // assume valid input
    vector<string> syllables;
    int size = 0;
    while (size < targ) {
        syllables.push_back(gen_syllable());
        size += syllables.back().size();
    }
    for (string s: syllables) cout << s;
    cout << endl << "(";
    for (string s: syllables) cout << s << "-";
    cout << "\b)"; // remove the last dash. This is ok because it moves back the cursor by one and then writes over it... I think

    main();
}