#ifndef FLASH_UTIL_HH
#define FLASH_UTIL_HH

#include "air/MDataFile.hh"
#include "foal/FoalDef.hh"

namespace flash
{

class Util
{
 public:
  air::SpeedMData* toSpeedMData(const foal::DepthMarketData* data);

  air::CffexMData* toCffexMData(const foal::DepthMarketData* data);
};

};

#endif
