#pragma once
#include <stdexcept>
#include <string>

#include <cfgpathpp/private/api.hpp>
#include <cfgpathpp/private/exportAPI.hpp>

namespace cfgpathpp {

// cfgpath exception
class cfgpath_exception : public std::runtime_error {
  public:
	cfgpath_exception(const std::string &msg)
	    : std::runtime_error("CFGPath++: " + msg) {}
};
namespace private_ {
// gets and frees a string from the C API
inline const std::string getString(char *str) {
	if (!str) {
		return std::string();
	}
	std::string result(str);
	API::LIBCFGPathPP_free(static_cast<void *>(str));
	return result;
}
} // namespace private_

/**
 * @brief Get the user home directory.
 *
 * @return std::string The user home directory.
 */
inline const std::string getHomePath() {
	char *homePath = nullptr;
	char *errorMsg = nullptr;
	API::LIBCFGPathPP_getHomeDir(&homePath, &errorMsg);
	if (errorMsg) {
		throw cfgpath_exception(private_::getString(errorMsg));
	}
	return private_::getString(homePath);
}

/**
 * @brief Get the user configuration directory.
 *
 * @return std::string The user configuration directory.
 */
inline const std::string getUserConfigPath() {
	char *userConfigPath = nullptr;
	char *errorMsg = nullptr;
	API::LIBCFGPathPP_getUserConfigDir(&userConfigPath, &errorMsg);
	if (errorMsg) {
		throw cfgpath_exception(private_::getString(errorMsg));
	}
	return private_::getString(userConfigPath);
}

/**
 * @brief Get the user data directory.
 *
 * @return std::string The user data directory.
 */
inline const std::string getUserDataPath() {
	char *userDataPath = nullptr;
	char *errorMsg = nullptr;
	API::LIBCFGPathPP_getUserDataDir(&userDataPath, &errorMsg);
	if (errorMsg) {
		throw cfgpath_exception(private_::getString(errorMsg));
	}
	return private_::getString(userDataPath);
}

/**
 * @brief Get the user cache directory.
 *
 * @return std::string The user cache directory.
 */
inline const std::string getUserCachePath() {
	char *userCachePath = nullptr;
	char *errorMsg = nullptr;
	API::LIBCFGPathPP_getUserCacheDir(&userCachePath, &errorMsg);
	if (errorMsg) {
		throw cfgpath_exception(private_::getString(errorMsg));
	}
	return private_::getString(userCachePath);
}

/**
 * @brief Get the App Config Path and create it if it does not exist.
 *
 * @param appName the name of the application.
 * @return const std::string the path to the application config directory.
 */
inline const std::string getAppConfigPath(std::string appName) {
	char *path = nullptr;
	char *errorMsg = nullptr;
	API::LIBCFGPathPP_getAppConfigPath(appName.data(), &path, &errorMsg);
	if (errorMsg) {
		throw cfgpath_exception(private_::getString(errorMsg));
	}
	return private_::getString(path);
}
/**
 * @brief Get the App Data Path object
 *
 * @param appName the name of the application.
 * @return const std::string the path to the application data directory.
 */
inline const std::string getAppDataPath(std::string appName) {
	char *path = nullptr;
	char *errorMsg = nullptr;
	API::LIBCFGPathPP_getAppDataPath(appName.data(), &path, &errorMsg);
	if (errorMsg) {
		throw cfgpath_exception(private_::getString(errorMsg));
	}
	return private_::getString(path);
}
/**
 * @brief Get the App Cache Path object
 *
 * @param appName the name of the application.
 * @return const std::string the path to the application cache directory.
 */
inline const std::string getAppCachePath(std::string appName) {
	char *path = nullptr;
	char *errorMsg = nullptr;
	API::LIBCFGPathPP_getAppCachePath(appName.data(), &path, &errorMsg);
	if (errorMsg) {
		throw cfgpath_exception(private_::getString(errorMsg));
	}
	return private_::getString(path);
}

inline const std::string generateAppHash() {
	char *hash = nullptr;
	char *errorMsg = nullptr;
	API::LIBCFGPathPP_generateAppHash(&hash, &errorMsg);
	if (errorMsg) {
		throw cfgpath_exception(private_::getString(errorMsg));
	}
	return private_::getString(hash);
}

} // namespace cfgpathpp
