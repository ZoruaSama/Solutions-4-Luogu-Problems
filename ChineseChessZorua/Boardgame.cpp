//
// Created by Zorua on 2021/6/25.
//

#include <iostream>
#include <QtCore/QString>
#include "Boardgame.h"
#pragma execution_character_set("utf-8")


Boardgame::Boardgame(){
    // id=1..5 是红方的兵 17..21是黑方的卒
    direction=true;
    step=0;
    last_move=0;
    for(int i=1;i<=5;++i){
        chesses[i].setSelf(i,"兵","兵",i*2-2,6);
        chesses[i+16].setSelf(i+16,"卒","兵",i*2-2,3);
    }
    // id=6..7 是红方的两个炮 22..23是黑方的两个炮
    chesses[6].setSelf(6,"炮","炮",1,7);
    chesses[7].setSelf(7,"炮","炮",7,7);
    chesses[22].setSelf(22,"炮","炮",1,2);
    chesses[23].setSelf(23,"炮","炮",7,2);

    // id=8..9 是红方的两个车
    chesses[8].setSelf(8,"车","车",0,9);
    chesses[9].setSelf(9,"车","车",8,9);
    chesses[24].setSelf(24,"车","车",0,0);
    chesses[25].setSelf(25,"车","车",8,0);

    // id=10..11 是红方的两个马
    chesses[10].setSelf(10,"马","马",1,9);
    chesses[11].setSelf(11,"马","马",7,9);
    chesses[26].setSelf(26,"马","马",1,0);
    chesses[27].setSelf(27,"马","马",7,0);
    // id=12..13 是红方的两个相
    chesses[12].setSelf(12,"相","相",2,9);
    chesses[13].setSelf(13,"相","相",6,9);
    chesses[28].setSelf(28,"象","相",2,0);
    chesses[29].setSelf(29,"象","相",6,0);
    // id=14..15 是红方的两个士
    chesses[14].setSelf(14,"仕","仕",3,9);
    chesses[15].setSelf(15,"仕","仕",5,9);
    chesses[30].setSelf(30,"士","仕",3,0);
    chesses[31].setSelf(31,"士","仕",5,0);
    // id=16 是红方的帅
    chesses[16].setSelf(16,"帅","帅",4,9);
    chesses[32].setSelf(32,"将","帅",4,0);

    turn = true;

    for(int i=0;i<=9;++i){
        for(int j=0;j<=9;++j){
            layout[i][j]=0;
        }
    }
    for(int i=1;i<=32;++i){
        layout[chesses[i].getX()][chesses[i].getY()] = i;
    }
//    for(int i=0;i<=9;++i){
//        for(int j=0;j<=9;++j){
//            std::cout<<layout[i][j]<<' ';
//        }
//        std::cout<<std::endl;
//    }
    scoreRed=0;
    scoreBlack=0;
    for(int i=1;i<=16;++i){
        scoreRed+=chesses[i].selfValue(this);
    }
    for(int i=17;i<=32;++i){
        scoreBlack+=chesses[i].selfValue(this);
    }
}
bool Boardgame::isRed() const{
    return turn;
}
bool Boardgame::isBlack() const{
    return !turn;
}

bool Boardgame::isAttacked(Chess chess) {
    int ox=chess.getX();
    int oy=chess.getY();
    bool res=false;

    for(int i=1;i<=32;++i){
        if(chesses[i].isAlive() && chess.isEnemy(chesses[i]) && chesses[i].canMove(ox,oy,true,this)){
            res=true;
            std::cout<<"The king is attacked by "<<i<<std::endl;
            break;
        } //判断该棋子能否移动到该棋子的位置
    }
    return res;
}

void Boardgame::move(int chessid, int ox, int oy, int ex, int ey, int chessid_other) {
    turn = !turn;
    layout[ox][oy]=0;
    layout[ex][ey]=chessid;
    chesses[chessid].setX(ex);
    chesses[chessid].setY(ey);
    if(chessid_other!=0) chesses[chessid_other].setAlive(false); //吃子行为
    step++;
    last_move=chessid;
    scoreRed=0;
    scoreBlack=0;
    for(int i=1;i<=16;++i){
        scoreRed+=chesses[i].selfValue(this);
    }
    for(int i=17;i<=32;++i){
        scoreBlack+=chesses[i].selfValue(this);
    }
}

void Boardgame::rotate() {
    direction=!direction;
    for(int i=1;i<=32;++i){
        chesses[i].setX(8-chesses[i].getX());
        chesses[i].setY(9-chesses[i].getY());
    }
    for(int i=0;i<=9;++i){
        for(int j=0;j<=9;++j){
            layout[i][j]=0;
        }
    }
    for(int i=1;i<=32;++i){
        layout[chesses[i].getX()][chesses[i].getY()] = i;
    }
}

QString Boardgame::movestring(int chessid, int ox, int oy, int ex, int ey, bool rotate_direction) {
    QString cname = QString::fromUtf8(chesses[chessid].getName().c_str());
    QString ctype = QString::fromUtf8(chesses[chessid].getType().c_str());
    const QString number1 = "一二三四五六七八九";
    const QString number2 = "１２３４５６７８９";
    QString cstr = "第"+QString::number(getStep()/2+1)+"回合  ";
    if(chessid<=16){ //红棋的运动
        if(rotate_direction){
            ox=8-ox;
            ex=8-ex;
        }
        if(ey==oy){
            return cstr+cname+number1.mid(ox,1)+"平"+number1.mid(ex,1);
        }else if((ey<oy) xor rotate_direction){
            if(ctype=="相" || ctype=="士" || ctype=="马"){
                return cstr+cname+number1.mid(ox,1)+"退"+number1.mid(ex,1);
            }
            return cstr+cname+number1.mid(ox,1)+"退"+number1.mid(abs(ey-oy)-1,1);
        }else{
            if(ctype=="相" || ctype=="士" || ctype=="马"){
                return cstr+cname+number1.mid(ox,1)+"进"+number1.mid(ex,1);
            }
            return cstr+cname+number1.mid(ox,1)+"进"+number1.mid(abs(ey-oy)-1,1);
        }
    }else{
        if(!rotate_direction){
            ox=8-ox;
            ex=8-ex;

        }
        if(ey==oy){
            return cstr+cname+number2.mid(ox,1)+"平"+number2.mid(ex,1);
        }else if((ey>oy) xor rotate_direction){
            if(ctype=="相" || ctype=="士" || ctype=="马"){
                return cstr+cname+number2.mid(ox,1)+"退"+number2.mid(ex,1);
            }
            return cstr+cname+number2.mid(ox,1)+"退"+number2.mid(abs(ey-oy)-1,1);
        }else{
            if(ctype=="相" || ctype=="士" || ctype=="马"){
                return cstr+cname+number2.mid(ox,1)+"进"+number2.mid(ex,1);
            }
            return cstr+cname+number2.mid(ox,1)+"进"+number2.mid(abs(ey-oy)-1,1);
        }
    }

//    QString::fromUtf8(chesses[chessid].getName().c_str())<<ox<<direction.toStdString()<<oy<<std::endl;


}


int Boardgame::getStep() const{
    return step;
}

bool Boardgame::cmpBoardgame(Boardgame &a, Boardgame &b) {
    return (a.scoreRed-a.scoreBlack)>(b.scoreRed-b.scoreBlack);
}

bool Boardgame::cmpBoardgameInverse(Boardgame &a,Boardgame &b){
    return (a.scoreRed-a.scoreBlack)<(b.scoreRed-b.scoreBlack);
}