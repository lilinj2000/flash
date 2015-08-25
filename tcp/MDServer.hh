#ifndef FLASH_MDSERVER_HH
#define FLASH_MDSERVER_HH

#include "fema/MDService.hh"

namespace flash
{

class MData;

class MDServer : public fema::MDServiceCallback
{
 public:
  MDServer(soil::Options* options,
           const std::string& instru,
           const std::string& md_file);

  virtual ~MDServer();
  
  virtual void onRspSubMarketData(const std::string& instru, bool success);

  virtual void onRspUnsubMarketData(const std::string& instru, bool success);

  virtual void onRtnMarketData(const fema::DepthMarketData* data);

  virtual void onRspError(int errord_id, const std::string& error_msg);

 private:

  std::auto_ptr<fema::MDService> md_service_;

  std::auto_ptr<MData> md_file_;
};

};

#endif
