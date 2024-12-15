#include "Person.hpp"

Person::Person(std::string name,int attack,int defense, int health){
    m_name = name;
    m_attack = attack;
    m_defense = defense;
    m_health = health;
    m_paralize = false;
    m_isDead = false;
    m_isDefending = false;
}

Person::~Person(){}


void Person::update(){
    m_isEvading=false;    
}

void Person::attack(Person &target){
    if(m_paralize || m_isDefending){
        std::cout << m_name << " cannot attack right now!" << std::endl;
        m_paralize=false;
        m_isDefending=false;
        return;
    }
    if(target.isDefending()){
        std::cout << m_name << " is currently defending!" << std::endl;
        m_paralize=true;
        return;
    }
    if(target.isEvading()){
        std::cout << " The ennemy evaded "<< m_name <<"'s attack!" << std::endl;
        return;
    }
    std::cout << m_name << " attacks!" << std::endl;
    target.receiveDamage(m_attack);
}

void Person::receiveDamage(int dmg){
    int totaldmg = dmg - m_defense;
    if (totaldmg <= 0){
        totaldmg=1;
    }
    m_health -= totaldmg;

    if (m_health<=0)
    {
        m_isDead = true;
        m_health=0;
    }
    
}
bool Person::isAlive(){
    return !m_isDead;
}
bool Person::isDefending(){
    return m_isDefending;
}
void Person::heal(){
    m_health+=10;
}
void Person::defend(){
    m_isDefending=true;
}
void Person::evade(){
     m_isEvading=true;
}

bool Person::isEvading(){
   return m_isEvading;
}

void Person::status(){
    std::cout << m_name << " has " << m_health << "HP and is" << (m_isDefending?" defending":" not defending") << " and is" << (m_isEvading?" evading":" not evading") << " and is" << (m_paralize?" paralized":" not paralized") << "." << std::endl;
}