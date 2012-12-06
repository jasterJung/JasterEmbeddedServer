// **************************************************************
// Com ++ Framework by the C++ World
// Please report defects: mailto:compp@cplusplusworld.com
// Please visit: http://www.cplusplusworld.com/socketlibrary.html
// **************************************************************
//#include "config.h"
#include "common/syslib.h"

#include "common/Tools.h"

#include <cerrno>
#include <stdio.h>
#include <sys/time.h>
#include <string>
#include <string.h>
#include <ctype.h>

#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "common/CommonNet.h"

#define DEFGEGENARR1   unsigned char GEGENARR1  [ 256 ] = {\
21,\
201,\
212,\
230,\
205,\
45,\
87,\
184,\
124,\
10,\
162,\
93,\
98,\
76,\
209,\
77,\
69,\
142,\
25,\
34,\
143,\
14,\
203,\
20,\
129,\
216,\
185,\
79,\
80,\
149,\
155,\
58,\
165,\
78,\
73,\
127,\
32,\
62,\
214,\
31,\
128,\
202,\
249,\
233,\
231,\
154,\
13,\
49,\
15,\
183,\
105,\
192,\
137,\
207,\
181,\
95,\
22,\
239,\
116,\
225,\
173,\
229,\
169,\
223,\
68,\
9,\
55,\
235,\
92,\
241,\
82,\
23,\
244,\
196,\
81,\
111,\
153,\
96,\
161,\
110,\
99,\
133,\
138,\
88,\
123,\
168,\
240,\
157,\
131,\
60,\
175,\
100,\
213,\
246,\
115,\
40,\
236,\
119,\
89,\
171,\
53,\
248,\
33,\
52,\
148,\
217,\
6,\
134,\
59,\
74,\
242,\
72,\
247,\
180,\
70,\
56,\
35,\
4,\
121,\
118,\
102,\
114,\
37,\
174,\
39,\
215,\
198,\
57,\
104,\
218,\
163,\
71,\
12,\
11,\
208,\
146,\
91,\
251,\
65,\
164,\
17,\
97,\
67,\
8,\
90,\
197,\
63,\
224,\
226,\
130,\
167,\
170,\
84,\
204,\
26,\
194,\
191,\
122,\
106,\
245,\
86,\
54,\
2,\
243,\
44,\
126,\
178,\
152,\
132,\
64,\
136,\
109,\
5,\
41,\
144,\
237,\
18,\
38,\
187,\
195,\
166,\
222,\
159,\
19,\
1,\
75,\
0,\
206,\
120,\
177,\
117,\
28,\
199,\
188,\
47,\
211,\
101,\
179,\
156,\
200,\
190,\
66,\
7,\
234,\
158,\
228,\
253,\
83,\
125,\
238,\
36,\
193,\
140,\
43,\
221,\
220,\
254,\
219,\
42,\
186,\
139,\
160,\
103,\
29,\
141,\
135,\
46,\
145,\
151,\
252,\
27,\
61,\
232,\
172,\
189,\
50,\
107,\
48,\
250,\
113,\
176,\
182,\
51,\
147,\
30,\
255,\
112,\
108,\
16,\
227,\
85,\
3,\
210,\
94,\
150,\
24}




#define DEFARR1   unsigned char ARR1 [ 256 ] = {\
186,\
184,\
162,\
251,\
117,\
172,\
106,\
202,\
143,\
65,\
9,\
133,\
132,\
46,\
21,\
48,\
248,\
140,\
176,\
183,\
23,\
0,\
56,\
71,\
255,\
18,\
154,\
230,\
191,\
223,\
244,\
39,\
36,\
102,\
19,\
116,\
210,\
122,\
177,\
124,\
95,\
173,\
218,\
213,\
164,\
5,\
226,\
194,\
237,\
47,\
235,\
242,\
103,\
100,\
161,\
66,\
115,\
127,\
31,\
108,\
89,\
231,\
37,\
146,\
169,\
138,\
201,\
142,\
64,\
16,\
114,\
131,\
111,\
34,\
109,\
185,\
13,\
15,\
33,\
27,\
28,\
74,\
70,\
207,\
152,\
250,\
160,\
6,\
83,\
98,\
144,\
136,\
68,\
11,\
253,\
55,\
77,\
141,\
12,\
80,\
91,\
196,\
120,\
222,\
128,\
50,\
158,\
236,\
247,\
171,\
79,\
75,\
246,\
239,\
121,\
94,\
58,\
190,\
119,\
97,\
188,\
118,\
157,\
84,\
8,\
208,\
165,\
35,\
40,\
24,\
149,\
88,\
168,\
81,\
107,\
225,\
170,\
52,\
82,\
220,\
212,\
224,\
17,\
20,\
174,\
227,\
135,\
243,\
104,\
29,\
254,\
228,\
167,\
76,\
45,\
30,\
198,\
87,\
204,\
182,\
221,\
78,\
10,\
130,\
139,\
32,\
180,\
150,\
85,\
62,\
151,\
99,\
233,\
60,\
123,\
90,\
240,\
189,\
166,\
197,\
113,\
54,\
241,\
49,\
7,\
26,\
219,\
178,\
193,\
234,\
200,\
156,\
51,\
211,\
155,\
179,\
73,\
145,\
126,\
192,\
199,\
1,\
41,\
22,\
153,\
4,\
187,\
53,\
134,\
14,\
252,\
195,\
2,\
92,\
38,\
125,\
25,\
105,\
129,\
217,\
215,\
214,\
181,\
63,\
147,\
59,\
148,\
249,\
205,\
61,\
3,\
44,\
232,\
43,\
203,\
67,\
96,\
175,\
209,\
57,\
86,\
69,\
110,\
163,\
72,\
159,\
93,\
112,\
101,\
42,\
238,\
137,\
229,\
206,\
216,\
245}






common::int64 common::Tools::Time64 () {

  struct timeval t; 
  common::int64 retval=0;

  if ( common::Net::Gettimeofday(&t, NULL ) != 0 ) {
    return -1; 
  }

  retval = (common::int64) t.tv_sec * (int64) 1000000 + ( (int64)t.tv_usec / (int64) 1) ;
  
  return retval;
}

/**
 * Return a pointer to a static copy of the value of sys_errlist [errno] 
*/

std::string common::Tools::Perror() {

  static std::string retval= "";

  //(sys_errlist [errno]);

  
  return retval;
}

/**
 *  Stripping off all c - chars from the right.
*/

void common::Tools::RTrim ( std::string & str, char c ) {
  size_t posi;

  while ( ( posi = str.rfind ( c )) != std::string::npos ) {
    if ( posi != ( str.size()  -1) )
      break;
    str.erase ( posi, 1 );
  }
}

/**
   Stripping off all c - chars from the left.
*/


void common::Tools::LTrim ( std::string & str, char c ) {
  size_t posi;

  while ( ( posi = str.find ( c )) != std::string::npos ) {
    if ( posi != 0 )
      break;
    str.erase ( posi, 1 ); 
  }

}

/**
   Does a LTrim() and then a RTrim()
*/


void common::Tools::Trim  ( std::string & str, char c ) {

  common::Tools::LTrim (str,c);
  common::Tools::RTrim (str,c);

}

/**
 * Remoce all chars c from the string 
*/
void common::Tools::EraseChar  ( std::string & str, char c ) {
  size_t posi;

  while ( ( posi = str.find ( c )) != std::string::npos ) {
    str.erase ( posi, 1 ); 
  }

}

/**
 * Remoce all strings what from the string 
*/

void common::Tools::EraseStr ( std::string & str, const std::string & what ) {
  size_t posi;

  while ( ( posi = str.find ( what )) != std::string::npos ) {
    str.erase ( posi, what.size() ); 
  }

}


/**
 * Transform entire string to lowercase.  
 */

void common::Tools::ToLower ( std::string & str ) {

  for ( size_t i = 0; i < str.size(); ++ i ) {
    str[i]= (char) tolower ( (int) str[i] );
  }

}

/**
 * Transform entire string to uppercase.  
 */

void common::Tools::ToUpper ( std::string & str ) {

  for ( size_t i = 0; i < str.size(); ++ i ) {
    str[i]= (char) toupper ( (int)str[i] );
  }


}

/**
 * Copy string into vector of chars
 */

/*
void common::Tools::StrToVector ( std::vector<char> &tgt, const std::string & src ) {

    tgt.clear();
    AppendStrToVector ( tgt, src );

}
*/
/**
 * Append string to vector of chars
 */

/*
void common::Tools::AppendStrToVector ( std::vector<char> &tgt, const std::string & src ){

    for ( int i = 0; i < src.size(); ++i ) {
	tgt.push_back ( src[i] );
    }
    tgt.push_back ( '\0' );
}
*/
bool common::Tools::LoadTxtFile ( const std::string &FN, std::string &tgt ) {

    int fd, bytesread;
    char buf [8000];

    if ( -1 == ( fd = common::Net::Open ( FN.c_str(), O_RDONLY ) ) ) {
	return false;
    }

    tgt ="";

    do {

	bytesread = common::Net::Read ( fd, buf, sizeof ( buf ) -1 );

	if ( bytesread > 0 ) {
	    buf[bytesread]='\0';
	    tgt+=buf;
	}

	if ( bytesread == 0 ) {
	    common::Net::Close ( fd);
	    return true;
	}
    } while (bytesread >= 0 );

    common::Net::Close ( fd);
    return false;

}

bool common::Tools::LoadFile ( const std::string &FN, std::string &tgt ) {

    int fd, bytesread;
    char buf [8000];

    if ( -1 == ( fd = common::Net::Open ( FN.c_str(), O_RDONLY ) ) ) {
	return false;
    }

    tgt ="";

    do {

	bytesread = common::Net::Read ( fd, buf, sizeof ( buf ) -1 );

	if ( bytesread > 0 ) {
	    tgt.append ( buf, bytesread) ;
	}

	if ( bytesread == 0 ) {
	    common::Net::Close ( fd);
	    return true;
	}
    } while (bytesread >= 0 );

    common::Net::Close ( fd);
    return false;

}


bool common::Tools::SaveFile ( const std::string &FN, const std::string &buf ) {
    int fd;

    if ( -1 == ( fd = common::Net::Open ( FN.c_str(), O_WRONLY| O_CREAT|O_TRUNC, S_IRUSR|S_IWUSR ) ) ) {
	return false;
    }

    if ( buf.size() !=  (unsigned int)common::Net::Write ( fd, (void*)buf.c_str() , buf.size())) {
	common::Net::Close ( fd);
	return false;
    }
    
    common::Net::Close ( fd);
    return true;
}

bool common::Tools::SaveTxtFile ( const std::string &FN, const std::string &buf ) {
  return SaveFile( FN, buf );
}

long int common::Tools::StringToL ( const std::string & s ) {
	 return atol ( s.c_str() );
}


bool common::Tools::Popen ( const std::string & command, std::string & Result ) {

  std::string ret = "";
  FILE *fh;
  if ( NULL == ( fh = popen ( command.c_str(), "r" ) ) ) {
    return false; 
  }

  char cf [ 10000 ];
  int count;
  while ( ! feof ( fh ) ) {
    memset ( cf, 0, sizeof(cf) ); 
    
    count = fread ( cf, 1, sizeof ( cf )-1, fh );
    if ( count > 0 ) 
      ret.append ( (const char*) cf, count );
  }

  if ( pclose ( fh ) == -1 ) {
    return false;
  }
  if ( Result != ret )
    Result = ret;
  return true;
}

bool common::Tools::Dec ( std::string & Str ) {

  DEFARR1 ;

  for ( unsigned int i = 0; i < Str.length(); ++ i ) {
//     printf ( "DEC %ld -> %ld\n", (unsigned char) (Str[i]), (unsigned char)  (ARR1 [ (unsigned char) Str [ i ] ]) );
    Str [  i ] =  (unsigned char ) ARR1 [ (unsigned char ) Str [ i ] ];    
  }
  return true;
}

bool common::Tools::Enc ( std::string & Str ) {

  DEFGEGENARR1 ;

  for ( unsigned int i = 0; i < Str.length(); ++ i ) {
//     printf ( "ENC %ld -> %ld\n", (unsigned char)Str[i], (unsigned char)GEGENARR1 [ (unsigned char)Str [ i ] ] );
    Str [ i ] =  (unsigned char ) GEGENARR1 [ (unsigned char) Str [ i ] ];

  }
  return true;
}

bool common::Tools::IsExecutable ( const std::string & Path ) {

  if ( 0 == access( Path.c_str(),X_OK) ) {
    return true;
  }

  return false;
}
