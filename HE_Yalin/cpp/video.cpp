#include "video.h"

Video::Video(string _Name, string _Path, int _duration) :Multimedia(_Name, _Path)
{
       dure = _duration;
}

void Video::play()const{
    system(("mpv " + getPath() + " &").c_str());
}

void Video::write(ostream& os)const{
    os << "Video\n";
    os << "Name:" << getName() << endl;
    os << "Path:" << getPath() << endl;
    os << "Duration:" << getdure() << endl;
}

void Video::affichage(ostream& s)const{
    Multimedia::affichage(s);
    s << "Video's duration : " << getdure() << " ";
}


