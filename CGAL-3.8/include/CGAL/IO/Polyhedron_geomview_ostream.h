// Copyright (c) 1997  ETH Zurich (Switzerland).
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
// $URL: svn+ssh://scm.gforge.inria.fr/svn/cgal/trunk/Polyhedron_IO/include/CGAL/IO/Polyhedron_geomview_ostream.h $
// $Id: Polyhedron_geomview_ostream.h 56667 2010-06-09 07:37:13Z sloriot $
// 
//
// Author(s)     : Lutz Kettner  <kettner@mpi-sb.mpg.de>

#ifndef CGAL_IO_POLYHEDRON_GEOMVIEW_OSTREAM_H
#define CGAL_IO_POLYHEDRON_GEOMVIEW_OSTREAM_H 1

#include <CGAL/IO/Geomview_stream.h>
#include <CGAL/IO/generic_print_polyhedron.h>
#include <CGAL/Polyhedron_3.h>

namespace CGAL {

class Polyhedron_writer_geomview {
    Geomview_stream*  out;
public:
    Polyhedron_writer_geomview( Geomview_stream& geo) : out(&geo) {}
    void write_header( std::ostream&, 
                       std::size_t vertices, 
                       std::size_t, 
                       std::size_t facets) {
        // ignore ostream. Output goes to Geomview_stream.
        // Print header.
        out->set_ascii_mode();
        *out << "(geometry " << out->get_new_id("polyhedron")
             << " {appearance {}{ ";
        out->set_binary_mode();
        *out << "OFF BINARY\n"  << int(vertices) << int(facets) << 0 ;
    }
    void write_footer() {
        *out << "}})";
        out->set_ascii_mode();
    }
    void write_vertex( const double& x, const double& y, const double& z) {
        *out << x << y << z;
    }
    void write_facet_header() {}
    void write_facet_begin( std::size_t no) { *out << int(no); }
    void write_facet_vertex_index( std::size_t index) { *out << int(index); }
    void write_facet_end() {
        double r = out->fcr(),
               g = out->fcg(),
               b = out->fcb();
        *out << 4 << r << g << b << 1.0;
    }
};


template < class Traits,
           class Items,
#ifndef CGAL_CFG_NO_TMPL_IN_TMPL_PARAM
           template < class T, class I, class A>
#endif
           class HDS, class Alloc>
Geomview_stream&
operator<<( Geomview_stream &gv,
            const Polyhedron_3<Traits,Items,HDS,Alloc> &P) {
    Polyhedron_writer_geomview  writer(gv);
    generic_print_polyhedron( std::cerr, P, writer); // note: cerr not used.
    return gv;
}

} //namespace CGAL

#endif // CGAL_IO_POLYHEDRON_GEOMVIEW_OSTREAM_H //
// EOF //
