#include <cstdlib>
#define LIB_CFGPathLIBRARY_EXPORT
#include <cfgpathpp/cfgpath.hpp>
#include <cfgpathpp/impl/impl.hpp>
#include <cfgpathpp/private/api.hpp>
#include <cstring>
#include <exception>
#include <filesystem>
#include <string>
#include <xxhash.h>

namespace cfgpathpp {

namespace util {
void createPath(std::string path) {
	// create the path recursively
	if (path.empty()) {
		return;
	}
	// check if the path exists
	if (std::filesystem::exists(path)) {
		return;
	}
	std::filesystem::create_directories(path);
}
} // namespace util

namespace API {
char *copyString(std::string str) {
	char *result = new char[str.length() + 1];
	// copy it using memcpy
	memcpy(result, str.c_str(), str.length() + 1);
	return result;
}
// C function calls
extern "C" {
LIB_CFGPathAPI void LIB_CFGPATHPP_getHomeDir(char **path, char **errorMsg) {
	try {
		std::string homeDir = impl::getHomeDir();
		*path = copyString(homeDir);
	} catch (std::exception const &err) {
		free(path);
		path = nullptr;
		*errorMsg = copyString(err.what());
	}
}
LIB_CFGPathAPI void LIB_CFGPATHPP_getUserConfigDir(char **path,
                                                   char **errorMsg) {
	try {
		std::string userConfigDir = impl::getUserConfigDir();
		*path = copyString(userConfigDir);
	} catch (std::exception const &err) {
		free(path);
		path = nullptr;
		*errorMsg = copyString(err.what());
	}
}
LIB_CFGPathAPI void LIB_CFGPATHPP_getUserDataDir(char **path, char **errorMsg) {
	try {
		std::string userDataDir = impl::getUserDataDir();
		*path = copyString(userDataDir);
	} catch (std::exception const &err) {
		free(path);
		path = nullptr;
		*errorMsg = copyString(err.what());
	}
}
LIB_CFGPathAPI void LIB_CFGPATHPP_getUserCacheDir(char **path,
                                                  char **errorMsg) {
	try {
		std::string userCacheDir = impl::getUserCacheDir();
		*path = copyString(userCacheDir);

	} catch (std::exception const &err) {
		free(path);
		path = nullptr;
		*errorMsg = copyString(err.what());
	}
}
LIB_CFGPathAPI void LIB_CFGPATHPP_getAppConfigPath(const char *appName,
                                                   char **path,
                                                   char **errorMsg) {
	try {
		std::string appConfigPath = impl::getUserConfigDir() + "/" + appName;
		util::createPath(appConfigPath);
		*path = copyString(appConfigPath);
	} catch (std::exception const &err) {
		free(*path);
		path = nullptr;
		*errorMsg = copyString(err.what());
	}
}
LIB_CFGPathAPI void LIB_CFGPATHPP_getAppDataPath(const char *appName,
                                                 char **path, char **errorMsg) {
	try {
		std::string appDataPath = impl::getUserDataDir() + "/" + appName;
		util::createPath(appDataPath);
		*path = copyString(appDataPath);
	} catch (std::exception const &err) {
		free(*path);
		path = nullptr;
		*errorMsg = copyString(err.what());
	}
}
LIB_CFGPathAPI void LIB_CFGPATHPP_getAppCachePath(const char *appName,
                                                  char **path,
                                                  char **errorMsg) {
	try {
		std::string appCachePath = impl::getUserCacheDir() + "/" + appName;
		util::createPath(appCachePath);
		*path = copyString(appCachePath);
	} catch (std::exception const &err) {
		free(*path);
		path = nullptr;
		*errorMsg = copyString(err.what());
	}
}

LIB_CFGPathAPI void LIB_CFGPATHPP_generateAppHash(char **hash,
                                                  char **errorMsg) {
	try {
		std::string appHash = impl::generateAppHash();
		// make a hash of the app hash
		appHash = std::to_string(XXH64(appHash.c_str(), appHash.length(), 0));
		*hash = copyString(appHash);
	} catch (std::exception const &err) {
		free(*hash);
		hash = nullptr;
		*errorMsg = copyString(err.what());
	}
}
LIB_CFGPathAPI void LIB_CFGPATHPP_free(void *ptr) { free(ptr); }
}
} // namespace API
} // namespace cfgpathpp
