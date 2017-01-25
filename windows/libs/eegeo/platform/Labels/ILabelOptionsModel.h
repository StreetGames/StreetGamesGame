// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Labels.h"
#include "IModelObserver.h"
#include "IOcclusionResolver.h"

#include <string>

namespace Eegeo
{
    namespace Labels
    {
        class ILabelOptionsModel
        {
        public:
            ~ILabelOptionsModel() {}
            
            virtual bool IsDebugDrawEnabled() const = 0;
            
            virtual OcclusionResolverMode::Type GetOcclusionMode() const = 0;
            
            virtual float GetConstraintRadiusScale() const = 0;
            
            virtual float GetFadeDurationScale() const = 0;
            
            virtual std::string GetFontName() const = 0;
            
            virtual bool IsDebugIdentifyStyleEnabled() const = 0;
            
            virtual std::string GetDebugIdentifyStyleName() const = 0;
            
            virtual void SetDebugDraw(bool enabled) = 0;
            
            virtual void SetOcclusionMode(OcclusionResolverMode::Type occlusionMode) = 0;
            
            virtual void SetConstraintRadiusScale(float constraintRadiusScale) = 0;
            
            virtual void SetFadeDurationScale(float fadeDurationScale) = 0;
            
            virtual void SetFontName(const std::string& fontName) = 0;
            
            virtual void SetDebugIdentifyStyle(const std::string& styleName) = 0;
        };
        
        class ILabelOptionsModelObserver : public IModelObserver
        {
            
        };
    }
}