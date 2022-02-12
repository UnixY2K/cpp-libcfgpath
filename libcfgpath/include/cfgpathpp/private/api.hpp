#pragma once
#include <cfgpathpp/private/exportAPI.hpp>

// C function calls
namespace cfgpathpp {
namespace API {
extern "C" {
LIB_CFGPathAPI void LIB_CFGPATHPP_getHomeDir(char **path, char **errorMsg);
LIB_CFGPathAPI void LIB_CFGPATHPP_getUserConfigDir(char **path,
                                                   char **errorMsg);
LIB_CFGPathAPI void LIB_CFGPATHPP_getUserDataDir(char **path, char **errorMsg);
LIB_CFGPathAPI void LIB_CFGPATHPP_getUserCacheDir(char **path, char **errorMsg);

LIB_CFGPathAPI void LIB_CFGPATHPP_getAppConfigPath(const char *appName,
                                                   char **path,
                                                   char **errorMsg);
LIB_CFGPathAPI void LIB_CFGPATHPP_getAppDataPath(const char *appName,
                                                 char **path, char **errorMsg);
LIB_CFGPathAPI void LIB_CFGPATHPP_getAppCachePath(const char *appName,
                                                  char **path, char **errorMsg);

LIB_CFGPathAPI void LIB_CFGPATHPP_free(void *ptr);
} // extern "C"
} // namespace API
} // namespace cfgpathpp