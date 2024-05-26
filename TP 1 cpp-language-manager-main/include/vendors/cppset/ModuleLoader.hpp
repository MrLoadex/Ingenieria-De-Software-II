/**
* Copyright (c) 2022 Gabriel Nicolás González Ferreira. All rights reserved.
* This file is part of CPPSET tools.
* Released under the MIT license
* https://opensource.org/licenses/MIT
**/

#ifndef MODULE_LOADER_HPP
#define MODULE_LOADER_HPP

#ifndef __DEBUG__
    #define __DEBUG__
#endif

#include <string>
#include <iostream>
#include <SharedLibraryLoader.hpp>

using namespace std;

class ModuleLoader
{
    private:
        SharedLibraryLoader* libraryLoader;
        bool isLoaded;

        void showError(string message, string message2 = "")
        {
            cerr << message << ' ' << message2 << endl;
            exit(EXIT_FAILURE);
        }        
    
    public:
        ModuleLoader()
        {
            #ifdef __DEBUG__
                cout << "create ModuleLoader..." << endl << endl;
            #endif // __DEBUG__

            libraryLoader = new SharedLibraryLoader;
        }
        /**
         * @brief Construct a new Module Loader object
         * with parameter const char* to able the syntax
         * ModuleLoader ml = "./path/to/library" 
         * 
         * @param filePath 
         */
        ModuleLoader(const char* filePath)
        {
            #ifdef __DEBUG__
                cout << "create ModuleLoader..." << endl << endl;
            #endif // __DEBUG__

            libraryLoader = new SharedLibraryLoader;
            isLoaded = libraryLoader->load(filePath);
        }

        ~ModuleLoader()
        {
            #ifdef __DEBUG__
                cout  << endl << "Call SharedLibraryLoader destructor from ModuleLoader..." << endl << endl;
            #endif // __DEBUG__

            delete libraryLoader;

            #ifdef __DEBUG__
                cout << "delete ModuleLoader..." << endl << endl;
            #endif // __DEBUG__
        }

        void load(string filePath)
        {
            isLoaded = libraryLoader->load(filePath);
        }

        template<typename ObjectType> 
        ObjectType getInstanceAs() //OK
        {
            //@toDo doctrine comment format
            ObjectType obj = nullptr;
            if(isLoaded)
            {
                typedef ObjectType ( *LibFunctionPointer ) (void);
                LibFunctionPointer libFunctionPointer = (LibFunctionPointer)libraryLoader->getExternSymbol("getInstance");
                if( libFunctionPointer )
                {
                    obj = libFunctionPointer();
                    if( dynamic_cast<ObjectType> (obj) == nullptr )
                    {
                        showError("Error: The return type of the function is not the same as the one requested!");
                    } 
                }
                else
                {
                    showError("Error: Function name does not exist in symbol table!");
                }
            }
            else
            {
                showError("Error: Library is not loaded, can't get instance");
            }
            
            return obj;        
        }
};

typedef ModuleLoader import;

#endif // MODULE_LOADER_HPP