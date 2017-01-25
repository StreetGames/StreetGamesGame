#pragma once

#include "Types.h"

#include "EmscriptenApi.h"
#include "EmscriptenIndoorMapData.h"
#include "Modules.h"
#include "Interiors.h"
#include "InteriorMarkerModel.h"
#include "InteriorsEntityIdHighlightController.h"
#include "ICallback.h"
#include <string>

namespace Eegeo
{
    namespace Emscripten
    {
        namespace Api
        {
            typedef void (*TMarkerCallback)(const char*, const char*, double*);

            class EmscriptenIndoorsApi: protected Eegeo::NonCopyable
            {
            public:
                EmscriptenIndoorsApi(
                    const TMapId& mapId,
                    const Eegeo::Modules::Map::Layers::InteriorsPresentationModule& interiorsPresentationModule,
                    Resources::Interiors::Markers::InteriorMarkerModelRepository& interiorMarkerModelRepository,
                    Eegeo::Resources::Interiors::InteriorsEntityIdHighlightController& interiorsEntityIdHighlightController
                    );
                ~EmscriptenIndoorsApi();

                void SetIndoorMapEnteredCallback(void (*enteredCallback)(void));
                void SetIndoorMapExitedCallback(void (*exitedCallback)(void));
                void SetIndoorMapFloorChangedCallback(void (*floorChangedCallback)(void));

                void SetIndoorMapMarkerAddedCallback(TMarkerCallback markerAddedCallback);
                void SetIndoorMapMarkerRemovedCallback(TMarkerCallback markerRemovedCallback);

                void ExecuteMarkerCallback(TMarkerCallback markerCallback, const Resources::Interiors::Markers::InteriorMarkerModel& interiorMarkerModel);

                void ExitIndoorMap() const;

                const Resources::Interiors::InteriorsModel* GetActiveIndoorMap() const;
                void UpdateIndoorMapData();

                bool HasActiveIndoorMap() const;
                const EmscriptenIndoorMapData& GetIndoorMapData();

                int GetSelectedFloorIndex() const;
                bool SetSelectedFloorIndex(int floorIndex);

                void EnterIndoorMap(const std::string& indoorMapId);

                Resources::Interiors::InteriorInteractionModel& GetInteriorInteractionModel();

                float GetFloorHeightAboveSeaLevel(int floorIndex) const;

                void SetEntityHighlights(const std::vector<std::string>& entityIds, const Eegeo::v4& color);
                void ClearEntityHighlights();
                void AddAreaHighlight(const std::string& areaId, const Eegeo::v4& color);
                void ClearAreaHighlight(const std::string& areaId);

            private:
                void HandleInteriorChanged();

                void HandleInteriorMarkerAdded(const Resources::Interiors::Markers::InteriorMarkerModel& interiorMarkerModel);
                void HandleInteriorMarkerRemoved(const Resources::Interiors::Markers::InteriorMarkerModel& interiorMarkerModel);

                const TMapId m_mapId;
                Resources::Interiors::InteriorSelectionModel& m_interiorSelectionModel;
                Resources::Interiors::InteriorInteractionModel& m_interiorInteractionModel;
                Resources::Interiors::Markers::InteriorMarkerModelRepository& m_interiorMarkerModelRepository;
                Resources::Interiors::InteriorsEntityIdHighlightController& m_interiorsEntityIdHighlightController;

                void (*m_indoorMapEnteredCallback)(void);
                void (*m_indoorMapExitedCallback)(void);
                void (*m_indoorMapFloorChangedCallback)(void);

                TMarkerCallback m_markerAddedCallback;
                TMarkerCallback m_markerRemovedCallback;

                Helpers::TCallback0<EmscriptenIndoorsApi> m_interiorChangedCallback;
                Helpers::TCallback1<EmscriptenIndoorsApi, const Resources::Interiors::Markers::InteriorMarkerModel&> m_markerModelAddedToRepoCallback;
                Helpers::TCallback1<EmscriptenIndoorsApi, const Resources::Interiors::Markers::InteriorMarkerModel&> m_markerModelRemovedFromRepoCallback;

                EmscriptenIndoorMapData m_indoorMapData;
                std::vector<std::vector<Rendering::Renderables::InstancedInteriorFloorRenderable*>> m_highlightedRenderables;
            };
        }
    }
}
