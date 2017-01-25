// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "IFileIO.h"
#include "Types.h"
#include <set>
#include <vector>
#include <string>
#include <iostream>
#include <sys/stat.h>

namespace Eegeo
{
	namespace Emscripten
	{
		class EmscriptenFileIO : public Eegeo::Helpers::IFileIO, protected Eegeo::NonCopyable
		{
		public:
			EmscriptenFileIO(const std::string& basePath);
			virtual ~EmscriptenFileIO();

			virtual bool OpenFile(std::fstream& stream, size_t& size, const std::string& name, std::ios_base::openmode mode=std::ifstream::in);
			virtual bool WriteFile(const Byte* data, size_t size, const std::string& name, std::ios_base::openmode mode=std::ifstream::out);
			virtual bool DeleteFile(const std::string& name);
			virtual bool Exists(const std::string& name);
			virtual bool TryStat(const std::string& name, Helpers::FileStat& s);
			virtual std::string GetAppFilePathname(const std::string& filename);
        private:
            std::string m_basePath;
		};
	}
}