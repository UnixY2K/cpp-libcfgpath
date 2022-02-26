#include <cfgpathpp/cfgpath.hpp>
#include <cstdlib>
#include <fstream>
#include <stdexcept>
#include <string>

namespace cfgpathpp::impl {
const std::string getHomeDir() {
	const char *home = std::getenv("HOME");
	if (home) {
		return std::getenv("HOME");
	}
	throw std::runtime_error("HOME environment variable not set");
}

const std::string getUserConfigDir() {
	std::string path;
	const char *cHomeDir = std::getenv("XDG_CONFIG_HOME");
	if (!cHomeDir) {
		return getHomeDir() + "/.config";
	}
	return std::string(cHomeDir);
}

const std::string getUserDataDir() {
	std::string path;
	const char *cHomeDir = std::getenv("XDG_DATA_HOME");
	if (!cHomeDir) {
		return getHomeDir() + "/.local/share";
	}
	return std::string(cHomeDir);
}

const std::string getUserCacheDir() {
	std::string path;
	const char *cHomeDir = std::getenv("XDG_CACHE_HOME");
	if (!cHomeDir) {
		return getHomeDir() + "/.cache";
	}
	return std::string(cHomeDir);
}

const std::string generateAppHash() {
	std::string sp;
	std::ifstream("/proc/self/comm") >> sp;
	return sp;
}

} // namespace cfgpathpp::impl
