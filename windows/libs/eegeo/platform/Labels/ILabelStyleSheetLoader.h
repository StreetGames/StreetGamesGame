// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#include "Labels.h"
#include "ICallback.h"

#include <string>


namespace Eegeo
{
    namespace Labels
    {
        struct LabelStyleSheetLoaderResult
        {
            LabelStyleSheetLoaderResult(const std::string& url, bool succeed)
            : m_url(url)
            , m_succeed(succeed)
            {}
            
            const std::string& Url() const { return m_url; }
            bool IsSucceed() const { return m_succeed; }
        private:
            std::string m_url;
            bool m_succeed;
        };
        
        
        
        class ILabelStyleSheetLoader
        {
        public:
            typedef Helpers::ICallback1<const LabelStyleSheetLoaderResult> LoadCompleteCallbackType;
            virtual ~ILabelStyleSheetLoader() {}
            
            virtual void Load(const std::string& url, LoadCompleteCallbackType& callback) = 0;
            
        };
    }
}