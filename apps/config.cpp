#include "config.hpp"

using namespace JunoSync;

std::map<std::string, std::string> JunoSync::CONFIG = {
    {"port", "18548"}
};

int Config::init(const boost::filesystem::path &confPath)
{
// TODO: Write
#ifdef linux
    libconfig::Config cfg;

    try
    {
        cfg.readFile(confPath);
    }
    catch (const libconfig::FileIOException &fioex)
    {
        // TODO: Replace cout with a good logging library.
        // File probably doesn't exist. Try creating a new one
        std::cout << "Could not open configuration file" << std::endl;
        Config::createDefault(confPath);
    }
    catch (const ParseExpression &pex)
    {
        // TODO: Replace cerr with a good logging library.
        std::cerr << "File " << pex.getFile() << " error on line " <<
            pex.getLine() << ": " << pex.getError() << std::endl;
        return 0b00000001; // TODO: Make this an enum
    }
#endif

#ifdef _WIN32
    HKEY regHandle;
    DWORD openErr = RegOpenKeyExW(HKEY_CURRENT_USER, CONFIG_KEY, 0, KEY_READ,
        &regHandle);

    if (openErr == ERROR_NO_MATCH || openErr == ERROR_FILE_NOT_FOUND)
    {
        // TODO: Replace this with a logging library
        std::cout << "The JunoSync key doesn't exist. Creating it." <<
            std::endl;
        return Config::createDefault();
    }
    else if (openErr != ERROR_SUCCESS)
    {
        // TODO: Rewrite this with an actual logging library
        std::cerr << "There has been an error reading the registry." <<
            std::endl;
        return 0b00000001; // TODO: Make this an enum
    }
    else
    {
        // TODO: Replace
        std::cout << "Reading settings from registry" << std::endl;
        for (const auto &kv: CONFIG)
        {
            // kv needs to be wstring rather than string so some conversion is
            // necessary. It is assumed that kv.first and kv.second are ASCII.
            std::wstring key(kv.first.begin(), kv.first.end());
            std::copy(kv.first.begin(), kv.first.end(), key.begin());
            std::wstring value(kv.second.begin(), kv.second.end());
            std::copy(kv.second.begin(), kv.second.end(), value.begin());

            std::wstring strVal;
            Registry::GetStringRegKey(regHandle, key, strVal, L"");

            CONFIG[kv.first] = std::string(strVal);
        }
        return 0; // TODO: Make this an enum
    }
#endif
}

int Config::createDefault(const boost::filesystem::path &confPath)
{
#ifdef linux
    // TODO: Write
#endif

#ifdef _WIN32
    HKEY regHandle;
    DWORD createErr = RegCreateKeyExW(HKEY_CURRENT_USER, CONFIG_KEY, 0,
        NULL, REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, NULL, &regHandle,
        NULL);
    if (createErr != ERROR_SUCCESS)
    {
        // TODO: Rewrite with a logging library
        std::cerr << "Could not create registry key." << std::endl;
        std::cerr << createErr << std::endl;
        return createErr;
    }
    else
    {
        // TODO: Use a logging library
        std::cout << "Created default key. Writing to it." << std::endl;
        for (const auto &kv: CONFIG)
        {
            RegSetValueEx(regHandle, TEXT(kv.first.c_str()), 0, REG_SZ,
                (LPBYTE)kv.second.c_str(), kv.second.length() + 1);
        }
        return 0;
    }
#endif
}