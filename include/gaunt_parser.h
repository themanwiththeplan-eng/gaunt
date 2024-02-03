#include <getopt.h>
#include <string>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include "gaunt_include.h"

using namespace gaunt_include;

namespace gaunt_parser {
    int parser(int argc, char **argv){
        std::ofstream file("gaunt.mod");
       

        int get;
        int sync;
        int tidy;
        int mod;
        char *getValue = NULL;
        char *syncValue = NULL;
        char *modValue = NULL;
        char *tidyValue = NULL;
        int index;


        opterr = 0;

        // TODO: implement the -g, -t, and -y options
        while((get = getopt(argc, argv, "s:g:t:y")) != -1){
            switch(get){
                case 's':
                    modValue = (optarg);
                    file;
                    file << "mod "<< modValue << std::endl;
                    file.close();
                    break;
                case 'g':
                    getValue = (optarg);
                    break;
                    // implemented for tidy
                case 't':
                    break;
                    // implemented for sync
                case 'y':
                    break;
                
                case '?':
                    if(optopt == 'g' || optopt == 's'){
                        std::cout << stderr << "Option -" << optopt << " requires an argument." << std::endl;
                    }
                    
                    return 1;
                default:
                    abort();
            }
        }
       for (int index = optind; index < argc; index++){
            std::cout << "Non-option argument " << argv[index] << std::endl;
        }  
        
        return 0;
    };
}