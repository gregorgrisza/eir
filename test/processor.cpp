#include <catch2/catch_all.hpp>
#include "../src/processor/Preprocessor.hpp"

TEST_CASE("Normalize sentence", "[normalize]")
{
  SECTION("All uppercase") {
    std::string sentence = "ALL UPPERCASE";
    Preprocessor::normalize(sentence);
    REQUIRE(sentence == "all uppercase");
  }

  SECTION("First uppercase") {
    std::string sentence = "First only";
    Preprocessor::normalize(sentence);
    REQUIRE(sentence == "first only");
  }
}

TEST_CASE("Remove stop words from sentence", "[removeStopWords]")
{
  SECTION("Remove commas") {
    std::string sentence = "Remove, comma";
    Preprocessor::removeStopWords(sentence);
    REQUIRE(sentence == "Remove  comma");
  }
}

TEST_CASE("Sanitize sentence", "[sanitize]")
{
  SECTION("Remove digits") {
    std::string sentence = "Remo5ve digits1";
    Preprocessor::sanitize(sentence);
    REQUIRE(sentence == "Remove digits");
  }

  SECTION("Remove punctuations") {
    std::string sentence = "Remo%$#ve, dig__its";
    Preprocessor::sanitize(sentence);
    REQUIRE(sentence == "Remove digits");
  }
}

TEST_CASE("Tokenize sentence", "[tokenize]")
{
  SECTION("Tokenize") {
    std::string sentence = "Tokenize me";
    std::set<std::string> tokens = {"Tokenize", "me"};
    REQUIRE(Preprocessor::tokenize(sentence) == tokens);
  }

  SECTION("Tokenize dirty") {
    std::string sentence = "Tokenize1% m-e";
    std::set<std::string> tokens = {"Tokenize1%", "m-e"};
    REQUIRE(Preprocessor::tokenize(sentence) == tokens);
  }
}
