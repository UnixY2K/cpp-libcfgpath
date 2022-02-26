#include <catch2/catch.hpp>
#include <cfgpathpp/cfgpath.hpp>
#include <iostream>
#include <string>

TEST_CASE("cgfpathpp", "[App]"){
    SECTION("Generate Application Hash"){
        std::string appHash = cfgpathpp::generateAppHash();
        std::cout << "Application Hash: " << appHash << std::endl;
        REQUIRE(!appHash.empty());
        REQUIRE(appHash.size() == 19);
        REQUIRE(appHash == "9050539884890905268");
    }
}