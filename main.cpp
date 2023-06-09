# include <iostream>
# include <memory>

using namespace std;

class BaseAdaptee
{
public:
virtual ~BaseAdaptee() = default;

virtual void specificRequest() = 0;
};

class ConAdaptee : public BaseAdaptee
{
public:
    void specificRequest() override { cout << "Method ConAdaptee;" << endl; }
};

class ConAdapteeA : public BaseAdaptee
{
public:
    void specificRequest() override { cout << "we was here" << endl; }
};

class Adapter
{
public:
    virtual ~Adapter() = default;
    virtual void request() = 0;
};

class ConAdapter : public Adapter
{
private:
    shared_ptr<BaseAdaptee>  adaptee;
public:
    ConAdapter(shared_ptr<BaseAdaptee> ad) : adaptee(ad) {}

    void request() override;
};


void ConAdapter::request()
{
    cout << "Adapter: ";

    if (adaptee)
    {
        adaptee->specificRequest();
    }
    else
    {
        cout << "Empty!" << endl;
    }
}

int main()
{
shared_ptr<BaseAdaptee> adaptee = make_shared<ConAdapteeA>();
shared_ptr<Adapter> adapter = make_shared<ConAdapter>(adaptee);

adapter->request();
}





//#include <iostream>

//using namespace std;
//enum TypeEnemy
//{
//    Hard,
//    Easy
//};

//class Enemy
//{
//private:
//    int damage_;
//    int attack_range_;
//    string typeEnemy_;

//public:
//    Enemy(int damgae, int attack_range, string typeEnemy):damage_(damgae), attack_range_(attack_range), typeEnemy_(typeEnemy){}
//    void getAllStats(){ cout << "       class: " << typeEnemy_ << "\n      damage: " << damage_ << "\nattack range: " << attack_range_ << endl; }
//};

//class EnemyFactory{
//public:
//    virtual Enemy getEnemy() = 0;
//};

//class Archer:public EnemyFactory
//{
//private:
//    int damage_;
//    int attackRange_;

//    void getStats(TypeEnemy type)
//    {
//        switch (type) {
//        case Hard:
//            damage_ = 13;
//            attackRange_ = 380;
//            break;

//        case Easy:
//            damage_ = 7;
//            attackRange_ = 220;
//            break;
//        }
//    }

//public:
//    Archer(TypeEnemy type) { getStats(type); }
//    Enemy getEnemy() override { return Enemy(damage_, attackRange_, "Archer"); }
//};


//class Sworder:public EnemyFactory{
//private:
//    int damage_;
//    int attackRange;

//    int getStats(TypeEnemy type)
//    {
//        int result = -1;

//        switch (type) {
//        case Hard:
//            damage_ = 23;
//            attackRange = 20;
//            break;
//        case Easy:
//            damage_ = 8;
//            attackRange = 20;
//            break;
//        }

//        return result;
//    }

//public:
//    Sworder(TypeEnemy type) { getStats(type); }
//    Enemy getEnemy() override { return Enemy(damage_, attackRange, "Sworder"); }
//};

//int main()
//{
//    Sworder Sworder(Hard);
//    EnemyFactory Archer{Sworder};
//    EnemyFactory* archerFactory = new Archer(Hard);
//    Enemy archer = archerFactory->getEnemy();
//    archer.getAllStats();
//}
