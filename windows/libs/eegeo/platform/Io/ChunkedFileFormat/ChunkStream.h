// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "BinaryParsing.h"
#include <istream>
#include <string>

namespace Eegeo
{
    namespace IO
    {
        namespace ChunkedFileFormat
        {
            static const std::string ChunkedFileTag = "HCFF";
            static const std::string CellModelTag = "CMDL";
            static const std::string QuantizedCompressedMeshSetTag = "QCMS";
            static const std::string NavGraphTag = "NAVG";
            static const std::string RoadNamesTag = "RDNM";
            static const std::string LcmTerrainTag = "LCMT";
            static const std::string TreeTag = "TREE";
            static const std::string RoadTag = "ROAD";
            static const std::string RailTag = "RAIL";
            static const std::string TramlineTag = "TRAM";
            static const std::string Glowmap = "GLOW";
            static const std::string Jpeg = "JPEG";
            static const std::string PlacenameTag = "PLAC";
            static const std::string InteriorTag = "INTR";
            static const std::string InteriorMetadataTag = "INTM";
			static const std::string InteriorInstanceDataTag = "INST";
            static const std::string InteriorsFloorTag = "FLOR";
            static const std::string InteriorEntityTag = "ENTI";
            static const std::string InteriorMarkersTag = "IMKR";
            static const std::string TextTag = "TEXT";
            static const std::string CoverageManifestTag = "CTMN";
            static const std::string CoverageTreeListTag = "CTLS";
            static const std::string BlockCoverageTreeTag = "BLCT";
            static const std::string BuildingFootprintsListTag = "BFLS";
            static const std::string BuildingFootprintsTag = "BDFP";
            static const std::string HighlightGeometryTag = "HIGH";
            static const std::string ReferencedChunkStoreTag = "REFS";
            static const std::string ReferenceChunkTag = "REFC";
            static const std::string ThemeManifestTag = "THMN";
            static const std::string InteriorMaterialsTag = "IMTS";
            static const std::string InteriorMaterialTag = "IMAT";
            static const std::string ThemesTag = "THMS";
            static const std::string ThemeTag = "THME";
            static const std::string PlaceNameStylesTag = "PSTL";
            static const std::string PlaceNameStyleTag = "PSTE";
            static const std::string VehiclesTag = "VCLS";
            static const std::string VehicleTypeTag = "VTLS";
            static const std::string VehicleTag = "VHCL";
            static const std::string ThemeStatesTag = "TSTS";
            static const std::string ThemeStateTag = "THST";
            static const std::string ThemeLightingTag = "THLI";
            static const std::string ThemeTexturesTag = "THTX";
            static const std::string ThemeOverlayTag = "THOV";
            static const std::string ThemeLcmTexturesTag = "THLT";
            static const std::string BinaryFontInfoTag = "BFIN";
            static const std::string BinaryFontCommonTag = "BFCO";
            static const std::string BinaryFontPagesTag = "BFPA";
            static const std::string BinaryFontCharsTag = "BFCH";
            static const std::string BinaryFontKerningTag = "BFKE";
            
            class ChunkStream
            {
            public:
                ChunkStream();
                ~ChunkStream();
                
                static bool Requires_Ios5_Cpp11_Runtime_Fix;
                
                bool TrySetStream(std::istream* bytes);

                const std::string& GetCurrentTag() const { Eegeo_ASSERT(!AtEndOfStream()); return m_currentTag; }
                u32 GetHeaderVersion() const { Eegeo_ASSERT(!AtEndOfStream()); return m_headerVersion; }
                u32 GetCurrentBodyVersion() const { Eegeo_ASSERT(!AtEndOfStream()); return m_currentBodyVersion; }
                u32 GetCurrentBodyAlignment() const { Eegeo_ASSERT(!AtEndOfStream()); return m_currentBodyAlignment; }
                u32 GetCurrentNumOfChildren() const { Eegeo_ASSERT(!AtEndOfStream()); return m_currentNumberOfChildren; }
                u32 GetCurrentBodyLength() const { Eegeo_ASSERT(!AtEndOfStream()); return static_cast<u32>(m_currentBodyLength); }
                
                bool HasAlignedData() const;
                
                // eof bit is only set if we have read past the end of stream (and not if we have tellg / seeked past the end of stream)
                bool AtEndOfStream() const { return m_pBytes->eof(); }
                std::istream* GetCurrentBodyData();
                bool AdvanceToNextChunk();
                u32 SkipSubtree(std::string expectedTag);
                
            private:

                std::istream* m_pBytes;
                u32 m_headerVersion;
                
                std::string m_currentTag;
                u32 m_currentBodyVersion;
                u32 m_currentBodyAlignment;
                u32 m_currentNumberOfChildren;
                std::istream::off_type m_currentBodyLength;
                std::istream::pos_type m_currentBodyStreamPosition;
                Resources::BinaryParsing::BinaryParser m_headerParser;
                
                std::istream::pos_type GetPositionOfNextChunk();
                bool TryReadRootChunkHeader();
                bool TryReadChunkHeader(bool isHcffRootChunk);
                void Reset();
                void ClearCurrent();
            };
        }
    }
}
