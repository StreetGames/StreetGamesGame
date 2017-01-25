#pragma once

#include "Types.h"

#include "EmscriptenApi.h"
#include "Modules.h"
#include "Interiors.h"
#include "ICallback.h"
#include <string>

namespace Eegeo
{
    namespace Emscripten
    {
        namespace Api
        {
            typedef void (*TExpandCollapseCallback)(void);

            class EmscriptenExpandFloorsApi: protected Eegeo::NonCopyable
            {
            public:
                EmscriptenExpandFloorsApi(Resources::Interiors::InteriorInteractionModel& interiorInteractionModel);
                ~EmscriptenExpandFloorsApi();

                void SetCollapseStartCallback(TExpandCollapseCallback collapseStartCallback);
                void SetCollapseCallback(TExpandCollapseCallback collapseCallback);
                void SetCollapseEndCallback(TExpandCollapseCallback collapseEndCallback);

                void SetExpandStartCallback(TExpandCollapseCallback expandStartCallback);
                void SetExpandCallback(TExpandCollapseCallback expandCallback);
                void SetExpandEndCallback(TExpandCollapseCallback expandEndCallback);

                Resources::Interiors::InteriorInteractionModel& GetInteriorInteractionModel() const;

                void OnUpdate();

            private:
                void HandleInteractionStateChanged();

                void UpdateExpandedState();

                Resources::Interiors::InteriorInteractionModel& m_interiorInteractionModel;

                Helpers::TCallback0<EmscriptenExpandFloorsApi> m_interactionStateChangedCallback;

                TExpandCollapseCallback m_collapseStartCallback;
                TExpandCollapseCallback m_collapseCallback;
                TExpandCollapseCallback m_collapseEndCallback;
                TExpandCollapseCallback m_expandStartCallback;
                TExpandCollapseCallback m_expandCallback;
                TExpandCollapseCallback m_expandEndCallback;

                bool m_previouslyCollapsed;
                bool m_previouslyExpanded;
            };
        }
    }
}