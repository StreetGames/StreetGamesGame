#pragma once

#include "Types.h"

#include "EmscriptenApi.h"
#include "LatLongAltitude.h"
#include "Modules.h"
#include "Geofencing.h"

#include <map>
#include <vector>

namespace Eegeo
{
    namespace Emscripten
    {
        namespace Api
        {
            typedef int TGeofenceId;

            class EmscriptenGeofenceApi: protected Eegeo::NonCopyable
            {
            public:
                EmscriptenGeofenceApi(Modules::Data::GeofenceModule& geofenceModule);
                ~EmscriptenGeofenceApi();

                void CreateGeofence(TGeofenceId geofenceId, std::vector<Eegeo::Space::LatLongAltitude> points);
                void RemoveGeofence(TGeofenceId geofenceId);
                void SetGeofenceAltitude(TGeofenceId geofenceId, double altitude);

                Data::Geofencing::GeofenceModel& GetGeofence(TGeofenceId geofenceId);

            private:
                Data::Geofencing::GeofenceController& m_geofenceController;

                std::map<TGeofenceId, Data::Geofencing::GeofenceModel*> m_geofences;
            };
        }
    }
}