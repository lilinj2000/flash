#include "MData.hh"

namespace flash
{

MData::MData(const std::string& file)
{
  file_.open( file.data() );
  
  if( !file_.good() )
  {
    throw std::runtime_error("open the data file " + file + " failed.");
  }
}

MData::~MData()
{
  file_.close();
}

void MData::outDepthMarketData(const fema::DepthMarketData* data)
{

  namespace bg=boost::gregorian;
  namespace bp=boost::posix_time;
  
  bg::date today(bg::from_undelimited_string(data->TradingDay));
  bp::ptime start_time(today, bp::duration_from_string(data->UpdateTime));
  start_time = start_time + bp::milliseconds(data->UpdateMillisec);

  bp::time_duration delay = data->time_stamp - start_time;
  
  file_<<data->UpdateTime <<"\t" <<data->UpdateMillisec <<"\t"
       <<start_time <<"\t"
       <<data->time_stamp <<"\t"
       <<delay.total_microseconds() <<std::endl;
}


};
