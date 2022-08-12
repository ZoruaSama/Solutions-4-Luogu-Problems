#include <iostream>
#include <fstream>
#include <vector>
#include <cstdio>

using namespace std;
string type_to_string(int); //���������type���intת��Ϊʵ�ʵ�Ա������
int total_id=0; //���������Ա�������ʼ���
class StaffBase{//Ϊ��ʵ�ֶ�̬�Ļ���  ���е��麯������������
public:
    int id;      //Ա���ı��
    string name;    //Ա������
    int age;    //Ա������
    bool status; //Ա��״̬
    int type; //Ա������
    string inPosition(); //���������status���bool����ת��Ϊ�ַ���
    void operator++(){ //��������� ����������1��
        age++;
    }
    void operator++(int){
        age++;
    }
    virtual void showStaff(){ };//��ʾԱ������Ϣ
    virtual void addManages(int){ };//����Ա�����������Ա
    virtual void delManages(int){ };//ɾ��Ա�����������Ա
    virtual int numOfManages(){ return 0; };//����Ա�����������Ա����
    virtual void outputManages(){ };//���Ա�����������Ա����Ϣ
    virtual vector<StaffBase*>* getManages(){ return NULL; };//����Ա�����������Ա�б�
    virtual int getAttr(const string&){ return 0; };//��ȡĳ������(�����޸�/��ȡ����)

};
string StaffBase::inPosition() { //���������status���bool����ת��Ϊ�ַ���
        return (status ? "��ְ":"��ְ");
}

vector<StaffBase*> staffs; //���ڴ��[StaffBase�����ĵ�ַ]��һ��vector�б�
class Staff:public StaffBase{
public:
    Staff();
    Staff(int,string,int,bool,int);
    void setStaff();
    void showStaff();
    int getAttr(const string& name);
};
Staff::Staff(){ //�������캯����Ĭ�Ϲ��캯�����ֶ�������Ϣ�ģ������Ǹ����캯���Ǵ��ļ��ж�ȡʱ�õ�
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
    cout<<"������Ա������:";
    cin>>name;
    cout<<"������Ա������:";
    cin>>age;
    while(cin.fail()){
        cout<<"�����ʽ����"<<endl;
        cin.clear();
        cin.sync();
        cin>>age;
    }
    cout<<"������Ա����ְ״̬(T/F):";
    string temp;
    cin>>temp;
    status = (temp == "T");
}
void Staff::showStaff(){
    cout<<"0.Ա�����:"<<id<<endl;
    cout<<"1.Ա������:"<<name<<endl;
    cout<<"2.Ա������:"<<age<<endl;
    string temp;
    cout<<"3.��ְ״̬:"<<inPosition()<<endl;
    cout<<"4.Ա������:"<<::type_to_string(type)<<endl;
}
int Staff::getAttr(const string& _name) {
    if(_name=="0"){
        cout<<"�޷��޸�Ա����š�"<<endl;
        return 0;
    }else if(_name == "1"){
        cout<<"������Ա������:";
        cin>>name;
    }else if(_name == "2"){
        cout<<"������Ա������:";
        cin>>age;
        while(cin.fail()){  //��������ʽ�Ƿ�������
            cout<<"�����ʽ����"<<endl;
            cin.clear();
            cin.sync();
            cin>>age;
        }
    }else if(_name == "3"){
        cout<<"������Ա����ְ״̬(T/F):";
        string temp;
        cin>>temp;
        status = (temp == "T");
    }else if(_name == "4"){
        cout<<"�޷�ֱ���޸�Ա�����͡�"<<endl;
    }
}

class Salesman : public Staff{
public:
    int sales; //���۶�
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
    cout<<"������Ա�����۶�:";
    cin>>sales;
    while(cin.fail()){
        cout<<"�����ʽ����"<<endl;
        cin.clear();
        cin.sync();
        cin>>sales;
    }
}

void Salesman::showStaff() {
    Staff::showStaff();
    cout<<"5.���۶�:"<<sales<<endl;
}

int Salesman::getAttr(const string& _name) {
    Staff::getAttr(_name);
    if(_name=="5"){
        int mode;
        cout<<"0. ֱ���޸�"<<endl
            <<"1. ��������"<<endl;
        cout<<"��ѡ���޸�ģʽ:";
        cin>>mode;
        if(mode==0){
            cout<<"������Ա�����۶�:";
            cin>>sales;
            while(cin.fail()){
                cout<<"�����ʽ����"<<endl;
                cin.clear();
                cin.sync();
                cin>>sales;
            }
        }else if(mode == 1){
            int _sales;
            cout<<"�������޸���:";
            cin>>_sales;
            while(cin.fail()){
                cout<<"�����ʽ����"<<endl;
                cin.clear();
                cin.sync();
                cin>>_sales;
            }
            sales += _sales;
        }else{
            cout<<"�����˴����ģʽ��"<<endl;
        }

        return 0;
    }
    if(_name=="sales"){
        return sales;
    }
}
class Manager:public Staff{
public:
    vector<StaffBase*> manages; // �����������Ա����
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
    cout<<"���������ı��(����0����ֹ):";
    int num;
    do{
        cin>>num;
        while(cin.fail()){
            cout<<"�����ʽ����"<<endl;
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
    cout<<"5.������Ա:"<<endl;
    outputManages();
}
int Manager::getAttr(const string& _name){
    Staff::getAttr(_name);
    if(_name=="5"){
        cout<<"��ɾ����Ա�ڱ��ǰ���һ��'-'��, �������Աֱ�������š�����0��ֹ��"<<endl;
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
    cout<<"���ʧ�ܡ�û���ҵ� id Ϊ"<<num<<"��Ա����"<<endl;
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
        cout<<"ɾ��ʧ�ܡ�û���ҵ� id Ϊ"<<num<<"��Ա����"<<endl;
    }
}
int Manager::numOfManages() {
    return (int)manages.size();
}
vector<StaffBase *>* Manager::getManages() {
    return &manages; //��ȡmanages�б�ĵ�ַ������
}

void Manager::outputManages() {
    for(int i=0;i<manages.size();++i){
        cout<<staffs[i]->id<<':'
            <<staffs[i]->name<<'('
            <<staffs[i]->age<<')'<<"   "
            <<staffs[i]->inPosition()<<"��"
            <<type_to_string(staffs[i]->type)<<' '<<endl;
    }
    cout<<"����"<<numOfManages()<<"����������Ա��"<<endl;
}

string type_to_string(int type){
    if(type==0){
        return "��ͨԱ��";
    }else if(type==1){
        return "������Ա";
    }else if(type==2){
        return "�ŶӾ���";
    }else{
        return "???";
    }
}
int main() {
    int cm;
    const int exitCode = 7; //���������ǵ����˳�����ѡ��Ĵ���
    fstream file("data.txt");  //��data�ļ��ж�ȡ����
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
        cout<<"data.txt �ļ�������, �����޷��������С�"<<endl;
        return 0;
    }
    do{
        cout<<"Ա������ϵͳ������������Ҫ�Ĺ��ܱ��"<<endl;
        cout<<"1. �����Ϣ"<<endl;
        cout<<"2. �����Ϣ"<<endl;
        cout<<"3. �޸���Ϣ"<<endl;
        cout<<"4. ɾ����Ϣ"<<endl;
        cout<<"5. ��ѯ��Ϣ"<<endl;
        cout<<"6. ��������"<<endl;
        cout<<"7. �˳�����"<<endl;
        cin>>cm;
        if(cin.fail()){
            cout<<"�����ʽ����"<<endl;
            cin.clear();
            cin.sync();
            continue ;
        }
        if(cm==1){
            int type;
            cout<<"�����������Ϊ:(0.��ͨԱ�� 1.������Ա 2.�ŶӾ��� 3.ALL):";
            cin>>type;
            int cnt=0;
            for(int i=0;i<staffs.size();++i){
                if(type == 3 || staffs[i]->type==type){
                    staffs[i]->showStaff();
                    cout<<"===================="<<endl;
                    cnt++;
                }
            }
            cout<<"�����ɡ��������"<<cnt<<"�����ݡ�"<<endl;
        }else if(cm==2){
            int type;
            cout<<"����ӵ�������(0.��ͨԱ�� 1.������Ա 2.�ŶӾ���):";
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
            cout<<"���Ա����ɡ�"<<endl;
        }else if(cm==3){
            int id;
            cout<<"���޸ĵ�Ա�����Ϊ:";
            cin>>id;
            for(int i=0;i<=staffs.size();++i){
                if(i==staffs.size()){
                    cout<<"û���ҵ���� id ��Ա����"<<endl;
                    break;
                }else{
                    if(staffs[i]->id==id){
                        staffs[i]->showStaff();
                        cout<<"���޸ĵ�������:";
                        string tmp;
                        cin>>tmp;
                        staffs[i]->getAttr(tmp);
                        break;
                    }
                }
            }
        }else if(cm==4){
            int id;
            cout<<"��ɾ����Ա�����Ϊ:";
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
                cout<<"ʧ�ܡ�û���ҵ� id Ϊ"<<id<<"��Ա����"<<endl;
            }else{
                cout<<"ɾ���ɹ���"<<endl;
            }
        }else if(cm==5){
            int mode;
            cout<<"������Ҫ��ѯ����Ϣ:"<<endl;
            cout<<"0.�� id Ϊ�ؼ��ֲ�ѯ"<<endl
                <<"1.������Ϊ�ؼ��ֲ�ѯ"<<endl
                <<"2.������Ϊ�ؼ��ֲ�ѯ"<<endl
                <<"3.��Ա��״̬Ϊ�ؼ��ֲ�ѯ"<<endl
                <<"4.�����۶�Ϊ�ؼ��ֲ�ѯ(����������Ա)"<<endl;
            cin>>mode;
            vector<StaffBase*>::iterator it;
            if(mode == 0){
                int id;
                cout<<"����������ѯ��ID:";
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
                cout<<"����������ѯ������:";
                cin>>name;
                for(it=staffs.begin();it!=staffs.end();it++){
                    if((*it)->name == name){
                        (*it)->showStaff();
                        cout<<"===================="<<endl;
                        cnt++;
                    }
                }
                cout<<"�����ɡ��������"<<cnt<<"�����ݡ�"<<endl;
            }else if(mode == 2){
                int age1,age2;
                int cnt=0;
                cout<<"���������䷶Χ(ʾ��:7-20):";
                scanf("%d-%d",&age1,&age2);
                for(it=staffs.begin();it!=staffs.end();it++){
                    if((*it)->age >= age1 && (*it)->age <=age2){
                        (*it)->showStaff();
                        cout<<"===================="<<endl;
                        cnt++;
                    }
                }
                cout<<"�����ɡ��������"<<cnt<<"�����ݡ�"<<endl;
            }else if(mode == 3){
                string status;
                int cnt=0;
                cout<<"������Ա��״̬(T/F):";
                cin>>status;
                for(it=staffs.begin();it!=staffs.end();it++){
                    if((*it)->status == (status=="T")){
                        (*it)->showStaff();
                        cout<<"===================="<<endl;
                        cnt++;
                    }
                }
                cout<<"�����ɡ��������"<<cnt<<"�����ݡ�"<<endl;
            }else if(mode == 4){
                int sales1,sales2;
                int cnt=0;
                cout<<"���������۶Χ(ʾ��:7-20):";
                scanf("%d-%d",&sales1,&sales2);
                for(it=staffs.begin();it!=staffs.end();it++){
                    if((*it)->type==1 && (*it)->getAttr("sales") >= sales1 && (*it)->getAttr("sales") <=sales2){
                        (*it)->showStaff();
                        cout<<"===================="<<endl;
                        cnt++;
                    }
                }
                cout<<"�����ɡ��������"<<cnt<<"�����ݡ�"<<endl;
            }
        }else if(cm==6){
            for(int i=0;i<staffs.size();++i){
                (*staffs[i])++;
            }
            cout<<"������³ɹ���"<<endl;
        }else if(cm!=exitCode){
            cout<<"��Ч��ָ�"<<endl;
        }
        system("pause");
    }while(cm!=exitCode);
    fstream outfile("data.txt",ios::out); //������д�뵽data�ļ���
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
        cout<<"data.txt �ļ�������, �����޷��������С�"<<endl;
        return 0;
    }
    return 0;
}