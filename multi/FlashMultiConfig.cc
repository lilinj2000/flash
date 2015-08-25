#include "FlashMultiConfig.hh"
#include "util/FlashLog.hh"
#include "fema/MultiMDService.hh"

#include <fstream>
#include <iostream>
#include <boost/program_options.hpp>

namespace flash
{

FlashMultiOptions::FlashMultiOptions():
    config_options_("FlashMultiConfigOptions")
{

  namespace po = boost::program_options;

  config_options_.add_options()
      ("flash.instrument_id", po::value<std::string>(&instrument_id), 
       "instrument id")
      ("flash.multi_md_file", po::value<std::string>(&multi_md_file), 
       "multi md file")

      ("flash.log_cfg", po::value<std::string>(&log_cfg), 
       "log config file")
      ;

  return;
  
}

FlashMultiOptions::~FlashMultiOptions()
{
}

po::options_description* FlashMultiOptions::configOptions()
{
  return &config_options_;
}

FlashConfig::FlashConfig(int argc, char* argv[])
{
  flash_multi_options_.reset(new FlashMultiOptions());
  fema_multimd_options_.reset( fema::MultiMDService::createOptions() );
      
  std::auto_ptr<soil::Config> config( soil::Config::create() );
  config->registerOptions( flash_multi_options_.get() );
  config->registerOptions( fema_multimd_options_.get() );

  config->configFile() = "flash_multi.cfg";
  config->loadConfig(argc, argv);
  
  // init the log
  FLASH_LOG_INIT( flash_multi_options_->log_cfg );
  
  return;
}

FlashConfig::~FlashConfig()
{
}

};  
