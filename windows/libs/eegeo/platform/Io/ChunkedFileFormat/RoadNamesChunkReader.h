// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "VectorMath.h"
#include "ChunkedFileFormat.h"
#include "ParsedRoadNames.h"
#include "RoadClassification.h"
#include <vector>

namespace Eegeo
{
    namespace IO
    {
        namespace ChunkedFileFormat
        {
            namespace RoadNamesChunkReader
            {
                struct RoadNameInstance
                {
                    char* pRoadName;
                    int roadNameSizeBytes;
                    int roadClassificationIndex;
                    Eegeo::v3 segmentStartLocalEcef;
                    Eegeo::v3 segmentEndLocalEcef;
                };
                
                struct RoadNames
                {
                    char* stringTable;
                    int stringTableByteSize;
                    int totalCharacters;
                    std::vector<RoadNameInstance> roads;
                    std::vector<Eegeo::Resources::Roads::RoadClassification> roadClassificationLUT;
                };
                
                void SkipRoadNames(ChunkStream& chunkStream);
                int ReadRoadNamesVersion0(ChunkStream& chunkStream, dv3 ecefCellOrigin, int maxCharsPerRoadName, std::vector<Resources::Roads::RoadNameData>& roadNamesData);
                int ReadRoadNamesVersion1Or2(ChunkStream& chunkStream, RoadNames& roadNames);
                
            }
        }
    }
}