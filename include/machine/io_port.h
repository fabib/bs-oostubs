/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                              I O _ P O R T                                *
 *                                                                           *
 *---------------------------------------------------------------------------*/

#ifndef __io_port_include__
#define __io_port_include__

/**
 * Every computer uses a separate I/O memory that is only adressable by 
 * the methods <code>'in'</code> and <code>'out'</code>.
 * Each instance of IO_Port is an abstraction of an adress in that memory.
 * Using those abstractions adresses in memory can be accessed like ports. 
 */
class IO_Port {
  /** adress of the port in the I/O adress space */
  unsigned short address;
public:
  IO_Port (unsigned short a) : address (a) {};

  /**
   * Puts a value to the associated port.
   *
   * @param val byte value that will be put to the port
   */
  void outb (unsigned char val) const {
	asm("outb %1, %0"
		:
		:"d"(address), "a"(val)
		);
  };

  /**
   * Puts a value to the associated port.
   *
   * @param val word value that will be put to the port
   */
  void outw (unsigned short val) const { 
	asm("out %1, %0"
		:
		:"d"(address), "a"(val)
		);
  };

  /**
   * Gets a value from the associated port.
   *
   * @return the byte value from the associated port.
   */
  char inb () const {
	volatile char val=0;
    asm(
		"in %0, %%al\t\n"
		"mov %%al, (%1)"
		:
		:"d"(address), "r"(&val)
		:"%al"
		);
	return val;
  };

  /**
   * Gets a value from the associated port.
   *
   * @return the word value from the associated port.
   */
  short inw () const { 	
	volatile short val=0;
    asm(
		"in %0, %%ax\t\n"
		"mov %%ax, (%1)"
		:
		:"d"(address), "r"(&val)
		:"%ax"
		);
	return val;
  };
};

#endif
