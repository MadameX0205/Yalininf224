#ifndef MULTIMEDIA_H
#define MULTIMEDIA_H

#include <string>
#include <iostream>

using namespace std;


class Multimedia
{
protected:
    // instance variables
    string name{};
    string path{};

public:
    // constructeurs
    Multimedia();  //sans argument
    Multimedia(string _name, string _path); //avec argument

    //getters
    string getName()const; //les fonctions qui ne modifient pas les variables d'instances doivent etre const
    string getPath()const;

    // setters
    void setName(string _name);
    void setPath(string _path);

    //destructeur
    virtual ~Multimedia(){};

    //méthode d'affichage:afficher la valeur des variables de l'objet
    virtual void affichage(ostream& s)const;

    //play: chaque type d'objet nécessite un programme différent pour etre joué
    virtual void play() const = 0; //etape 4 methode abstraite / virtuelle pure

    //write
    virtual void write(ostream& os)const;

};

#endif // MULTIMEDIA_H
