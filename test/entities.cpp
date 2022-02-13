#include <catch2/catch_all.hpp>
#include "../src/model/entities/City.hpp"
#include "../src/model/entities/Location.hpp"
#include "../src/model/entities/Date.hpp"

TEST_CASE("Location entity", "[location]")
{
  SECTION("Constructor") {
    REQUIRE(Location("Loc").Value == "Loc");
  }

  SECTION("ID") {
    REQUIRE(Location("Loc").Name() == Location::ID);
  }
}

TEST_CASE("Date entity", "[Date]")
{
  SECTION("Constructor") {
    REQUIRE(Date("Dat").Value == "Dat");
  }

  SECTION("ID") {
    REQUIRE(Date("Dat").Name() == Date::ID);
  }
}

TEST_CASE("City entity", "[city]")
{
  SECTION("Constructor") {
    REQUIRE(City("Cit").Value == "Cit");
  }

  SECTION("ID") {
    REQUIRE(City("Cit").Name() == City::ID);
  }
}
