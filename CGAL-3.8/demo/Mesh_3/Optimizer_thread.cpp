// Copyright (c) 2010 INRIA Sophia-Antipolis (France).
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
// $URL: svn+ssh://scm.gforge.inria.fr/svn/cgal/trunk/Mesh_3/demo/Mesh_3/Optimizer_thread.cpp $
// $Id: Optimizer_thread.cpp 57256 2010-07-01 08:27:03Z stayeb $
//
//
// Author(s)     : Stephane Tayeb
//
//******************************************************************************
// File Description : 
//******************************************************************************

#include <QTime>
#include <QTimer>
#include "Optimizer_thread.h"
#include "Scene_c3t3_item.h"


Optimizer_thread::
Optimizer_thread(Optimization_function_interface* f, Scene_c3t3_item* item)
  : f_(f)
  , item_(item)
  , rc_()
  , time_(0)
  , timer_(new QTimer(this))
  , timer_period_(1)
{
  connect(timer_, SIGNAL(timeout()),
          this,   SLOT(emit_status()));
  
  timer_->start(static_cast<int>(timer_period_*1000));  
}


Optimizer_thread::~Optimizer_thread()
{
  delete f_;
}


void
Optimizer_thread::
run()
{
  QTime timer;
  timer.start();
  
  rc_ = f_->launch();
  time_ = double(timer.elapsed()) / 1000;
  
  emit done(this);
}


void
Optimizer_thread::
stop()
{
  f_->stop();
}

void
Optimizer_thread::
emit_status()
{
  emit (status_report(f_->status(timer_period_)));
}


#include "Optimizer_thread.moc"
