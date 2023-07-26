#include "group.h"

void Group::setName(string _name){
    groupName = _name;
}

void Group::affichage(ostream &s){
    s << groupName << endl;
    for (Group :: iterator it = this-> begin(); it != this->end(); it++){
          (*it)->affichage(s);
        }
    }

 void Group::play(){
        for (Group :: iterator it = this-> begin(); it != this->end(); it++){
            (*it)->play();
        }
    }
