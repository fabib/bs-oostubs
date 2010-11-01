/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                         C G A _ S T R E A M                               *
 *                                                                           *
 *---------------------------------------------------------------------------*/

#ifndef __cgastr_include__
#define __cgastr_include__

#include "object/o_stream.h"
#include "machine/cgascr.h"

/** \brief CGA based output mechanism, similar to cout
 *
 * CGA_Stream enables the output of different data as string using the CGA 
 * screen. It is derived from the class CGA_Screen which makes additional 
 * formats and effects available.
 * CGA_Stream extends the functionality of the classes CGA_Screen and O_Stream.
 */
class CGA_Stream  : public O_Stream, public CGA_Screen {
public:
 
  /** \brief flush the content of the internal buffer
   *
   * \todo write implementation
   *
   * It is called automaticaly as soon as the buffer is full or if a newline is
   * encountered.
   **/
  virtual void flush();
};

#endif
