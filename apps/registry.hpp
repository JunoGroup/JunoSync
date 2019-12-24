/**
 * Utility functions for dealing with the Windows registry
 */
#pragma once

#ifdef _WIN32

#include <Windows.h>
#include <string>

namespace JunoSync
{
	namespace Registry
	{
		/**
		 * @brief Fetches a DWORD Registry Key
		 * 
		 * @param handle Handle to the registry openned with RegOpenKeyEx
		 * @param strValName The key name to be found
		 * @param nValue Pointer to C-style string array
		 * @param nDefaultValue Default value if nothing else is given
		 * @return Same as RegQueryValueKeyEx()
		 * 
		 * @see RegQueryValueKeyEx
		 */
		LONG GetDWORDRegKey(HKEY handle, const std::wstring &strValName,
			DWORD &nValue, DWORD nDefaultValue);

		/**
		 * @brief Fetches a Boolean Registry Key
		 * 
		 * @param handle Handle to the registry openned with RegOpenKeyEx
		 * @param strValName The key name to be found
		 * @param nValue Pointer to C-style string array
		 * @param nDefaultValue Default value if nothing else is given
		 * @return Same as RegQueryValueKeyEx()
		 * 
		 * @see RegQueryValueKeyEx
		 */
		LONG GetBoolRegKey(HKEY handle, const std::wstring &strValName,
			bool &bValue, bool bDefaultValue);

		/**
		 * @brief Fetches a string Registry Key
		 * 
		 * @param handle Handle to the registry openned with RegOpenKeyEx
		 * @param strValName The key name to be found
		 * @param nValue Pointer to C-style string array
		 * @param nDefaultValue Default value if nothing else is given
		 * @return Same as RegQueryValueKeyEx()
		 * 
		 * @see RegQueryValueKeyEx
		 */
		LONG GetStringRegKey(HKEY handle, const std::wstring &strValueName,
			std::wstring &strValue, const std::wstring &strDefaultValue);
	}
}

#endif