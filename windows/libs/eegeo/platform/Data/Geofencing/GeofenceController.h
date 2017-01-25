// Copyright (c) 2015 eeGeo. All rights reserved.

#pragma once

#include "Types.h"
#include "Geofencing.h"
#include "GeofenceRenderer.h"
#include "GeofenceViewFactory.h"
#include "DataEntityController.h"
#include "TerrainHeightProvider.h"
#include <map>

namespace Eegeo
{
    namespace Data
    {
        namespace Geofencing
        {
            struct GeofenceArgs
            {
                typedef TGeofenceId TId;
                typedef GeofenceModel TModel;
                typedef GeofenceView TView;
                typedef GeofenceViewFactory TViewFactory;
                typedef GeofenceRenderer TRenderableFilter;
            };
            
            class GeofenceController : public Data::DataEntityController<GeofenceArgs>
            {
            public:
                GeofenceController(
                    GeofenceViewFactory& viewFactory,
                    GeofenceRenderer& renderableFilter,
                    const Resources::Terrain::Heights::TerrainHeightProvider& terrainHeightProvider)
                : DataEntityController(viewFactory, renderableFilter)
                , m_terrainHeightProvider(terrainHeightProvider)
                {
                }

                void Update()
                {
                    std::vector<TModel*> dirtyGeofences;

                    for (TModelToView::iterator iter = m_modelToView.begin(); iter != m_modelToView.end(); ++iter)
                    {
                        TModel* pModel = iter->first;
                        bool dirty = TryUpdateGeofenceHeights(*pModel);
                        if (dirty)
                        {
                            dirtyGeofences.push_back(pModel);
                        }
                    }

                    for (std::vector<TModel*>::iterator iter = dirtyGeofences.begin(); iter != dirtyGeofences.end(); ++iter)
                    {
                        TModel& geofence = **iter;
                        geofence.RecalculateMeshVertices();
                        UpdateGeofenceView(geofence);
                    }
                }

                bool TryUpdateGeofenceHeights(TModel& geofence)
                {
                    const int MinimumLevelToReadHeights = 11;
                    const std::vector<dv3>& ecefGeofenceVertices = geofence.GetEcefBaseVertices();

                    for (size_t i = 0; i < geofence.GetVertexCount(); ++i)
                    {
                        const dv3& point = ecefGeofenceVertices[i];
                        GeofenceVertexHeight vertexHeight = geofence.GetVertexTerrainHeight(i);

                        float newHeight;
                        int newLevel;
                        bool updatedHeight = m_terrainHeightProvider.TryGetHeight(
                            point, MinimumLevelToReadHeights, vertexHeight.previousQueryTerminationLevel, vertexHeight.height, newLevel, newHeight);

                        if (updatedHeight && newLevel > vertexHeight.previousQueryTerminationLevel)
                        {
                            vertexHeight.height = newHeight;
                            vertexHeight.previousQueryTerminationLevel = newLevel;
                            geofence.SetVertexTerrainHeight(i, vertexHeight);
                        }
                    }

                    return geofence.IsDirty();
                }

                void UpdateGeofenceView(TModel& geofence)
                {
                    Remove(geofence);
                    Add(geofence);
                }

            private:
                const Resources::Terrain::Heights::TerrainHeightProvider& m_terrainHeightProvider;
            };
        }
    }
}

