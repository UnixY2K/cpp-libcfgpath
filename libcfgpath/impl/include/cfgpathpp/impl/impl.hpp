#pragma once
#include <string>

namespace cfgpathpp::impl {

// contains platform-dependent definitions
const std::string getHomeDir();
const std::string getUserConfigDir();
const std::string getUserDataDir();
const std::string getUserCacheDir();
const std::string generateAppHash();
} // namespace cfgpathpp::impl