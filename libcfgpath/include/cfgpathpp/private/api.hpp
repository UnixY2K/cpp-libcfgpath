#pragma once
#include <cfgpathpp/private/exportAPI.hpp>

// C function calls
namespace cfgpathpp {
namespace API {
extern "C" {
LIBCFGPathAPI void LIBCFGPathPP_getHomeDir(char **path, char **errorMsg);
LIBCFGPathAPI void LIBCFGPathPP_getUserConfigDir(char **path,
                                                   char **errorMsg);
LIBCFGPathAPI void LIBCFGPathPP_getUserDataDir(char **path, char **errorMsg);
LIBCFGPathAPI void LIBCFGPathPP_getUserCacheDir(char **path, char **errorMsg);

LIBCFGPathAPI void LIBCFGPathPP_getAppConfigPath(const char *appName,
                                                   char **path,
                                                   char **errorMsg);
LIBCFGPathAPI void LIBCFGPathPP_getAppDataPath(const char *appName,
                                                 char **path, char **errorMsg);
LIBCFGPathAPI void LIBCFGPathPP_getAppCachePath(const char *appName,
                                                  char **path, char **errorMsg);
LIBCFGPathAPI void LIBCFGPathPP_generateAppHash(char **hash, char **errorMsg);

LIBCFGPathAPI void LIBCFGPathPP_free(void *ptr);
} // extern "C"
} // namespace API
} // namespace cfgpathpp