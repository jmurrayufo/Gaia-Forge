
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

// Print out an entire property tree (child nodes are indented!)
void print(boost::property_tree::ptree const& pt,int indent)
{
    using boost::property_tree::ptree;
    ptree::const_iterator end = pt.end();
    for (ptree::const_iterator it = pt.begin(); it != end; ++it) {
        for(int i = 0;i<indent;i++)
            cout << "    ";
        std::cout << it->first << ": " << it->second.get_value<std::string>() << std::endl;
        print(it->second,indent+1);
    }
}