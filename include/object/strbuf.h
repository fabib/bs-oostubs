/*****************************************************************************
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                       S T R I N G B U F F E R                             *
 *                                                                           *
 *---------------------------------------------------------------------------*/

#ifndef __strbuf_include__
#define __strbuf_include__

/**
 * Stringbuffer implements a buffer gathering characters that have to be 
 * outputed on the screen or a differenct output device. If the buffer is full
 * or the user wishes to print the content of the buffer on the output device
 * method flush() is called. To enable Stringbuffer to work with different 
 * output devices method flush() has to be implemented by the subclasses of 
 * Stringbuffer.
 * Since every subclass needs access to the variables and methods of the
 * Stringbuffer every variable and method of Stringbuffer is declared 
 * 'protected'.
 */
class Stringbuffer {
protected:
  /** buffer containing the characters of the Stringbuffer
   *
   * \todo write declaration
   **/

  /** buffer pointer saving the position of the next insertion 
   *
   * \todo write declaration
   **/

  /** Default constructor of Stringbuffer setting the buffer empty.
   *
   * \todo write implementation
   **/
  Stringbuffer();

  /** Default destructor of Stringbuffer. Flushes the buffer.
   *
   * \todo write implementation
   **/
  virtual ~Stringbuffer();

  /** 
   * Method put() inserts a character into the buffer. If the buffer is full 
   * after the insertion the buffer has to be emptied by calling the method 
   * flush().
   *
   * \todo write implementation
   *
   * @param c character to be inserted into the buffer
   **/
  void put(char c); 

  /**
   * Method flush() prints the curent content of the buffer. It is called 
   * automaticaly as soon as the buffer is full or manualy if an output is 
   * forced. After printing the buffer content the buffer pointer is reseted.
   * To enalbe the Stringbuffer to work with different output mechanisms the
   * method has to be implemented in a subclass of Stringbuffer.
   **/
  virtual void flush() = 0;
};

#endif
