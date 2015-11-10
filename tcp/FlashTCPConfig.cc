#include "FlashTCPConfig.hh"
#include "util/FlashLog.hh"
#include "foal/MDService.hh"

#include <fstream>
#include <iostream>
#include <boost/program_options.hpp>

namespace flash
{

FlashTCPOptions::FlashTCPOptions():
    config_options_("FlashTCPConfigOptions")
{

  namespace po = boost::program_options;

  config_options_.add_options()
      ("flash.instrument_id", po::value<std::string>(&instrument_id), 
       "instrument id")
      ("flash.tcp_md_file", po::value<std::string>(&tcp_md_file), 
       "tcp md file")
      ("flash.speed_md_file", po::value<std::string>(&speed_md_file), 
       "speed md file")

      ("flash.log_cfg", po::value<std::string>(&log_cfg), 
       "log config file")
      ;

  return;
  
}

FlashTCPOptions::~FlashTCPOptions()
{
}

po::options_description* FlashTCPOptions::configOptions()
{
  return &config_options_;
}

FlashConfig::FlashConfig(int argc, char* argv[])
{
  flash_tcp_options_.reset(new FlashTCPOptions());
  foal_md_options_.reset( foal::MDService::createOptions() );
      
  std::unique_ptr<soil::Config> config( soil::Config::create() );
  config->registerOptions( flash_tcp_options_.get() );
  config->registerOptions( foal_md_options_.get() );

  config->configFile() = "tcp.cfg";
  config->loadConfig(argc, argv);
  
  // init the log
  FLASH_LOG_INIT( flash_tcp_options_->log_cfg );
  
  return;
}

FlashConfig::~FlashConfig()
{
}

};  
