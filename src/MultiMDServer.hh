#ifndef FLASH_MULTI_MDSERVER_HH
#define FLASH_MULTI_MDSERVER_HH

#include "fema/MultiMDService.hh"

namespace flash
{

class MData;

class MultiMDServer : public fema::MultiMDServiceCallback
{
 public:
  MultiMDServer(soil::Options* options,
                const std::string& instru,
                const std::string& multimd_file);

  virtual ~MultiMDServer();
  
  virtual void onRtnMarketData(const fema::DepthMarketData* data);

  virtual void onRspError(int errord_id, const std::string& error_msg);

 private:

  std::auto_ptr<fema::MultiMDService> multimd_service_;

  std::auto_ptr<MData> multimd_file_;
};

};

#endif
