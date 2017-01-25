// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Rendering.h"
#include "IMaterial.h"
#include "FontMaterialSetProperties.h"
#include <vector>

namespace Eegeo
{
    namespace Fonts
    {
        class FontMaterialSet : protected Eegeo::NonCopyable
        {
        public:
            typedef std::vector<Rendering::Materials::IMaterial*> TMaterialVector;

            FontMaterialSet(const TMaterialVector& materials, const FontMaterialSetProperties& properties)
            : m_materials(materials)
            , m_properties(properties)
            {
            }
            
            ~FontMaterialSet()
            {
                for(TMaterialVector::iterator it = m_materials.begin(); it != m_materials.end(); ++it)
                {
                    Eegeo_DELETE (*it);
                }
                m_materials.clear();
            }
            
            const TMaterialVector& GetMaterials() const
            {
                return m_materials;
            }
            
            int GetNumOfMaterials() const
            {
                return static_cast<int>(m_materials.size());
            }
            
            Rendering::Materials::IMaterial& GetMaterial(int materialIndex) const
            {
                return *(m_materials.at(materialIndex));
            }
            
            const FontMaterialSetProperties& GetProperties() const { return m_properties; }
            
        private:
            TMaterialVector m_materials;
            const FontMaterialSetProperties m_properties;
        };
    }
}
