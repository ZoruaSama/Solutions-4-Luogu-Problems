
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Boardgame.h"

#include <iostream>
#include <queue>

#include <QTextCodec>
#include <QMouseEvent>
#include <QtGui/QPainter>


#pragma execution_character_set("utf-8")


const int HISTORY_MAX=10; //棋局历史记录最多数量
const int cube = 64; //基本格子宽度
const int chessCube = 30; //基本棋子宽度

Boardgame *boardgame; //棋盘绘制时的最基本棋盘指针
int ox;//绘画原点x
int oy;//绘画原点y

std::deque<Boardgame> history; //棋局历史记录
std::vector<Boardgame> moves;
QTextCodec *codec = QTextCodec::codecForName("GBK");
QFont *qFont = new QFont();
int mouseState = 0; //鼠标状态



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->widget->setPalette(QPalette(Qt::white));
    ui->widget->setAutoFillBackground(true); //设置背景为白色
    ui->widget->setVisible(false);
    setPalette(QPalette(Qt::white));
    setAutoFillBackground(true); //设置背景为白色
    this->setFixedSize(this->width(),this->height());
    boardgame = new Boardgame();
    ox = ui->widget->x()+ui->groupBox->x()+32;
    oy = ui->widget->y()+ui->groupBox->y()+44;
    qFont->setPointSize(18);
    qFont->setFamily("kaiti");
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(on_btnNewGame_clicked()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(on_btnRegret_clicked()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(on_btnRotate_clicked()));
    this->update();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event) {
    ui->label->setText("BLK "+QString::number(boardgame->scoreBlack));
    ui->label_2->setText("RED "+QString::number(boardgame->scoreRed));
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
    QBrush brush;
    brush.setColor(Qt::yellow);
    brush.setStyle(Qt::SolidPattern);
    painter.setBrush(brush);
    painter.drawRect(rect);
    QPixmap pix,pix_s;
    pix.load("res\\board.png");
    painter.drawPixmap(rect,pix);

    //绘制棋子
    pix.load("res\\chess.png");
    pix_s.load("res\\chess_s.png");
    if(!history.empty()){
        int cid=boardgame->last_move;
        int ex = boardgame->chesses[cid].getX();
        int ey = boardgame->chesses[cid].getY();
        int cx = history.back().chesses[cid].getX();
        int cy = history.back().chesses[cid].getY();
        int nx = ox + cx * (cube + 1);
        int ny = oy + cy * (cube + 1);
        int nx2 = ox + ex * (cube + 1);
        int ny2 = oy + ey * (cube + 1);
        painter.setOpacity(0.3);
        pen.setColor(Qt::darkCyan);
        painter.setPen(pen);
        painter.drawLine(nx,ny,nx2,ny2);
        nx = ox + cx * (cube + 1) - pix.width() / 2;
        ny = oy + cy * (cube + 1) - pix.height() / 2;
        QString qString = QString::fromUtf8(boardgame->chesses[cid].getName().c_str());
        painter.drawPixmap(nx,ny,pix.width(),pix.height(),pix);
        if(cid>16){
            pen.setColor(Qt::black);
            painter.setPen(pen);
        }else{
            pen.setColor(Qt::red);
            painter.setPen(pen);
        }
        painter.setFont(*qFont);
        painter.drawText(nx+15,ny+40,qString);
        painter.setOpacity(1);

    }
    for(int i=1;i<=32;++i){
        if(!boardgame->chesses[i].isAlive()) continue;
        int cx = boardgame->chesses[i].x;
        int cy = boardgame->chesses[i].y;
        int nx = ox + cx * (cube + 1) - pix.width() / 2;
        int ny = oy + cy * (cube + 1) - pix.height() / 2;
        painter.drawPixmap(nx,ny,pix.width(),pix.height(),i==mouseState? pix_s : pix);
        //QString qString =  codec->toUnicode(boardgame->chesses[i].getName().c_str());
        QString qString = QString::fromUtf8(boardgame->chesses[i].getName().c_str());
        if(i>16){
            pen.setColor(Qt::black);
            painter.setPen(pen);
        }else{
            pen.setColor(Qt::red);
            painter.setPen(pen);
        }
        painter.setFont(*qFont);
        painter.drawText(nx+15,ny+40,qString);
    }
}
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    // 如果是鼠标左键按下
    this->update();
    const int maxx= (cube + 1) * 8 + chessCube;
    const int maxy= (cube + 1) * 9 + chessCube;
    if(event->x()-ox<-chessCube || event->y()-oy<-chessCube ||event->x()-ox> maxx || event->y()-oy>maxy){
        return ;
    }
    if(event->button() == Qt::LeftButton)
    {
        std::cout<<"Click Real Point:"<<event->x()-ox<<' '<<event->y()-oy<<std::endl; //输出点击的格点
        int ex = (event->x()-ox+chessCube)/(cube + 1);
        int ey = (event->y()-oy+chessCube)/(cube + 1);

        std::cout<<"Click Cube Point:"<<ex<<' '<<ey<<std::endl; //输出点击的格点
        int isSpace=0; //点击的是否是空点
        for(int i=1;i<=32;++i){ //判断是否点击了棋子
            if(!boardgame->chesses[i].isAlive()) continue;
            int cx = boardgame->chesses[i].x;
            int cy = boardgame->chesses[i].y;
            if(cx==ex && cy==ey){
                isSpace=i;
                std::cout<<"Click Chess:"<<isSpace<<std::endl; //输出点击的格点
                break;
            }
        }
        int cx = boardgame->chesses[mouseState].getX();
        int cy = boardgame->chesses[mouseState].getY();
        if(mouseState!=0){ //如果选中状态下
            if(isSpace==0){ //如果点击的是空地而且符合移动规则那么就移动
                if(boardgame->chesses[mouseState].canMove(ex,ey,false,boardgame)){
                    if(cx!=ex || cy!=ey){
                        //判断此走步会不会导致己方被将军
                        Boardgame temp = *boardgame;
                        temp.move(mouseState,cx,cy,ex,ey,isSpace);
                        if(!temp.isAttacked(!temp.isRed() ? temp.chesses[16]:temp.chesses[32])){
                            ui->listWidget->addItem(boardgame->movestring(mouseState,cx,cy,ex,ey,boardgame->direction));
                            history.push_back(*boardgame);
                            if(history.size()>HISTORY_MAX){
                                history.pop_front();
                            }
                            boardgame->move(mouseState,cx,cy,ex,ey,isSpace);
                            std::cout<<"moved"<<std::endl;
                        }
                    }
                    mouseState=0;
                    std::cout<<"released"<<std::endl;
                }
            }else if((isSpace<=16 && boardgame->isRed()) || (boardgame->isBlack()  && isSpace>16)){ //点击的是己方棋子
                mouseState=isSpace;
                std::cout<<"switched"<<std::endl;
                //ALL Completed 点击己方棋子只可能是切换
            }else if((isSpace>16 && boardgame->isRed()) || (boardgame->isBlack()  && isSpace<16)){ //点击的是敌方棋子
                if(boardgame->chesses[mouseState].canMove(ex,ey,true,boardgame)){
                    if(cx!=ex || cy!=ey){
                        //如果符合吃子规则那么就吃子
                        Boardgame temp = *boardgame;
                        temp.move(mouseState,cx,cy,ex,ey,isSpace);
                        if(!temp.isAttacked(!temp.isRed() ? temp.chesses[16]:temp.chesses[32])){
                            ui->listWidget->addItem(boardgame->movestring(mouseState,cx,cy,ex,ey,boardgame->direction));
                            history.push_back(*boardgame);
                            if(history.size()>HISTORY_MAX){
                                history.pop_front();
                            }
                            boardgame->move(mouseState,cx,cy,ex,ey,isSpace);
                            //杀死目标棋子
                            std::cout<<"attacked"<<std::endl;
                        }
                    }
                    mouseState=0;
                    std::cout<<"released"<<std::endl;
                }
            }

        }else{
            if(mouseState==0 && boardgame->isRed() && isSpace<=16 || mouseState==0 && boardgame->isBlack()  && isSpace>16){ //鼠标处于未选中状态
                mouseState=isSpace;
                std::cout<<"selected"<<std::endl;
            }
        }
    }

        // 如果是鼠标右键按下
    else if(event->button() == Qt::RightButton){
        moves.clear();
        if(boardgame->isRed()){
            for(int i=1;i<=16;++i){
                boardgame->chesses[i].makemoves(moves,boardgame);
            }
            if(!moves.empty()){
                std::sort(moves.begin(),moves.end(),Boardgame::cmpBoardgame);
                history.push_back(*boardgame);
                if(history.size()>HISTORY_MAX){
                    history.pop_front();
                }
                delete boardgame;
                boardgame = new Boardgame(moves[0]);
            }
        }else{
            for(int i=16;i<=32;++i){
                boardgame->chesses[i].makemoves(moves,boardgame);
            }
            if(!moves.empty()){
                std::sort(moves.begin(),moves.end(),Boardgame::cmpBoardgameInverse);

                history.push_back(*boardgame);
                if(history.size()>HISTORY_MAX){
                    history.pop_front();
                }
                delete boardgame;
                boardgame = new Boardgame(moves[0]);
            }

        }
    }
    this->update();
}

void MainWindow::on_btnNewGame_clicked(){
    delete boardgame;
    boardgame = new Boardgame();
    ui->listWidget->clear();
    history.clear();
    this->update();
}
void MainWindow::on_btnRegret_clicked(){
    if(!history.empty()){
        delete boardgame;
        boardgame = new Boardgame(history.back());
        history.pop_back();
        ui->listWidget->takeItem(ui->listWidget->count()-1);
    }
    this->update();
}
void MainWindow::on_btnRotate_clicked(){
//    boardgame->rotate();
//    for(int i=0;i<history.size();++i){
//        history[i].rotate();
//    }
//    int temp = ui->label_2->y();
//    ui->label_2->move(ui->label_2->x(),ui->label->y());
//    ui->label->move(ui->label->x(),temp);
    std::cout<<system("echo 123>in.txt");
    this->update();
}

