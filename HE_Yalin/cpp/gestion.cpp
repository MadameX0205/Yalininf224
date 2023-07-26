#include "gestion.h"

Gestion::Gestion()
{

}

PhotoPtr Gestion::createPhoto(double _latitude, double _longitude, const string &_objectName, const string &_filePath){
    //cout<<"Photo not created no problem"<<endl;
    PhotoPtr newPhoto = make_shared<Photo>(_latitude, _longitude, _objectName, _filePath);
    cout<<"Photo created no problem"<<endl;
    multimediaMap [newPhoto->getName()] = newPhoto;
        return newPhoto;
}

VideoPtr Gestion::createVideo(const std::string &_objectName, const string &_filePath, int _dure){
    VideoPtr newVideo = make_shared<Video>(_objectName, _filePath, _dure);
    multimediaMap [newVideo->getName()] = newVideo;
    return newVideo;
}

FilmPtr Gestion::createFilm(const string &_objectName, const string &_filePath, int _dure, int _chapitrenum, const int *_chapitredure){
    FilmPtr newFilm = make_shared<Film>(_objectName,_filePath,_dure,_chapitrenum,_chapitredure);
    multimediaMap [newFilm->getName()] = newFilm;
    return newFilm;
}

GroupPtr Gestion::createGroup(const string &_groupName){
    GroupPtr newGroup = make_shared<Group>(_groupName);
    groupeMap [_groupName] = newGroup;
    return newGroup;
}


void Gestion::createPhoto(PhotoPtr photo){
    multimediaMap [photo->getName()] = photo;
}

void Gestion::createVideo(VideoPtr video){
    multimediaMap [video->getName()] = video;
}

void Gestion::createFilm(FilmPtr film){
    multimediaMap [film->getName()] = film;
}

void Gestion::createGroup(GroupPtr group){
    groupeMap [group->getGroupName()] = group;
}

GroupPtr Gestion::findGroupe(string name, ostream &flux) const{
    auto it = groupeMap.find(name);
        if(it!=groupeMap.end()){
            it->second->affichage(flux);
            return it->second;
        }
        cout<<"Nothing matchs"<<endl;
        return nullptr;
}

MultimediaPtr Gestion::findMultimedia(string name, ostream &flux) const{
    auto it = multimediaMap.find(name);
        if(it!=multimediaMap.end()){
            it->second->affichage(flux);
            return it->second;
        }
        std::cout<<"Nothing matchs"<<std::endl;
        return nullptr;
}

void Gestion::searchetaffichage(const string &name, ostream &outputStream)const{
    auto it1 = groupeMap.find(name);
    auto it2 = multimediaMap.find(name);

    if (it1 != groupeMap.end()){
        (it1->second)->affichage(outputStream);
    }
    else if (it2 != multimediaMap.end()){
        (it2->second)->affichage(outputStream);
    }
    else{
        outputStream
        << "\nFound nothing for: " << name
        <<endl;
    }
}

void Gestion::play(const string& name, ostream& outputStream) const{
    auto it1 = multimediaMap.find(name);

    if (it1 != multimediaMap.end()){
        (it1->second)->play();
        outputStream
        << "\nPlaying: " << name
        <<endl;
    }
    else{
        outputStream
        << "\nFound nothing for: " << name
        <<endl;
    }
}

void Gestion::eraseGroup(const string& name) {
    auto it1 = groupeMap.find(name);

    if (it1 != groupeMap.end()){
        for (auto it = (it1->second)->begin(); it != (it1->second)->end(); ++it){
            it->reset();
        }
        groupeMap.erase(it1->first);
        (it1->second).reset();
    }
    else{
        cout
        << "\nFound nothing for: " << name
        <<endl;
    }
}

