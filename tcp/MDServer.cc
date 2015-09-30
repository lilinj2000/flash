#include "MDServer.hh"
#include "util/FlashLog.hh"

namespace flash
{

MDServer::MDServer(soil::Options* options,
                   const std::string& instru,
                   const std::string& md_file)
{
  FLASH_TRACE <<"MDServer::MDServer()";

  md_file_.reset( new air::MData(md_file) );
  
  md_service_.reset( foal::MDService::createService(options, this) );

  foal::InstrumentSet instrus;
  instrus.insert( instru );
  md_service_->subMarketData( instrus );
}

MDServer::~MDServer()
{
  FLASH_TRACE <<"MDServer::~MDServer()";
}

void MDServer::onRspSubMarketData(const std::string& instru, bool success)
{
  FLASH_TRACE <<"MDServer::onRspSubMarketData()";
}

void MDServer::onRspUnsubMarketData(const std::string& instru, bool success)
{
  FLASH_TRACE <<"MDServer::onRspUnsubMarketData()";
}

void MDServer::onRtnMarketData(const foal::DepthMarketData* data)
{
  FLASH_TRACE <<"MDServer::onRtnMarketData()";

  md_file_->pushMData( data->InstrumentID, data->UpdateTime,
                       data->UpdateMillisec );
}

void MDServer::onRspError(int errord_id, const std::string& error_msg)
{
  FLASH_TRACE <<"MDServer::onRspError()";
}


};
