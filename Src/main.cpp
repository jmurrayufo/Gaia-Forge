
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
    ptree pt;

    boost::property_tree::json_parser::read_json((std::string)"test.json",pt);

    cout << pt.get("test","What Happened?") << endl; 
    cout << pt.get("test1","What Happened?") << endl;

    CApp theApp;
    fprintf(stdout,"Booted main()\n   %s:%d\n",__FILE__,__LINE__);
    return theApp.OnExecute();
}
//==============================================================================
