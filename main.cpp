#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main () {

    // Read in the options:
    std::ifstream teaser_options; 
    teaser_options.open("teaser_options.txt");
    std::vector<std::string> options_vect;
    std::string option;
    if ( teaser_options.is_open() ) {
        while( teaser_options.good() ){
            teaser_options >> option; // pipe file's content into stream
            options_vect.push_back(option); // pipe stream's content to standard output
        }
    }
    teaser_options.close();

    // Read in the results:
    std::ifstream teaser_results; 
    teaser_results.open("teaser_results.txt");
    std::vector<std::string> results_vect;
    std::string result;
    if ( teaser_results.is_open() ) {
        while( teaser_results.good() ){
            teaser_results >> result; // pipe file's content into stream
            results_vect.push_back(result); // pipe stream's content to standard output
        }
    }
    teaser_results.close();

    for(auto index = 0; index < 10; index++){
        std::cout << results_vect[index];
    }
}