/*
 * DateTest.h
 *
 *  Created on: 2017Äê11ÔÂ20ÈÕ
 *      Author: Administrator
 */

#ifndef SRC_ZA_DATETEST_H_
#define SRC_ZA_DATETEST_H_


#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include <time.h>
#include <stdexcept>
#include <unistd.h>
#include <sys/time.h>
#include <iostream>

#define  DT_YEAR_LEN         (4)
#define  DT_MONTH_LEN        (2)
#define  DT_DAY_LEN          (2)
#define  DT_HOUR_LEN         (2)
#define  DT_MINUTE_LEN       (2)
#define  DT_SECOND_LEN       (2)
#define  DT_DATE_LEN         (DT_YEAR_LEN + DT_MONTH_LEN + DT_DAY_LEN)

std::string ToCSVDate( char * sDate );


void mainDateTest();


#endif /* SRC_ZA_DATETEST_H_ */
