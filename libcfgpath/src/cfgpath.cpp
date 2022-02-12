#include <cstdlib>
#define LIB_CFGPathLIBRARY_EXPORT
#include <cfgpathpp/cfgpath.hpp>
#include <cfgpathpp/private/api.hpp>
#include <cstring>
#include <exception>
#include <filesystem>
#include <string>

namespace cfgpathpp {
// contains platform-dependent definitions
namespace impl {
const std::string getHomeDir();
const std::string getUserConfigDir();
const std::string getUserDataDir();
const std::string getUserCacheDir();
} // namespace impl

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
// C function calls
extern "C" {
LIB_CFGPathAPI void LIB_CFGPATHPP_getHomeDir(char **path, char **errorMsg) {
	try {
		std::string homeDir = impl::getHomeDir();
		*path = strdup(homeDir.c_str());
	} catch (std::exception const &err) {
		free(path);
		path = nullptr;
		*errorMsg = strdup(err.what());
	}
}
LIB_CFGPathAPI void LIB_CFGPATHPP_getUserConfigDir(char **path,
                                                   char **errorMsg) {
	try {
		std::string userConfigDir = impl::getUserConfigDir();
		*path = strdup(userConfigDir.c_str());
	} catch (std::exception const &err) {
		free(path);
		path = nullptr;
		*errorMsg = strdup(err.what());
	}
}
LIB_CFGPathAPI void LIB_CFGPATHPP_getUserDataDir(char **path, char **errorMsg) {
	try {
		std::string userDataDir = impl::getUserDataDir();
		*path = strdup(userDataDir.c_str());
	} catch (std::exception const &err) {
		free(path);
		path = nullptr;
		*errorMsg = strdup(err.what());
	}
}
LIB_CFGPathAPI void LIB_CFGPATHPP_getUserCacheDir(char **path,
                                                  char **errorMsg) {
	try {
		std::string userCacheDir = impl::getUserCacheDir();
		*path = strdup(userCacheDir.c_str());

	} catch (std::exception const &err) {
		free(path);
		path = nullptr;
		*errorMsg = strdup(err.what());
	}
}
LIB_CFGPathAPI void LIB_CFGPATHPP_getAppConfigPath(const char *appName,
                                                   char **path,
                                                   char **errorMsg) {
	try {
		std::string appConfigPath = impl::getUserConfigDir() + "/" + appName;
		util::createPath(appConfigPath);
		*path = strdup(appConfigPath.c_str());
	} catch (std::exception const &err) {
		free(*path);
		path = nullptr;
		*errorMsg = strdup(err.what());
	}
}
LIB_CFGPathAPI void LIB_CFGPATHPP_getAppDataPath(const char *appName,
                                                 char **path, char **errorMsg) {
	try {
		std::string appDataPath = impl::getUserDataDir() + "/" + appName;
		util::createPath(appDataPath);
		*path = strdup(appDataPath.c_str());
	} catch (std::exception const &err) {
		free(*path);
		path = nullptr;
		*errorMsg = strdup(err.what());
	}
}
LIB_CFGPathAPI void LIB_CFGPATHPP_getAppCachePath(const char *appName,
                                                  char **path,
                                                  char **errorMsg) {
	try {
		std::string appCachePath = impl::getUserCacheDir() + "/" + appName;
		util::createPath(appCachePath);
		*path = strdup(appCachePath.c_str());
	} catch (std::exception const &err) {
		free(*path);
		path = nullptr;
		*errorMsg = strdup(err.what());
	}
}
LIB_CFGPathAPI void LIB_CFGPATHPP_free(void *ptr) { free(ptr); }
}
} // namespace API
} // namespace cfgpathpp
