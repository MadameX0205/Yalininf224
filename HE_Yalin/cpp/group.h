#ifndef GROUP_H
#define GROUP_H

#include "multimedia.h"
#include <list>
#include <string>
#include <memory>

using MultimediaPtr = std::shared_ptr<Multimedia>;  //Q9
// typedef Multimedia* T; //Q8

class Group : public list<MultimediaPtr>
{
private:
    string groupName = "";
public:
    //constructeur
    Group(){}

    Group( string _groupName ):list< shared_ptr<Multimedia> >(){groupName = _groupName;};

    //accesseur qui renvoie le nom du groupe
    const string getGroupName() const {return groupName;}
    void setName(string _name);

    //Q8 méthode d'affichage qui affiche les attrributs de tous les objets de la liste.
    void affichage(ostream &s);

    void play();

     ~Group(){}

};

#endif // GROUP_H
