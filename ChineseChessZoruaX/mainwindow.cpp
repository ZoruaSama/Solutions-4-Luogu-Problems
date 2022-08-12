#include "mainwindow.h"
#include "ui_mainwindow.h"


//#pragma GCC optimize(3,"Ofast","inline")
//#pragma GCC optimize(2)


#include <time.h>
#include <iostream>
#include <windows.h>
#include <minwindef.h>

#include <QTextCodec>
#include <QMouseEvent>
#include <QtGui/QPainter>


#include <fstream>

#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkAccessManager>
#include <QtCore/QProcess>
#include <QtWidgets/QMessageBox>


#pragma execution_character_set("utf-8")

const int HISTORY_MAX=10; //棋局历史记录最多数量
const int cube = 64; //基本格子宽度
const int chessCube = 30; //基本棋子宽度


//======== Engine部分
// 棋盘范围
const int RANK_TOP = 3;
const int RANK_BOTTOM = 12;
const int FILE_LEFT = 3;
const int FILE_RIGHT = 11;
const int BOARD_EDGE = 8;

// 棋子编号
const int PIECE_KING = 0;
const int PIECE_ADVISOR = 1;
const int PIECE_BISHOP = 2;
const int PIECE_KNIGHT = 3;
const int PIECE_ROOK = 4;
const int PIECE_CANNON = 5;
const int PIECE_PAWN = 6;

// 其他常数
const int MAX_GEN_MOVES = 160; // 最大的生成走法数 128
const int MAX_MOVES = 320;     // 最大的历史走法数 256
const int LIMIT_DEPTH = 64;    // 最大的搜索深度  64
const int MATE_VALUE = 10000;  // 最高分值，即将死的分值
const int BAN_VALUE = MATE_VALUE - 100; // 长将判负的分值，低于该值将不写入置换表   100
const int WIN_VALUE = MATE_VALUE - 200; // 搜索出胜负的分值界限，超出此值就说明已经搜索出杀棋了
const int DRAW_VALUE = 20;     // 和棋时返回的分数(取负值)
const int ADVANCED_VALUE = 3;  // 先行权分值
const int RANDOM_MASK = 7;     // 随机性分值
const int NULL_MARGIN = 400;   // 空步裁剪的子力边界
const int NULL_DEPTH = 2;      // 空步裁剪的裁剪深度
const int HASH_SIZE = 1 << 24; // 置换表大小
const int HASH_ALPHA = 1;      // ALPHA节点的置换表项
const int HASH_BETA = 2;       // BETA节点的置换表项
const int HASH_PV = 3;         // PV节点的置换表项///标记数值
const int BOOK_SIZE = 16384;   // 开局库大小
const int THINKINGSECS = 5;    // 思考时间


// 判断棋子是否在棋盘中的数组
static const char ccInBoard[256] = {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0,
        0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0,
        0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0,
        0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0,
        0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0,
        0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0,
        0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0,
        0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0,
        0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0,
        0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

// 判断棋子是否在九宫的数组
static const char ccInFort[256] = {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

// 判断步长是否符合特定走法的数组，1=帅(将)，2=仕(士)，3=相(象)
static const char ccLegalSpan[512] = {
        0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 3, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 2, 1, 2, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 2, 1, 2, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 3, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0
};

// 根据步长判断马是否蹩腿的数组
static const char ccKnightPin[512] = {
        0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,-16,  0,-16,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0, -1,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0, -1,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0, 16,  0, 16,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0
};

// 帅(将)的步长
static const char ccKingDelta[4] = {-16, -1, 1, 16};
// 仕(士)的步长
static const char ccAdvisorDelta[4] = {-17, -15, 15, 17};
// 马的步长，以帅(将)的步长作为马腿
static const char ccKnightDelta[4][2] = {{-33, -31}, {-18, 14}, {-14, 18}, {31, 33}};
// 马被将军的步长？？？，以仕(士)的步长作为马腿
static const char ccKnightCheckDelta[4][2] = {{-33, -18}, {-31, -14}, {14, 31}, {18, 33}};

// 棋盘初始设置
static const BYTE cucpcStartup[256] = {
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0, 20, 19, 18, 17, 16, 17, 18, 19, 20,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0, 21,  0,  0,  0,  0,  0, 21,  0,  0,  0,  0,  0,
        0,  0,  0, 22,  0, 22,  0, 22,  0, 22,  0, 22,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0, 14,  0, 14,  0, 14,  0, 14,  0, 14,  0,  0,  0,  0,
        0,  0,  0,  0, 13,  0,  0,  0,  0,  0, 13,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0, 12, 11, 10,  9,  8,  9, 10, 11, 12,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
};

// 子力位置价值表
static const BYTE cucvlPiecePos[7][256] = {
        { // 帅(将)
                0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                0,  0,  0,  0,  0,  0,  1,  1,  1,  0,  0,  0,  0,  0,  0,  0,
                0,  0,  0,  0,  0,  0,  2,  2,  2,  0,  0,  0,  0,  0,  0,  0,
                0,  0,  0,  0,  0,  0, 11, 15, 11,  0,  0,  0,  0,  0,  0,  0,
                0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
        }, { // 仕(士)
                0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                0,  0,  0,  0,  0,  0, 20,  0, 20,  0,  0,  0,  0,  0,  0,  0,
                0,  0,  0,  0,  0,  0,  0, 23,  0,  0,  0,  0,  0,  0,  0,  0,
                0,  0,  0,  0,  0,  0, 20,  0, 20,  0,  0,  0,  0,  0,  0,  0,
                0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
        }, { // 相(象)
                0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                0,  0,  0,  0,  0, 20,  0,  0,  0, 20,  0,  0,  0,  0,  0,  0,
                0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                0,  0,  0, 18,  0,  0,  0, 23,  0,  0,  0, 18,  0,  0,  0,  0,
                0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                0,  0,  0,  0,  0, 20,  0,  0,  0, 20,  0,  0,  0,  0,  0,  0,
                0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
        },
        { //ma
                0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                0,  0,  0, 90, 90, 90, 96, 90, 96, 90, 90, 90,  0,  0,  0,  0,
                0,  0,  0, 90, 96,103, 97, 94, 97,103, 96, 90,  0,  0,  0,  0,
                0,  0,  0, 92, 98, 99,103, 99,103, 99, 98, 92,  0,  0,  0,  0,
                0,  0,  0, 93,108,100,107,100,107,100,108, 93,  0,  0,  0,  0,
                0,  0,  0, 90,100, 99,103,104,103, 99,100, 90,  0,  0,  0,  0,
                0,  0,  0, 90, 98,101,102,103,102,101, 98, 90,  0,  0,  0,  0,
                0,  0,  0, 92, 94, 98, 95, 98, 95, 98, 94, 92,  0,  0,  0,  0,
                0,  0,  0, 93, 92, 94, 95, 92, 95, 94, 92, 93,  0,  0,  0,  0,
                0,  0,  0, 85, 90, 92, 93, 78, 93, 92, 90, 85,  0,  0,  0,  0,
                0,  0,  0, 88, 85, 90, 88, 90, 88, 90, 85, 88,  0,  0,  0,  0,
                0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
        },
        { // 车
                0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                0,  0,  0,206,208,207,213,214,213,207,208,206,  0,  0,  0,  0,
                0,  0,  0,206,212,209,216,233,216,209,212,206,  0,  0,  0,  0,
                0,  0,  0,206,208,207,214,216,214,207,208,206,  0,  0,  0,  0,
                0,  0,  0,206,213,213,216,216,216,213,213,206,  0,  0,  0,  0,
                0,  0,  0,208,211,211,214,215,214,211,211,208,  0,  0,  0,  0,
                0,  0,  0,208,212,212,214,215,214,212,212,208,  0,  0,  0,  0,
                0,  0,  0,204,209,204,212,214,212,204,209,204,  0,  0,  0,  0,
                0,  0,  0,198,208,204,212,212,212,204,208,198,  0,  0,  0,  0,
                0,  0,  0,200,208,206,212,200,212,206,208,200,  0,  0,  0,  0,
                0,  0,  0,194,206,204,212,200,212,204,206,194,  0,  0,  0,  0,
                0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
        },{ //pao
                0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                0,  0,  0,100,100, 96, 91, 90, 91, 96,100,100,  0,  0,  0,  0,
                0,  0,  0, 98, 98, 96, 92, 89, 92, 96, 98, 98,  0,  0,  0,  0,
                0,  0,  0, 97, 97, 96, 91, 92, 91, 96, 97, 97,  0,  0,  0,  0,
                0,  0,  0, 96, 99, 99, 98,100, 98, 99, 99, 96,  0,  0,  0,  0,
                0,  0,  0, 96, 96, 96, 96,100, 96, 96, 96, 96,  0,  0,  0,  0,
                0,  0,  0, 95, 96, 99, 96,100, 96, 99, 96, 95,  0,  0,  0,  0,
                0,  0,  0, 96, 96, 96, 96, 96, 96, 96, 96, 96,  0,  0,  0,  0,
                0,  0,  0, 97, 96,100, 99,101, 99,100, 96, 97,  0,  0,  0,  0,
                0,  0,  0, 96, 97, 98, 98, 98, 98, 98, 97, 96,  0,  0,  0,  0,
                0,  0,  0, 96, 96, 97, 99, 99, 99, 97, 96, 96,  0,  0,  0,  0,
                0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
        },


        { // 兵(卒)
                0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                0,  0,  0,  9,  9,  9, 11, 13, 11,  9,  9,  9,  0,  0,  0,  0,
                0,  0,  0, 19, 24, 34, 42, 44, 42, 34, 24, 19,  0,  0,  0,  0,
                0,  0,  0, 19, 24, 32, 37, 37, 37, 32, 24, 19,  0,  0,  0,  0,
                0,  0,  0, 19, 23, 27, 29, 30, 29, 27, 23, 19,  0,  0,  0,  0,
                0,  0,  0, 14, 18, 20, 27, 29, 27, 20, 18, 14,  0,  0,  0,  0,
                0,  0,  0,  7,  0, 13,  0, 16,  0, 13,  0,  7,  0,  0,  0,  0,
                0,  0,  0,  7,  0,  7,  0, 15,  0,  7,  0,  7,  0,  0,  0,  0,
                0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
        }
};

// 判断棋子是否在棋盘中
inline BOOL IN_BOARD(int sq) {
    return ccInBoard[sq] != 0;
}

// 判断棋子是否在九宫中
inline BOOL IN_FORT(int sq) {
    return ccInFort[sq] != 0;
}

// 获得格子的横坐标
inline int RANK_Y(int sq) {
    return sq >> 4;
}

// 获得格子的纵坐标
inline int FILE_X(int sq) {
    return sq & 15;
}

// 根据纵坐标和横坐标获得格子
inline int COORD_XY(int x, int y) {
    return x + (y << 4);
}

// 翻转格子
inline int SQUARE_FLIP(int sq) {
    return 254 - sq;
}

// 纵坐标水平镜像
inline int FILE_FLIP(int x) {
    return 14 - x;
}

// 横坐标垂直镜像
inline int RANK_FLIP(int y) {
    return 15 - y;
}

// 格子水平镜像
inline int MIRROR_SQUARE(int sq) {
    return COORD_XY(FILE_FLIP(FILE_X(sq)), RANK_Y(sq));
}

// 格子水平镜像
inline int SQUARE_FORWARD(int sq, int sd) {
    return sq - 16 + (sd << 5);
}

// 走法是否符合帅(将)的步长
inline BOOL KING_SPAN(int sqSrc, int sqDst) {
    return ccLegalSpan[sqDst - sqSrc + 256] == 1;
}

// 走法是否符合仕(士)的步长
inline BOOL ADVISOR_SPAN(int sqSrc, int sqDst) {
    return ccLegalSpan[sqDst - sqSrc + 256] == 2;
}

// 走法是否符合相(象)的步长
inline BOOL BISHOP_SPAN(int sqSrc, int sqDst) {
    return ccLegalSpan[sqDst - sqSrc + 256] == 3;
}

// 相(象)眼的位置
inline int BISHOP_PIN(int sqSrc, int sqDst) {
    return (sqSrc + sqDst) >> 1;
}

// 马腿的位置
inline int KNIGHT_PIN(int sqSrc, int sqDst) {
    return sqSrc + ccKnightPin[sqDst - sqSrc + 256];
}

// 是否未过河
inline BOOL HOME_HALF(int sq, int sd) {
    return (sq & 0x80) != (sd << 7);
}

// 是否已过河
inline BOOL AWAY_HALF(int sq, int sd) {
    return (sq & 0x80) == (sd << 7);
}

// 是否在河的同一边
inline BOOL SAME_HALF(int sqSrc, int sqDst) {
    return ((sqSrc ^ sqDst) & 0x80) == 0;
}

// 是否在同一行
inline BOOL SAME_RANK(int sqSrc, int sqDst) {
    return ((sqSrc ^ sqDst) & 0xf0) == 0;
}

// 是否在同一列
inline BOOL SAME_FILE(int sqSrc, int sqDst) {
    return ((sqSrc ^ sqDst) & 0x0f) == 0;
}

// 获得红黑标记(红子是8，黑子是16)
inline int SIDE_TAG(int sd) {
    return 8 + (sd << 3);
}

// 获得对方红黑标记
inline int OPP_SIDE_TAG(int sd) {
    return 16 - (sd << 3);
}

// 获得走法的起点
inline int SRC(int mv) {
    return mv & 255;
}

// 获得走法的终点
inline int DST(int mv) {
    return mv >> 8;
}

// 根据起点和终点获得走法
inline int MOVE(int sqSrc, int sqDst) {
    return sqSrc + sqDst * 256;
}

// 走法水平镜像
inline int MIRROR_MOVE(int mv) {
    return MOVE(MIRROR_SQUARE(SRC(mv)), MIRROR_SQUARE(DST(mv)));
}

// RC4密码流生成器
struct RC4Struct {
    BYTE s[256];
    int x, y;

    void InitZero(void);   // 用空密钥初始化密码流生成器
    BYTE NextByte(void) {  // 生成密码流的下一个字节
        BYTE uc;
        x = (x + 1) & 255;
        y = (y + s[x]) & 255;
        uc = s[x];
        s[x] = s[y];
        s[y] = uc;
        return s[(s[x] + s[y]) & 255];
    }
    DWORD NextLong(void) { // 生成密码流的下四个字节
        BYTE uc0, uc1, uc2, uc3;
        uc0 = NextByte();
        uc1 = NextByte();
        uc2 = NextByte();
        uc3 = NextByte();
        return uc0 + (uc1 << 8) + (uc2 << 16) + (uc3 << 24);
    }
};

// 用空密钥初始化密码流生成器
void RC4Struct::InitZero(void) {
    int i, j;
    BYTE uc;

    x = y = j = 0;
    for (i = 0; i < 256; i ++) {
        s[i] = i;
    }
    for (i = 0; i < 256; i ++) {
        j = (j + s[i]) & 255;
        uc = s[i];
        s[i] = s[j];
        s[j] = uc;
    }
}

// Zobrist结构键值
struct ZobristStruct {
    DWORD dwKey, dwLock0, dwLock1;

    void InitZero(void) {                 // 用零填充Zobrist
        dwKey = dwLock0 = dwLock1 = 0;
    }
    void InitRC4(RC4Struct &rc4) {        // 用密码流填充Zobrist
        dwKey = rc4.NextLong();
        dwLock0 = rc4.NextLong();
        dwLock1 = rc4.NextLong();
    }
    void Xor(const ZobristStruct &zobr) { // 执行XOR操作
        dwKey ^= zobr.dwKey;
        dwLock0 ^= zobr.dwLock0;
        dwLock1 ^= zobr.dwLock1;
    }
    void Xor(const ZobristStruct &zobr1, const ZobristStruct &zobr2) {
        dwKey ^= zobr1.dwKey ^ zobr2.dwKey;
        dwLock0 ^= zobr1.dwLock0 ^ zobr2.dwLock0;
        dwLock1 ^= zobr1.dwLock1 ^ zobr2.dwLock1;
    }
};

// Zobrist表、、、、存到256个局面信息 其中那些额外的是扩充用 为的是能够进行位运算
static struct {
    ZobristStruct Player;
    ZobristStruct Table[14][256];
} Zobrist;

// 初始化Zobrist表
static void InitZobrist(void) {
    int i, j;
    RC4Struct rc4;

    rc4.InitZero();
    Zobrist.Player.InitRC4(rc4);
    for (i = 0; i < 14; i ++) {
        for (j = 0; j < 256; j ++) {
            Zobrist.Table[i][j].InitRC4(rc4);
        }
    }
}

// 历史走法信息(占4字节)
struct MoveStruct {
    WORD wmv;
    BYTE ucpcCaptured, ucbCheck;
    DWORD dwKey;

    void Set(int mv, int pcCaptured, BOOL bCheck, DWORD dwKey_) {
        wmv = mv;
        ucpcCaptured = pcCaptured;
        ucbCheck = bCheck;
        dwKey = dwKey_;
    }
}; // mvs

// 局面结构
struct PositionStruct {
    int sdPlayer;                   // 轮到谁走，0=红方，1=黑方
    BYTE ucpcSquares[256];          // 棋盘上的棋子
    int vlWhite, vlBlack;           // 红、黑双方的子力价值
    int nDistance, nMoveNum;        // 距离根节点的步数，历史走法数
    MoveStruct mvsList[MAX_MOVES];  // 历史走法信息列表
    ZobristStruct zobr;             // Zobrist

    void ClearBoard(void) {         // 清空棋盘
        sdPlayer = vlWhite = vlBlack = nDistance = 0;
        memset(ucpcSquares, 0, 256);
        zobr.InitZero();
    }
    void SetIrrev(void) {           // 清空(初始化)历史走法信息
        mvsList[0].Set(0, 0, Checked(), zobr.dwKey);
        nMoveNum = 1;
    }
    void Startup(void);             // 初始化棋盘
    void ChangeSide(void) {         // 交换走子方
        sdPlayer = 1 - sdPlayer;
        zobr.Xor(Zobrist.Player);
    }
    void AddPiece(int sq, int pc) { // 在棋盘上放一枚棋子、、、、、ucpcSquares棋盘上的棋子sq位置 pc棋子信息
        ucpcSquares[sq] = pc;
        // 红方加分，黑方(注意"cucvlPiecePos"取值要颠倒)减分
        if (pc < 16) {
            vlWhite += cucvlPiecePos[pc - 8][sq];///// vlWhite白方棋子的子力//////////cucvlPiecePos子力评价表
            zobr.Xor(Zobrist.Table[pc - 8][sq]);
        } else {
            vlBlack += cucvlPiecePos[pc - 16][SQUARE_FLIP(sq)];
            zobr.Xor(Zobrist.Table[pc - 9][sq]);
        }
    }
    void DelPiece(int sq, int pc) { // 从棋盘上拿走一枚棋子
        ucpcSquares[sq] = 0;
        // 红方减分，黑方(注意"cucvlPiecePos"取值要颠倒)加分
        if (pc < 16) {
            vlWhite -= cucvlPiecePos[pc - 8][sq];
            zobr.Xor(Zobrist.Table[pc - 8][sq]);
        } else {
            vlBlack -= cucvlPiecePos[pc - 16][SQUARE_FLIP(sq)];
            zobr.Xor(Zobrist.Table[pc - 9][sq]);
        }
    }
    int Evaluate(void) const {    // 局面评价函数
        return (sdPlayer == 0 ? vlWhite - vlBlack : vlBlack - vlWhite) + ADVANCED_VALUE;
    }
    BOOL InCheck(void) const {      // 是否被将军
        return mvsList[nMoveNum - 1].ucbCheck;
    }
    BOOL Captured(void) const {     // 上一步是否吃子
        return mvsList[nMoveNum - 1].ucpcCaptured != 0;
    }
    int MovePiece(int mv);                      // 搬一步棋的棋子
    void UndoMovePiece(int mv, int pcCaptured); // 撤消搬一步棋的棋子
    BOOL MakeMove(int mv);                      // 走一步棋
    void UndoMakeMove(void) {                   // 撤消走一步棋
        nDistance --;
        nMoveNum --;
        ChangeSide();
        UndoMovePiece(mvsList[nMoveNum].wmv, mvsList[nMoveNum].ucpcCaptured);
    }
    void NullMove(void) {                       // 走一步空步空着搜索
        DWORD dwKey;
        dwKey = zobr.dwKey;
        ChangeSide();
        mvsList[nMoveNum].Set(0, 0, FALSE, dwKey);
        nMoveNum ++;
        nDistance ++;
    }
    void UndoNullMove(void) {                   // 撤消走一步空步
        nDistance --;
        nMoveNum --;
        ChangeSide();
    }
    // 生成所有走法，如果"bCapture"为"TRUE"则只生成吃子走法
    int GenerateMoves(int *mvs, BOOL bCapture = FALSE) const;
    BOOL LegalMove(int mv) const;               // 判断走法是否合理
    BOOL Checked(void) const;                   // 判断是否被将军
    BOOL IsMate(void);                          // 判断是否被杀
    int DrawValue(void) const {                 // 和棋分值
        return (nDistance & 1) == 0 ? -DRAW_VALUE : DRAW_VALUE;
    }
    int RepStatus(int nRecur = 1) const;        // 检测重复局面
    int RepValue(int nRepStatus) const {        // 重复局面分值
        int vlReturn;
        vlReturn = ((nRepStatus & 2) == 0 ? 0 : nDistance - BAN_VALUE) +
                   ((nRepStatus & 4) == 0 ? 0 : BAN_VALUE - nDistance);
        return vlReturn == 0 ? DrawValue() : vlReturn;
    }
    BOOL NullOkay(void) const {                 // 判断是否允许空步裁剪
        return (sdPlayer == 0 ? vlWhite : vlBlack) > NULL_MARGIN;
    }
    void Mirror(PositionStruct &posMirror) const; // 对局面镜像
};

// 初始化棋盘
void PositionStruct::Startup(void) {
    int sq, pc;
    ClearBoard();
    for (sq = 0; sq < 256; sq ++) {
        pc = cucpcStartup[sq];
        if (pc != 0) {
            AddPiece(sq, pc);
        }
    }
    SetIrrev();
}

// 搬一步棋的棋子
int PositionStruct::MovePiece(int mv) {
    int sqSrc, sqDst, pc, pcCaptured;
    sqSrc = SRC(mv);
    sqDst = DST(mv);
    pcCaptured = ucpcSquares[sqDst];
    if (pcCaptured != 0) {
        DelPiece(sqDst, pcCaptured);
    }
    pc = ucpcSquares[sqSrc];
    DelPiece(sqSrc, pc);
    AddPiece(sqDst, pc);
    return pcCaptured;
}

// 撤消搬一步棋的棋子
void PositionStruct::UndoMovePiece(int mv, int pcCaptured) {
    int sqSrc, sqDst, pc;
    sqSrc = SRC(mv);
    sqDst = DST(mv);
    pc = ucpcSquares[sqDst];
    DelPiece(sqDst, pc);
    AddPiece(sqSrc, pc);
    if (pcCaptured != 0) {
        AddPiece(sqDst, pcCaptured);
    }
}

// 走一步棋
BOOL PositionStruct::MakeMove(int mv) {
    int pcCaptured;
    DWORD dwKey;

    dwKey = zobr.dwKey;
    pcCaptured = MovePiece(mv);
    if (Checked()) {
        UndoMovePiece(mv, pcCaptured);
        return FALSE;
    }
    ChangeSide();
    mvsList[nMoveNum].Set(mv, pcCaptured, Checked(), dwKey);
    nMoveNum ++;
    nDistance ++;
    return TRUE;
}

// "GenerateMoves"参数
const BOOL GEN_CAPTURE = TRUE;

// 生成所有走法，如果"bCapture"为"TRUE"则只生成吃子走法
int PositionStruct::GenerateMoves(int *mvs, BOOL bCapture) const {
    int i, j, nGenMoves, nDelta, sqSrc, sqDst;
    int pcSelfSide, pcOppSide, pcSrc, pcDst;
    // 生成所有走法，需要经过以下几个步骤：

    nGenMoves = 0;
    pcSelfSide = SIDE_TAG(sdPlayer);
    pcOppSide = OPP_SIDE_TAG(sdPlayer);
    for (sqSrc = 0; sqSrc < 256; sqSrc ++) {

        // 1. 找到一个本方棋子，再做以下判断：
        pcSrc = ucpcSquares[sqSrc];
        if ((pcSrc & pcSelfSide) == 0) {
            continue;
        }

        // 2. 根据棋子确定走法
        switch (pcSrc - pcSelfSide) {
            case PIECE_KING:
                for (i = 0; i < 4; i ++) {
                    sqDst = sqSrc + ccKingDelta[i];
                    if (!IN_FORT(sqDst)) {
                        continue;
                    }
                    pcDst = ucpcSquares[sqDst];
                    if (bCapture ? (pcDst & pcOppSide) != 0 : (pcDst & pcSelfSide) == 0) {
                        mvs[nGenMoves] = MOVE(sqSrc, sqDst);
                        nGenMoves ++;
                    }
                }
                break;
            case PIECE_ADVISOR:
                for (i = 0; i < 4; i ++) {
                    sqDst = sqSrc + ccAdvisorDelta[i];
                    if (!IN_FORT(sqDst)) {
                        continue;
                    }
                    pcDst = ucpcSquares[sqDst];
                    if (bCapture ? (pcDst & pcOppSide) != 0 : (pcDst & pcSelfSide) == 0) {
                        mvs[nGenMoves] = MOVE(sqSrc, sqDst);
                        nGenMoves ++;
                    }
                }
                break;
            case PIECE_BISHOP:
                for (i = 0; i < 4; i ++) {
                    sqDst = sqSrc + ccAdvisorDelta[i];
                    if (!(IN_BOARD(sqDst) && HOME_HALF(sqDst, sdPlayer) && ucpcSquares[sqDst] == 0)) {
                        continue;
                    }
                    sqDst += ccAdvisorDelta[i];
                    pcDst = ucpcSquares[sqDst];
                    if (bCapture ? (pcDst & pcOppSide) != 0 : (pcDst & pcSelfSide) == 0) {
                        mvs[nGenMoves] = MOVE(sqSrc, sqDst);
                        nGenMoves ++;
                    }
                }
                break;
            case PIECE_KNIGHT:
                for (i = 0; i < 4; i ++) {
                    sqDst = sqSrc + ccKingDelta[i];
                    if (ucpcSquares[sqDst] != 0) {
                        continue;
                    }
                    for (j = 0; j < 2; j ++) {
                        sqDst = sqSrc + ccKnightDelta[i][j];
                        if (!IN_BOARD(sqDst)) {
                            continue;
                        }
                        pcDst = ucpcSquares[sqDst];
                        if (bCapture ? (pcDst & pcOppSide) != 0 : (pcDst & pcSelfSide) == 0) {
                            mvs[nGenMoves] = MOVE(sqSrc, sqDst);
                            nGenMoves ++;
                        }
                    }
                }
                break;
            case PIECE_ROOK:
                for (i = 0; i < 4; i ++) {
                    nDelta = ccKingDelta[i];
                    sqDst = sqSrc + nDelta;
                    while (IN_BOARD(sqDst)) {
                        pcDst = ucpcSquares[sqDst];
                        if (pcDst == 0) {
                            if (!bCapture) {
                                mvs[nGenMoves] = MOVE(sqSrc, sqDst);
                                nGenMoves ++;
                            }
                        } else {
                            if ((pcDst & pcOppSide) != 0) {
                                mvs[nGenMoves] = MOVE(sqSrc, sqDst);
                                nGenMoves ++;
                            }
                            break;
                        }
                        sqDst += nDelta;
                    }
                }
                break;
            case PIECE_CANNON:
                for (i = 0; i < 4; i ++) {
                    nDelta = ccKingDelta[i];
                    sqDst = sqSrc + nDelta;
                    while (IN_BOARD(sqDst)) {
                        pcDst = ucpcSquares[sqDst];
                        if (pcDst == 0) {
                            if (!bCapture) {
                                mvs[nGenMoves] = MOVE(sqSrc, sqDst);
                                nGenMoves ++;
                            }
                        } else {
                            break;
                        }
                        sqDst += nDelta;
                    }
                    sqDst += nDelta;
                    while (IN_BOARD(sqDst)) {
                        pcDst = ucpcSquares[sqDst];
                        if (pcDst != 0) {
                            if ((pcDst & pcOppSide) != 0) {
                                mvs[nGenMoves] = MOVE(sqSrc, sqDst);
                                nGenMoves ++;
                            }
                            break;
                        }
                        sqDst += nDelta;
                    }
                }
                break;
            case PIECE_PAWN:
                sqDst = SQUARE_FORWARD(sqSrc, sdPlayer);
                if (IN_BOARD(sqDst)) {
                    pcDst = ucpcSquares[sqDst];
                    if (bCapture ? (pcDst & pcOppSide) != 0 : (pcDst & pcSelfSide) == 0) {
                        mvs[nGenMoves] = MOVE(sqSrc, sqDst);
                        nGenMoves ++;
                    }
                }
                if (AWAY_HALF(sqSrc, sdPlayer)) {
                    for (nDelta = -1; nDelta <= 1; nDelta += 2) {
                        sqDst = sqSrc + nDelta;
                        if (IN_BOARD(sqDst)) {
                            pcDst = ucpcSquares[sqDst];
                            if (bCapture ? (pcDst & pcOppSide) != 0 : (pcDst & pcSelfSide) == 0) {
                                mvs[nGenMoves] = MOVE(sqSrc, sqDst);
                                nGenMoves ++;
                            }
                        }
                    }
                }
                break;
        }
    }
    return nGenMoves;
}

// 判断走法是否合理
BOOL PositionStruct::LegalMove(int mv) const {
    int sqSrc, sqDst, sqPin;
    int pcSelfSide, pcSrc, pcDst, nDelta;
    // 判断走法是否合法，需要经过以下的判断过程：

    // 1. 判断起始格是否有自己的棋子
    sqSrc = SRC(mv);
    pcSrc = ucpcSquares[sqSrc];
    pcSelfSide = SIDE_TAG(sdPlayer);
    if ((pcSrc & pcSelfSide) == 0) {
        return FALSE;
    }

    // 2. 判断目标格是否有自己的棋子
    sqDst = DST(mv);
    pcDst = ucpcSquares[sqDst];
    if ((pcDst & pcSelfSide) != 0) {
        return FALSE;
    }

    // 3. 根据棋子的类型检查走法是否合理
    switch (pcSrc - pcSelfSide) {
        case PIECE_KING:
            return IN_FORT(sqDst) && KING_SPAN(sqSrc, sqDst);
        case PIECE_ADVISOR:
            return IN_FORT(sqDst) && ADVISOR_SPAN(sqSrc, sqDst);
        case PIECE_BISHOP:
            return SAME_HALF(sqSrc, sqDst) && BISHOP_SPAN(sqSrc, sqDst) &&
                   ucpcSquares[BISHOP_PIN(sqSrc, sqDst)] == 0;
        case PIECE_KNIGHT:
            sqPin = KNIGHT_PIN(sqSrc, sqDst);
            return sqPin != sqSrc && ucpcSquares[sqPin] == 0;
        case PIECE_ROOK:
        case PIECE_CANNON:
            if (SAME_RANK(sqSrc, sqDst)) {
                nDelta = (sqDst < sqSrc ? -1 : 1);
            } else if (SAME_FILE(sqSrc, sqDst)) {
                nDelta = (sqDst < sqSrc ? -16 : 16);
            } else {
                return FALSE;
            }
            sqPin = sqSrc + nDelta;
            while (sqPin != sqDst && ucpcSquares[sqPin] == 0) {
                sqPin += nDelta;
            }
            if (sqPin == sqDst) {
                return pcDst == 0 || pcSrc - pcSelfSide == PIECE_ROOK;
            } else if (pcDst != 0 && pcSrc - pcSelfSide == PIECE_CANNON) {
                sqPin += nDelta;
                while (sqPin != sqDst && ucpcSquares[sqPin] == 0) {
                    sqPin += nDelta;
                }
                return sqPin == sqDst;
            } else {
                return FALSE;
            }
        case PIECE_PAWN:
            if (AWAY_HALF(sqDst, sdPlayer) && (sqDst == sqSrc - 1 || sqDst == sqSrc + 1)) {
                return TRUE;
            }
            return sqDst == SQUARE_FORWARD(sqSrc, sdPlayer);
        default:
            return FALSE;
    }
}

// 判断是否被将军
BOOL PositionStruct::Checked() const {
    int i, j, sqSrc, sqDst;
    int pcSelfSide, pcOppSide, pcDst, nDelta;
    pcSelfSide = SIDE_TAG(sdPlayer);
    pcOppSide = OPP_SIDE_TAG(sdPlayer);
    // 找到棋盘上的帅(将)，再做以下判断：

    for (sqSrc = 0; sqSrc < 256; sqSrc ++) {
        if (ucpcSquares[sqSrc] != pcSelfSide + PIECE_KING) {
            continue;
        }

        // 1. 判断是否被对方的兵(卒)将军
        if (ucpcSquares[SQUARE_FORWARD(sqSrc, sdPlayer)] == pcOppSide + PIECE_PAWN) {
            return TRUE;
        }
        for (nDelta = -1; nDelta <= 1; nDelta += 2) {
            if (ucpcSquares[sqSrc + nDelta] == pcOppSide + PIECE_PAWN) {
                return TRUE;
            }
        }

        // 2. 判断是否被对方的马将军(以仕(士)的步长当作马腿)
        for (i = 0; i < 4; i ++) {
            if (ucpcSquares[sqSrc + ccAdvisorDelta[i]] != 0) {
                continue;
            }
            for (j = 0; j < 2; j ++) {
                pcDst = ucpcSquares[sqSrc + ccKnightCheckDelta[i][j]];
                if (pcDst == pcOppSide + PIECE_KNIGHT) {
                    return TRUE;
                }
            }
        }

        // 3. 判断是否被对方的车或炮将军(包括将帅对脸)
        for (i = 0; i < 4; i ++) {
            nDelta = ccKingDelta[i];
            sqDst = sqSrc + nDelta;
            while (IN_BOARD(sqDst)) {
                pcDst = ucpcSquares[sqDst];
                if (pcDst != 0) {
                    if (pcDst == pcOppSide + PIECE_ROOK || pcDst == pcOppSide + PIECE_KING) {
                        return TRUE;
                    }
                    break;
                }
                sqDst += nDelta;
            }
            sqDst += nDelta;
            while (IN_BOARD(sqDst)) {
                int pcDst = ucpcSquares[sqDst];
                if (pcDst != 0) {
                    if (pcDst == pcOppSide + PIECE_CANNON) {
                        return TRUE;
                    }
                    break;
                }
                sqDst += nDelta;
            }
        }
        return FALSE;
    }
    return FALSE;
}

// 判断是否被杀
BOOL PositionStruct::IsMate(void) {
    int i, nGenMoveNum, pcCaptured;
    int mvs[MAX_GEN_MOVES];

    nGenMoveNum = GenerateMoves(mvs);
    for (i = 0; i < nGenMoveNum; i ++) {
        pcCaptured = MovePiece(mvs[i]);
        if (!Checked()) {
            UndoMovePiece(mvs[i], pcCaptured);
            return FALSE;
        } else {
            UndoMovePiece(mvs[i], pcCaptured);
        }
    }
    return TRUE;
}

// 检测重复局面
int PositionStruct::RepStatus(int nRecur) const {
    BOOL bSelfSide, bPerpCheck, bOppPerpCheck;
    const MoveStruct *lpmvs;

    bSelfSide = FALSE;
    bPerpCheck = bOppPerpCheck = TRUE;
    lpmvs = mvsList + nMoveNum - 1;
    while (lpmvs->wmv != 0 && lpmvs->ucpcCaptured == 0) {
        if (bSelfSide) {
            bPerpCheck = bPerpCheck && lpmvs->ucbCheck;
            if (lpmvs->dwKey == zobr.dwKey) {
                nRecur --;
                if (nRecur == 0) {
                    return 1 + (bPerpCheck ? 2 : 0) + (bOppPerpCheck ? 4 : 0);
                }
            }
        } else {
            bOppPerpCheck = bOppPerpCheck && lpmvs->ucbCheck;
        }
        bSelfSide = !bSelfSide;
        lpmvs --;
    }
    return 0;
}

// 对局面镜像
void PositionStruct::Mirror(PositionStruct &posMirror) const {
    int sq, pc;
    posMirror.ClearBoard();
    for (sq = 0; sq < 256; sq ++) {
        pc = ucpcSquares[sq];
        if (pc != 0) {
            posMirror.AddPiece(MIRROR_SQUARE(sq), pc);
        }
    }
    if (sdPlayer == 1) {
        posMirror.ChangeSide();
    }
    posMirror.SetIrrev();
}

static PositionStruct posSt; // 局面实例

// 与图形界面有关的全局变量
static struct {
    HINSTANCE hInst;                              // 应用程序句柄实例
    HWND hWnd;                                    // 主窗口句柄
    HDC hdc, hdcTmp;                              // 设备句柄，只在"ClickSquare"过程中有效
    HBITMAP bmpBoard, bmpSelected, bmpPieces[24]; // 资源图片句柄
    int sqSelected, mvLast;                       // 选中的格子，上一步棋
    BOOL bFlipped, bGameOver;                     // 是否翻转棋盘，是否游戏结束(不让继续玩下去)
    int busy;
} BoardGame;

// 置换表项结构
struct HashItem {
    BYTE ucDepth, ucFlag;
    short svl;
    WORD wmv, wReserved;
    DWORD dwLock0, dwLock1;
};

// 开局库项结构
struct BookItem {
    DWORD dwLock;
    WORD wmv, wvl;
};

// 与搜索有关的全局变量
static struct {
    int mvResult;                  // 电脑走的棋
    int nHistoryTable[65536];      // 历史表
    int mvKillers[LIMIT_DEPTH][2]; // 杀手走法表
    HashItem HashTable[HASH_SIZE]; // 置换表
    int nBookSize;                 // 开局库大小
    BookItem BookTable[BOOK_SIZE]; // 开局库
} Search;

// 装入开局库
static void LoadBook(void) {
    std::ifstream in("res\\BOOK.DAT",std::ios::in|std::ios::binary);
    in.seekg(0,std::ios_base::end);
    Search.nBookSize=in.tellg()/sizeof(BookItem);
    std::cout<<"Search.nBookSize "<<Search.nBookSize<<"\n";
    if (Search.nBookSize > BOOK_SIZE) {
        Search.nBookSize = BOOK_SIZE;
    }
    in.seekg(0,std::ios::beg);
    in.read(reinterpret_cast<char *>(Search.BookTable), Search.nBookSize * sizeof(BookItem));
    in.close();
}

static int CompareBook(const void *lpbk1, const void *lpbk2) {
    DWORD dw1, dw2;
    dw1 = ((BookItem *) lpbk1)->dwLock;
    dw2 = ((BookItem *) lpbk2)->dwLock;
    return dw1 > dw2 ? 1 : dw1 < dw2 ? -1 : 0;
}

// 搜索开局库
static int SearchBook(void) {
    return 0;
    int i, vl, nBookMoves, mv;
    int mvs[MAX_GEN_MOVES], vls[MAX_GEN_MOVES];
    BOOL bMirror;
    BookItem bkToSearch, *lpbk;
    PositionStruct posMirror;
    // 搜索开局库的过程有以下几个步骤

    // 1. 如果没有开局库，则立即返回
    if (Search.nBookSize == 0) {
        return 0;
    }
    // 2. 搜索当前局面
    bMirror = FALSE;
    bkToSearch.dwLock = posSt.zobr.dwLock1;
    lpbk = (BookItem *) bsearch(&bkToSearch, Search.BookTable, Search.nBookSize, sizeof(BookItem), CompareBook);
    // 3. 如果没有找到，那么搜索当前局面的镜像局面
    if (lpbk == NULL) {
        bMirror = TRUE;
        posSt.Mirror(posMirror);
        bkToSearch.dwLock = posMirror.zobr.dwLock1;
        lpbk = (BookItem *) bsearch(&bkToSearch, Search.BookTable, Search.nBookSize, sizeof(BookItem), CompareBook);
    }
    // 4. 如果镜像局面也没找到，则立即返回
    if (lpbk == NULL) {
        return 0;
    }
    // 5. 如果找到，则向前查第一个开局库项
    while (lpbk >= Search.BookTable && lpbk->dwLock == bkToSearch.dwLock) {
        lpbk --;
    }
    lpbk ++;
    // 6. 把走法和分值写入到"mvs"和"vls"数组中
    vl = nBookMoves = 0;
    while (lpbk < Search.BookTable + Search.nBookSize && lpbk->dwLock == bkToSearch.dwLock) {
        mv = (bMirror ? MIRROR_MOVE(lpbk->wmv) : lpbk->wmv);
        if (posSt.LegalMove(mv)) {
            mvs[nBookMoves] = mv;
            vls[nBookMoves] = lpbk->wvl;
            vl += vls[nBookMoves];
            nBookMoves ++;
            if (nBookMoves == MAX_GEN_MOVES) {
                break; // 防止"BOOK.DAT"中含有异常数据
            }
        }
        lpbk ++;
    }
    if (vl == 0) {
        return 0; // 防止"BOOK.DAT"中含有异常数据
    }
    // 7. 根据权重随机选择一个走法
    vl = rand() % vl;
    for (i = 0; i < nBookMoves; i ++) {
        vl -= vls[i];
        if (vl < 0) {
            break;
        }
    }
    return mvs[i];
}

// 提取置换表项
static int ProbeHash(int vlAlpha, int vlBeta, int nDepth, int &mv) {
    BOOL bMate; // 杀棋标志：如果是杀棋，那么不需要满足深度条件
    HashItem hsh;

    hsh = Search.HashTable[posSt.zobr.dwKey & (HASH_SIZE - 1)];
    if (hsh.dwLock0 != posSt.zobr.dwLock0 || hsh.dwLock1 != posSt.zobr.dwLock1) {
        mv = 0;
        return -MATE_VALUE;
    }
    mv = hsh.wmv;
    bMate = FALSE;
    if (hsh.svl > WIN_VALUE) {
        if (hsh.svl < BAN_VALUE) {
            return -MATE_VALUE; // 可能导致搜索的不稳定性，立刻退出，但最佳着法可能拿到
        }
        hsh.svl -= posSt.nDistance;
        bMate = TRUE;
    } else if (hsh.svl < -WIN_VALUE) {
        if (hsh.svl > -BAN_VALUE) {
            return -MATE_VALUE; // 同上
        }
        hsh.svl += posSt.nDistance;
        bMate = TRUE;
    }
    if (hsh.ucDepth >= nDepth || bMate) {
        if (hsh.ucFlag == HASH_BETA) {
            return (hsh.svl >= vlBeta ? hsh.svl : -MATE_VALUE);
        } else if (hsh.ucFlag == HASH_ALPHA) {
            return (hsh.svl <= vlAlpha ? hsh.svl : -MATE_VALUE);
        }
        return hsh.svl;
    }
    return -MATE_VALUE;
};

// 保存置换表项
static void RecordHash(int nFlag, int vl, int nDepth, int mv) {
    HashItem hsh;
    hsh = Search.HashTable[posSt.zobr.dwKey & (HASH_SIZE - 1)];
    if (hsh.ucDepth > nDepth) {
        return;
    }
    hsh.ucFlag = nFlag;
    hsh.ucDepth = nDepth;
    if (vl > WIN_VALUE) {
        if (mv == 0 && vl <= BAN_VALUE) {
            return; // 可能导致搜索的不稳定性，并且没有最佳着法，立刻退出
        }
        hsh.svl = vl + posSt.nDistance;
    } else if (vl < -WIN_VALUE) {
        if (mv == 0 && vl >= -BAN_VALUE) {
            return; // 同上
        }
        hsh.svl = vl - posSt.nDistance;
    } else {
        hsh.svl = vl;
    }
    hsh.wmv = mv;
    hsh.dwLock0 = posSt.zobr.dwLock0;
    hsh.dwLock1 = posSt.zobr.dwLock1;
    Search.HashTable[posSt.zobr.dwKey & (HASH_SIZE - 1)] = hsh;
};

// MVV/LVA每种子力的价值
static BYTE cucMvvLva[24] = {
        0, 0, 0, 0, 0, 0, 0, 0,
        5, 1, 1, 3, 4, 3, 2, 0,
        5, 1, 1, 3, 4, 3, 2, 0
};

// 求MVV/LVA值
inline int MvvLva(int mv) {
    return (cucMvvLva[posSt.ucpcSquares[DST(mv)]] << 3) - cucMvvLva[posSt.ucpcSquares[SRC(mv)]];
}

// "qsort"按MVV/LVA值排序的比较函数
static int CompareMvvLva(const void *lpmv1, const void *lpmv2) {
    return MvvLva(*(int *) lpmv2) - MvvLva(*(int *) lpmv1);
}

// "qsort"按历史表排序的比较函数
static int CompareHistory(const void *lpmv1, const void *lpmv2) {
    return Search.nHistoryTable[*(int *) lpmv2] - Search.nHistoryTable[*(int *) lpmv1];
}


// 走法排序阶段
const int PHASE_HASH = 0;
const int PHASE_KILLER_1 = 1;
const int PHASE_KILLER_2 = 2;
const int PHASE_GEN_MOVES = 3;
const int PHASE_REST = 4;

// 走法排序结构
struct SortStruct {
    int mvHash, mvKiller1, mvKiller2; // 置换表走法和两个杀手走法
    int nPhase, nIndex, nGenMoves;    // 当前阶段，当前采用第几个走法，总共有几个走法
    int mvs[MAX_GEN_MOVES];           // 所有的走法

    void Init(int mvHash_) { // 初始化，设定置换表走法和两个杀手走法
        mvHash = mvHash_;
        mvKiller1 = Search.mvKillers[posSt.nDistance][0];
        mvKiller2 = Search.mvKillers[posSt.nDistance][1];
        nPhase = PHASE_HASH;
    }
    int Next(void); // 得到下一个走法
};

// 得到下一个走法
int SortStruct::Next(void) {
    int mv;
    switch (nPhase) {
        // "nPhase"表示着法启发的若干阶段，依次为：

        // 0. 置换表着法启发，完成后立即进入下一阶段；
        case PHASE_HASH:
            nPhase = PHASE_KILLER_1;
            if (mvHash != 0) {
                return mvHash;
            }
            // 技巧：这里没有"break"，表示"switch"的上一个"case"执行完后紧接着做下一个"case"，下同

            // 1. 杀手着法启发(第一个杀手着法)，完成后立即进入下一阶段；
        case PHASE_KILLER_1:
            nPhase = PHASE_KILLER_2;
            if (mvKiller1 != mvHash && mvKiller1 != 0 && posSt.LegalMove(mvKiller1)) {
                return mvKiller1;
            }

            // 2. 杀手着法启发(第二个杀手着法)，完成后立即进入下一阶段；
        case PHASE_KILLER_2:
            nPhase = PHASE_GEN_MOVES;
            if (mvKiller2 != mvHash && mvKiller2 != 0 && posSt.LegalMove(mvKiller2)) {
                return mvKiller2;
            }

            // 3. 生成所有着法，完成后立即进入下一阶段；
        case PHASE_GEN_MOVES:
            nPhase = PHASE_REST;
            nGenMoves = posSt.GenerateMoves(mvs);
            qsort(mvs, nGenMoves, sizeof(int), CompareHistory);
            nIndex = 0;

            // 4. 对剩余着法做历史表启发；
        case PHASE_REST:
            while (nIndex < nGenMoves) {
                mv = mvs[nIndex];
                nIndex ++;
                if (mv != mvHash && mv != mvKiller1 && mv != mvKiller2) {
                    return mv;
                }
            }

            // 5. 没有着法了，返回零。
        default:
            return 0;
    }
}

// 对最佳走法的处理
inline void SetBestMove(int mv, int nDepth) {
    int *lpmvKillers;
    Search.nHistoryTable[mv] += nDepth * nDepth;
    lpmvKillers = Search.mvKillers[posSt.nDistance];
    if (lpmvKillers[0] != mv) {
        lpmvKillers[1] = lpmvKillers[0];
        lpmvKillers[0] = mv;
    }
}

// 静态(Quiescence)搜索过程
static int SearchQuiesc(int vlAlpha, int vlBeta) {
    int i, nGenMoves;
    int vl, vlBest;
    int mvs[MAX_GEN_MOVES];
    // 一个静态搜索分为以下几个阶段

    // 1. 检查重复局面
    vl = posSt.RepStatus();
    if (vl != 0) {
        return posSt.RepValue(vl);
    }

    // 2. 到达极限深度就返回局面评价
    if (posSt.nDistance == LIMIT_DEPTH) {
        return posSt.Evaluate();
    }

    // 3. 初始化最佳值
    vlBest = -MATE_VALUE; // 这样可以知道，是否一个走法都没走过(杀棋)

    if (posSt.InCheck()) {
        // 4. 如果被将军，则生成全部走法
        nGenMoves = posSt.GenerateMoves(mvs);
        qsort(mvs, nGenMoves, sizeof(int), CompareHistory);
    } else {

        // 5. 如果不被将军，先做局面评价
        vl = posSt.Evaluate();
        if (vl > vlBest) {
            vlBest = vl;
            if (vl >= vlBeta) {
                return vl;
            }
            if (vl > vlAlpha) {
                vlAlpha = vl;
            }
        }

        // 6. 如果局面评价没有截断，再生成吃子走法
        nGenMoves = posSt.GenerateMoves(mvs, GEN_CAPTURE);
        qsort(mvs, nGenMoves, sizeof(int), CompareMvvLva);
    }

    // 7. 逐一走这些走法，并进行递归
    for (i = 0; i < nGenMoves; i ++) {
        if (posSt.MakeMove(mvs[i])) {
            vl = -SearchQuiesc(-vlBeta, -vlAlpha);
            posSt.UndoMakeMove();

            // 8. 进行Alpha-Beta大小判断和截断
            if (vl > vlBest) {    // 找到最佳值(但不能确定是Alpha、PV还是Beta走法)
                vlBest = vl;        // "vlBest"就是目前要返回的最佳值，可能超出Alpha-Beta边界
                if (vl >= vlBeta) { // 找到一个Beta走法
                    return vl;        // Beta截断
                }
                if (vl > vlAlpha) { // 找到一个PV走法
                    vlAlpha = vl;     // 缩小Alpha-Beta边界
                }
            }
        }
    }

    // 9. 所有走法都搜索完了，返回最佳值
    return vlBest == -MATE_VALUE ? posSt.nDistance - MATE_VALUE : vlBest;
}

// "SearchFull"的参数
const BOOL NO_NULL = TRUE;

// 超出边界(Fail-Soft)的Alpha-Beta搜索过程
static int SearchFull(int vlAlpha, int vlBeta, int nDepth, BOOL bNoNull = FALSE) {
    int nHashFlag, vl, vlBest;
    int mv, mvBest, mvHash, nNewDepth;
    SortStruct Sort;
    // 一个Alpha-Beta完全搜索分为以下几个阶段

    // 1. 到达水平线，则调用静态搜索(注意：由于空步裁剪，深度可能小于零)
    if (nDepth <= 0) {
        return SearchQuiesc(vlAlpha, vlBeta);
    }

    // 1-1. 检查重复局面(注意：不要在根节点检查，否则就没有走法了)
    vl = posSt.RepStatus();
    if (vl != 0) {
        return posSt.RepValue(vl);
    }

    // 1-2. 到达极限深度就返回局面评价
    if (posSt.nDistance == LIMIT_DEPTH) {
        return posSt.Evaluate();
    }

    // 1-3. 尝试置换表裁剪，并得到置换表走法
    vl = ProbeHash(vlAlpha, vlBeta, nDepth, mvHash);
    if (vl > -MATE_VALUE) {
        return vl;
    }

    // 1-4. 尝试空步裁剪(根节点的Beta值是"MATE_VALUE"，所以不可能发生空步裁剪)
    if (!bNoNull && !posSt.InCheck() && posSt.NullOkay()) {
        posSt.NullMove();
        vl = -SearchFull(-vlBeta, 1 - vlBeta, nDepth - NULL_DEPTH - 1, NO_NULL);
        posSt.UndoNullMove();
        if (vl >= vlBeta) {
            return vl;
        }
    }

    // 2. 初始化最佳值和最佳走法
    nHashFlag = HASH_ALPHA;
    vlBest = -MATE_VALUE; // 这样可以知道，是否一个走法都没走过(杀棋)
    mvBest = 0;           // 这样可以知道，是否搜索到了Beta走法或PV走法，以便保存到历史表

    // 3. 初始化走法排序结构
    Sort.Init(mvHash);

    // 4. 逐一走这些走法，并进行递归
    while ((mv = Sort.Next()) != 0) {
        if (posSt.MakeMove(mv)) {
            // 将军延伸
            nNewDepth = posSt.InCheck() ? nDepth : nDepth - 1;
            // PVS
            if (vlBest == -MATE_VALUE) {
                vl = -SearchFull(-vlBeta, -vlAlpha, nNewDepth);
            } else {
                vl = -SearchFull(-vlAlpha - 1, -vlAlpha, nNewDepth);
                if (vl > vlAlpha && vl < vlBeta) {
                    vl = -SearchFull(-vlBeta, -vlAlpha, nNewDepth);
                }
            }
            posSt.UndoMakeMove();

            // 5. 进行Alpha-Beta大小判断和截断
            if (vl > vlBest) {    // 找到最佳值(但不能确定是Alpha、PV还是Beta走法)
                vlBest = vl;        // "vlBest"就是目前要返回的最佳值，可能超出Alpha-Beta边界
                if (vl >= vlBeta) { // 找到一个Beta走法
                    nHashFlag = HASH_BETA;
                    mvBest = mv;      // Beta走法要保存到历史表
                    break;            // Beta截断
                }
                if (vl > vlAlpha) { // 找到一个PV走法
                    nHashFlag = HASH_PV;
                    mvBest = mv;      // PV走法要保存到历史表
                    vlAlpha = vl;     // 缩小Alpha-Beta边界
                }
            }
        }
    }

    // 5. 所有走法都搜索完了，把最佳走法(不能是Alpha走法)保存到历史表，返回最佳值
    if (vlBest == -MATE_VALUE) {
        // 如果是杀棋，就根据杀棋步数给出评价
        return posSt.nDistance - MATE_VALUE;
    }
    // 记录到置换表
    RecordHash(nHashFlag, vlBest, nDepth, mvBest);
    if (mvBest != 0) {
        // 如果不是Alpha走法，就将最佳走法保存到历史表
        SetBestMove(mvBest, nDepth);
    }
    return vlBest;
}

// 根节点的Alpha-Beta搜索过程
static int SearchRoot(int nDepth) {
    int vl, vlBest, mv, nNewDepth;
    SortStruct Sort;

    vlBest = -MATE_VALUE;
    Sort.Init(Search.mvResult);
    while ((mv = Sort.Next()) != 0) {
        if (posSt.MakeMove(mv)) {
            nNewDepth = posSt.InCheck() ? nDepth : nDepth - 1;
            if (vlBest == -MATE_VALUE) {
                vl = -SearchFull(-MATE_VALUE, MATE_VALUE, nNewDepth, NO_NULL);
            } else {
                vl = -SearchFull(-vlBest - 1, -vlBest, nNewDepth);
                if (vl > vlBest) {
                    vl = -SearchFull(-MATE_VALUE, -vlBest, nNewDepth, NO_NULL);
                }
            }
            posSt.UndoMakeMove();
            if (vl > vlBest) {
                vlBest = vl;
                Search.mvResult = mv;
                if (vlBest > -WIN_VALUE && vlBest < WIN_VALUE) {
                    vlBest += (rand() & RANDOM_MASK) - (rand() & RANDOM_MASK);
                }
            }
        }
    }
    RecordHash(HASH_PV, vlBest, nDepth, Search.mvResult);
    SetBestMove(Search.mvResult, nDepth);
    return vlBest;
}

std::string fenGen() {
    std::string fen{""};
    char spaceBetween{'0'};
    for(int y=RANK_TOP;y<=RANK_BOTTOM;++y){
        for(int x=FILE_LEFT;x<=FILE_RIGHT;++x){
            int sq=COORD_XY(x,y);
            int pc=posSt.ucpcSquares[sq];
            switch (pc) {
                //空格
                case 0:
                    ++spaceBetween;
                    break;
                    //兵
                case 14:
                    if (spaceBetween != '0') {
                        fen += spaceBetween;
                        spaceBetween = '0';
                    }
                    fen += 'P';
                    break;
                case 22:
                    if (spaceBetween != '0') {
                        fen += spaceBetween;
                        spaceBetween = '0';
                    }
                    fen += 'p';
                    break;

                    //将
                case 8:
                    if (spaceBetween != '0') {
                        fen += spaceBetween;
                        spaceBetween = '0';
                    }
                    fen += 'K';
                    break;
                case 16:
                    if (spaceBetween != '0') {
                        fen += spaceBetween;
                        spaceBetween = '0';
                    }
                    fen += 'k';
                    break;

                    //士
                case 9:
                    if (spaceBetween != '0') {
                        fen += spaceBetween;
                        spaceBetween = '0';
                    }
                    fen += 'A';
                    break;
                case 17:
                    if (spaceBetween != '0') {
                        fen += spaceBetween;
                        spaceBetween = '0';
                    }
                    fen += 'a';
                    break;

                    //象
                case 10:
                    if (spaceBetween != '0') {
                        fen += spaceBetween;
                        spaceBetween = '0';
                    }
                    fen += 'B';
                    break;
                case 18:
                    if (spaceBetween != '0') {
                        fen += spaceBetween;
                        spaceBetween = '0';
                    }
                    fen += 'b';
                    break;

                    //车和炮
                case 12:
                    if (spaceBetween != '0') {
                        fen += spaceBetween;
                        spaceBetween = '0';
                    }
                    fen += 'R';
                    break;
                case 13:
                    if (spaceBetween != '0') {
                        fen += spaceBetween;
                        spaceBetween = '0';
                    }
                    fen += 'C';
                    break;
                case 20:
                    if (spaceBetween != '0') {
                        fen += spaceBetween;
                        spaceBetween = '0';
                    }
                    fen += 'r';
                    break;
                case 21:
                    if (spaceBetween != '0') {
                        fen += spaceBetween;
                        spaceBetween = '0';
                    }
                    fen += 'c';
                    break;

                    //马
                case 11:
                    if (spaceBetween != '0') {
                        fen += spaceBetween;
                        spaceBetween = '0';
                    }
                    fen += 'N';
                    break;
                case 19:
                    if (spaceBetween != '0') {
                        fen += spaceBetween;
                        spaceBetween = '0';
                    }
                    fen += 'n';
                    break;
            }
        }
        if (spaceBetween != '0') {
            fen += spaceBetween;
            spaceBetween = '0';
        }
        fen += '/';
    }
    fen.erase(--end(fen));
//    fen += side ? " w" : " b";
    fen+=" b";
    return fen;
}


QNetworkAccessManager *http = new QNetworkAccessManager();
static int SearchZoruaBook(){
//    QString s = "echo ";
//    s.append(fenGen());
//    s.append("123123");
//    s.append(" > in.txt");
//    std::cout<<system(s.toLatin1())<<"\n";


//    system("python res/book.py > out.txt");



//    HttpRequest httpReq{"112.73.74.24", 80};
//    std::string res = httpReq.HttpGet("/chessdb.php?action=queryall&board=" + fenGen());
//
//    if (res.empty()){
//        return 0;
//    }else{
//        std::vector<std::string> splitRes = httpReq.split(res, "\n");
//        std::vector<std::string> parse = httpReq.split(*--splitRes.end(), ":");
//        if(parse.at(0) != "move") return 0;
//        int srcY = 9-parse.at(1).at(1)+'0'+3;
//        int srcX = parse.at(1).at(0)-'a'+3;
//        int dstY = 9-parse.at(1).at(3)+'0'+3;
//        int dstX = parse.at(1).at(2)-'a'+3;
//        int mv = MOVE((srcY<<4) + srcX,(dstY<<4) + dstX);
////        std::cout<<srcY<<' '<<srcX<<' '<<dstY<<' '<<dstX<<"\n";
////        std::cout<<"BOOK "<<MOVE((srcY<<4) + srcX,(dstY<<4) + dstX)<<"\n";
//        return mv;
//    }

//    QNetworkRequest request;
//    QString url = "http://www.chessdb.cn/chessdb.php?action=queryall&board="+QString::fromStdString(fenGen());
//    request.setUrl(QUrl(url));
//    request.setRawHeader("Host","www.chessdb.cn");
//    http->get(request);
}

void MainWindow::requestReceived(QNetworkReply* reply){
//    std::cout<<""
//    std::cout<<"replyCode "<<reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt()<<"\n";
//    std::cout<<"replyUrl"<<reply->url().url().toStdString()<<"\n";
//    QString replyText;
//    replyText.fromLatin1(reply->readAll());
//    std::cout<<"replyText "<<replyText.toStdString()<<"\n";
}

// 迭代加深搜索过程
static void SearchMain() {
    int i, t, vl, nGenMoves;
    int mvs[MAX_GEN_MOVES];
    // 初始化
    memset(Search.nHistoryTable, 0, 65536 * sizeof(int));       // 清空历史表
    memset(Search.mvKillers, 0, LIMIT_DEPTH * 2 * sizeof(int)); // 清空杀手走法表
    memset(Search.HashTable, 0, HASH_SIZE * sizeof(HashItem));  // 清空置换表
    t=clock(); // 初始化定时器
    posSt.nDistance = 0; // 初始步数
    // 搜索开局库
    Search.mvResult = SearchBook();
    if (Search.mvResult != 0) {
        std::cout<<"Book1\n";
        posSt.MakeMove(Search.mvResult);
        if (posSt.RepStatus(3) == 0) {
            posSt.UndoMakeMove();
            return;
        }
        posSt.UndoMakeMove();
    }
    // 搜索开局库
    Search.mvResult = SearchZoruaBook();
    if (Search.mvResult != 0) {
        std::cout<<"Book2\n";
        posSt.MakeMove(Search.mvResult);
        if (posSt.RepStatus(3) == 0) {
            posSt.UndoMakeMove();
            return;
        }
        posSt.UndoMakeMove();
    }
    // 检查是否只有唯一走法
    vl = 0;
    nGenMoves = posSt.GenerateMoves(mvs);
    for (i = 0; i < nGenMoves; i ++)
    {
        if (posSt.MakeMove(mvs[i]))
        {
            posSt.UndoMakeMove();
            Search.mvResult = mvs[i];
            vl ++;
        }
    }
    if (vl == 1) {
        return;
    }
    // 迭代加深过程
    for (i = 1; i <= LIMIT_DEPTH; i ++)
    {
        std::cout<<"DEPTH: "<<i<<"\n";
        vl = SearchRoot(i);
        // 搜索到杀棋，就终止搜索
        if (vl > WIN_VALUE || vl < -WIN_VALUE)
        {
            break;
        }
        // 超过指定时间，就终止搜索


        if (clock() - t > THINKINGSECS * CLOCKS_PER_SEC)
        {
            std::cout<<"Time Over\n";
            break;
        }else{
            std::cout<<"Time " << clock() - t <<"\n";
        }
    }
}



//======== QT图形部分处理

int ox;//绘画原点x
int oy;//绘画原点y

QFont *qFont = new QFont();


MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->widget->setPalette(QPalette(Qt::white));
    ui->widget->setAutoFillBackground(false); //设置背景为白色
    ui->widget->setVisible(false);
    setPalette(QPalette(Qt::white));
    setAutoFillBackground(false); //设置背景为白色
    this->setFixedSize(this->width(),this->height());
    ox = ui->widget->x()+ui->groupBox->x()+23;
    oy = ui->widget->y()+ui->groupBox->y()+35;
    qFont->setPointSize(18);
    qFont->setFamily("kaiti");
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(on_btnNewGame_clicked()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(on_btnRegret_clicked()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(on_btnRotate_clicked()));
    connect(http,SIGNAL(finished(QNetworkReply*)),this,SLOT(requestReceived(QNetworkReply*)));
    srand((unsigned long) time(NULL));
    InitZobrist();
    LoadBook();
#ifdef QT_NO_DEBUG
    std::cout<<"r mode\n";
#endif
    this->update();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event) {
//    ui->label->setText("BLK "+QString::number(boardgame->scoreBlack));
//    ui->label_2->setText("RED "+QString::number(boardgame->scoreRed));
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setRenderHint(QPainter::TextAntialiasing);
    QGroupBox *groupBox=ui->groupBox;
    QWidget *widget=ui->widget;
    QRect rect(widget->x()+groupBox->x(),widget->y()+groupBox->y(),widget->width(),widget->height());
    QPen pen;
    pen.setWidth(5);
    pen.setColor(Qt::black);
    painter.setPen(pen);
    painter.setFont(*qFont);
    QBrush brush;
    brush.setColor(Qt::yellow);
    brush.setStyle(Qt::SolidPattern);
    painter.setBrush(brush);
    painter.drawRect(rect);
    QPixmap pix,pix_s;
    //绘制棋盘
    pix.load("res\\board.png");
    painter.drawPixmap(rect,pix);

    //绘制棋子
    pix.load("res\\chess.png");
    pix_s.load("res\\chess_s.png");
    int xx,yy,sq,pc;
    for(int x=FILE_LEFT;x<=FILE_RIGHT;++x){
        for(int y=RANK_TOP;y<=RANK_BOTTOM;++y){
            if(BoardGame.bFlipped){
                xx=BOARD_EDGE+(FILE_FLIP(x)-FILE_LEFT)*(cube+1);
                yy=BOARD_EDGE+(RANK_FLIP(y)-RANK_TOP)*(cube+1);
            }else{
                xx=BOARD_EDGE+(x-FILE_LEFT)*(cube+1);
                yy=BOARD_EDGE+(y-RANK_TOP)*(cube+1);
            }
            sq=COORD_XY(x,y);
            pc=posSt.ucpcSquares[sq];
            if(pc!=0){
                int nx = ox + xx - 30;
                int ny = oy + yy - 30;
                if (sq == BoardGame.sqSelected || sq == SRC(BoardGame.mvLast) || sq == DST(BoardGame.mvLast)) {
                    painter.drawPixmap(nx,ny,60,60,pix_s);
                }else{
                    painter.drawPixmap(nx,ny,60,60,pix);
                }
                QString qString = QString::number(pc);
                if(pc==8){
                    qString="帅";
                }else if(pc==9){
                    qString="仕";
                }else if(pc==10){
                    qString="相";
                }else if(pc==11){
                    qString="马";
                }else if(pc==12){
                    qString="车";
                }else if(pc==13){
                    qString="炮";
                }else if(pc==14){
                    qString="兵";
                }else if(pc==16){
                    qString="将";
                }else if(pc==17){
                    qString="士";
                }else if(pc==18){
                    qString="象";
                }else if(pc==19){
                    qString="马";
                }else if(pc==20){
                    qString="车";
                }else if(pc==21){
                    qString="炮";
                }else if(pc==22){
                    qString="卒";
                }
                if(pc>=16){
                    pen.setColor(Qt::black);
                    painter.setPen(pen);
                }else{
                    pen.setColor(Qt::red);
                    painter.setPen(pen);
                }
                painter.setPen(pen);
                painter.drawText(nx+15,ny+40,qString);
            }
            //绘制历史记录
        }
    }
//    if(!history.empty()){
//        int cid=boardgame->last_move;
//        int ex = boardgame->chesses[cid].getX();
//        int ey = boardgame->chesses[cid].getY();
//        int cx = history.back().chesses[cid].getX();
//        int cy = history.back().chesses[cid].getY();
//        int nx = ox + cx * (cube + 1);
//        int ny = oy + cy * (cube + 1);
//        int nx2 = ox + ex * (cube + 1);
//        int ny2 = oy + ey * (cube + 1);
//        painter.setOpacity(0.3);
//        pen.setColor(Qt::darkCyan);
//        painter.setPen(pen);
//        painter.drawLine(nx,ny,nx2,ny2);
//        nx = ox + cx * (cube + 1) - pix.width() / 2;
//        ny = oy + cy * (cube + 1) - pix.height() / 2;
//        QString qString = QString::fromUtf8(boardgame->chesses[cid].getName().c_str());
//        painter.drawPixmap(nx,ny,pix.width(),pix.height(),pix);
//        if(cid>16){
//            pen.setColor(Qt::black);
//            painter.setPen(pen);
//        }else{
//            pen.setColor(Qt::red);
//            painter.setPen(pen);
//        }
//
//        painter.setFont(*qFont);
//        painter.drawText(nx+15,ny+40,qString);
//        painter.setOpacity(1);
//
//    }
//    for(int i=1;i<=32;++i){
//        if(!boardgame->chesses[i].isAlive()) continue;
//        int cx = boardgame->chesses[i].x;
//        int cy = boardgame->chesses[i].y;
//        int nx = ox + cx * (cube + 1) - pix.width() / 2;
//        int ny = oy + cy * (cube + 1) - pix.height() / 2;
//        painter.drawPixmap(nx,ny,pix.width(),pix.height(),i==mouseState? pix_s : pix);
//        //QString qString =  codec->toUnicode(boardgame->chesses[i].getName().c_str());
//        QString qString = QString::fromUtf8(boardgame->chesses[i].getName().c_str());
//        if(i>16){
//            pen.setColor(Qt::black);
//            painter.setPen(pen);
//        }else{
//            pen.setColor(Qt::red);
//            painter.setPen(pen);
//        }
//        painter.setFont(*qFont);
//        painter.drawText(nx+15,ny+40,qString);
//    }
}
void ResponseMove(){
    int vlRep;
    std::cout<<"Thinking Start "<<clock()<<"\n";
    SearchMain();
    std::cout<<"Thinking Over "<<clock()<<"\n";
    posSt.MakeMove(Search.mvResult);
    BoardGame.mvLast=Search.mvResult;
    vlRep=posSt.RepStatus(3);
    if(posSt.IsMate()){
        //AI赢了
        BoardGame.bGameOver=1;
    }else if(vlRep>0){
        vlRep=posSt.RepValue(vlRep);
        //对玩家来说的分值
        BoardGame.bGameOver=1;
        //长打了
    }else if(posSt.nMoveNum>100){
        BoardGame.bGameOver=1;
        //和棋
    }else{
        if(posSt.Captured()){
            posSt.SetIrrev();
        }
    }
}
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(BoardGame.busy){
        return ;
    }
    // 如果是鼠标左键按下
    const int maxx= (cube + 1) * 8 + chessCube;
    const int maxy= (cube + 1) * 9 + chessCube;
    if(event->x()-ox<-chessCube || event->y()-oy<-chessCube ||event->x()-ox> maxx || event->y()-oy>maxy){
        return ;
    }
    if(event->button() == Qt::LeftButton)
    {
        int ex = (event->x()-ox+chessCube)/(cube + 1) +FILE_LEFT;
        int ey = (event->y()-oy+chessCube)/(cube + 1) +RANK_TOP;
        int sq=COORD_XY(ex,ey);
        sq=BoardGame.bFlipped ? SQUARE_FLIP(sq):sq;
        int pc=posSt.ucpcSquares[sq];
        if((pc & SIDE_TAG(posSt.sdPlayer))!=0){
            //选中这个棋子
            BoardGame.sqSelected=sq;
        }else if(BoardGame.sqSelected && !BoardGame.bGameOver){
            //如果点击的是空白 但是有子已经选中了 那么就是走子行为
            int mv = MOVE(BoardGame.sqSelected,sq);
//            std::cout<<RANK_Y(SRC(mv))<<' '<<FILE_X(SRC(mv))<<' '<<RANK_Y(DST(mv))<<' '<<FILE_X(DST(mv))<<"\n";
//            std::cout<<"You Choose "<<mv<<"\n";
            int vlRep;
            if(posSt.LegalMove(mv)){
                if(posSt.MakeMove(mv)){
                    this->update();
                    BoardGame.busy=1;
                    setCursor(Qt::WaitCursor);
                    BoardGame.mvLast=mv;
                    BoardGame.sqSelected=0;
                    vlRep=posSt.RepStatus(3); //检查重复局面
                    if(posSt.IsMate()){
                        std::cout<<"You Win\n";
                        //BoardGame.bGameOver = 1;
                    }else if(vlRep > 0){
                        vlRep = posSt.RepValue(vlRep);
                        //对AI来说的分值
                        //BoardGame.bGameOver=1;
                        //长打了……
                    }else if(posSt.nMoveNum>100){
                        //BoardGame.bGameOver=1;
                        //和棋
                    }else{
                        if(posSt.Captured()){
                            posSt.SetIrrev();//记录历史数据
                        }
                        ResponseMove();
                    }
                    setCursor(Qt::ArrowCursor);
                    BoardGame.busy=0;
                }
            }
        }

//        std::cout<<"Click Cube Point:"<<ex<<' '<<ey<<std::endl; //输出点击的格点
//        std::cout<<"Click Chess:"<<pc<<std::endl; //输出点击的格
//        std::cout<<"LastSelected:"<<BoardGame.sqSelected<<std::endl; //输出点击的格

    }
        // 如果是鼠标右键按下
    else if(event->button() == Qt::RightButton){
        //ResponseMove();
        std::cout<<fenGen()<<"\n";
        std::cout<<SearchZoruaBook()<<"\n";
    }
    this->update();
}

void MainWindow::on_btnNewGame_clicked(){
    BoardGame.bFlipped = 0;
    posSt.Startup();
    BoardGame.sqSelected = 0;
    BoardGame.mvLast = 0;
    BoardGame.bGameOver = 0;
    this->update();
}
void MainWindow::on_btnRegret_clicked(){
//    if(!history.empty()){
//        delete boardgame;
//        boardgame = new Boardgame(history.back());
//        history.pop_back();
//        ui->listWidget->takeItem(ui->listWidget->count()-1);
//    }
//    this->update();
    int sum=0;
    std::cout<<clock()<<"\n";
    for(int i=1;i<=1000;++i){
        for(int j=1;j<=100;++j){
            for(int k=1;k<=100;++k){
                sum+=i+j+k;
                sum%=19491001;
            }
        }
    }
    std::cout<<clock()<<"\n";
    std::cout<<sum<<"\n";
}
void MainWindow::on_btnRotate_clicked(){
    BoardGame.bFlipped = !BoardGame.bFlipped;
    std::cout<<system("echo 12345>in.txt")<<"\n";
    this->update();

}

