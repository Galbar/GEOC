// Copyright (c) 2005  INRIA (France).
// All rights reserved.
//
// This file is part of CGAL (www.cgal.org); you may redistribute it under
// the terms of the Q Public License version 1.0.
// See the file LICENSE.QPL distributed with CGAL.
//
// Licensees holding a valid commercial license may use this file in
// accordance with the commercial license agreement provided with the software.
//
// This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
// WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
//
// $URL: svn+ssh://scm.gforge.inria.fr/svn/cgal/trunk/Surface_mesh_parameterization/include/CGAL/Taucs_fix.h $
// $Id: Taucs_fix.h 46746 2008-11-07 15:30:00Z lrineau $
//
//
// Author(s)     : Laurent Saboret, Pierre Alliez, Bruno Levy

#ifndef CGAL_TAUCS_FIX_H
#define CGAL_TAUCS_FIX_H

#include <CGAL/basic.h> // include basic.h before testing #defines

//
// Include TAUCS main header taucs.h
//

// GCC 3.x does not compile if we include complex.h within "extern C {}"
// and complains that this header is deprecated.
#if defined(__GNUC__)
    #undef __DEPRECATED
    #include <complex.h>
#endif

// taucs.h will define min/max macros if it's not already done (e.g. by Windows.h).
#ifndef min
    #define CGAL_TAUCS_DEFINES_MIN
#endif
#ifndef max
    #define CGAL_TAUCS_DEFINES_MAX
#endif

// TAUCS is a C library
extern "C" {
    #include <taucs.h>
}

// Undefine Taucs' min/max macros to avoid an error
// with std::min()/std::max() calls in standard C++ headers.
#ifdef CGAL_TAUCS_DEFINES_MIN
    #undef min
#endif
#ifdef CGAL_TAUCS_DEFINES_MAX
    #undef max
#endif

#endif // CGAL_TAUCS_FIX_H
