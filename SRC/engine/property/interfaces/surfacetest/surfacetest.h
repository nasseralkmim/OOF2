// -*- C++ -*-

/* This software was produced by NIST, an agency of the U.S. government,
 * and by statute is not subject to copyright in the United States.
 * Recipients of this software assume all responsibilities associated
 * with its operation, modification and maintenance. However, to
 * facilitate maintenance we ask that before distributing modified
 * versions of this software, you first contact the authors at
 * oof_manager@nist.gov.
 */

#ifndef SIMPLETENSION_H
#define SIMPLETENSION_H

#include "engine/property.h"
#include "common/coord.h"
//#include <string>


class SmallSystem;

// Surface property for testing the logistics of surface properties.
class ForceSurfaceTest : public EqnProperty {
private:
  double coef;
public:
  ForceSurfaceTest(PyObject *reg, const std::string &name,
	      double coef);
  virtual ~ForceSurfaceTest() {}
  virtual int integration_order(const CSubProblem*, const Element*) const;
  virtual bool constant_in_space() const { return true; }
  virtual void begin_element(const CSubProblem*, const Element*);
  virtual void end_element(const CSubProblem*, const Element*);

  virtual void cross_reference(Material*);
  virtual void post_process(CSubProblem *, const Element *) const;

  
  
  // The actual value of the force contributions.
  virtual void force_value(const FEMesh *mesh, const Element *element,
			   const Equation *eqn, const MasterPosition &pt,
			   double time, SmallSystem *eqndata) const;
  
  // Derivatives of the force contributions wrt the DOFs.
  virtual void force_deriv_matrix(const FEMesh *mesh, const Element *element,
				  const Equation *eqn, 
				  const ElementFuncNodeIterator&,
				  const MasterPosition &pt,
				  double time, SmallSystem *eqndata) const;
  
};

class FluxSurfaceTest : public FluxProperty 
{
private:
  double coef;
public:
  FluxSurfaceTest(PyObject *reg, const std::string &name,
		  double coef);
  virtual ~FluxSurfaceTest() {}
  virtual int integration_order(const CSubProblem*, const Element*) const;
  virtual bool constant_in_space() const { return true; }
  virtual void begin_element(const CSubProblem*, const Element*);
  virtual void end_element(const CSubProblem*, const Element*);
  virtual void cross_reference(Material*);
  virtual void post_process(CSubProblem*, const Element*) const;

  virtual void static_flux_value(const FEMesh *mesh, const Element *element,
				 const Flux *flux, const MasterPosition &pt,
				 double time, SmallSystem *fluxdata) const;
  virtual void flux_matrix(const FEMesh *mesh, const Element *el,
			   const ElementFuncNodeIterator &efi,
			   const Flux *flux, const MasterPosition &pt,
			   double time, SmallSystem *fluxdata) const;
  
};


#endif
