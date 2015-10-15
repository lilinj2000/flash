#ifndef FLASH_UTIL_HH
#define FLASH_UTIL_HH

#include "air/MData.hh"
#include "foal/FoalDef.hh"

namespace flash
{

class Util
{
 public:
  air::SpeedMDataField* toSpeedMDataField(const foal::DepthMarketData* data);

  air::CffexMDataField* toCffexMDataField(const foal::DepthMarketData* data);
};

};

#endif
