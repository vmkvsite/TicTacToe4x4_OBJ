#ifndef PLAYER_H
#define PLAYER_H

class Player {
private:
    char symbol;

public:
    Player(char playerSymbol);
    char getSymbol() const;
    void setSymbol(char newSymbol);
};

#endif