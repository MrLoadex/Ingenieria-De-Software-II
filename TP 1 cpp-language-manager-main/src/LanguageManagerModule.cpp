/**
 * @file LanguageManagerModule.cpp
 * @author Gabriel Ferreira (gferreiragabriel@abc.gob.ar)
 * @brief Header of Language Manager Module Example
 * @version 0.1
 * @date 2022-10-26
 * 
 * @copyright Copyright (c) 2022 Released under the MIT license
 * @link https://opensource.org/licenses/MIT @endlink
 * 
 */
#include <LanguageManagerModule.hpp>

/**
 * @brief Construct a new Language Manager Module:: Language Manager Module object
 * 
 */
LanguageManagerModule::LanguageManagerModule()
{
    #ifdef __DEBUG__
        cout << "create LanguageManagerModule from shared library..." << endl;
    #endif // __DEBUG__
    _language = "default";
    _languageFilePath = "./lang/"+_language+".lang";
}

/**
 * @brief Destroy the Language Manager Module:: Language Manager Module object
 * 
 */
LanguageManagerModule::~LanguageManagerModule()
{
    #ifdef __DEBUG__
        cout << "delete LanguageManagerModule from shared library..." << endl;
    #endif // __DEBUG__
}

/**
 * @brief 
 * 
 * @param filePath 
 */
void LanguageManagerModule::setLanguageFilePath(string filePath) 
{
    _languageFilePath = filePath;
}

/**
 * @brief 
 * 
 * @param language 
 */
void LanguageManagerModule::setLanguage(string language) 
{
    _language = language;
    _languageFilePath = "./lang/"+_language+".lang";
}

/**
 * @brief 
 * @param key 
 * @return string 
 */
string LanguageManagerModule::translate(string key) 
{
    string result;
    //_langReader = new LangReader();
    _langReader = make_shared<LangReader>();
    _langReader->open(_languageFilePath);
    result =_langReader->getValueOf(key);
    if(result == "")
    {
        result = "NULL TRANSLATION OF KEY: " + key + "!";
    } 
    //delete _langReader;
    return result;
}

/**
 * @brief Get the Instance object
 * 
 * @return LanguageManagerModule* 
 */

/*LanguageManagerModule* getInstance() 
{
    return new LanguageManagerModule();
}
*/

shared_ptr<LanguageManagerModule> getInstance() 
{
    //return new LanguageManagerModule();
    //shared_ptr<LanguageManagerModule> punteroInteligente;
    //punteroInteligente = make_shared<LanguageManagerModule>();
    return make_shared<LanguageManagerModule>();
}
