#include <getopt.h>
#include <string>
#include <stdio.h>
#include <iostream>
#include <fstream>


namespace gaunt_parser {
    int parser(int argc, char **argv){
       

        int start;
        int get;
        int sync;
        int tidy;
        char *startValue = NULL;
        char *getValue = NULL;
        char *syncValue = NULL;
        char *tidyValue = NULL;
        int index;

        opterr = 0;

        while((get = getopt(argc, argv, "s:g:")) != -1){
            switch(get){
                case 's':
                    startValue = optarg;
                    if (startValue == NULL || startValue[0] == '\0') {
                        std::ofstream outFile; // FIXME: Fix outFile, not currently working 
                        outFile.open("gaunt.mod", std::ios::out);
                        outFile << "module gaunt" << std::endl;
                        outFile.close();
                    }else{
                        std::cout << "This doesn't require an argument, default is gaunt.mod" << std::endl;
                    }
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
                    if(optopt == 'g'){
                        std::cout << stderr << "Option -" << optopt << " requires an argument." << std::endl;
                    }
                    else if(isprint(optopt)){
                        std::cout << stderr << "Unknown option `-" << optopt << "'." << std::endl;
                    }
                    else{
                        std::cout << stderr << "Unknown option character `\\x" << optopt << "'." << std::endl;
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