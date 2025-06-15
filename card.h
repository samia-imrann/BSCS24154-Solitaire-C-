#ifndef CARD_H
#define CARD_H

#include <iostream>
using namespace std;

class card {
public:
    char suit;
    int rank;
    bool faceUp;

    card(char s = ' ', int r = 0, bool face = false) : suit(s), rank(r), faceUp(face) {}
    ~card() {}

    card& operator=(const card& other) {
        if (this != &other) {
            this->suit = other.suit;
            this->rank = other.rank;
            this->faceUp = other.faceUp;
        }
        return *this;
    }

    friend ostream& operator<<(ostream& os, const card& c) {
        if (!c.faceUp) {
            os << "[ ]";
            return os;
        }

        if (c.suit == 'H' || c.suit == 'D') {
            os << "\033[31m";  // Red color for Hearts and Diamonds
            switch (c.rank) {
            case 1:
                os << "A";
                break;
            case 11:
                os << "J";
                break;
            case 12:
                os << "Q";
                break;
            case 13:
                os << "K";
                break;
            case 10:
                os << "10";
                break;
            default:
                os << c.rank;
            }
            os << "\033[0m "; // Reset color
        }
        else {
            switch (c.rank) {
            case 1:
                os << "A";
                break;
            case 11:
                os << "J";
                break;
            case 12:
                os << "Q";
                break;
            case 13:
                os << "K";
                break;
            case 10:
                os << "10";
                break;
            default:
                os << c.rank;
            }
            os << " ";
        }

        return os;
    }
};


#endif //CARD_H
