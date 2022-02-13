#include <catch2/catch_all.hpp>
#include "../src/processor/Analyzer.hpp"
#include "../src/model/intents/None.hpp"
#include "../src/model/intents/GetFact.hpp"
#include "../src/model/intents/GetWeather.hpp"
#include "../src/service/IntentRecognitionService.hpp"

TEST_CASE("One learned prediction", "[Analyzer]")
{
  auto sut = Analyzer();
  auto intentDefinition = IntentDefinition();
  intentDefinition.Input.push_back("What is the weather today?");
  intentDefinition.Intent = GetWeather::ID;
  intentDefinition.EntitiesConfigurations["Paris"] = "City";

  std::vector<IntentDefinition> intentDefintions{
    intentDefinition
  };

  SECTION("Full match"){
    std::string intent;
    sut.analyze(intentDefintions);
    sut.predict({"What", "is", "the", "weather", "today?"}, intent);
    REQUIRE(intent == GetWeather::ID);
  }

  SECTION("Part match"){
    std::string intent;
    sut.analyze(intentDefintions);
    sut.predict({"What", "is"}, intent);
    REQUIRE(intent == GetWeather::ID);
  }

  SECTION("No matching words"){
    std::string intent;
    sut.analyze(intentDefintions);
    sut.predict({"Tell", "me", "fact"}, intent);
    REQUIRE(intent == None::ID);
  }

  SECTION("Empty input"){
    std::string intent;
    sut.analyze(intentDefintions);
    sut.predict({}, intent);
    REQUIRE(intent == None::ID);
  }
}

TEST_CASE("Two learned with common words prediction", "[Analyzer]")
{
  auto sut = Analyzer();
  auto intentDefinition = IntentDefinition();
  intentDefinition.Input.push_back("What is the weather today?");
  intentDefinition.Intent = GetWeather::ID;
  intentDefinition.EntitiesConfigurations["Paris"] = "City";

  auto intentDefinition2 = IntentDefinition();
  intentDefinition2.Input.push_back("Tell me the fact.");
  intentDefinition2.Intent = GetFact::ID;
  intentDefinition2.EntitiesConfigurations["Paris"] = "City";

  std::vector<IntentDefinition> intentDefintions{
    intentDefinition, intentDefinition2
  };

  SECTION("Match with mixed words"){
    std::string intent;
    sut.analyze(intentDefintions);
    sut.predict({"Tell", "me", "the", "weather", "today?"}, intent);
    REQUIRE(intent == GetWeather::ID);
  }

  SECTION("Part match with more important word"){
    std::string intent;
    sut.analyze(intentDefintions);
    sut.predict({"What", "is", "the", "fact"}, intent);
    REQUIRE(intent == GetFact::ID);
  }

  SECTION("Match with partially matching"){
    std::string intent;
    sut.analyze(intentDefintions);
    sut.predict({"Tell", "some", "fact"}, intent);
    REQUIRE(intent == GetFact::ID);
  }
}

TEST_CASE("Corrupted input prediction", "[IntentRecognitionService]")
{
  auto sut = IntentRecognitionService();
  sut.init("train_data.json");

  SECTION("Digits inside"){
    std::string intent;
    auto intentDefinition = sut.recognize("Wha1t i2s t3he we4ather t5oday?");
    REQUIRE(intentDefinition.Intent == GetWeather::ID);
  }

  SECTION("Punktuations without space inside") {
    std::string intent;
    auto intentDefinition = sut.recognize("What is the weather,today?");
    REQUIRE(intentDefinition.Intent == GetWeather::ID);
  }

  SECTION("Fully corrupted word") {
    std::string intent;
    auto intentDefinition = sut.recognize("What is #$%^ weather,today?");
    REQUIRE(intentDefinition.Intent == GetWeather::ID);
  }

  SECTION("Multiple spaces") {
    std::string intent;
    auto intentDefinition = sut.recognize("What      is #$   %^ weather     ,today?");
    REQUIRE(intentDefinition.Intent == GetWeather::ID);
  }

  SECTION("Punctuation between words") {
    std::string intent;
    auto intentDefinition = sut.recognize("What$%^is^&*weather%^&today?");
    REQUIRE(intentDefinition.Intent == None::ID);
  }

  SECTION("Punctuation as prefix and postfix of words") {
    std::string intent;
    auto intentDefinition = sut.recognize("What$%, ^is^& *weather%^, &today?");
    REQUIRE(intentDefinition.Intent == GetWeather::ID);
  }
}
