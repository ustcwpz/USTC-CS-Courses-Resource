
#include <iostream>
#include <fstream>
#include <rapidjson/prettywriter.h>
#include <rapidjson/stringbuffer.h>

#include <c1recognizer/recognizer.h>

#include "syntax_tree_serializer.hpp"

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "Usage: c1r_test <input>." << std::endl;
        return -1;
    }

    std::ifstream input(argv[1]);
    c1_recognizer::recognizer rcg(input);
    c1_recognizer::error_reporter reporter(std::cerr);

    if (!rcg.execute(reporter))
        return 1;

    std::shared_ptr<c1_recognizer::syntax_tree::syntax_tree_node> ast = rcg.get_syntax_tree();

    rapidjson::StringBuffer s;
    rapidjson::PrettyWriter<decltype(s)> writer(s);
    c1_recognizer::syntax_tree::syntax_tree_serializer<decltype(writer)> serializer(writer);
    serializer.serialize(*ast);

    std::cout << s.GetString() << std::endl;
    return 0;
}
