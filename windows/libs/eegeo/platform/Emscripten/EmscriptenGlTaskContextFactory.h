// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "IGlTaskContextFactory.h"
#include "EmscriptenSharedGlContext.h"

namespace Eegeo
{
	namespace Emscripten
	{
		class EmscriptenGlTaskContextFactory : public Concurrency::Tasks::IGlTaskContextFactory
		{
		public:
			EmscriptenGlTaskContextFactory(EGLDisplay& display,
										EGLContext& context,
										EGLSurface& surface);

			~EmscriptenGlTaskContextFactory();

			Concurrency::Tasks::IGlTaskContext* Build();

			void UpdateSurface(EGLSurface& surface);
		private:
			EGLDisplay& m_display;
			EGLContext& m_context;
			EGLSurface& m_surface;

			EmscriptenSharedGlContext* m_pEmscriptenSharedGlContext;
		};
	}
}
