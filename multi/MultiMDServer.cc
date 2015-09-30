#include "MultiMDServer.hh"
#include "util/FlashLog.hh"

namespace flash
{

MultiMDServer::MultiMDServer(soil::Options* options,
                             const std::string& instru,
                             const std::string& multimd_file)
{
  FLASH_TRACE <<"MultiMDServer::MultiMDServer()";

  multimd_file_.reset( new air::MData(multimd_file, instru) );
  
  multimd_service_.reset( foal::MultiMDService::createService(options, this) );

}

MultiMDServer::~MultiMDServer()
{
  FLASH_TRACE <<"MultiMDServer::~MultiMDServer()";
}

void MultiMDServer::onRtnMarketData(const foal::DepthMarketData* data)
{
  FLASH_TRACE <<"MultiMDServer::onRtnMarketData()";

  // FLASH_PDU <<*data;

  multimd_file_->pushMData( data->InstrumentID,
                            data->UpdateTime,
                            data->UpdateMillisec );
}

void MultiMDServer::onRspError(int errord_id, const std::string& error_msg)
{
  FLASH_TRACE <<"MultiMDServer::onRspError()";
}


};
