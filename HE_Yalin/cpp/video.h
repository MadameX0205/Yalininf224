#ifndef VIDEO_H
#define VIDEO_H
#include <iostream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include "multimedia.h"

using namespace std;


class Video : public Multimedia
{
protected:
    int dure{};
public:

    Video(string _Name, string _Path, int _duration);
    //getters
    int getdure()const{return dure;}//les fonctions qui ne modifient pas les variables d'instances doivent etre const
    // setters
    void setdure(int _dure){dure= _dure;}

    //print
    void affichage(ostream& s)const override;

    //play
    void play() const override;

    //write
    void write(ostream& os)const override;

    //destructeur
    ~Video(){};
};

#endif // VIDEO_H
