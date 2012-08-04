
#include <ostream>
#include <string>
#include <stdio.h>
#include <SDL.h>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include "capp/CApp.h"

using namespace std;

//Johns Test comment
//==============================================================================
int main(int argc, char* argv[]) {
    using boost::property_tree::ptree;
    using namespace boost::property_tree::json_parser;
    ptree pt;

    read_json("test.json", pt);

    cout << pt.get("test","What Happened?") << endl; 
    cout << pt.get("test1.item1","What Happened?") << endl;
    cout << pt.get("test1.item1","What Happened?") << endl;
    pt.add("test1.item2",3.14f);
    pt.add("1.2.3.4.5",6);
    pt.add("test1.item2",3.14f);

    write_json("test2.json", pt);



    CApp theApp;
    fprintf(stdout,"Booted main()\n   %s:%d\n",__FILE__,__LINE__);
    return theApp.OnExecute();
}
//==============================================================================
