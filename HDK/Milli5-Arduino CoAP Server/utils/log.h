/*

Copyright (c) Silver Spring Networks, Inc. 
All rights reserved.

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the ""Software""), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of 
the Software, and to permit persons to whom the Software is furnished to do so, 
subject to the following conditions:

The above copyright notice and this permission notice shall be included in all 
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED AS IS, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

Except as contained in this notice, the name of Silver Spring Networks, Inc. 
shall not be used in advertising or otherwise to promote the sale, use or other 
dealings in this Software without prior written authorization from Silver Spring
Networks, Inc.

*/
/*
 * $Id: log.h 104571 2016-11-24 03:29:11Z dcecil $
 *
 * Console diagnostic logging utilities
 */

/*!
* Log are helper functions to output informations over a serial port
* Different levels can be used to extend or reduce output
*
* <br>
* <b>Log levels:</b><br>
* <table border="0">
* <tr><td>0</td><td>LOG_EMERG</td><td>system is unusable </td></tr>
* <tr><td>1</td><td>LOG_ALERT</td><td>action must be taken immediately </td></tr>
* <tr><td>2</td><td>LOG_CRIT</td><td>critical conditions </td></tr>
* <tr><td>3</td><td>LOG_ERR</td><td>error conditions </td></tr>
* <tr><td>4</td><td>LOG_WARNING</td><td>warning conditions </td></tr>
* <tr><td>2</td><td>LOG_NOTICE</td><td>normal but significant condition </td></tr>
* <tr><td>3</td><td>LOG_INFO</td><td>informational </td></tr>
* <tr><td>4</td><td>LOG_DEBUG</td><td>debug-level messages </td></tr>
* </table>
*/

#ifndef INC_LOG_H
#define INC_LOG_H

#include <arduino.h>

#define PRINTF_LEN		256

#define LOG_EMERG       (0)         /* system is unusable */
#define LOG_ALERT       (1)         /* action must be taken immediately */
#define LOG_CRIT        (2)         /* critical conditions */
#define LOG_ERR         (3)         /* error conditions */
#define LOG_WARNING     (4)         /* warning conditions */
#define LOG_NOTICE      (5)         /* normal but significant condition */
#define LOG_INFO        (6)         /* informational */
#define LOG_DEBUG       (7)         /* debug-level messages */

// Serial should only have been defined by mshield.h
// In your .ino file, make sure log.h is included after mshield.h
// This makes sure we done define Serial here in case of the .ino file
#ifndef Serial
	// Pointer to Serial
	static Serial_ * pS = NULL;
	#define Serial (*pS)
#endif

/**
* @brief
* Init logging
*
* @param Serial_ pointer to Serial object used for printing to console
* @param baun The baud rate for printing to console
*
*/
void log_init( Serial_ * pSerial, uint32_t baud );

/**
* @brief
* Get pointer to Serial
*
* @return Serial_ pointer to Serial object used for printing to console
*
*/
Serial_ * log_get_serial();

/**
* @brief
* Set log level
*
* @param level The log level
* @return void
*
*/
extern void dlog_level(int level);

/**
* @brief
* Output a debug message to serial port
*
* @param level The log level
* @param my_format format string to output
* @param ... any number of variables
* @return void
*
*/
extern void dlog (int level, const char *my_format, ...)
            __attribute__ ((format (printf, 2, 3)));

/**
* @brief
* Dump a list
*
* @param level The log level
* @param label A label to be printed
* @param data A pointer to the list
* @param len Length of list
* @return void
*
*/
extern void ddump(int level, const char *label, const void *data, int len);

/**
* @brief
* Print label and number to serial port
*
* @param label text string
* @param d an integer
*
*/
void print_number( const char * label, int d );

/**
* @brief
* Print buffer
*
* @param buf text string
*
*/
void print_buf( const char * buf );

/**
* @brief
* Log a message
*
* @param label A label to be printed
* @param data A pointer to the list
* @param datalen Length of list
* @param eol  
* @return void
*
*/
extern void log_msg(const char *label, const void *data, int datalen, int eol);

void capture( uint8_t ch );
void capture_dump( uint8_t * p, int count );
void print_number( char * label, int d );

#endif /* INC_LOG_H */
