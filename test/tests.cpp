#include <catch2/catch_all.hpp>
#include "../src/processor/Analyzer.hpp"

TEST_CASE("Factorials are computed", "[factorial]")
{
  auto sut = Analyzer();
  auto intentDefinition = IntentDefinition();
  intentDefinition.Input.push_back("What is the weather today?");
  intentDefinition.Intent = "Get Weather";
  intentDefinition.EntitiesConfigurations["Paris"] = "City";

  std::vector<IntentDefinition> intentDefintions{
    intentDefinition
  };

  std::string intent;
  sut.analyze(intentDefintions);
  sut.predict({"What", "is", "the", "weather", "today?"}, intent);
  REQUIRE(intent == intentDefinition.Intent);
}
