// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "ILabelStyleSheetLoader.h"
#include "Types.h"
#include "Helpers.h"

#include <vector>

namespace Eegeo
{
    namespace Labels
    {
        class IUpdatable
        {
        public:
            virtual ~IUpdatable() {}
            virtual void Update() = 0;
        };
        
        
        class LocalJsonLabelStyleSheetLoader : public ILabelStyleSheetLoader, public IUpdatable, private Eegeo::NonCopyable
        {
        public:
            LocalJsonLabelStyleSheetLoader(Helpers::IFileIO& fileIO,
                                           const ILabelStyleSheetParser& labelStyleSheetParser,
                                           ILabelStyleSheetBuilder& labelStyleSheetBuilder);
            
            void Load(const std::string& url, LoadCompleteCallbackType& callback);
            
            void Update();

        private:
        
            struct LabelStyleSheetLoad
            {
                LabelStyleSheetLoad(const std::string& url,  LoadCompleteCallbackType& callback)
                : m_url(url)
                , m_pCallback(&callback)
                {}
                
                const std::string& GetUrl() const { return m_url; }
                LoadCompleteCallbackType& GetCallback() const { return *m_pCallback; }
            private:
                std::string m_url;
                LoadCompleteCallbackType* m_pCallback;
            };
            
            bool TryLoad(const LabelStyleSheetLoad& load);
            
            Helpers::IFileIO& m_fileIO;
            const ILabelStyleSheetParser& m_labelStyleSheetParser;
            ILabelStyleSheetBuilder& m_labelStyleSheetBuilder;
            
            std::vector<LabelStyleSheetLoad> m_loads;
        };
    }
}