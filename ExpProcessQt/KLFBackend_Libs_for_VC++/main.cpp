#include <QApplication>
#include <utility>
#include "mainwindow.h"
//#include "DataAccess.h"
//#include "TokenLibrary.h"

int main(int argc, char *argv[])
{
//    DataAccess* instance=DataAccess::getInstance();

//    TokenLibrary* tkl=TokenLibrary::getInstance();
//    //float t=clock();
//    pair<int, int> range=tkl->searchToken("s");
//    //cout<<"Query time: "<<(clock()-t)/CLOCKS_PER_SEC<<endl;

//    cout<<tkl->getToken(range.first)<<"  "<<tkl->getToken(range.second)<<endl;


    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    
    return a.exec();
}
