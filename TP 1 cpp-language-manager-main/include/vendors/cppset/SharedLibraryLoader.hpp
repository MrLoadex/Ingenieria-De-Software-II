/**
* Copyright (c) 2022 Gabriel Nicolás González Ferreira. All rights reserved.
* This file is part of CPPSET tools.
* Released under the MIT license
* https://opensource.org/licenses/MIT
**/

#ifndef SHARED_LIBRARY_LOADER_HPP
#define SHARED_LIBRARY_LOADER_HPP

#ifndef __DEBUG__
    #define __DEBUG__
#endif

#ifdef __unix__
    #define RTLD_LAZY   1
    #define RTLD_NOW    2
    #define RTLD_GLOBAL 4
    #include <vendors/dlopen/dlfcn.h>
#elif __APPLE__
    #include <vendors/dlopen/dlfcnMac.h>
#elif defined(_WIN32) || defined(WIN32)
    #include <windows.h>
#endif // defined

#include <string>
#include <iostream>

using namespace std;

class SharedLibraryLoader
{
    private:
        void* library;
        void* symbol;
        bool isFree;
        bool isLoaded;

        void showError(string message, string message2 = "")
        {
            cerr << message << ' ' << message2 << endl;
            exit(EXIT_FAILURE);
        }

    public:
        SharedLibraryLoader()
        {
            #ifdef __DEBUG__
                cout << "create SharedLibraryLoader..." << endl << endl;
            #endif // __DEBUG__
            
            library = nullptr;
            symbol = nullptr;
            isLoaded = false;
            isFree = false;
        }

        SharedLibraryLoader(string filePath)
        {
            #ifdef __DEBUG__
                cout << "create SharedLibraryLoader..." << endl;
                cout << "Load library into SharedLibraryLoader constructor" << endl;
            #endif // __DEBUG__

            isLoaded = false;
            isFree = false;
            load(filePath);
            symbol = nullptr;
        }

        virtual ~SharedLibraryLoader()
        {
            #ifdef __DEBUG__
                cout << "Free library into SharedLibraryLoader destructor:" << endl << endl;
            #endif // __DEBUG__

            freeLibrary();

            #ifdef __DEBUG__
                cout << "delete SharedLibraryLoader..." << endl << endl;
            #endif // __DEBUG__
        }

        void* load(string filePath)
        {
            #ifdef __DEBUG__
                cout << "0-Load library:" << endl;
            #endif // __DEBUG__            

            #ifdef __unix__
                filePath += ".so";
                library = dlopen(filePath.c_str(), RTLD_NOW);
            #elif __APPLE__
                filePath += ".dylib";
                library = dlopen(filePath.c_str(), RTLD_LOCAL|RTLD_LAZY);
            #elif defined(_WIN32) || defined(WIN32)
                filePath += ".dll";
                library = (void*) LoadLibrary(filePath.c_str());
            #endif // defined

            //LEER DOCUMENTACION DE MICROSOFT
            (library) ? isLoaded = true : isLoaded = false;
            if(!isLoaded) showError("Error: The library "+filePath+" could not be loaded!");
            
            #ifdef __DEBUG__
                if(isLoaded) cout << "  Is loaded: true" << endl << endl;
            #endif // __DEBUG__      
            
            return library;
        }

        void* getExternSymbol(string name)
        {
            if(isLoaded)
            {
                #ifdef __unix__
                    symbol = dlsym(library, name.c_str());
                #elif __APPLE__
                    symbol = dlsym(library, name.c_str());
                #elif defined(_WIN32) || defined(WIN32)
                    symbol = (void*) GetProcAddress((HINSTANCE)library, name.c_str());
                #endif // defined        
                if(!symbol) showError("Error: Library symbol does not exist or cannot be obtained!");        
            }
            else
            {
                showError("Error: Library is not loaded, can't get symbol");
            }
            

            return symbol;
        }

        /**
         * @brief Free the shared library handler. dlclose no return boolean value
         */
        bool freeLibrary()
        {
            #ifdef __DEBUG__
                cout << "  1-Execute freeLibrary method..." << endl;
                cout << "  2-Previous IsFree value: " << isFree << endl;
                cout << "  3-Previous IsLoaded value: " << isLoaded << endl;
            #endif // __DEBUG__

            if(isLoaded)
            {
                #ifdef __unix__
                    isLoaded = dlclose(library);
                    isLoaded ? isFree = false : isFree = true; 
                #elif __APPLE__
                    isLoaded = dlclose(library);
                    isLoaded ? isFree = false : isFree = true; 
                #elif defined(_WIN32) || defined(WIN32)
                    isFree = FreeLibrary((HINSTANCE)library);
                    isFree ? isLoaded = false : isLoaded = true; 
                #endif // defined
            }
            // else
            // {
            //     showError("Error releasing library not loaded!");
            // }

            #ifdef __DEBUG__
                cout << "  4-Last IsFree value: " << isFree << endl;
                cout << "  5-Last IsLoaded value: " << isLoaded << endl << endl;
            #endif // __DEBUG__

            return isFree;
        }
};

#endif // SHARED_LIBRARY_LOADER_HPP

