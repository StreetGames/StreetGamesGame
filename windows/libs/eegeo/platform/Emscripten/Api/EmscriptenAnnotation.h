#pragma once

#include "Types.h"
#include "VectorMathDecl.h"
#include "LatLongAltitude.h"

namespace Eegeo
{
    namespace Emscripten
    {
        namespace Api
        {
            typedef int TAnnotationId;

            class EmscriptenAnnotation
            {
            public:
                EmscriptenAnnotation(const TAnnotationId& annotationId, const Eegeo::Space::LatLong& worldPosition, const double elevation);

                const Eegeo::Space::LatLongAltitude& GetWorldPosition() const;
                void SetWorldPosition(const Eegeo::Space::LatLong& worldPosition);

                double GetElevation() const;
                void SetElevation(double elevation);

                double* GetScreenSpacePositionPointer();

                void SetScreenSpacePosition(const Eegeo::v3& position);
                void UpdateAltitude(const double altitude);

            private:
                TAnnotationId m_annotationId;

                Eegeo::Space::LatLongAltitude m_worldPosition;
                double m_elevation;
                double m_screenSpacePosition[3];
            };
        }
    }
}