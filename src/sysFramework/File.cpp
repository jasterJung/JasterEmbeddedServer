// **************************************************************
// Com ++ Framework by the C++ World
// Please report defects: mailto:compp@cplusplusworld.com
// Please visit: http://www.cplusplusworld.com/socketlibrary.html
// **************************************************************

#include <sys/types.h>
#include "common/File.h"
#include "common/CommonNet.h"
#include <sys/stat.h>
#include <fcntl.h>


/**
  * Destructor
  **/
common::File::~File () {


}

/**
  * Constructor
  **/
common::File::File ( ) {

  SetName ( "" );

}

/**
  * Constructor
  **/
common::File::File (const std::string & FileName) {

  SetName ( FileName );
  OpenRW();

}
/**
  * Set FileName
  **/
void common::File::SetName (const std::string & FileName){
  FN = FileName;
}
void common::File::OpenWR(){

  if ( fd != -1 )
    Close();

  fd = common::Net::Open ( FN.c_str(), O_WRONLY|O_CREAT, 0644 ) ;
  if ( fd == -1 )
	  std::cout << "Cannot open file" ;
    //throw syspp::ComException ( "Cannot open file" ) ;
  IsOpen = true;
}
void common::File::OpenRD(){

  if ( fd != -1 )
    Close();

  fd = common::Net::Open ( FN.c_str(), O_RDONLY ) ;
  if ( fd == -1 )
	  std::cout << "Cannot open file" ;
    //throw syspp::ComException ( "Cannot open file" ) ;
  IsOpen = true;

}
void common::File::OpenRW(){

  if ( fd != -1 )
    Close();

  fd = common::Net::Open ( FN.c_str(), O_RDONLY|O_WRONLY|O_CREAT, 0644 ) ;
  if ( fd == -1 )
	  std::cout << "Cannot open file" ;
    //throw syspp::ComException ( "Cannot open file" ) ;

  IsOpen = true;
}

/**
  * Sorry. Not implemented yet.
  **/
void common::File::Truncate(){

  if ( fd != -1 )
    Close();

  fd = common::Net::Open ( FN.c_str(), O_RDONLY|O_WRONLY|O_CREAT|O_TRUNC, 0644 ) ;
  if ( fd == -1 )
	  std::cout << "Cannot open file" ;
    //throw syspp::ComException ( "Cannot open file" ) ;

}

/**
  * Sorry. Not implemented yet.
  **/
void common::File::Create (){

  if ( fd != -1 )
    Close();

  fd = common::Net::Open ( FN.c_str(), O_RDONLY|O_WRONLY|O_CREAT, 0644 ) ;
  if ( fd == -1 )
	  std::cout << "Cannot open file" ;
    //throw syspp::ComException ( "Cannot open file" ) ;

  IsOpen = true;
}

/**
  * Sorry. Not implemented yet.
  **/
void common::File::Lock (){
}

/**
  * Sorry. Not implemented yet.
  **/
void common::File::UnLock (){
}


/**
  * Deletes the file from the file system.
  **/
void common::File::Delete (){
  common::Net::Unlink (FN.c_str());
}
void common::File::Chmod (mode_t mode){

  if ( fd == -1 ) {
    if ( FN != "" ) {
      if ( -1 == common::Net::Chmod ( FN.c_str(), mode ) ) {
    	  std::cout << "Cannot chmod" ;
	//throw syspp::ComException ( "Cannot chmod" ) ;
      }
    }
  } else {
    if ( -1 == common::Net::FChmod ( fd , mode ) ) {
    	std::cout << "Cannot chmod" ;
      //throw syspp::ComException ( "Cannot chmod" ) ;
    }
  }

}


/**
  * Sorry. Not implemented yet.
  **/
void common::File::SetPerm (){
}


/**
  * Sorry. Not implemented yet.
  **/
void common::File::SetOwnerRD (){

  Chmod ( 0 );

}

/**
  * Sorry. Not implemented yet.
  **/
void common::File::SetOwnerWR (){
}

/**
  * Sorry. Not implemented yet.
  **/
void common::File::SetOwnerRW (){
}

/**
  * Sorry. Not implemented yet.
  **/

/**
  * Sorry. Not implemented yet.
  **/

void common::File::SetGroupRD (){
}

/**
  * Sorry. Not implemented yet.
  **/
void common::File::SetGroupWR (){
}

/**
  * Sorry. Not implemented yet.
  **/
void common::File::SetGroupRW (){
}

/**
  * Sorry. Not implemented yet.
  **/

void common::File::SetOthersRD (){
}

/**
  * Sorry. Not implemented yet.
  **/
void common::File::SetOthersWR (){
}

/**
  * Sorry. Not implemented yet.
  **/
void common::File::SetOthersRW (){
}



/**
  * Sorry. Not implemented yet.
  **/
bool common::File::Exist ( const std::string & FileName ){
  return false;
}

/**
  * Sorry. Not implemented yet.
  **/
bool common::File::IsWriteable ( const std::string & FileName ){
  return false;
}

/**
  * Sorry. Not implemented yet.
  **/
bool common::File::IsReadable ( const std::string & FileName ){
  return false;
}

/**
  * Sorry. Not implemented yet.
  **/
void common::File::SetOwnerRD ( const std::string & FileName ){
}

/**
  * Sorry. Not implemented yet.
  **/
void common::File::SetOwnerWR ( const std::string & FileName ){
}

/**
  * Sorry. Not implemented yet.
  **/
void common::File::SetOwnerRW ( const std::string & FileName ){
}

/**
  * Sorry. Not implemented yet.
  **/
void common::File::SetGroupRD ( const std::string & FileName ){
}

/**
  * Sorry. Not implemented yet.
  **/
void common::File::SetGroupWR ( const std::string & FileName ){
}

/**
  * Sorry. Not implemented yet.
  **/
void common::File::SetGroupRW ( const std::string & FileName ){
}

/**
  * Sorry. Not implemented yet.
  **/
void common::File::SetOthersRD ( const std::string & FileName ){
}

/**
  * Sorry. Not implemented yet.
  **/
void common::File::SetOthersWR ( const std::string & FileName ){
}

/**
  * Sorry. Not implemented yet.
  **/
void common::File::SetOthersRW ( const std::string & FileName ){
}

void common::File::Delete ( const std::string & FileName ){

  common::Net::Unlink (FileName.c_str());

}


/**
  * Sorry. Not implemented yet.
  **/
void common::File::Chmod (const std::string & FileName, mode_t mode){
	chmod(FileName.c_str(),  mode);
}
