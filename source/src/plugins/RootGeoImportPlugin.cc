/// \file RootGeoImportPlugin.cc
/*
 *
 * RootGeoImportPlugin.cc source template automatically generated by a class generator
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

namespace dqm4hep {

  namespace display {

    class RootGeoImportPlugin : public GeometryBuilder {
    public:
      RootGeoImportPlugin() = default;
      ~RootGeoImportPlugin() = default;
      core::StatusCode readSettings(const core::TiXmlHandle &handle);
      TGeoManager* buildGeometry();
    
    private:      
      std::string    m_fileName = {""};           ///< The file name to import (root, gdml, xml)
      std::string    m_geometryName = {""};       ///< The geometry name to import
      std::string    m_importOption = {""};       ///< The import options
    };
    
    //-------------------------------------------------------------------------------------------------
    //-------------------------------------------------------------------------------------------------
    
    core::StatusCode RootGeoImportPlugin::readSettings(const core::TiXmlHandle &handle) {
      RETURN_RESULT_IF(core::STATUS_CODE_SUCCESS, !=, core::XmlHelper::readParameter(
        handle, "FileName", m_fileName
      ));
      
      RETURN_RESULT_IF_AND_IF(core::STATUS_CODE_SUCCESS, core::STATUS_CODE_NOT_FOUND, !=, core::XmlHelper::readParameter(
        handle, "GeometryName", m_geometryName
      ));
      
      RETURN_RESULT_IF_AND_IF(core::STATUS_CODE_SUCCESS, core::STATUS_CODE_NOT_FOUND, !=, core::XmlHelper::readParameter(
        handle, "ImportOption", m_importOption
      ));
      
      return core::STATUS_CODE_SUCCESS;
    }
    
    //-------------------------------------------------------------------------------------------------

    TGeoManager* RootGeoImportPlugin::buildGeometry() {
      return TGeoManager::Import(m_fileName.c_str(), m_geometryName.c_str(), (Option_t*)m_importOption.c_str());
    }
    
    DQM_PLUGIN_DECL(RootGeoImportPlugin, "RootGeoImport");

  }

}
