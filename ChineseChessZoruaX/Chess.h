//
// Created by Zorua on 2021/7/2.
//

#ifndef CHINESECHESSZORUA_CHESS_H
#define CHINESECHESSZORUA_CHESS_H


#include <vector>

class Boardgame;
class Chess{
    //棋子的类

public:
    explicit Chess();

    Chess(int id, std::string name, std::string type, int x, int y);

    int id; //棋子的编号
    std::string name; //棋子的名字
    std::string type; //棋子的类型 用红方名称
    int control; //这个棋子控制的点位的数量
    int cpoints[20]; //这个棋子控制的实际点位 用一个4位数表示坐标 /100为x坐标 %100为y坐标

    const std::string &getType() const;
    bool alive;

    bool isAlive() const;

    void setAlive(bool alive);

    //是否还活着
    void setType(const std::string &type);

    //实际的兵种 使用红棋叫法
    int x,y; //棋子的坐标


    //~~~~ Getter && Setter ~~~~~
    int getId() const;
    void setId(int id);
    const std::string &getName() const;
    void setName(const std::string &name);
    int getX() const;
    void setX(int x);
    int getY() const;
    void setY(int y);

    //~~~~~ 常用函数 ~~~~~
    //获得实际绘制的坐标
    //获得在该点的分值
    //判断是红是黑

    void setSelf(int id, std::string name, std::string type, int x, int y);


    bool isAttack();

    bool isBlack();

    bool isRed();

    bool canMove(int px, int py, bool enemy, Boardgame* boardgame);

    bool isInNines();

    bool isInNines(int x, int y);

    bool isEnemy(const Chess &other);

    int selfValue(Boardgame* boardgame);

    //=======================
    static const int Shuai[10][9];
    static const int Bing[10][9];
    static const int Pao[10][9];
    static const int Che[10][9];
    static const int Ma[10][9];
    static const int Shi[10][9];
    static const int Xiang[10][9];
    static const int CheM;
    static const int MaM;
    static const int PaoM;
    static const int PaoVsKing;
    static const int PaoVsKingWithAir;

    void makemoves(std::vector<Boardgame> &vector, Boardgame *boardgame);

    bool isEnemy(int other);
};


#endif //CHINESECHESSZORUA_CHESS_H
