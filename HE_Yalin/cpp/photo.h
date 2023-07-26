#ifndef PHOTO_H
#define PHOTO_H

#include "multimedia.h"
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

class Photo : public Multimedia{
private:
    double latitude{};
    double longitude{};

public:
    Photo(){};
    //destructeur
    ~Photo(){};
    Photo(double _latitude, double _longitude,string name, string path): Multimedia(name, path){
        latitude = _latitude;
        longitude = _longitude;
    };
    //getters
    double getlatitude()const{return latitude;}//les fonctions qui ne modifient pas les variables d'instances doivent etre const
    double getlongitude()const{return longitude;};

    // setters
    void setlatitude(double _latitude){latitude = _latitude;}
    void setlongitude(double _longitude){longitude = _longitude;}

    //print
    void affichage(ostream& s)const override;

    //play
    void play()const override;

    //write
    void write(ostream& os)const override;


};

#endif // PHOTO_H
