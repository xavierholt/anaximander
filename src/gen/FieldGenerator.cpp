#include "FieldGenerator.h"

namespace Plat
{
  std::default_random_engine FieldGenerator::cGenerator(time(0));

  FieldGenerator::FieldGenerator(): FieldGenerator(cGenerator()) {
    //All Done.
  }

  FieldGenerator::FieldGenerator(unsigned int seed): mGenerator(seed), mSeed(seed) {
    // All done.
  }
}
