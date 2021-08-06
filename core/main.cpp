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
    cout << "Enter the desired number of characters that you want the password to be" << endl;
    cin >> targ;
    if (targ < 1) {
        cout << "invalid input, it must be more than 0" << endl;
        main();
    }
    vector<string> syllables;
    int size = 0;
    while (size < targ) {
        syllables.push_back(gen_syllable());
        size += syllables.back().size();
    }
    cout << "length " << size << ":" << endl;
    for (string s: syllables) cout << s;
    cout << endl << "(";
    for (string s: syllables) cout << s << "-";
    cout << "\b)"; // remove the last dash. This is ok because it moves back the cursor by one and then writes over it... I think

    if (size > targ) {
        cout << endl << "or length " << size-syllables.back().size() << ":" << endl;
        for (int i = 0; i < syllables.size() - 1; i++) {
            cout << syllables[i]; // don't cout the last one because that made the size go over
        }
        cout << endl << "(";
        for (int i = 0 ; i < syllables.size() - 1; i++) {
            cout << syllables[i] << "-";
        }
        cout << "\b)";
    }
    cout << endl;
}