#ifndef FLASH_MDSERVER_HH
#define FLASH_MDSERVER_HH

#include "foal/MDService.hh"
#include "air/MData.hh"

namespace flash
{

class Util;

class MDServer : public foal::MDServiceCallback
{
 public:
  MDServer(soil::Options* options,
           const std::string& instru,
           const std::string& md_file,
           const std::string& speed_file);

  virtual ~MDServer();
  
  virtual void onRspSubMarketData(const std::string& instru, bool success);

  virtual void onRspUnsubMarketData(const std::string& instru, bool success);

  virtual void onRtnMarketData(const foal::DepthMarketData* data);

  virtual void onRspError(int errord_id, const std::string& error_msg);

 private:

  std::auto_ptr<foal::MDService> md_service_;

  std::auto_ptr<air::MData> md_file_;
  std::auto_ptr<air::MData> speed_file_;

  std::auto_ptr<Util> util_;
};

};

#endif
