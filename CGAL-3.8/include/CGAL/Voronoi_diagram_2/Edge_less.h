// Copyright (c) 2006 Foundation for Research and Technology-Hellas (Greece).
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
// $URL: svn+ssh://scm.gforge.inria.fr/svn/cgal/trunk/Voronoi_diagram_2/include/CGAL/Voronoi_diagram_2/Edge_less.h $
// $Id: Edge_less.h 56668 2010-06-09 08:45:58Z sloriot $
// 
//
// Author(s)     : Menelaos Karavelas <mkaravel@iacm.forth.gr>

#ifndef CGAL_VORONOI_DIAGRAM_2_EDGE_LESS_H
#define CGAL_VORONOI_DIAGRAM_2_EDGE_LESS_H 1

#include <CGAL/Voronoi_diagram_2/basic.h>

namespace CGAL {

namespace VoronoiDiagram_2 { namespace Internal {

template<class Edge_t>
struct Edge_less
{
  typedef Edge_t        Edge;
  typedef bool          result_type;

  bool operator()(const Edge& e1, const Edge& e2) const {
    if ( e1.first != e2.first ) { return e1.first < e2.first; }
    return e1.second < e2.second;
  }
};


} } //namespace VoronoiDiagram_2::Internal

} //namespace CGAL

#endif // CGAL_VORONOI_DIAGRAM_2_EDGE_LESS_H
