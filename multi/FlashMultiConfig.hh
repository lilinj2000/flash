#ifndef FLASH_MULTI_CONFIG_HH
#define FLASH_MULTI_CONFIG_HH

#include <string>
#include <memory>
#include "soil/Config.hh"

namespace flash
{

namespace po = boost::program_options;

class FlashMultiOptions : public soil::Options
{
 public:

  FlashMultiOptions();
  
  virtual ~FlashMultiOptions();

  virtual po::options_description* configOptions();

  std::string instrument_id;
  std::string multi_md_file;
  std::string speed_md_file;
  std::string log_cfg;

 private:
  boost::program_options::options_description config_options_;
};

class FlashConfig
{
 public:
  
  FlashConfig(int argc=0, char* argv[]=NULL);
  ~FlashConfig();

  FlashMultiOptions* flashMultiOptions()
  {
    return flash_multi_options_.get();
  }

  soil::Options* foalMultiMDOptions()
  {
    return foal_multimd_options_.get();
  }

 private:
  std::unique_ptr<FlashMultiOptions> flash_multi_options_;
  
  std::unique_ptr<soil::Options> foal_multimd_options_;  

};

}  


#endif 
