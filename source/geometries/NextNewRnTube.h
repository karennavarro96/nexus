// ----------------------------------------------------------------------------
///  \file   
///  \brief    Tube arround the vessel to shoot backgrounds comming from the Buffer Gas
///            mainly Radon in the air attached to the vessel walls 
///  \author   <miquel.nebot@ific.uv.es>,
///  \date     3 Dic 2013
///  \version  $Id$
///
///  Copyright (c) 2013 NEXT Collaboration
// ----------------------------------------------------------------------------

#ifndef __NEXTNEW_RN_TUBE__
#define __NEXTNEW_RN_TUBE__

#include "BaseGeometry.h"
#include "CylinderPointSampler.h"

#include <G4Navigator.hh>

class G4GenericMessenger;

namespace nexus {

  class NextNewRnTube: public BaseGeometry
  {
  public:
    /// Constructor
    NextNewRnTube();

    /// Destructor
    ~NextNewRnTube();

    /// Sets the Logical Volume where Radon tube will be placed
    void SetLogicalVolume(G4LogicalVolume* mother_logic);

    /// Generate a vertex within a given region of the geometry
    G4ThreeVector GenerateVertex(const G4String& region) const;

    /// Builder
    void Construct();


  private:
    // Mother Logical Volume of the ICS
    G4LogicalVolume* _mother_logic;
    // Dimensions
    G4double  _inner_diam, _length, _thickness;
   
    // Visibility of the shielding
    G4bool _visibility;

    // Vertex generators
    CylinderPointSampler* _tube_gen;

    // Messenger for the definition of control commands
    G4GenericMessenger* _msg; 

  };

} // end namespace nexus

#endif
