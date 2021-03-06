// Copyright (c) 2006-2008 Inria Lorraine (France). All rights reserved.
//
// This file is part of CGAL (www.cgal.org); you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public License as
// published by the Free Software Foundation; version 2.1 of the License.
// See the file LICENSE.LGPL distributed with CGAL.
//
// Licensees holding a valid commercial license may use this file in
// accordance with the commercial license agreement provided with the software.
//
// This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
// WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
//
// $URL: svn+ssh://scm.gforge.inria.fr/svn/cgal/trunk/Algebraic_kernel_d/include/CGAL/RS/algebraic_1_operators.h $
// $Id: algebraic_1_operators.h 59002 2010-10-04 11:00:27Z lrineau $
//
// Author: Luis Pe�aranda <luis.penaranda@loria.fr>

#ifndef CGAL_RS_ALGEBRAIC_1_OPERATORS_H
#define CGAL_RS_ALGEBRAIC_1_OPERATORS_H

namespace CGAL{

inline
Algebraic_1 Algebraic_1::operator+()const{
        return *this;
}

inline
Algebraic_1 Algebraic_1::operator-()const{
        mpfi_t inv;
        mpfi_init2(inv,mpfi_get_prec(mpfi()));
        mpfi_neg(inv,mpfi());
        Algebraic_1 *inverse=new Algebraic_1(inv,
                                             pol().minusx(),
                                             nr(),
                                             mult(),
                                             NULL,
                                             NULL,
                                             -lefteval());
        return *inverse;
}

} // namespace CGAL

#endif  // CGAL_RS_ALGEBRAIC_1_OPERATORS_H

// vim: tabstop=8: softtabstop=8: smarttab: shiftwidth=8: expandtab
