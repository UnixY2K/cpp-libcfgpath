#pragma once
#include <string>
#include <string_view>

namespace cfgpathpp {

/**
 * @brief Get the Config Path directory
 *
 * @return constexpr std::string_view the directory
 */
const std::string getConfigPath();

} // namespace cfgpathpp
