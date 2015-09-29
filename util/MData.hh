#ifndef FLASH_MDATA_HH
#define FLASH_MDATA_HH

#include <string>
#include <fstream>

#include "foal/FoalDef.hh"

namespace flash
{

class MData
{
 public:
  MData(const std::string& file);

  virtual ~MData();

  void outDepthMarketData(const foal::DepthMarketData* data);

 private:
  
  std::ofstream  file_;
};

};

#endif
