#pragma once

#include <boost/filesystem.hpp>

#define DEFAULT_CONF_PATH "JunoSync.conf"

namespace JunoSync
{
    /**
     * Static class containing Configuration information
     */
    class Config
    {
    public:
        /**
         * The port to serve on
         */
        int port;

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
        static int init(const boost::filesystem::path &confPath = DEFAULT_CONF_PATH);

    private:
        Config() {}

        /**
         * @brief Writes a default config file
         */
        static void createDefault(const boost::filesystem::path &confPath = DEFAULT_CONF_PATH);
    };
}