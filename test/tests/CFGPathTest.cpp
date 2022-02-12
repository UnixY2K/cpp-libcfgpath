#include <catch2/catch.hpp>
#include <cfgpathpp/cfgpath.hpp>

TEST_CASE("cfgpath", "[util]") {
	SECTION("Get Directories") {
		SECTION("getHomeDir") {
			std::string homeDir = cfgpathpp::getHomePath();
			REQUIRE(!homeDir.empty());
		}
		SECTION("getUserConfigDir") {
			std::string userConfigDir = cfgpathpp::getUserConfigPath();
			REQUIRE(!userConfigDir.empty());
		}
		SECTION("getUserDataDir") {
			std::string userDataDir = cfgpathpp::getUserDataPath();
			REQUIRE(!userDataDir.empty());
		}
		SECTION("getUserCacheDir") {
			std::string userCacheDir = cfgpathpp::getUserCachePath();
			REQUIRE(!userCacheDir.empty());
		}
	}
	SECTION("Get App Directories") {
		std::string appName = "cfgpathpp_test";
		SECTION("getAppConfigPath") {
			std::string appConfigPath = cfgpathpp::getAppConfigPath(appName);
			REQUIRE(!appConfigPath.empty());
		}
		SECTION("getAppDataPath") {
			std::string appDataPath = cfgpathpp::getAppDataPath(appName);
			REQUIRE(!appDataPath.empty());
		}
		SECTION("getAppCachePath") {
			std::string appCachePath = cfgpathpp::getAppCachePath(appName);
			REQUIRE(!appCachePath.empty());
		}
	}
}