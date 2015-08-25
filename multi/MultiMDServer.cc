#include "MultiMDServer.hh"
#include "util/FlashLog.hh"
#include "util/MData.hh"

namespace flash
{

MultiMDServer::MultiMDServer(soil::Options* options,
                             const std::string& instru,
                             const std::string& multimd_file)
{
  FLASH_TRACE <<"MultiMDServer::MultiMDServer()";

  multimd_file_.reset( new MData(multimd_file) );
  
  multimd_service_.reset( fema::MultiMDService::createService(options, this) );

  multimd_service_->addFilter( instru );
}

MultiMDServer::~MultiMDServer()
{
  FLASH_TRACE <<"MultiMDServer::~MultiMDServer()";
}

void MultiMDServer::onRtnMarketData(const fema::DepthMarketData* data)
{
  FLASH_TRACE <<"MultiMDServer::onRtnMarketData()";

  FLASH_PDU <<*data;

  multimd_file_->outDepthMarketData( data );
}

void MultiMDServer::onRspError(int errord_id, const std::string& error_msg)
{
  FLASH_TRACE <<"MultiMDServer::onRspError()";
}


};
