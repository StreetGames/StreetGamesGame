// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "ILabelOptionsModel.h"
#include "IModelObserver.h"
#include "Labels.h"


namespace Eegeo
{
    namespace Labels
    {
        class LabelOptionsModel : public ILabelOptionsModel, public ILabelOptionsModelObserver, private Eegeo::NonCopyable
        {
        public:
            LabelOptionsModel(bool debugDrawEnabled,
                              OcclusionResolverMode::Type occlusionMode,
                              float constraintRadiusScale,
                              float fadeDurationScale,
                              const std::string& fontName);
            
            bool IsDebugDrawEnabled() const;
            
            OcclusionResolverMode::Type GetOcclusionMode() const;
            
            float GetConstraintRadiusScale() const;
            
            float GetFadeDurationScale() const;
            
            std::string GetFontName() const;
            
            bool IsDebugIdentifyStyleEnabled() const;
            
            std::string GetDebugIdentifyStyleName() const;
            
            void SetDebugDraw(bool enabled);
            
            void SetOcclusionMode(OcclusionResolverMode::Type occlusionMode);
            
            void SetConstraintRadiusScale(float constraintRadiusScale);
            
            void SetFadeDurationScale(float fadeDuration);
            
            void SetFontName(const std::string& fontName);
            
            void SetDebugIdentifyStyle(const std::string& styleName);
            
            void RegisterChangedCallback(CallbackType& callback);
            
            void UnregisterChangedCallback(CallbackType& callback);
            
        private:
            void NotifyChanged() const;
        
            bool m_debugDrawEnabled;
            OcclusionResolverMode::Type m_occlusionMode;
            float m_constraintRadiusScale;
            float m_fadeDurationScale;
            std::string m_fontName;
            std::string m_debugIdentifyStyle;
            
            Helpers::CallbackCollection0 m_callbacks;
        };
    }
}