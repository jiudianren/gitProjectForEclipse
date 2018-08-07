/*
 * Tip.h
 *
 *  Created on: 2017Äê5ÔÂ5ÈÕ
 *      Author: Lian
 */

#ifndef TIP_H_
#define TIP_H_

#include <stdio.h>
#define DEBUG2(x,y) "Line:" #y " ,File: " x
#define DEBUG1(x,y) DEBUG2(x,y)
#define LINE_FILE DEBUG1( __FILE__ , __LINE__ )
#define INFO  printf("%s.\n", LINE_FILE);


#endif /* TIP_H_ */
