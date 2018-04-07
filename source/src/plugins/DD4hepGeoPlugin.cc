/// \file DD4hepGeoPlugin.cc
/*
 *
 * DD4hepGeoPlugin.cc source template automatically generated by a class generator
 * Creation date : ven. sept. 5 2014
 *
 * This file is part of DQM4HEP libraries.
 * 
 * DQM4HEP is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * based upon these libraries are permitted. Any copy of these libraries
 * must include this copyright notice.
 * 
 * DQM4HEP is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with DQM4HEP.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * @author Remi Ete
 * @copyright CNRS , IPNL
 */

// -- dqm4hep headers
#include <dqm4hep/GeometryBuilder.h>
#include <dqm4hep/XmlHelper.h>
#include <dqm4hep/PluginManager.h>

// -- root headers
#include <TGeoManager.h>

/// -- dd4hep headers
#include "DD4hep/Detector.h"

namespace dqm4hep {

  namespace display {

    class DD4hepGeoPlugin : public GeometryBuilder {
    public:
      DD4hepGeoPlugin() = default;
      ~DD4hepGeoPlugin() = default;
      core::StatusCode readSettings(const core::TiXmlHandle &handle);
      TGeoManager* buildGeometry();
    
    private:      
      std::string    m_fileName = {""};           ///< The file name to import (root, gdml, xml)
      std::string    m_geometryName = {""};       ///< The geometry name to import
      std::string    m_importOption = {""};       ///< The import options
    };
    
    //-------------------------------------------------------------------------------------------------
    //-------------------------------------------------------------------------------------------------
    
    core::StatusCode DD4hepGeoPlugin::readSettings(const core::TiXmlHandle &handle) {
      RETURN_RESULT_IF(core::STATUS_CODE_SUCCESS, !=, core::XmlHelper::readParameter(
        handle, "FileName", m_fileName
      ));
      
      return core::STATUS_CODE_SUCCESS;
    }
    
    //-------------------------------------------------------------------------------------------------

    TGeoManager* DD4hepGeoPlugin::buildGeometry() {
      dd4hep::Detector& theDetector = dd4hep::Detector::getInstance();
      theDetector.fromCompact( m_fileName );
      return gGeoManager;
    }
    
    DQM_PLUGIN_DECL(DD4hepGeoPlugin, "DD4hepGeo");

  }

}
