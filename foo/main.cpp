#include <iostream>
#include <fstream>
#include <vector>
#include <cstdio>

using namespace std;
string type_to_string(int); //这个函数将type这个int转换为实际的员工名字
int total_id=0; //这个变量是员工编号起始编号
class StaffBase{//为了实现多态的基类  所有的虚函数定义在这里
public:
    int id;      //员工的编号
    string name;    //员工姓名
    int age;    //员工年龄
    bool status; //员工状态
    int type; //员工类型
    string inPosition(); //这个函数把status这个bool变量转换为字符串
    void operator++(){ //运算符重载 将岁数增加1岁
        age++;
    }
    void operator++(int){
        age++;
    }
    virtual void showStaff(){ };//显示员工的信息
    virtual void addManages(int){ };//增加员工所管理的人员
    virtual void delManages(int){ };//删除员工所管理的人员
    virtual int numOfManages(){ return 0; };//返回员工所管理的人员数量
    virtual void outputManages(){ };//输出员工所管理的人员的信息
    virtual vector<StaffBase*>* getManages(){ return NULL; };//返回员工所管理的人员列表
    virtual int getAttr(const string&){ return 0; };//获取某个属性(用于修改/读取操作)

};
string StaffBase::inPosition() { //这个函数把status这个bool变量转换为字符串
        return (status ? "在职":"离职");
}

vector<StaffBase*> staffs; //用于存放[StaffBase类对象的地址]的一个vector列表
class Staff:public StaffBase{
public:
    Staff();
    Staff(int,string,int,bool,int);
    void setStaff();
    void showStaff();
    int getAttr(const string& name);
};
Staff::Staff(){ //两个构造函数，默认构造函数是手动输入信息的，下面那个构造函数是从文件中读取时用的
    type = 0;
    setStaff();
}
Staff::Staff(int _id,string _name,int _age,bool _status,int _type){
    id=_id;
    name=_name;
    age=_age;
    status=_status;
    type=_type;
}
void Staff::setStaff(){
    id = ++total_id;
    cout<<"请输入员工名字:";
    cin>>name;
    cout<<"请输入员工年龄:";
    cin>>age;
    while(cin.fail()){
        cout<<"输入格式有误。"<<endl;
        cin.clear();
        cin.sync();
        cin>>age;
    }
    cout<<"请输入员工在职状态(T/F):";
    string temp;
    cin>>temp;
    status = (temp == "T");
}
void Staff::showStaff(){
    cout<<"0.员工编号:"<<id<<endl;
    cout<<"1.员工名字:"<<name<<endl;
    cout<<"2.员工年龄:"<<age<<endl;
    string temp;
    cout<<"3.在职状态:"<<inPosition()<<endl;
    cout<<"4.员工类型:"<<::type_to_string(type)<<endl;
}
int Staff::getAttr(const string& _name) {
    if(_name=="0"){
        cout<<"无法修改员工编号。"<<endl;
        return 0;
    }else if(_name == "1"){
        cout<<"请输入员工名字:";
        cin>>name;
    }else if(_name == "2"){
        cout<<"请输入员工年龄:";
        cin>>age;
        while(cin.fail()){  //检查输入格式是否有问题
            cout<<"输入格式有误。"<<endl;
            cin.clear();
            cin.sync();
            cin>>age;
        }
    }else if(_name == "3"){
        cout<<"请输入员工在职状态(T/F):";
        string temp;
        cin>>temp;
        status = (temp == "T");
    }else if(_name == "4"){
        cout<<"无法直接修改员工类型。"<<endl;
    }
}

class Salesman : public Staff{
public:
    int sales; //销售额
    Salesman();
    Salesman(int,string,int,bool,int,int);
    void setStaff();
    void showStaff();
    int getAttr(const string&);
};

Salesman::Salesman() {
    type=1;
    setStaff();
}
Salesman::Salesman(int _id,string _name,int _age,bool _status,int _type,int _sales)
:Staff(_id,_name,_age,_status,_type){
    sales=_sales;
}
void Salesman::setStaff() {
    cout<<"请输入员工销售额:";
    cin>>sales;
    while(cin.fail()){
        cout<<"输入格式有误。"<<endl;
        cin.clear();
        cin.sync();
        cin>>sales;
    }
}

void Salesman::showStaff() {
    Staff::showStaff();
    cout<<"5.销售额:"<<sales<<endl;
}

int Salesman::getAttr(const string& _name) {
    Staff::getAttr(_name);
    if(_name=="5"){
        int mode;
        cout<<"0. 直接修改"<<endl
            <<"1. 增量更新"<<endl;
        cout<<"请选择修改模式:";
        cin>>mode;
        if(mode==0){
            cout<<"请输入员工销售额:";
            cin>>sales;
            while(cin.fail()){
                cout<<"输入格式有误。"<<endl;
                cin.clear();
                cin.sync();
                cin>>sales;
            }
        }else if(mode == 1){
            int _sales;
            cout<<"请输入修改量:";
            cin>>_sales;
            while(cin.fail()){
                cout<<"输入格式有误。"<<endl;
                cin.clear();
                cin.sync();
                cin>>_sales;
            }
            sales += _sales;
        }else{
            cout<<"输入了错误的模式。"<<endl;
        }

        return 0;
    }
    if(_name=="sales"){
        return sales;
    }
}
class Manager:public Staff{
public:
    vector<StaffBase*> manages; // 他所管理的人员对象
    Manager();
    Manager(int,string,int,bool,int);
    void setStaff();
    void showStaff();
    void addManages(int);
    void delManages(int);
    int numOfManages();
    void outputManages();
    vector<struct StaffBase *> * getManages();
    int getAttr(const string& name);
};
Manager::Manager() {
    type=2;
    setStaff();
}
Manager::Manager(int _id,string _name,int _age,bool _status,int _type)
:Staff(_id,_name,_age,_status,_type){

};

void Manager::setStaff() {
    cout<<"请输入管理的编号(输入0以终止):";
    int num;
    do{
        cin>>num;
        while(cin.fail()){
            cout<<"输入格式有误。"<<endl;
            cin.clear();
            cin.sync();
            cin>>num;
        }
        if(num!=0){
            addManages(num);
        }
    }while(num!=0);
}
void Manager::showStaff(){
    Staff::showStaff();
    cout<<"5.管理人员:"<<endl;
    outputManages();
}
int Manager::getAttr(const string& _name){
    Staff::getAttr(_name);
    if(_name=="5"){
        cout<<"欲删除人员在编号前添加一个'-'号, 欲添加人员直接输入编号。输入0终止。"<<endl;
        int tmp;
        do{
            cin>>tmp;
            if(tmp>0){
                addManages(tmp);
            }else if(tmp < 0){
                tmp=-tmp;
                delManages(tmp);
            }
        }while(tmp!=0);
        return 0;
    }
}
void Manager::addManages(int num) {
    for(int i=0;i<staffs.size();++i){
        if(staffs[i]->id==num){
            manages.push_back(staffs[i]);
            return ;
        }
    }
    cout<<"添加失败。没有找到 id 为"<<num<<"的员工。"<<endl;
}
void Manager::delManages(int num) {
    vector<StaffBase*>::iterator it;
    for(it=manages.begin();it!=manages.end();it++){
        if((*it)->id == num){
            manages.erase(it);
            break;
        }
    }
    if(it==manages.end()){
        cout<<"删除失败。没有找到 id 为"<<num<<"的员工。"<<endl;
    }
}
int Manager::numOfManages() {
    return (int)manages.size();
}
vector<StaffBase *>* Manager::getManages() {
    return &manages; //获取manages列表的地址并返回
}

void Manager::outputManages() {
    for(int i=0;i<manages.size();++i){
        cout<<staffs[i]->id<<':'
            <<staffs[i]->name<<'('
            <<staffs[i]->age<<')'<<"   "
            <<staffs[i]->inPosition()<<"的"
            <<type_to_string(staffs[i]->type)<<' '<<endl;
    }
    cout<<"共有"<<numOfManages()<<"个被管理人员。"<<endl;
}

string type_to_string(int type){
    if(type==0){
        return "普通员工";
    }else if(type==1){
        return "销售人员";
    }else if(type==2){
        return "团队经理";
    }else{
        return "???";
    }
}
int main() {
    int cm;
    const int exitCode = 7; //这个常量标记的是退出程序选项的代号
    fstream file("data.txt");  //从data文件中读取数据
    if(file.is_open()){
        StaffBase* staff;
        int id;
        string name;
        int age;
        bool status;
        int type;
        int sales;
        int m;
        while(!file.eof()){
            file>>id;
            file>>name;
            file>>age;
            file>>status;
            file>>type;
            if(type==0){
                staff = new Staff(id,name,age,status,type);
            }else if(type==1){
                file>>sales;
                staff = new Salesman(id,name,age,status,type,sales);
            }else if(type==2){
                int nums,tmp;
                file>>nums;
                staff = new Manager(id,name,age,status,type);
                for(int i=0;i<nums;++i){
                    file>>tmp;
                    staff->addManages(tmp);
                }
            }
            if(m!=id){
                staffs.push_back(staff);
                m=id;
            }
            total_id = max(total_id,id);
        }
        file.close();
    }else{
        cout<<"data.txt 文件不存在, 程序无法正常运行。"<<endl;
        return 0;
    }
    do{
        cout<<"员工管理系统。请输入所需要的功能编号"<<endl;
        cout<<"1. 输出信息"<<endl;
        cout<<"2. 添加信息"<<endl;
        cout<<"3. 修改信息"<<endl;
        cout<<"4. 删除信息"<<endl;
        cout<<"5. 查询信息"<<endl;
        cout<<"6. 更新年龄"<<endl;
        cout<<"7. 退出程序"<<endl;
        cin>>cm;
        if(cin.fail()){
            cout<<"输入格式有误。"<<endl;
            cin.clear();
            cin.sync();
            continue ;
        }
        if(cm==1){
            int type;
            cout<<"欲输出的类型为:(0.普通员工 1.销售人员 2.团队经理 3.ALL):";
            cin>>type;
            int cnt=0;
            for(int i=0;i<staffs.size();++i){
                if(type == 3 || staffs[i]->type==type){
                    staffs[i]->showStaff();
                    cout<<"===================="<<endl;
                    cnt++;
                }
            }
            cout<<"输出完成。共输出了"<<cnt<<"条数据。"<<endl;
        }else if(cm==2){
            int type;
            cout<<"欲添加的类型是(0.普通员工 1.销售人员 2.团队经理):";
            cin>>type;
            StaffBase* staff;
            if(type==0){
                staff = new Staff;
            }else if(type==1){
                staff = new Salesman;
            }else if(type==2){
                staff = new Manager;
            }
            staffs.push_back(staff);
            cout<<"添加员工完成。"<<endl;
        }else if(cm==3){
            int id;
            cout<<"欲修改的员工编号为:";
            cin>>id;
            for(int i=0;i<=staffs.size();++i){
                if(i==staffs.size()){
                    cout<<"没有找到这个 id 的员工。"<<endl;
                    break;
                }else{
                    if(staffs[i]->id==id){
                        staffs[i]->showStaff();
                        cout<<"欲修改的内容是:";
                        string tmp;
                        cin>>tmp;
                        staffs[i]->getAttr(tmp);
                        break;
                    }
                }
            }
        }else if(cm==4){
            int id;
            cout<<"欲删除的员工编号为:";
            cin>>id;
            vector<StaffBase*>::iterator it;
            for(it=staffs.begin();it!=staffs.end();it++){
                if((*it)->id == id){
                    delete (*it);
                    staffs.erase(it);
                    break;
                }
            }
            if(it==staffs.end()){
                cout<<"失败。没有找到 id 为"<<id<<"的员工。"<<endl;
            }else{
                cout<<"删除成功。"<<endl;
            }
        }else if(cm==5){
            int mode;
            cout<<"请输入要查询的信息:"<<endl;
            cout<<"0.以 id 为关键字查询"<<endl
                <<"1.以姓名为关键字查询"<<endl
                <<"2.以年龄为关键字查询"<<endl
                <<"3.以员工状态为关键字查询"<<endl
                <<"4.以销售额为关键字查询(仅限销售人员)"<<endl;
            cin>>mode;
            vector<StaffBase*>::iterator it;
            if(mode == 0){
                int id;
                cout<<"请输入欲查询的ID:";
                cin>>id;
                for(it=staffs.begin();it!=staffs.end();it++){
                    if((*it)->id == id){
                        (*it)->showStaff();
                        break;
                    }
                }
            }else if(mode == 1){
                string name;
                int cnt=0;
                cout<<"请输入欲查询的姓名:";
                cin>>name;
                for(it=staffs.begin();it!=staffs.end();it++){
                    if((*it)->name == name){
                        (*it)->showStaff();
                        cout<<"===================="<<endl;
                        cnt++;
                    }
                }
                cout<<"输出完成。共输出了"<<cnt<<"条数据。"<<endl;
            }else if(mode == 2){
                int age1,age2;
                int cnt=0;
                cout<<"请输入年龄范围(示例:7-20):";
                scanf("%d-%d",&age1,&age2);
                for(it=staffs.begin();it!=staffs.end();it++){
                    if((*it)->age >= age1 && (*it)->age <=age2){
                        (*it)->showStaff();
                        cout<<"===================="<<endl;
                        cnt++;
                    }
                }
                cout<<"输出完成。共输出了"<<cnt<<"条数据。"<<endl;
            }else if(mode == 3){
                string status;
                int cnt=0;
                cout<<"请输入员工状态(T/F):";
                cin>>status;
                for(it=staffs.begin();it!=staffs.end();it++){
                    if((*it)->status == (status=="T")){
                        (*it)->showStaff();
                        cout<<"===================="<<endl;
                        cnt++;
                    }
                }
                cout<<"输出完成。共输出了"<<cnt<<"条数据。"<<endl;
            }else if(mode == 4){
                int sales1,sales2;
                int cnt=0;
                cout<<"请输入销售额范围(示例:7-20):";
                scanf("%d-%d",&sales1,&sales2);
                for(it=staffs.begin();it!=staffs.end();it++){
                    if((*it)->type==1 && (*it)->getAttr("sales") >= sales1 && (*it)->getAttr("sales") <=sales2){
                        (*it)->showStaff();
                        cout<<"===================="<<endl;
                        cnt++;
                    }
                }
                cout<<"输出完成。共输出了"<<cnt<<"条数据。"<<endl;
            }
        }else if(cm==6){
            for(int i=0;i<staffs.size();++i){
                (*staffs[i])++;
            }
            cout<<"年龄更新成功。"<<endl;
        }else if(cm!=exitCode){
            cout<<"无效的指令。"<<endl;
        }
        system("pause");
    }while(cm!=exitCode);
    fstream outfile("data.txt",ios::out); //将数据写入到data文件中
    if(outfile.is_open()){
        for(int i=0;i<staffs.size();++i){
            outfile<<staffs[i]->id<<' '
                   <<staffs[i]->name<<' '
                   <<staffs[i]->age<<' '
                   <<staffs[i]->status<<' '
                   <<staffs[i]->type<<' ';
            if(staffs[i]->type==1){
                outfile<<staffs[i]->getAttr("sales")<<' ';
            }else if(staffs[i]->type==2){
                vector<StaffBase*> s = *staffs[i]->getManages();
                outfile<<s.size()<<' ';
                for(int i=0;i<s.size();++i){
                    outfile<<s[i]->id<<' ';
                }
            }
            if(i!=staffs.size()-1) outfile<<endl;
        }
        outfile.close();
    }else{
        cout<<"data.txt 文件不存在, 程序无法正常运行。"<<endl;
        return 0;
    }
    return 0;
}