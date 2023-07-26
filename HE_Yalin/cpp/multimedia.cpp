#include "multimedia.h"

using namespace std;

Multimedia::Multimedia(string _name, string _path)
{
    name = _name;
    path = _path;
}

string Multimedia::getName() const {
    return name;
}

string Multimedia::getPath() const {
    return path;
}

void Multimedia::setName(string _name){
    name = _name;
}

void Multimedia::setPath(string _path){
    path = _path;
}

void Multimedia::affichage(ostream &s) const{
    s << "Fiche name: " << name << " " << "path:" << path << endl;
}

void Multimedia::write(ostream &os) const{
    os << getName() << endl;
    os << getPath() << endl;
}
