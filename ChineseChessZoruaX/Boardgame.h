//
// Created by Zorua on 2021/6/25.
//

#ifndef CHINESECHESSZORUA_BOARDGAME_H
#define CHINESECHESSZORUA_BOARDGAME_H
#pragma execution_character_set("utf-8")

#include <string>
#include <Chess.h>
#include <QtCore/QString>


#endif //CHINESECHESSZORUA_BOARDGAME_H

class Boardgame {

public:
    explicit Boardgame();
    Chess chesses[33]; //32个棋子
    int layout[10][10];
    int step;
    int last_move;
    int getStep() const;
    int scoreRed;
    int scoreBlack;
    //步数 双方每一步棋算一步 一回合两步
    bool turn; //轮到谁了? true为红  false为黑

    bool isRed() const;
    bool isBlack() const;
    bool isAttacked(Chess chess);
    bool direction; //为true时红在下，否则红在上
    void move(int chessid, int ox, int oy, int ex, int ey, int chessid_other);
    void rotate();//翻转棋盘
    QString movestring(int chessid, int ox, int oy, int ex, int ey, bool rotate_direction);
    static bool cmpBoardgame(Boardgame &a,Boardgame &b);
    static bool cmpBoardgameInverse(Boardgame &a,Boardgame &b);

};
