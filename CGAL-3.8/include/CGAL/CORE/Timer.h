/****************************************************************************
 * Core Library Version 1.7, August 2004
 * Copyright (c) 1995-2004 Exact Computation Project
 * All rights reserved.
 *
 * This file is part of CORE (http://cs.nyu.edu/exact/core/); you may
 * redistribute it under the terms of the Q Public License version 1.0.
 * See the file LICENSE.QPL distributed with CORE.
 *
 * Licensees holding a valid commercial license may use this file in
 * accordance with the commercial license agreement provided with the
 * software.
 *
 * This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
 * WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 *
 *
 * File: Timer.h
 * Synopsis:
 *      Timer is a class to provide simple timing functions:
 *
 *      Here is an example of how to use it:
 *
 *		Timer timer;
 *
 *              timer.start();
 *              .. do some tasks for timing ..
 *              timer.stop();
 *
 *              long clock = timer.getClocks();     // get CPU clocks
 *              long seconds = time.getSeconds();   // get seconds
 *
 * Written by 
 *       Zilin Du <zilin@cs.nyu.edu>
 *
 * WWW URL: http://cs.nyu.edu/exact/
 * Email: exact@cs.nyu.edu
 *
 * $URL: svn+ssh://scm.gforge.inria.fr/svn/cgal/trunk/Core/include/CGAL/CORE/Timer.h $
 * $Id: Timer.h 56668 2010-06-09 08:45:58Z sloriot $
 ***************************************************************************/

#ifndef _CORE_TIMER_H_
#define _CORE_IIMER_H_

#include <CGAL/CORE/Impl.h>
#include <ctime>

namespace CORE { 

class Timer {
private:
  long startClock;
  long clocks;

public:
  Timer() : startClock(0), clocks(0) {}

  void start() {
    startClock = clock();
  }

  void stop() {
    clocks = clock() - startClock;
  }

  long getClocks() {
    return clocks;
  }

  float getSeconds() {
    return (float)clocks / CLOCKS_PER_SEC;
  }
};

} //namespace CORE
#endif // _CORE_TIMER_H_
