#ifndef FLASH_CONFIG_HH
#define FLASH_CONFIG_HH

#include <string>
#include <memory>
#include "soil/Config.hh"

namespace flash
{

namespace po = boost::program_options;

class FlashOptions : public soil::Options
{
 public:

  FlashOptions();
  
  virtual ~FlashOptions();

  virtual po::options_description* configOptions();

  std::string instrument_id;
  std::string tcp_md_file;
  std::string multi_md_file;
  std::string log_cfg;

 private:
  boost::program_options::options_description config_options_;
};

class FlashConfig
{
 public:
  
  FlashConfig(int argc=0, char* argv[]=NULL);
  ~FlashConfig();

  FlashOptions* flashOptions()
  {
    return flash_options_.get();
  }

  soil::Options* femaMDOptions()
  {
    return fema_md_options_.get();
  }

  soil::Options* femaMultiMDOptions()
  {
    return fema_multimd_options_.get();
  }

 private:
  std::auto_ptr<FlashOptions> flash_options_;
  
  std::auto_ptr<soil::Options> fema_md_options_;

  std::auto_ptr<soil::Options> fema_multimd_options_;
};

}  


#endif 
