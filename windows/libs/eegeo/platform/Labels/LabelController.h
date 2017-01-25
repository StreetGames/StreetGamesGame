// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Labels.h"
#include "ILabelController.h"
#include "Rendering.h"
#include "Streaming.h"
#include "ICallback.h"
#include "LabelLayer.h"

#include <vector>

namespace Eegeo
{
    namespace Labels
    {
        class LabelController : public ILabelController, private Eegeo::NonCopyable
        {
        public:
            LabelController(const ILabelViewRepository& labelViewRepository,
                            LabelViewRepositoryObserver& labelViewRepositoryObserver,
                            ILabelRenderer& labelRenderer,
                            const ILabelOptionsModel& labelOptionsModel,
                            Eegeo::Labels::ILabelOptionsModelObserver& labelOptionsModelObserver,
                            const ILabelAnchorFilterModel& labelHiddenFilterModel,
                            ILabelAnchorFilterModelObserver& labelHiddenFilterModelObserver,
                            const Rendering::EnvironmentFlatteningService& environmentFlatteningService,
                            IOcclusionResolver& occlusionResolver,
                            const ILabelStyleRepository& labelStyleRepository,
                            const Streaming::ResourceCeilingProvider& resourceCeilingProvider,
                            float cameraAltitudeToCullPastHorizon,
                            const std::vector<double>& lodRefinementAltitudes,
                            float lodRefinementHysteresis
                            );
            
            ~LabelController();
            
            void Update(float deltaTime, const Camera::RenderCamera& renderCamera);
            
        private:
            bool FetchFromRepository();
            
            void UpdateHiddenState();
        
            void UpdateTransforms(const LabelViewUpdateParams& labelViewUpdateParams);
            
            void UpdateOcclusion();
            
            void UpdateFadeState(const LabelViewUpdateParams& labelViewUpdateParams);
            
            void SubmitToRenderer();
            
            void DebugDraw(const Camera::RenderCamera& renderCamera, const u32 debugDrawFlags);
            
            void OnLabelOptionsModelChanged();
            
            void OnLabelHiddenFilterModelChanged();
            
            int CalcZoomLevel(const float cameraAltitude) const;
            
            std::vector<LabelView*> m_repositoryViewList;
            std::vector<LabelView*> m_repositoryViewForCurrentZoomList;
            std::vector<LabelView*> m_viewList;
            std::vector<int> m_cullingStats;
            int m_currentZoomLevel;
            bool m_labelHiddenFilterModelChanged;
            
            const ILabelViewRepository& m_labelViewRepository;
            LabelViewRepositoryObserver& m_labelViewRepositoryObserver;
            ILabelRenderer& m_labelRenderer;
            const ILabelOptionsModel& m_labelOptionsModel;
            Eegeo::Labels::ILabelOptionsModelObserver& m_labelOptionsModelObserver;
            const ILabelAnchorFilterModel& m_labelHiddenFilterModel;
            ILabelAnchorFilterModelObserver& m_labelHiddenFilterModelObserver;
            Helpers::TCallback0<LabelController> m_labelOptionsModelChangedCallback;
            Helpers::TCallback0<LabelController> m_labelHiddenFilterModelChangedCallback;
            const Rendering::EnvironmentFlatteningService& m_environmentFlatteningService;
            float m_previousEnvironmentFlatteningScale;
            IOcclusionResolver& m_occlusionResolver;
            const ILabelStyleRepository& m_labelStyleRepository;
            float m_cameraAltitudeToCullPastHorizon;
            const std::vector<double> m_lodRefinementAltitudes;
            const float m_lodRefinementHysteresis;
            const Streaming::ResourceCeilingProvider& m_resourceCeilingProvider;
        };
    }
}