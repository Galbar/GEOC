// Copyright (c) 2003,2004,2005,2006  INRIA Sophia-Antipolis (France) and
// Notre Dame University (U.S.A.).  All rights reserved.
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
// $URL: svn+ssh://scm.gforge.inria.fr/svn/cgal/trunk/Segment_Delaunay_graph_2/include/CGAL/Segment_Delaunay_graph_2/Traits_wrapper_2.h $
// $Id: Traits_wrapper_2.h 56667 2010-06-09 07:37:13Z sloriot $
// 
//
// Author(s)     : Menelaos Karavelas <mkaravel@cse.nd.edu>

#ifndef CGAL_SEGMENT_DELAUNAY_GRAPH_2_TRAITS_WRAPPER_2_H
#define CGAL_SEGMENT_DELAUNAY_GRAPH_2_TRAITS_WRAPPER_2_H

#include <CGAL/Segment_Delaunay_graph_2/basic.h>

namespace CGAL {

template<class Gt_base>
class Segment_Delaunay_graph_traits_wrapper_2 : public Gt_base
{
private:
  typedef Segment_Delaunay_graph_traits_wrapper_2<Gt_base> Self;

public:
  struct Triangle_2 {};

  Segment_Delaunay_graph_traits_wrapper_2() {}

  Segment_Delaunay_graph_traits_wrapper_2(const Gt_base&) {}
};

} //namespace CGAL

#endif // CGAL_SEGMENT_DELAUNAY_GRAPH_2_TRAITS_WRAPPER_2_H
