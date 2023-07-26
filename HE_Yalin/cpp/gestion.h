#ifndef GESTION_H
#define GESTION_H

#include "multimedia.h"
#include "group.h"
#include "photo.h"
#include "video.h"
#include "film.h"

#include <string>
#include <memory>
#include <map>
#include <iostream>
#include <sstream>

using namespace std;
typedef std::shared_ptr<Photo> PhotoPtr;
typedef std::shared_ptr<Video> VideoPtr;
typedef std::shared_ptr<Film> FilmPtr;
typedef std::shared_ptr<Group> GroupPtr;
typedef std::shared_ptr <Multimedia> MultimediaPtr;
/**
* brief Class with two instances : an associative map of Multimedia objects and one of Groupe objects
*To prevent an object to be created outside the table there are two possibilities:
*either adding a pointer toward a Table in the Multimedia class and check if it is null or not
*or setting the constructors of the Video, Photo, Film as protected
*/
class Gestion
{
private:
   map<string, MultimediaPtr> multimediaMap;
   map<string, GroupPtr> groupeMap;

public:
    Gestion();

    PhotoPtr createPhoto(double _latitude, double _longitude,const string & _objectName, const string &_filePath);
    void createPhoto(PhotoPtr photo);

    VideoPtr createVideo(std::string const& _objectName,string const& _filePath, int _dure);
    void createVideo(VideoPtr video);

    FilmPtr createFilm(string const& _objectName, string const& _filePath, int _dure, int _chapitrenum, const int* _chapitredure);
    void createFilm(FilmPtr film);

    GroupPtr createGroup(string const& _groupName);
    void createGroup(GroupPtr group);

    /**
     * \brief rechercher un groupe et afficher son attribut avant de le renvoyer
     */
    GroupPtr findGroupe(string name, ostream &flux) const;


    /**
     * \brief rechercher un Multimedia et afficher son attribut avant de le retourner
     */

    MultimediaPtr findMultimedia(string name, ostream &flux) const;

    /**
     * \brief Play multimdeia file
     */
     //void play(string name);

    void play(const string& name , ostream& so)const;
    void eraseGroup(const string& name);
    void searchetaffichage(const string& name, ostream& outputStream) const;
};

#endif // GESTION_H
