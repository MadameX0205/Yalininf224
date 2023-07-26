#ifndef FILM_H
#define FILM_H

#include "video.h"
#include <string>

class Film:public Video
{
//mettre les attributs de Film à private (ou protected).
private:
    //friend class Gestion;
    int* chapitredure = nullptr;
    int chapitrenum;

public:
    Film(string name, string path, int dure, int _chapitrenum, const int* _chapitredure);

    //copie constructeur et operateur=
    Film(const Film&);
    Film& operator=(const Film& );

    //modifieur
    void modifier(const int* newchapdure, const int newchapmun);


    //return le tableau de duree
    int* getChapitredure() const;

    //return le nombre de chapitre
    int getChapnum() const;

    void affichage(ostream& s)const override;

    //on a besoin d'un destructeur qui libérera la mémoire allouée avant la destruction de l'objet.
    virtual ~Film() override;

};

#endif // FILM_H
