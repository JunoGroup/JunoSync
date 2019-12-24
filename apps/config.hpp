#pragma once

#ifdef linux
#include <libconfig.h++>
#endif

#ifdef _WIN32
#include <Windows.h>
#include "registry.hpp"
#endif

#include <boost/filesystem.hpp>
#include <iostream>
#include <string>
#include <map>

#define DEFAULT_CONF_PATH "JunoSync.conf"
#define CONFIG_KEY L"Software\\Juno\\JunoSync"

namespace JunoSync
{
    /**
     * The configuration dictionary
     * 
     * It has the following key value settings:
     *     "port", "18548"
     */
    extern std::map<std::string, std::string> CONFIG;

    /**
     * Static class containing Configuration information
     */
    namespace Config
    {
        /**
         * @brief Reads the configuration from filepath and parses it.
         *
         * If the configuration filepath is not given, then it will read from
         * DEFAULT_CONF_PATH. If this does not exist. If either filepath or 
         * DEFAULT_CONF_PATH don't exist, then the function will generate 
         * default configuration files in the respective path.
         *
         * @param confPath The path to the configuration
         * 
         * @returns 0b00000001 If critical error, 0, otherwise.
         */
        int init(const boost::filesystem::path &confPath = DEFAULT_CONF_PATH);

        /**
         * @brief Writes a default config file
         */
        static int createDefault(const boost::filesystem::path &confPath = DEFAULT_CONF_PATH);
    };
}