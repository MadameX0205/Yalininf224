//
// main.cpp
//
#include <memory>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>

#include "multimedia.h"
#include "video.h"
#include "photo.h"
#include "film.h"
#include "gestion.h"
#include "group.h"
#include "tcpserver.h"

using namespace std;

const int PORT = 3331;

Gestion* myGestion = new Gestion();

stringstream requestprocess(const string& request);
stringstream search(string name);
stringstream play(string name);


int main(int argc, const char* argv[])
{
    //std::cout << "Hello brave new world" << std::endl;
    /*Test for etape 3
        Multimedia *multimedia = new Multimedia("video","/cal/homes/yahe/Desktop/inf224");
        multimedia->affichage(std::cout);
        delete multimedia;*/

   /*test for etape 4
    Photo *p = new Photo(10.0,20.0,"wangyibo","/cal/homes/yahe/Desktop/inf224/photo/wangyibo.jpeg");
    p->affichage(std::cout);
    p->play(); // affichier la photo
    p->write(std::cout);
    delete p;*/

    /* etape 5 Traitement uniforme(en utilisant le polymorphisme)
    Multimedia** multimedia=new Multimedia* [2];
    unsigned int num=0;
    multimedia[num++]=new Photo(10.0,20.0,"wangyibo","/cal/homes/yahe/Desktop/inf224/photo/wangyibo.jpeg");
    multimedia[num++]=new Video("tavail","/cal/homes/yahe/Desktop/inf224/photo/travail.mp4",2);
    ofstream info("test5.txt");

    if (info){
        for (int i =0; i<2 ;i++){
        multimedia[i]->play();
        multimedia[i]->affichage(info);
        delete multimedia[i];
        }
     }

    delete multimedia[0];
    delete multimedia[1];*/

    /* etape 6
    int* tab=new int[2];
    tab[0]=5;
    tab[1]=6;
    Film *movie=new Film("tavail","/cal/homes/yahe/Desktop/inf224/photo/travail.mp4",11,2,tab);
    ofstream test6("text61.txt");
    if(test6)movie->affichage(test6);
    cout<<"Nombre de chapitre: "<<movie->getChapnum()<<endl;
    const int *durationOld=movie->getChapitre();
    cout<<"Duree des chapitres: ";
    for(int i=0;i<2;++i){
       cout<<durationOld[i]<<' ';
    }
    cout<<endl;
    delete[] tab;
    tab=nullptr;
    delete[] durationOld;
    durationOld=nullptr;
    tab=new int[2]();
    tab[0]=52;
    tab[1]=70;
    movie->modifier(tab,2);
    cout<<"Nombre de chapitre: "<<movie->getChapnum()<<endl;
    const int* durationNew=movie->getChapitre();
    cout<<"Duree des chapitres: ";
    for(int i=0;i<2;++i){
    cout<<durationNew[i]<<' ';
    }
     cout<<endl; */



    /**************************************************Client-server****************************************************************/

    PhotoPtr boy = myGestion->createPhoto(10.0,20.0,"boy","./content/boy.jpeg");
    PhotoPtr TinTin = myGestion->createPhoto(10.0,20.0,"TinTin","./content/TinTin.png");
    VideoPtr travail = myGestion->createVideo("travail","./content/travail.mp4",11);

    GroupPtr people = myGestion->createGroup("People");
    people->push_back(boy);
    people->push_back(TinTin);
    people->push_back(travail);

   // myGestion->searchAndDisplay("boy", cout);
   // myGestion->play("boy", cout);
    //myGestion->play("Soleil");

    //SERVER
        // cree le TCPServer
    // cree le TCPServer
    auto* server =
    new TCPServer( [&](std::string const& request, std::string& response) {

      // the request sent by the client to the server
      //std::cout << "request: " << request << std::endl;

      stringstream streamResponse = requestprocess(request);
      string final{};
      string temp{};

      while(getline(streamResponse, temp)){
            final += temp+";";
      }

      response = final;

      // the response that the server sends back to the client
      //response = "RECEIVED: " + request;


      // return false would close the connecytion with the client
      return true;
    });


    // lance la boucle infinie du serveur
    std::cout << "Starting Server on port " << PORT << std::endl;

    int status = server->run(PORT);

    // en cas d'erreur
    if (status < 0) {
      std::cerr << "Could not start Server on port " << PORT << std::endl;
      return 1;
    }

   return 0;
}

/*****************************************************************************************/
/**
 * @brief requestprocess
 * Cette methode est appelee chaque fois lorsqu'il y a une requete a traiter.
 * @param request
 * @return
 */
stringstream requestprocess(const string& request){

    stringstream stream;
    stream << request << endl;

    string requestName, requestDetails;
    stream >> requestName >> requestDetails;

    cout << "This processe is : " << requestName << " and the fiche name is: " << requestDetails <<endl;

    stringstream streamToReturn;

    if (requestName=="search"){
        streamToReturn = search(requestDetails);
    } else if (requestName=="play"){
        streamToReturn = play(requestDetails);
    } else {
        streamToReturn << "\nUnknown request: " << requestName <<endl;
    }

    return streamToReturn;

}

stringstream search(string name){

    stringstream stream;
    myGestion->searchetaffichage(name, stream);

    return stream;
}

stringstream play(string name){

    stringstream stream;
    myGestion->play(name, stream);

    return stream;
}
