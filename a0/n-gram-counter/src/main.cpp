//including other code
#include <iostream>
#include <map>
#include <string>

//including a namespace
using namespace std;

/*
 * Counts the frequency of each n-gram found in the text
 * n: the number of adjacent characters to consider
 * text: the input text
 */

//the entry point of the program
void countNgrams(int &n, string &text) {
    if (n <= 0) {
        cerr << "ERROR: n must be greater than 0" << endl;
        return;
    }

    //------------------

    cout << "Input text: " << text << endl;
    cout << "Number of adjacent characters: " << n << endl;

    //map of pairs (x, y), where x is an n-gram and y is the count of that n-gram in the text
    map<string, int> ngramCounts;

    //IMPLEMENT YOUR ALGORITHM HERE
    //Since the map class will automatically add a missing key, as well as increase its count
    //everytime it is encountered, the algorithm is simply that of reading through the string,
    //reading a section of using std::string.substr(), which is set to pull a string of n characters
    //long. Continue doing this via a for loop till the end of the string is reached
    for (int i = 0; i+(n-1) < text.length(); i++) {
        ngramCounts[text.substr(i, n)]++;
    }

    //print the map with the n-gram counts
    cout << "n-gram counts:" << endl;

    for (const auto &ngram: ngramCounts) {
        std::cout << "n-gram: " << ngram.first << " --> count: " << ngram.second << std::endl;
    }

    cout << "--------------------" << endl;
}

int main(int argc, char *argv[]) {
    //test cases for our program, feel free to add and change test cases
    string texts[]{
        "hello world",
        "sssssss",
        string("What typically happens behind the scenes is that the ") +
        string("map is implemented as a self-balancing binary tree, and ") +
        string("the strict weak ordering is used to place new elements in the map, ") +
        string("and to determine whether two elements are equal. As an aside, ") +
        string("the same logic applies to std::set, where the key and value are one and the same."),
        "hello hello world"
    };

    //n: the number of adjacent characters for the n-grams
    //your program should work for any n
    int n = 3;

    //run our program for each test case
    for (string &text: texts) {
        countNgrams(n, text);
    }

    return 0;
}
