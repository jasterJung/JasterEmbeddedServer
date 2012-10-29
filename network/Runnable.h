#ifndef _RUNNABLE_H              //
#define _RUNNABLE_H



class Runnable {                // struct idiom

public:
  virtual void Run() = 0;//
  //virtual ~Runnable() = 0;
};

//Runnable::~Runnable(){};

#endif
