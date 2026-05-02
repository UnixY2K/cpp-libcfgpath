#include <cfgpathpp/cfgpath.hpp>
#include <cstdlib>
#include <stdexcept>
#include <string>

namespace cfgpathpp::impl {
const std::string getHomeDir() {
	const char *home = std::getenv("HOME");
	if (home) {
		return home;
	}
	throw std::runtime_error("HOME environment variable not set");
}

const std::string getUserConfigDir() {
	return getHomeDir() + "/Library/Preferences/";
}

const std::string getUserDataDir() { 
	return getHomeDir() + "/Library/"; 
}

const std::string getUserCacheDir() {
	return getHomeDir() + "/Library/Caches/";
}

const std::string generateAppHash() {
	return getprogname();
}

} // namespace cfgpathpp::impl
