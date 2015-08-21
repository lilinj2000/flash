#include "FlashServer.hh"
#include "FlashConfig.hh"
#include "MDServer.hh"
#include "MultiMDServer.hh"

namespace flash
{

FlashServer::FlashServer(int argc, char* argv[])
{
  cond_.reset( soil::Condition::create() );
    
  flash_config_.reset( new FlashConfig(argc, argv) );

  FlashOptions* flash_options = flash_config_->flashOptions();

  md_server_.reset( new MDServer(flash_config_->femaMDOptions(),
                                 flash_options->instrument_id,
                                 flash_options->tcp_md_file) );


  multimd_server_.reset( new MultiMDServer(
      flash_config_->femaMultiMDOptions(),
      flash_options->instrument_id,
      flash_options->multi_md_file) );

  do
  {
    cond_->wait(2000);
  }while( true );
                    
}

FlashServer::~FlashServer()
{
}

};
