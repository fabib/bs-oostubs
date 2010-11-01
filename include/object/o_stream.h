/*****************************************************************************
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                            O _ S T R E A M                                *
 *                                                                           *
 *---------------------------------------------------------------------------*/

#ifndef __o_stream_include__
#define __o_stream_include__

#include "object/strbuf.h"

/**
 * O_Stream extends the Stringbuffer and contains the definitions of the 
 * << operator of the most important predefined datatypes. It is used to 
 * implement the known usability of the C++ io_stream library. 
 * At the moment the display of characters, strings and digits is supported.
 * Besides the operator definition contained in O_Stream several auxiliary 
 * manipulators are defined. These manipulators are used to choose the basis 
 * for display of digits and to print the buffer after an endl.
 */
class O_Stream : public Stringbuffer{
public:

  /** basis for display of digits eg. 2, 8, 10 or 16 */
  enum Base
  {
	  bin=2,
	  oct=8,
	  dec=10,
	  hex=16
  };

  /** current selected base
   *
   *  \todo write declaration
   * **/


  /** Default constructor initialising with dezimal system
   *
   *  \todo write implementation
   **/
 O_Stream();

  /** Default Destructor
   *
   * \todo write implementation
   * **/
 virtual ~O_Stream();

  /** 
   * Operator << overloading the default operator. Is used to convert
   * the given datatype into a string that can be printed on an output device.
   * This operator has to be implemented for every standard data type (char, 
   * unsigned char, short, unsigned short, int, unsigned int, long, 
   * unsigned long, void*, char*).
   *
   * \todo write implementation
   *
   * @param value value of datatype (has the type of datatype) 
   * @return reference to the current O_Stream object.
   **/
  O_Stream& operator << (char value); 

  /** \copydoc operator<<(char value) **/
  O_Stream& operator << (unsigned char value);

  /** \copydoc operator<<(char value) **/
  O_Stream& operator << (char* value);

  /** \copydoc operator<<(char value) **/
  O_Stream& operator << (const char* value);

  /** \copydoc operator<<(char value) **/
  O_Stream& operator << (unsigned short value); 

  /** \copydoc operator<<(char value) **/
  O_Stream& operator << (short value); 

  /** \copydoc operator<<(char value) **/
  O_Stream& operator << (unsigned int value);

  /** \copydoc operator<<(char value) **/
  O_Stream& operator << (int value);

  /** \copydoc operator<<(char value) **/
  O_Stream& operator << (unsigned long value);

  /** \copydoc operator<<(char value) **/
  O_Stream& operator << (long value);

  /** \copydoc operator<<(char value) **/
  O_Stream& operator << (void* value);

  /**
   * Operator << overloading the default operator is used to call defined 
   * manipulators.
   *
   * \todo write implementation
   *
   * @param f mainpulator function to be applied to the ostream
   * @return reference to the current O_Stream object.
   **/
  O_Stream& operator << (O_Stream& (*f) (O_Stream&));

  /** declaration for manipulator functions **/

  friend O_Stream& endl(O_Stream&);
  friend O_Stream& bin(O_Stream&);
  friend O_Stream& oct(O_Stream&);
  friend O_Stream& dec(O_Stream&);
  friend O_Stream& hex(O_Stream&);
};

/*---------------------------------------------------------------------------*
 *                                                                           *
 *                          M A N I P U L A T O R E N                        *
 *                                                                           *
 *---------------------------------------------------------------------------*/
/**
 * The following methods receive and return a referenz to the current O_Stream
 * object. Class O_Stream defines an operator that can be used to call this so
 * called manipulators. It is eveen possible to embedd the output of the method
 * into the input of the stream.
 * Main goal of the manipulators is to influence the display of the following 
 * output (eg. by choosing a basis for the display of digits).
 **/ 

/** ENDL: prints buffer after adding a newline at the end of the buffer */
	O_Stream& endl(O_Stream &out);
 
/** BIN: choose binary basis for display */
	O_Stream& bin(O_Stream &out);
 
/** OCT: choose oktale basis for display */
	O_Stream& oct(O_Stream &out);
 
/** DEC: choose dezimal basis for display */
	O_Stream& dec(O_Stream &out);
 
/** HEX: choose hexadezimal basis for display */
	O_Stream& hex(O_Stream &out);
 
#endif
