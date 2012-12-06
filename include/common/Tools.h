// **************************************************************
// Com ++ Framework by the C++ World
// Please report defects: mailto:compp@cplusplusworld.com
// Please visit: http://www.cplusplusworld.com/socketlibrary.html
// **************************************************************

#ifndef  TOOLS_H
#define  TOOLS_H

#include <cerrno>
#include <string>

namespace common {

  const int StdSocketBufSz = (1024*128) ;

  typedef short int uint16 ;
  typedef unsigned short int int16 ;

  typedef int int32 ;
  typedef unsigned int uint32 ;

  typedef long long int64 ;
  typedef unsigned long long uint64 ;

  
class Tools {
 public:
  static int64 Time64() ;
  static std::string Perror();
  static void RTrim ( std::string & s, char c ) ;
  static void LTrim ( std::string & s, char c ) ;
  static void Trim  ( std::string & s, char c ) ;
  static void EraseChar  ( std::string & s, char c ) ;
  static void EraseStr ( std::string & str, const std::string & what ) ;
  static void ToLower ( std::string & str );  
  static void ToUpper ( std::string & str );
  //  static void StrToVector ( std::vector<char> &tgt, const std::string & src );
  //  static void AppendStrToVector ( std::vector<char> &tgt, const std::string & src );
  static bool LoadTxtFile ( const std::string &FN, std::string &tgt ) ;
  static bool LoadFile ( const std::string &FN, std::string &tgt ) ;
  static bool SaveTxtFile ( const std::string &FN, const std::string &buf );
  static bool SaveFile ( const std::string &FN, const std::string &buf );
  static long int StringToL ( const std::string & s );
  static bool Popen ( const std::string & s, std::string & Result  );
  static bool Dec ( std::string & Str );
  static bool Enc ( std::string & Str ) ;
  static bool IsExecutable ( const std::string & Path );
}; 
}


#endif
