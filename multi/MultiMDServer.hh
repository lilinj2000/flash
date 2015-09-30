#ifndef FLASH_MULTI_MDSERVER_HH
#define FLASH_MULTI_MDSERVER_HH

#include "foal/MultiMDService.hh"
#include "air/MData.hh"

namespace flash
{

class MultiMDServer : public foal::MultiMDServiceCallback
{
 public:
  MultiMDServer(soil::Options* options,
                const std::string& instru,
                const std::string& multimd_file);

  virtual ~MultiMDServer();
  
  virtual void onRtnMarketData(const foal::DepthMarketData* data);

  virtual void onRspError(int errord_id, const std::string& error_msg);

 private:

  std::auto_ptr<foal::MultiMDService> multimd_service_;

  std::auto_ptr<air::MData> multimd_file_;
};

};

#endif
