#include <catch2/catch_test_macros.hpp>
#include <cfgpathpp/cfgpath.hpp>
#include <string>

TEST_CASE("cgfpathpp", "[App]") {
	SECTION("Generate Application Hash") {
		std::string appHash = cfgpathpp::generateAppHash();
		REQUIRE(!appHash.empty());
		REQUIRE(appHash.size() == 19);
	}
}