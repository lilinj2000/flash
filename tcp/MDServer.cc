#include "MDServer.hh"
#include "util/FlashLog.hh"
#include "util/Util.hh"

namespace flash
{

MDServer::MDServer(soil::Options* options,
                   const std::string& instru,
                   const std::string& md_file,
                   const std::string& speed_file)
{
  FLASH_TRACE <<"MDServer::MDServer()";

  util_.reset( new Util() );
  
  if( !md_file.empty() )
    md_file_.reset( new air::MDataFile(md_file) );

  if( !speed_file.empty() )
    speed_file_.reset( new air::MDataFile(speed_file) );
  
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

  if( speed_file_.get() )
  {
    speed_file_->putData( util_->toSpeedMData(data) );
  }

  if( md_file_.get() )
  {
    md_file_->putData( util_->toCffexMData(data) );
  }

}

void MDServer::onRspError(int errord_id, const std::string& error_msg)
{
  FLASH_TRACE <<"MDServer::onRspError()";
}


};
