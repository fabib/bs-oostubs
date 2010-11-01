/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                       K E Y B O A R D _ C O N T R O L L E R               *
 *                                                                           *
 *---------------------------------------------------------------------------*/

#ifndef __Keyboard_Controller_include__
#define __Keyboard_Controller_include__

#include "machine/io_port.h"
#include "machine/key.h"

/** \brief Keyboard driver
 *
 * Abstraction of the keyboad controller of a computer.
 */
class Keyboard_Controller {
private:
  /**\brief the last read scancode **/
  unsigned char code;
  /**\brief the prefix for the currnet scancode **/
  unsigned char prefix;
  /** \brief Key to save the last input **/
  Key gather;
  /** \brief variable containing the current led status **/
  char leds;

  /** \brief Control port
   *
   * user defined port for seting status(R) or control(W) register
   **/
  const IO_Port ctrl_port;

  /** \brief Status port 
   *
   * user defined port for output(R) or input(W) of a buffer
   **/
  const IO_Port data_port;

  /** defined bits in the status register */
  enum { outb = 0x01, inpb = 0x02, auxb = 0x20 };

  /** keyboard commands. */
  struct kbd_cmd {
  	enum { set_led = 0xed, set_speed = 0xf3 };
  };
  
  enum { cpu_reset = 0xfe };

  /** keyboard responses */
  struct kbd_reply {
	  enum { ack = 0xfa };
  }; 

  /** constants used to decode the keyboard codes */
  enum { break_bit = 0x80, prefix1 = 0xe0, prefix2   = 0xe1 };

public:
  /** name of the keyboard LEDs */
  struct led {
    enum Leds{ caps_lock = 4, num_lock = 2, scroll_lock = 1 };
  };
  
private:
  /** \brief Scancode translation table without modifier**/
  static unsigned char normal_tab[];

  /** \brief Scancode translation table if shift is pressed**/
  static unsigned char shift_tab[];

  /** \brief Scancode translation table if alt is pressed**/
  static unsigned char alt_tab[];

  /** \brief Scancode translation table to ascii for numeric block**/
  static unsigned char asc_num_tab[];

  /** \brief Scancode translation table to special keys for numeric block**/
  static unsigned char scan_num_tab[];
         
  /**
   * Interpretes the make and break code of the keyboard an returns an valid
   * ASCII code, scancode and information about modifier keys like SHIFT and 
   * CTRL. 
   *
   * @return TRUE if character is komplete otherwise FALSE.
   */
  bool key_decoded ();

  /** 
   * Determins the ASCII code of a key according to the scancode and 
   * modifier bits.
   */
  void get_ascii_code ();
public:

   /**
    * Default constructor initially turns all LEDs of and sets speed and delay
    * of the keyboard maximal also clears the keyboard buffers.
    */
   Keyboard_Controller ();

  /**
   * Is used to get the information of the pressed key after is has been 
   * pressed. If a scancode and ASCII code could not be determined an invalid 
   * key is returned.
   *
   * \todo write implementation
   *
   * @return an invalid key if data transfer has not ended otherwise a valid 
   *         key with every information is returned. Can be checked withd 
   *         Key::valid().
   */
  Key key_hit ();

  /** \brief Reboots the computer using a keyboard controller command. **/
  void reboot ();

  /**
   * Sets the speed and delay of repeats of the keyboard. 
   *
   * \todo write implementation
   *
   * @param speed defines speed of a repeat (0 fast - 31 slow)
   * @param delay defines delay of a repeat (0 minimal - 7 maximal)
   */
  void set_repeat_rate (unsigned char speed, unsigned char delay);

  /**
   * Switches the specified LED of the keyboard on or off.
   * 
   * \todo write implementation
   *
   * @param led specifies the LED turned on or off
   * @param on if TRUE LED is turned on otherwise off
   */
  void set_led (led::Leds led, bool on);
};

#endif
