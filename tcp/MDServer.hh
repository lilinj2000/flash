#ifndef FLASH_MDSERVER_HH
#define FLASH_MDSERVER_HH

#include "foal/MDService.hh"
#include "air/MDataFile.hh"

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

  std::unique_ptr<foal::MDService> md_service_;

  std::unique_ptr<air::MDataFile> md_file_;
  std::unique_ptr<air::MDataFile> speed_file_;

  std::unique_ptr<Util> util_;
};

};

#endif
