#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <fstream>

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

    // Read in the results:
    std::ifstream teaser_results; 
    teaser_results.open("teaser_results.txt");
    std::vector<std::string> possible_results = options_vect;
    std::vector<std::string> elements_to_erase;
    std::vector<std::string> end_results;

    std::string trial_line;
    std::string result_line;

    if ( teaser_results.is_open() ) {
        while ( teaser_results ) {
            std::getline (teaser_results, trial_line); // trial line
            if( "" != trial_line ){   // Was not an empty line, which means starting a trial
                std::getline (teaser_results, result_line); // result line
                for( auto i = 0; i < 5; i++ ){  // get five characters
                    auto mychar = result_line[i];
                    if( mychar == 'o' ){
                        // get items that do not have myChar at this position
                        for(auto item: options_vect){
                            if(item[i] != trial_line[i]){
                                elements_to_erase.push_back(item);
                            }
                        }
                        
                    }else if( mychar == 'x' ){
                        // get items that do not contain myChar or they do but at this exact location
                        for(auto item: options_vect){
                            if(item.find(trial_line[i]) == std::string::npos){
                                elements_to_erase.push_back(item);
                            }else if(item[i] == trial_line[i]){
                                elements_to_erase.push_back(item);
                            }
                        }
                    }else{
                        // get items contain this character
                        for(auto item: options_vect){
                            if(item.find(trial_line[i]) != std::string::npos){
                                elements_to_erase.push_back(item);
                            }
                        }
                    }
                }
                for(auto er: elements_to_erase){
                    auto it = std::remove(possible_results.begin(), possible_results.end(), er);
                }
                
            }else{
                end_results.push_back(possible_results[0]);   // Add the remainder of options
                elements_to_erase.clear();
                possible_results = options_vect;
            }
        }
    }

    for(auto result : end_results){
        std::cout << result << ",";
    }
}