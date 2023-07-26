#include "photo.h"

void Photo::play()const{
    system(("imagej " + getPath() + " &").c_str());
}

void Photo::write(ostream& os)const{
    os << "Photo\n";
    os << "Name:" << getName() << endl;
    os << "Path:" << getPath() << endl;
    os << "Latitude:" << getlatitude() << endl;
    os << "Longitude:" << getlongitude()<<endl;

}

void Photo::affichage(ostream& s)const{
    Multimedia::affichage(s);
    s << "Photo's width : " << getlatitude()
      << "\nPhoto's length : " << getlongitude( )<< " ";
}
