#include "FieldGenerator.h"

namespace Plat
{
  std::default_random_engine FieldGenerator::cGenerator(time(0));

  FieldGenerator::FieldGenerator(): FieldGenerator(cGenerator()) {
    // All done.
  }

  FieldGenerator::FieldGenerator(unsigned int seed): mGenerator(seed), mSeed(seed) {
    // All done.
  }

  void FieldGenerator::generate(int xbits, int ybits) {
    Value::generate(xbits, ybits);
    mField = new Field(xbits, ybits);
    next(*mField);
  }
}
