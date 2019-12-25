#include "config.hpp"
#include "stringutils.hpp"
#include "spdlog/spdlog.h"

using namespace JunoSync;

std::map<std::string, std::string> JunoSync::CONFIG = {
    {"port", "18548"}
};

int Config::init(const boost::filesystem::path &confPath)
{
// TODO: Write
#ifdef linux
#endif

#ifdef _WIN32
    HKEY regHandle;
    DWORD openErr = RegOpenKeyExW(HKEY_CURRENT_USER, CONFIG_KEY, 0, KEY_READ,
        &regHandle);

    if (openErr == ERROR_NO_MATCH || openErr == ERROR_FILE_NOT_FOUND)
    {
        spdlog::warn("The HKEY_CURRENT_USER\\Software\\Juno\\JunoSync key "
            "doesn't exist. Creating it.");
        return Config::createDefault();
    }
    else if (openErr != ERROR_SUCCESS)
    {
        spdlog::error("There has been an error opening the "
            "HKEY_CURRENT_USER\\Software\\Juno\\JunoSync key.");
        return openErr;
    }
    else
    {
        spdlog::info("Reading configuration from registry.");
        for (const auto &kv: CONFIG)
        {
            std::wstring strVal;
            Registry::GetStringRegKey(regHandle,
                String::s2ws(kv.first), strVal, L"");

            CONFIG[kv.first] = String::ws2s(strVal);
        }

        DWORD closeErr = RegCloseKey(regHandle);
        if (closeErr != ERROR_SUCCESS)
        {
            spdlog::error("Could not close registry.");
            return closeErr;
        }

        return openErr;
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
        spdlog::error("Could not create "
            "HKEY_CURRENT_USER\\Software\\Juno\\JunoSync key");
        return createErr;
    }
    else
    {
        for (const auto &kv: CONFIG)
        {
            RegSetValueEx(regHandle, TEXT(kv.first.c_str()), 0, REG_SZ,
                (LPBYTE)kv.second.c_str(), kv.second.length() + 1);
        }

        DWORD closeErr = RegCloseKey(regHandle);
        if (closeErr != ERROR_SUCCESS)
        {
            spdlog::error("Could not close registry.");
        }

        return 0;
    }
#endif
}