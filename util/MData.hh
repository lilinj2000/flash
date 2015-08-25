#ifndef MDATA_HH
#define MDATA_HH

#include <string>
#include <fstream>

#include "fema/FemaDef.hh"

namespace flash
{

class MData
{
 public:
  MData(const std::string& file);

  virtual ~MData();

  void outDepthMarketData(const fema::DepthMarketData* data);

 private:
  
  std::ofstream  file_;
};

};

#endif
