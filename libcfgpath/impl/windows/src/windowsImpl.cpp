#include <Shlobj.h> // need to include definitions of constants
#include <Windows.h>
#include <cfgpathpp/cfgpath.hpp>
#include <codecvt>
#include <combaseapi.h>
#include <cstdlib>
#include <locale>
#include <stdexcept>
#include <string>
#include <winnt.h>

namespace cfgpathpp::impl {

// C++17 deprecated std::wstring_convert, so we will use
// WideCharToMultiByte and MultiByteToWideChar instead.
const std::string wstring_to_string(const std::wstring &wstr) {

	if (wstr.empty()) {
		return std::string();
	}
	if (wstr.size() > INT_MAX) {
		throw std::runtime_error(
		    "cannot convert wstring to string: wstring is too long");
	}
	const auto size_needed = WideCharToMultiByte(CP_UTF8, 0, &wstr.at(0),
	                                             static_cast<int>(wstr.size()),
	                                             nullptr, 0, nullptr, nullptr);
	if (size_needed <= 0) {
		throw std::runtime_error(
		    "could not translate std::wstring to std::string");
	}
	std::string res(size_needed, 0);
	WideCharToMultiByte(CP_UTF8, 0, &wstr.at(0), static_cast<int>(wstr.size()),
	                    &res.at(0), size_needed, nullptr, nullptr);
	return res;
}

const std::wstring string_to_wstring(const std::string &str) {
	if (str.empty()) {
		return std::wstring();
	}
	if (str.size() > INT_MAX) {
		throw std::runtime_error(
		    "cannot convert string to wstring: string is too long");
	}
	const auto size_needed = MultiByteToWideChar(
	    CP_UTF8, 0, &str.at(0), static_cast<int>(str.size()), nullptr, 0);
	if (size_needed <= 0) {
		throw std::runtime_error("MultiByteToWideChar() failed: " +
		                         std::to_string(size_needed));
	}

	std::wstring result(size_needed, 0);
	MultiByteToWideChar(CP_UTF8, 0, &str.at(0), static_cast<int>(str.size()),
	                    &result.at(0), size_needed);
	return result;
}

const std::string getKnowDir(const GUID &guid) {
	PWSTR winPath = nullptr;
	HRESULT hr = SHGetKnownFolderPath(guid, 0, nullptr, &winPath);
	if (FAILED(hr)) {
		CoTaskMemFree(winPath);
		throw std::runtime_error("SHGetKnownFolderPath() failed: " +
		                         std::to_string(hr));
	}
	std::string path = wstring_to_string(winPath);
	CoTaskMemFree(winPath);
	return path;
}

const std::string getHomeDir() {
	// %USERPROFILE%
	return getKnowDir(FOLDERID_Profile);
}

const std::string getUserConfigDir() {
	// %APPDATA%
	return getKnowDir(FOLDERID_RoamingAppData);
}

const std::string getUserDataDir() {
	// %LOCALAPPDATA%
	return getKnowDir(FOLDERID_LocalAppData);
}

const std::string getUserCacheDir() {
	// %LOCALAPPDATA%\Temp
	return getKnowDir(FOLDERID_LocalAppData) + "\\Temp";
}

} // namespace cfgpathpp::impl
