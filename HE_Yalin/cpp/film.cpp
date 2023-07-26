#include "film.h"
#include <string>

Film::Film(string name, string path, int dure, int _chapitrenum, const int* _chapitredure):
    Video(name, path, dure)
{
    chapitrenum = _chapitrenum;
    chapitredure = new int[_chapitrenum];
    for(int i = 0; i< chapitrenum ; ++i)
        chapitredure[i]=_chapitredure[i];
}

void Film::modifier(const int *newchapdure, int newchapmun){
    chapitrenum = newchapmun;
    if(newchapdure){
        delete[] chapitredure;
        chapitredure = new int[newchapmun];
        for(int i = 0; i< newchapmun; ++i)
            chapitredure[i]=newchapdure[i];
    }else{
        if(chapitredure){
            delete[] chapitredure;
            chapitredure = nullptr;
        }
    }
}

Film::Film(const Film& from):Video(from){
    modifier(from.chapitredure,from.chapitrenum);
}

Film& Film::operator=(const Film& from){
    Video::operator=(from);
    modifier(from.chapitredure,from.chapitrenum);
    return *this;
}

int* Film::getChapitredure() const{
    int* chapitre2 =new int[chapitrenum];
    for(int i = 0; i< chapitrenum ; i++)
            chapitre2[i]= chapitredure[i];
    return chapitre2;
}


int Film::getChapnum() const{
    return chapitrenum;
}

void Film::affichage(ostream &s) const{
    Video::affichage(s);
    s << "The film has " << getChapnum() << " chapiters." << endl;
    s << "Chapiter durations: ";
    const int* table=getChapitredure();
    for(int i = 0 ; i < chapitrenum ; ++i)
        s << table[i] << ' ';
    s << endl;
};


Film::~Film(){
    delete[] chapitredure;
};
