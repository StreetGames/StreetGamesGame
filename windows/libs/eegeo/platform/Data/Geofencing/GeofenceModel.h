// Copyright (c) 2015 eeGeo. All rights reserved.

#pragma once

#include "Types.h"
#include "LatLongAltitude.h"
#include "Colors.h"
#include <string>
#include <vector>

namespace Eegeo
{
    namespace Data
    {
        namespace Geofencing
        {
            typedef std::string TGeofenceId;

            struct GeofenceVertexHeight
            {
            public:
                GeofenceVertexHeight()
                : height(0.0f)
                , previousQueryTerminationLevel(-1) { }

                float height;
                int previousQueryTerminationLevel;
            };

            class GeofenceModel : private Eegeo::NonCopyable
            {
            public:
                class GeofenceBuilder : private Eegeo::NonCopyable
                {
                public:
                    GeofenceBuilder(
                            const TGeofenceId& id,
                            const v4& geofencePolygonColor,
                            const std::vector<Space::LatLongAltitude>& exteriorRingVertices)
                    : m_id(id)
                    , m_exteriorRingVertices(exteriorRingVertices)
                    , m_polygonColor(geofencePolygonColor)
                    , m_altitudeOffset(0.0f)
                    , m_finished(false)
                    {

                    }

                    GeofenceBuilder& AltitudeOffset(float altitudeOffset);
                    GeofenceBuilder& AddInteriorRing(const std::vector<Space::LatLongAltitude>& interiorRing);
                    GeofenceModel* Build();

                private:
                    const std::string m_id;
                    const std::vector<Space::LatLongAltitude> m_exteriorRingVertices;
                    std::vector<std::vector<Space::LatLongAltitude> > m_interiorRings;
                    const v4 m_polygonColor;
                    float m_altitudeOffset;
                    bool m_finished;
                };

                const TGeofenceId& GetId() const { return m_id; }
                const dv3& GetEcefCellCenter() const { return m_ecefCellCenter; }

                const v4 GetPolygonColor() const { return m_polygonColor; }
                void SetPolygonColor(const v4& polygonColor) { m_polygonColor = polygonColor; }

                double GetAltitudeOffset() const;
                void SetAltitudeOffset(double altitude);

                const std::vector<dv3>& GetEcefTriangleVertices() const;

                const std::vector<dv3>& GetEcefBaseVertices() const;
            
                size_t GetVertexCount() const;
                GeofenceVertexHeight GetVertexTerrainHeight(size_t vertex) const;
                void SetVertexTerrainHeight(size_t vertex, GeofenceVertexHeight vertexHeight);

                void RecalculateMeshVertices();
                bool IsDirty() const;

            private:
                
                GeofenceModel(
                    const TGeofenceId id,
                    const std::vector<dv3>& baseEcefTriangleVerts,
                    const dv3& ecefCellCenter,
                    double altitudeOffset,
                    const v4& polygonColor);

                const TGeofenceId m_id;
                const std::vector<dv3> m_baseEcefTriangleVerts;
                const dv3 m_ecefCellCenter;
                std::vector<GeofenceVertexHeight> m_vertexTerrainHeights;
                double m_altitudeOffset;
                v4 m_polygonColor;

                std::vector<dv3> m_ecefTriangleVerts;
                bool m_isDirty;
            };
        }
    }
}

