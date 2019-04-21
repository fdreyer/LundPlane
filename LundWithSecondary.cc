// $Id$
//
// Copyright (c) -, Frederic A. Dreyer, Gavin P. Salam, Gregory Soyez
//
//----------------------------------------------------------------------
// This file is part of FastJet contrib.
//
// It is free software; you can redistribute it and/or modify it under
// the terms of the GNU General Public License as published by the
// Free Software Foundation; either version 2 of the License, or (at
// your option) any later version.
//
// It is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
// or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public
// License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this code. If not, see <http://www.gnu.org/licenses/>.
//----------------------------------------------------------------------

#include "LundWithSecondary.hh"
#include <sstream>

FASTJET_BEGIN_NAMESPACE      // defined in fastjet/internal/base.hh

namespace contrib{

//----------------------------------------------------------------------
/// return LundDeclustering sequence of primary plane
std::vector<LundDeclustering> LundWithSecondary::primary(const PseudoJet& jet) const {
  return lund_gen_(jet);
}

//----------------------------------------------------------------------
/// return LundDeclustering sequence of secondary plane (slow version)
std::vector<LundDeclustering> LundWithSecondary::secondary(const PseudoJet& jet) const {
  // this is not optimal as one is computing the primary plane twice.
  std::vector<LundDeclustering> declusts = lund_gen_(jet);
  return secondary(jet, declusts);
}
//----------------------------------------------------------------------
/// return LundDeclustering sequence of secondary plane with primary sequence as input
std::vector<LundDeclustering> LundWithSecondary::secondary(const PseudoJet& jet,
				  const std::vector<LundDeclustering> & declusts) const {
  assert(secondary_def_);
  int secondary_index = (*secondary_def_)(declusts);
  // if we found the index of secondary emission, return its declustering sequence
  if (secondary_index >= 0) 
    return lund_gen_(declusts[secondary_index].softer());
  return std::vector<LundDeclustering>();
}
  
//----------------------------------------------------------------------
/// description
std::string LundWithSecondary::description() const {
  std::ostringstream oss;
  oss << "LundWithSecondary using " << secondary_def_->description()
      << " and " << lund_gen_.description();
  return oss.str();
}

} // namespace contrib

FASTJET_END_NAMESPACE
