//
// Created by Zorua on 2021/7/2.
//

#include <iostream>
#include "Chess.h"
#include "Boardgame.h"
const int Chess::Shuai[10][9] = {
        0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  1,  1,  1,  0,  0,  0,
        0,  0,  0,  2,  2,  2,  0,  0,  0,
        0,  0,  0, 11, 15, 11,  0,  0,  0
};
const int Chess::Bing[10][9] = {
        9,  9,  9, 11, 13, 11,  9,  9,  9,
       19, 24, 34, 42, 44, 42, 34, 24, 19,
       19, 24, 32, 37, 37, 37, 32, 24, 19,
       19, 23, 27, 29, 30, 29, 27, 23, 19,
       14, 18, 20, 27, 29, 27, 20, 18, 14,
        7,  0, 13,  0, 16,  0, 13,  0,  7,
        7,  0,  7,  0, 15,  0,  7,  0,  7,
        0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0
};
const int Chess::Pao[10][9] = {
        100,100, 96, 91, 90, 91, 96,100,100,
        98, 98, 96, 92, 89, 92, 96, 98, 98,
        97, 97, 96, 91, 92, 91, 96, 97, 97,
        96, 99, 99, 98,100, 98, 99, 99, 96,
        96, 96, 96, 96,100, 96, 96, 96, 96,
        95, 96, 99, 96,100, 96, 99, 96, 95,
        96, 96, 96, 96, 96, 96, 96, 96, 96,
        97, 96,100, 99,101, 99,100, 96, 97,
        96, 97, 98, 98, 98, 98, 98, 97, 96,
        96, 96, 97, 99, 99, 99, 97, 96, 96
};
const int Chess::Che[10][9] = {
        206,208,207,213,214,213,207,208,206,
        206,212,209,216,233,216,209,212,206,
        206,208,207,214,216,214,207,208,206,
        206,213,213,216,216,216,213,213,206,
        208,211,211,214,215,214,211,211,208,
        208,212,212,214,215,214,212,212,208,
        204,209,204,212,214,212,204,209,204,
        198,208,204,212,212,212,204,208,198,
        200,208,206,212,200,212,206,208,200,
        194,206,204,212,200,212,204,206,194
};
const int Chess::Ma[10][9] = {
        90, 90, 90, 96, 90, 96, 90, 90, 90,
        90, 96,103, 97, 94, 97,103, 96, 90,
        92, 98, 99,103, 99,103, 99, 98, 92,
        93,108,100,107,100,107,100,108, 93,
        90,100, 99,103,104,103, 99,100, 90,
        90, 98,101,102,103,102,101, 98, 90,
        92, 94, 98, 95, 98, 95, 98, 94, 92,
        93, 92, 94, 95, 92, 95, 94, 92, 93,
        85, 90, 92, 93, 78, 93, 92, 90, 85,
        88, 85, 90, 88, 90, 88, 90, 85, 88
};
const int Chess::Xiang[10][9] = {
        0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0, 20,  0,  0,  0, 20,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,
       18,  0,  0,  0, 23,  0,  0,  0, 18,
        0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0, 20,  0,  0,  0, 20,  0,  0
};
const int Chess::Shi[10][9] = {
        0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0, 20,  0, 20,  0,  0,  0,
        0,  0,  0,  0, 23,  0,  0,  0,  0,
        0,  0,  0, 20,  0, 20,  0,  0,  0,
};

const int Chess::CheM = 4;
const int Chess::MaM = 2;
const int Chess::PaoM = 2;
const int Chess::PaoVsKing = 20;
const int Chess::PaoVsKingWithAir = 30;
int Chess::getId() const {
    return id;
}

void Chess::setId(int id) {
    Chess::id = id;
}

const std::string &Chess::getName() const {
    return name;
}

void Chess::setName(const std::string &name) {
    Chess::name = name;
}

int Chess::getX() const {
    return x;
}

void Chess::setX(int x) {
    Chess::x = x;
}

int Chess::getY() const {
    return y;
}

void Chess::setY(int y) {
    Chess::y = y;
}

const std::string &Chess::getType() const {
    return type;
}

void Chess::setType(const std::string &type) {
    Chess::type = type;
}
bool Chess::isRed(){
    return getId()<=16;
}
bool Chess::isBlack(){
    return getId()>16;
}
bool Chess::isAttack(){
    if(isRed()){ //???????????????
        return getY()<5;
    }else{ //???????????????
        return getY()>4;
    }
}
bool Chess::isInNines(){
    if(getX()<3 || getX()>5) return false;
    if(isRed()){ //???????????????
        return getY()>=7 && getY()<=9;
    }else{ //???????????????
        return getY()>=0 && getY()<=2;
    }
}
bool Chess::isInNines(int x,int y){
    if(x<3 || x>5) return false;
    if(isRed()){ //???????????????
        return y>=7 && y<=9;
    }else{ //???????????????
        return y>=0 && y<=2;
    }
}
//??????????????????????????????????????????????????????
// px,py ??????????????????
// enemy ???????????????????????????????????????????????????????????????
// boardgame ???????????????
bool Chess::canMove(int px,int py,bool enemy,Boardgame* boardgame) {
    std::string ctype = getType();
    int ox = getX();
    int oy = getY();
    if(px<0 || px>8) return false;
    if(py<0 || py>9) return false;
    if (ctype == "???") {
//        std::cout << oy << "->" << py << ' ' << isBlack() << (oy > py) << std::endl;
        if (py > oy && isRed()) return false;

        if (oy > py && isBlack()) return false;
        if (isAttack()) {
            return abs(px - ox) + abs(py - oy) == 1;
        } else {
            return px == ox && abs(py - oy) == 1;
        }
    } else if (ctype == "???" || ctype == "???") {
        if(ctype=="???" && enemy){ //????????????
            int cnt = 0;
            if (ox == px) {
                for (int i = std::min(oy, py)+1; i <= std::max(oy, py)-1; ++i) { //????????????????????????????????????
                    if (boardgame->layout[ox][i] != 0) {
                        cnt++;
                    }
                }
                return cnt==1;
            } else if (oy == py) {
                for (int i = std::min(ox, px)+1; i <= std::max(ox, px)-1; ++i) { //????????????????????????????????????
                    if (boardgame->layout[i][oy] != 0) {
                        cnt++;
                    }
                }
                return cnt==1;
            }else{
                return false;
            }
        } else{ //??????????????????
            bool flag = true;
            if (ox == px) {
                for (int i = std::min(oy, py)+1; i <= std::max(oy, py)-1; ++i) { //???????????????????????????
//                    std::cout<<ox<<','<<i<<','<<boardgame->layout[ox][i]<<std::endl;
                    if (boardgame->layout[ox][i] != 0) {
                        flag = false;
                        break;
                    }
                }
                return flag;
            } else if (oy == py) {
                for (int i = std::min(ox, px)+1; i <= std::max(ox, px)-1; ++i) { //???????????????????????????
//                    std::cout<<i<<','<<oy<<','<<boardgame->layout[i][oy]<<std::endl;
                    if (boardgame->layout[i][oy] != 0) {
                        flag = false;
                        break;
                    }
                }
                return flag;
            }else{
                return false;
            }
        }
    }else if(ctype=="???"){ //????????????
        if(abs(px-ox)+abs(py-oy)!=3) return false;
        if(abs(px-ox)==2){
            if(px>ox){ //????????????
                return boardgame->layout[ox+1][oy]==0;
            }else{
                return boardgame->layout[ox-1][oy]==0;
            }
        }else if(abs(py-oy)==2){
            if(py>oy){ //????????????
                return boardgame->layout[ox][oy+1]==0;
            }else{
                return boardgame->layout[ox][oy-1]==0;
            }
        }else{
            return false;
        }
    }else if(ctype=="???"){ //????????????
        if(abs(px-ox)!=2 || abs(py-oy)!=2) return false;
        //????????????
        return boardgame->layout[(px+ox)/2][(py+oy)/2]==0;
    }else if(ctype=="???"){ //????????????
        if(abs(px-ox)!=1 || abs(py-oy)!=1) return false;
        //???????????????
        return isInNines(px,py);
    }else if(ctype=="???"){ //????????????
        if(enemy){ //????????????
            if(abs(px-ox)==0){
                bool flag=true;
                for (int i = std::min(oy, py)+1; i <= std::max(oy, py)-1; ++i) { //???????????????????????????
                    if (boardgame->layout[ox][i] != 0) {
                        flag = false;
                        break;
                    }
                }
                return flag;
            }else{
                return false;
            }
        }else{
            if(abs(px-ox) + abs(py-oy) != 1) return false;
            //???????????????
            return isInNines(px,py);
        }
    }
    return true;
}
Chess::Chess(){
    this->setId(0);
}
Chess::Chess(int id, std::string name, std::string type, int x, int y){
    this->setId(id);
    this->setName(name);
    this->setType(type);
    this->setX(x);
    this->setY(y);
    this->setAlive(true);
}
void Chess::setSelf(int id, std::string name, std::string type, int x, int y){
    this->setId(id);
    this->setName(name);
    this->setType(type);
    this->setX(x);
    this->setY(y);
    this->setAlive(true);
}

bool Chess::isAlive() const {
    return alive;
}

void Chess::setAlive(bool alive) {
    Chess::alive = alive;
}
bool Chess::isEnemy(int other){
    //???????????????????????????????????????
    return (other <=16) xor (getId()<=16);
}
bool Chess::isEnemy(const Chess& other){
    if(other.getId() == 0) return false;
    //???????????????????????????????????????
    return (other.getId()<=16) xor (getId()<=16);
}

int Chess::selfValue(Boardgame *boardgame) {
    int res=0;
    std::string ctype = getType();
    int ox = getX();
    int oy = getY();
    //?????????????????????????????????????????????
    //?????????????????????????????????????????????
    if(ctype=="???"){
        res+= 20;
    }else if(ctype=="???"){
        res+= 1;
    }else if(ctype=="???"){
        res+= 1;
    }else if(ctype=="???"){
        res+= 3;
    }else if(ctype=="???"){
        res+= 6;
    }else if(ctype=="???"){
        res+= 3;
    }else if(ctype=="???"){
        res+= 2;
    }else{
        res+= 0;
    }

    //??????????????????????????????????????? ???????????????????????????y ????????????x
    if((getId()<=16) xor boardgame->direction){
        //??????????????? false ??? ???????????????true ????????????
        //??????????????? true  ??? ???????????????false ????????????
        ox=8-ox;
        oy=9-oy;
    }
    if(ctype=="???"){
        res+= Chess::Shuai[oy][ox];
    }else if(ctype=="???"){
        res+= Chess::Shi[oy][ox];
    }else if(ctype=="???"){
        res+= Chess::Xiang[oy][ox];
    }else if(ctype=="???"){
        res+= Chess::Ma[oy][ox];
    }else if(ctype=="???"){
        res+= Chess::Che[oy][ox];
    }else if(ctype=="???"){
        res+= Chess::Pao[oy][ox];
    }else if(ctype=="???"){
        res+= Chess::Bing[oy][ox];
    }else{
        res+= 0;
    }
    //????????????????????????????????????????????????????????????????????? ???????????????????????????????????? ??????????????????????????????
    //?????????17?????? ?????????8?????? ?????????17??????
    //????????????????????????4??? ????????????????????????2??? ????????????????????????2??????????????????????????????
    ox = getX();
    oy = getY();
    if(ctype=="???"){
        int cx=ox;
        int cy=oy;
        for(int i=cx-1;i>=0;--i){
            if(boardgame->layout[i][cy]!=0) {
                if(isEnemy(boardgame->chesses[boardgame->layout[i][cy]])) res+=Chess::CheM;
                break;
            }else{
                res+=Chess::CheM;
            }
        }
        for(int i=cx+1;i<=8;++i){
            if(boardgame->layout[i][cy]!=0) {
                if(isEnemy(boardgame->chesses[boardgame->layout[i][cy]])) res+=Chess::CheM;
                break;
            }else{
                res+=Chess::CheM;
            }
        }
        for(int i=cy-1;i>=0;--i){
            if(boardgame->layout[cx][i]!=0) {
                if(isEnemy(boardgame->chesses[boardgame->layout[cx][i]])) res+=Chess::CheM;
                break;
            }else{
                res+=Chess::CheM;
            }
        }
        for(int i=cy+1;i<=9;++i){
            if(boardgame->layout[cx][i]!=0) {
                if(isEnemy(boardgame->chesses[boardgame->layout[cx][i]])) res+=Chess::CheM;
                break;
            }else{
                res+=Chess::CheM;
            }
        }
    }else if(ctype=="???"){
        int cx=ox;
        int cy=oy;
        int dx[]={-1,-2,+1,+2,-1,-2,+1,+2};
        int dy[]={+2,+1,+2,+1,-2,-1,-2,-1};
        for(int i=0;i<=8;++i){
            int nx=cx+dx[i];int ny=cy+dy[i];
            if(canMove(nx,ny,false,boardgame)){
                res+=Chess::MaM;
            }
        }
    }else if(ctype=="???"){
        int cx=ox;
        int cy=oy;
        if(getId()<=16){  //???????????????????????????
            if(boardgame->chesses[32].getX()==cx ||boardgame->chesses[32].getY()==cy) res+=Chess::PaoVsKing;
        }else{
            if(boardgame->chesses[16].getX()==cx ||boardgame->chesses[16].getY()==cy) res+=Chess::PaoVsKing;
        }
        for(int i=cx-1;i>=0;--i){
            if(boardgame->layout[i][cy]!=0) {
                if(isEnemy(boardgame->chesses[boardgame->layout[i][cy]])) res+=Chess::CheM;
                break;
            }else{
                res+=Chess::PaoM;
            }
        }
        for(int i=cx+1;i<=8;++i){
            if(boardgame->layout[i][cy]!=0) {
                if(isEnemy(boardgame->chesses[boardgame->layout[i][cy]])) res+=Chess::CheM;
                break;
            }else{
                res+=Chess::PaoM;
            }
        }
        for(int i=cy-1;i>=0;--i){
            if(boardgame->layout[cx][i]!=0) {
                if(isEnemy(boardgame->chesses[boardgame->layout[cx][i]])) res+=Chess::CheM;
                break;
            }else{
                res+=Chess::PaoM;
            }
        }
        for(int i=cy+1;i<=9;++i){
            if(boardgame->layout[cx][i]!=0) {
                if(isEnemy(boardgame->chesses[boardgame->layout[cx][i]])) res+=Chess::CheM;
                break;
            }else{
                res+=Chess::PaoM;
            }
        }
    }
    //???????????????????????????????????????????????????????????????

    //????????????????????????????????????????????????
    return res;
}

void Chess::makemoves(std::vector<Boardgame> &vector,Boardgame *boardgame){
    if(!isAlive()) return ;
    std::string ctype = getType();
    int ox = getX();
    int oy = getY();
    if(ctype=="???"){
        int dx[]={-1,0,+1,0};
        int dy[]={0,-1,0,+1};
        Boardgame newBoardgame = *boardgame;
        for(int i=0;i<4;++i){
            int nx = ox+dx[i];
            int ny = oy+dy[i];
            if(canMove(nx,ny,false,boardgame) && isEnemy(boardgame->layout[nx][ny])){
                if(boardgame->layout[nx][ny]==0 || isEnemy(boardgame->layout[nx][ny])){
                    newBoardgame.move(getId(),ox,oy,nx,ny,boardgame->layout[nx][ny]);
                    vector.push_back(newBoardgame);
                }
            }
        }
    }else if(ctype=="???"){
        int dx[]={-1,-2,-1,-2,+1,+2,+1,+2};
        int dy[]={-2,-1,+2,+1,+2,+1,-2,-1};
        Boardgame newBoardgame = *boardgame;
        for(int i=0;i<8;++i){
            int nx = ox+dx[i];
            int ny = oy+dy[i];
            if(canMove(nx,ny,false,boardgame)){
                if(boardgame->layout[nx][ny]==0 || isEnemy(boardgame->layout[nx][ny])){
                    newBoardgame.move(getId(),ox,oy,nx,ny,boardgame->layout[nx][ny]);
                    vector.push_back(newBoardgame);
                }
            }
        }
    }
}

