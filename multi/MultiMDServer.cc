#include "MultiMDServer.hh"
#include "util/FlashLog.hh"
#include "util/Util.hh"

namespace flash
{

MultiMDServer::MultiMDServer(soil::Options* options,
                             const std::string& instru,
                             const std::string& multi_md_file,
                             const std::string& speed_md_file)
{
  FLASH_TRACE <<"MultiMDServer::MultiMDServer()";

  util_.reset( new Util() );

  if( !multi_md_file.empty() )
  {
    multi_md_file_.reset( new air::MDataFile(multi_md_file, instru) );
  }

  if( !speed_md_file.empty() )
  {
    speed_md_file_.reset( new air::MDataFile(speed_md_file, instru) );
  }
  
  multimd_service_.reset( foal::MultiMDService::createService(options, this) );

}

MultiMDServer::~MultiMDServer()
{
  FLASH_TRACE <<"MultiMDServer::~MultiMDServer()";
}

void MultiMDServer::onRtnMarketData(const foal::DepthMarketData* data)
{
  FLASH_TRACE <<"MultiMDServer::onRtnMarketData()";

  if( speed_md_file_.get() )
  {
    speed_md_file_->putData( util_->toSpeedMData(data) );
  }

  if( multi_md_file_.get() )
  {
    multi_md_file_->putData( util_->toCffexMData(data) );
  }

}

void MultiMDServer::onRspError(int errord_id, const std::string& error_msg)
{
  FLASH_TRACE <<"MultiMDServer::onRspError()";
}


};
