#ifndef COMMAND_H
#define COMMAND_H

#include <string>
using namespace std;

class command 
{
public:
    string cmd;
    string source;
    string destination;
    int numCards;

    command(string c = " ", string s = " ", string d = " ", int num = 0)
        : cmd(c), source(s), destination(d), numCards(num) {
    }

    ~command() {}
};

#endif
