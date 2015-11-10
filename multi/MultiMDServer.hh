#ifndef FLASH_MULTI_MDSERVER_HH
#define FLASH_MULTI_MDSERVER_HH

#include "foal/MultiMDService.hh"
#include "air/MDataFile.hh"

namespace flash
{

class Util;

class MultiMDServer : public foal::MultiMDServiceCallback
{
 public:
  MultiMDServer(soil::Options* options,
                const std::string& instru,
                const std::string& multi_md_file,
                const std::string& speed_md_file);

  virtual ~MultiMDServer();
  
  virtual void onRtnMarketData(const foal::DepthMarketData* data);

  virtual void onRspError(int errord_id, const std::string& error_msg);

 private:

  std::unique_ptr<foal::MultiMDService> multimd_service_;

  std::unique_ptr<air::MDataFile> multi_md_file_;
  std::unique_ptr<air::MDataFile> speed_md_file_;
  std::unique_ptr<Util> util_;
};

};

#endif
