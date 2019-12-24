#pragma once

#include <locale>
#include <codecvt>
#include <string>

namespace JunoSync
{
    namespace String
    {
        /**
         * @brief Converts a regular string to a wide string
         * @details Converts using the UTF-8 encoding.
         * 
         * @param str The string to convert
         * @return Wide version of str
         * 
         * @author dk123 on StackOverflow
         */
            std::wstring s2ws(const std::string &str);

        /**
         * @brief Converts a wide string to a regular string
         * @details Converts using the UTF-8 encoding.
         * 
         * @param str The string to convert
         * @return Regular version of str
         */
        std::string ws2s(const std::wstring &str);
    }
}

