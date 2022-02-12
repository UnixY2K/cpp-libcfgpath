#pragma once
#include <string>
#include <string_view>

namespace cfgpathpp {
namespace constants {
constexpr std::string_view windows_path_separator{"\\"};
constexpr std::string_view unix_path_separator{"/"};
} // namespace constants

/**
 * @brief Get the Config Path directory
 *
 * @return constexpr std::string_view the directory
 */
const std::string getConfigPath();

} // namespace cfgpathpp
