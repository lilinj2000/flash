#include "FlashConfig.hh"
#include "FlashLog.hh"
#include "fema/MDService.hh"
#include "fema/MultiMDService.hh"

#include <fstream>
#include <iostream>
#include <boost/program_options.hpp>

namespace flash
{

FlashOptions::FlashOptions():
    config_options_("FlashConfigOptions")
{

  namespace po = boost::program_options;

  config_options_.add_options()
      ("flash.instrument_id", po::value<std::string>(&instrument_id), 
       "instrument id")
      ("flash.tcp_md_file", po::value<std::string>(&tcp_md_file), 
       "tcp md file")
      ("flash.multi_md_file", po::value<std::string>(&multi_md_file), 
       "multi md file")

      ("flash.log_cfg", po::value<std::string>(&log_cfg), 
       "log config file")
      ;

  return;
  
}

FlashOptions::~FlashOptions()
{
}

po::options_description* FlashOptions::configOptions()
{
  return &config_options_;
}

FlashConfig::FlashConfig(int argc, char* argv[])
{
  flash_options_.reset(new FlashOptions());
  fema_md_options_.reset( fema::MDService::createOptions() );
  fema_multimd_options_.reset( fema::MultiMDService::createOptions() );
      
  std::auto_ptr<soil::Config> config( soil::Config::create() );
  config->registerOptions( flash_options_.get() );
  config->registerOptions( fema_md_options_.get() );
  config->registerOptions( fema_multimd_options_.get() );

  config->configFile() = "flash.cfg";
  config->loadConfig(argc, argv);
  
  // init the log
  FLASH_LOG_INIT( flash_options_->log_cfg );
  
  return;
}

FlashConfig::~FlashConfig()
{
}

};  
