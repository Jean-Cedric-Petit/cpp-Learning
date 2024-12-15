#include <string>
#include <iostream>

class Person
{
private:
    int m_health;
    int m_defense;
    int m_attack;
    bool m_paralize;
    bool m_isDead;
    bool m_isDefending;
    bool m_isEvading;
    std::string m_name;
public:
    Person(std::string name,int attack,int defense, int health);
    virtual ~Person();
    void update();
    void attack(Person &target);
    void receiveDamage(int dmg);
    bool isDefending();
    bool isEvading();
    bool isAlive();
    void heal();
    void defend();
    void evade();
    void status();
};
